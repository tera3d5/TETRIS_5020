#pragma once


class Error
{
public:
    static void showDialog( const char* Message )
    {
        MessageBox(
            NULL,                   // ウィンドウハンドル
            Message,                // メッセージ
            "Error",                // タイトル
            MB_OK | MB_ICONERROR ); // フラグ
    }
};