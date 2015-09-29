#include <iostream>
#include <array>

using namespace std;

bool **makeBoard (int n, bool**board);
void checkAttack(int x, int y);

int main()
{

	bool **board;
	int n;  // board size 
	int k;  // number of bishops

	cin >> n;

	board = makeBoard(n, board);

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{	
			cout << " " << board[i][j];
			if (j == n-1)
				cout << endl;
		}
	}
	cout << endl;

	return 0;
}

bool** makeBoard(int n, bool **board)
{
	board = new bool*[n];
	for (int i=0 ; i<n ; i++)
		board[i] = new bool[n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{
			board[i][j] = false;
		}
	}

	return board;
}

bool placeBishop(bool **board,)
{
	/*
		- parse board
		- try to place bishop
		- 
		-
	*/
}

void isAttacking(int x, int y)
{

}