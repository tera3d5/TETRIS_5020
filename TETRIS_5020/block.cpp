#include "block.h"


enum
{
	right,
	left
};



void Block::brockchanger( int way, int box[4][4])
{

	if (way == right)
	{
		for (int i = 0;i < 4;i++)
			for (int j = 0;j < 4;j++)
				changebox[i][j] = box[i][j];


	}
}