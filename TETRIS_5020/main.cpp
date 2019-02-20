#include "sprite.h"
#include "direct3d.h"
#include "common.h"
#include "tetris.h"
#include "keyboard.h"
#include "pad.h"
#include "error.h"
#include "resource.h"



// 名前空間
using namespace DirectX;
using namespace SimpleMath;

// 列挙体
enum
{
    kTitleInit,
    kTitleUpdate,
    kGameInit,
    kGameUpdate,
    kResultInit,
    kResultUpdate
};


// プロトタイプ宣言
LRESULT CALLBACK WinProc( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdShow, int nCmdShow )
{
#ifdef _DEBUG
    // メモリリークのチェック
    //_CrtSetBreakAlloc( 162 );
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif



    // ミューテックスの作成
    HANDLE mutex = CreateMutex( NULL, false, "tetrisgame" );

    // 多重起動のチェック
    if( GetLastError() == ERROR_ALREADY_EXISTS )
    {
        // 起動している
        Error::showDialog( "既に起動しています。" );

        
        return 0;
    }


    // ウィンドウクラスの作成
    WNDCLASSEX wnd;
    ZeroMemory( &wnd, sizeof( WNDCLASSEX ) );

    wnd.cbSize = sizeof( WNDCLASSEX );      // 構造体サイズ
    wnd.style = CS_HREDRAW | CS_VREDRAW;    // スタイル
    wnd.hInstance = hInstance;              // アプリケーション
    wnd.lpszClassName = "ClassName";        // クラス名
    wnd.hCursor = LoadCursor( NULL, IDC_ARROW );    // カーソル形状
    wnd.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    wnd.lpfnWndProc = WinProc;      // ウィンドウプロシージャへの関数ポインタ
    wnd.hIcon = LoadIcon( hInstance, reinterpret_cast<LPSTR>(IDI_ICON1) );
    // wnd.hIconSm=LoadIcon←表示画面左上のアイコン

    // 登録
    if( !RegisterClassEx( &wnd ) )
    {
        // エラー
        return 0;
    }

    // ウィンドウサイズを決定
    RECT rect;
    rect.left = rect.top = 0L;
    rect.right = 1280L;
    rect.bottom = 720L;

    const DWORD style = WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME &~WS_MAXIMIZEBOX;
    const DWORD ex_style = WS_EX_OVERLAPPEDWINDOW;
    AdjustWindowRectEx( &rect, style, false, ex_style );

    // ウィンドウの作成
    const HWND hWnd = CreateWindowEx(
        ex_style,               // 拡張ウィンドウスタイル
        "ClassName",            // クラス名
        "Title",                // ウィンドウタイトル
        style,                  // ウィンドウスタイル
        CW_USEDEFAULT,          // 表示座標X
        CW_USEDEFAULT,          // 表示座標Y
        rect.right - rect.left, // ウィンドウ横幅
        rect.bottom - rect.top, // ウィンドウ縦幅
        NULL,                   // 親ウィンドウへのハンドル
        NULL,                   // メニューハンドル
        hInstance,              // アプリケーションインスタンス
        NULL );                 // ウィンドウ作成データ

    // NULLチェック
    if( hWnd == NULL )
    {
        // エラー
        return 0;
    }


    // Direct3D初期化
    if( !Direct3D::init( hWnd ) )
    {
        // エラー
        return 0;
    }

    // COMライブラリの初期化
    if( FAILED( CoInitializeEx( NULL, COINIT_MULTITHREADED ) ) )
    {
        // エラー
        return 0;
    }
    // Spriteクラス初期化
    if( !Sprite::init() )
    {
        // エラー
        return 0;
    }

    // Keyboardクラスの初期化
    if( !Key::init() )
    {
        //エラー
        return 0;
    }

    // Commonクラス初期化
    if( !Common::init() )
    {
        // エラー
        return 0;
    }


    // Fontクラスの初期化
    /*if( !Font::init() )
    {
        // エラー
        return 0;
    }*/

    // CRIADXの初期化
    /*if( !Adx::init( "Gane.acf" ) )
    {
        // エラー
        return 0;
    }*/

    // サウンドの読み込み
    //Adx::load( "CueSheet_0.acb", NULL );

    // ウィンドウの表示
    ShowWindow( hWnd, SW_SHOWNORMAL );

    // メインループ
    MSG msg = { NULL };

    // ファイルを開く
    /*FILE* fp = fopen( "data.txt", "r" );
    if( fp == NULL )
    {
        // エラー
        return 0;
    }*/

    // ファイルから数値を読み込む
    //int num = 0;
    //fscanf( fp, "%d", &num );

    // ファイルを閉じる
    //fclose( fp );


    // 時間計測
    DWORD t1, t2, t3 = 0L, dt;
    t1 = timeGetTime();
    t2 = timeGetTime();

    // 現在の作業番号
    int work_no = kGameInit;

    // シーンクラス変数
    //Title title;
    //Game game;
    Tetris tetris;


    //Result result;

   while( msg.message != WM_QUIT )
    {
        // メッセージ処理
        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            // フレームレート制御
            t1 = timeGetTime();  // 現在の時間
            dt = (t1 - t2) + t3; // 前回の更新からの差分を計算

            // 約16ミリ秒経過していたら処理を行う
            if( dt > 16 )
            {
                t2 = t1;         // 今の時間を前回の時間とする
                t3 = dt % 16;    // 誤差分を吸収

                // パッドクラス更新
                Pad::update();

                // Adxクラス更新
                //Adx::update();

                // シーン処理
                switch( work_no )
                {
                case kTitleInit:
                    // タイトルクラス初期化
                    /*if( !title.init() )
                    {
                        // エラー
                        PostQuitMessage( 0 );
                    }*/

                    // 次の処理へ
                    work_no = kTitleUpdate;
                    break;

                case kTitleUpdate:
                    // タイトルクラス更新処理
                    /*if( !title.update() )
                    {
                        // falseが帰ってきたら次のシーンへ
                        title.destroy();
                        work_no = kGameInit;
                    }*/

                    break;

                case kGameInit:
                    // ゲームクラス初期化
                    if( !tetris.init() )
                    {
                        // エラー
                        PostQuitMessage( 0 );
                    }

                    // 次の処理へ
                    work_no = kGameUpdate;
                    break;

                case kGameUpdate:
                    // ゲームクラス更新
                    tetris.update();
                        
                           // work_no = kResultInit;// kResultInit;
                        
                    break;


                case kResultInit:
                    // リザルト画面初期化
                    /*if( !result.init() )
                    {
                        // エラー
                        PostQuitMessage( 0 );

                    }*/

                    // 次の処理へ
                    work_no = kResultUpdate;
                    break;

                case kResultUpdate:
                    // リザルト画面更新
                    /*if( !result.update()
                    {
                        // falseが帰ってきたらタイトルへ
                        result.destroy();
                        work_no = KTitleInit;
                    }*/
                    break;

                    }



                

                //画面クリア
                Direct3D::clear();

                // スプライト描画開始
                Sprite::begin();

                switch( work_no )
                {
                case kTitleUpdate:
                    //title.draw();
                    break;

                case kGameUpdate:
                    tetris.singledraw();
                    break;

                case kResultUpdate:
                    //result.draw();
                    break;
                }


                // スプライト描画終了
                Sprite::end();

                // 描画更新
                Direct3D::present();
            }

        }
    }

    // COMライブラリの解放
    CoUninitialize();

    // インターフェイスの解放(確保した順の逆に開放していく)
    //title.destroy();
    tetris.destroy();
    //Font::destroy();
    Common::destroy();
    Sprite::destroy();
    Direct3D::destroy();
    //Adx::destroy();

    return 0;
}

LRESULT CALLBACK WinProc( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch( Msg )
    {
    case WM_PAINT:
        hdc = BeginPaint( hWnd, &ps );
        EndPaint( hWnd, &ps );
        break;

        

    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYUP:
        Keyboard::ProcessMessage( Msg, wParam, lParam );
        break;

    case WM_KEYDOWN:
        Keyboard::ProcessMessage( Msg, wParam, lParam );
        switch( wParam )
        {
        case VK_ESCAPE:
            // ESCが押されたらループを終了する
            PostMessage( hWnd, WM_CLOSE, 0, 0 );
            break;
        }
        break;

        // マウス入力を取得するため以下の処理を追加する
    case WM_ACTIVATEAPP:
    case WM_INPUT:
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_XBUTTONDOWN:
    case WM_XBUTTONUP:
    case WM_MOUSEHOVER:
        Keyboard::ProcessMessage( Msg, wParam, lParam );
        break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
    }

    return DefWindowProc( hWnd, Msg, wParam, lParam );
}