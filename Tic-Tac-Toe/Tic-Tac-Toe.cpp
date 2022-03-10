using namespace std;

#include <iostream>
#include < stdlib.h >

enum forgame {win, lose, tie};
enum BoxContain {X, o, nothing};
int const SIZE = 9;

class TicTacToePlane
{

	struct Box
	{
		char arr[SIZE][SIZE];
		BoxContain what;

		Box()
		{
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (i == 0||i== SIZE - 1||j==0||j==SIZE-1)
						arr[i][j] = '#';
					else arr[i][j] = ' ';
				}
			}
			what = nothing;
		}

		void XChangeBox(const char x)
		{
			for (int i = 1; i < SIZE-1; i++)
				for (int j = 1; j < SIZE - 1; j++)
					if (i == j)
						arr[i][j] = x;
					else if (i + j == SIZE - 1)
						arr[i][j] = x;
			what = X;
		}

		void OChangeBox(const char O)
		{
			for (int i = 2; i < SIZE - 2; i++)
				for (int j = 2; j < SIZE - 2; j++)
					if (i == 2 || j == 2 || i == SIZE - 3 || j == SIZE - 3)
						arr[i][j] = O;
			what = o;
		}

	};


    Box board [3][3];
public:

	void PrintBoard()
	{
		for (int i = 0; i < 3; i++)
			for (int k = 0; k < SIZE; k++)
			{
				for (int j = 0; j < 3; j++)
					for (int l = 0; l < SIZE; l++)
						cout << board[i][j].arr[k][l];
				cout << endl;
			}
	}

	void Turn(int a, int b, int turn)
	{
		if (turn % 2 == 1)
			board[a][b].OChangeBox('O');
		else board[a][b].XChangeBox('X');
	}


	forgame CheckRow(int a)
	{
		int i = 0;
		for (int j = 0; j < 3; j++)
			if (board[a][j].what == nothing)
				return tie;
			else if (board[a][j].what == o)
				i++;
		if (i == 0)
			return win;
		else if (i == 3)
			return lose;
		else return tie;

	}

	forgame CheckColumn(int a)
	{
		int i = 0;
		for (int j = 0; j < 3; j++)
			if (board[j][a].what == nothing)
				return tie;
			else if (board[j][a].what == o)
				i++;
		if (i == 0)
			return win;
		else if (i == 3)
			return lose;
		else return tie;
	}

	forgame CheckDiagonals()
	{
		if (board[1][1].what != board[0][0].what || board[1][1].what != board[2][2].what)
			1;
		else if (board[1][1].what == o)
			return lose;
		else return  win;
		
		if (board[1][1].what != board[0][2].what || board[1][1].what != board[2][0].what)
			return tie;
		else if (board[1][1].what == o)
			return lose;
		else return win;	
	}

	forgame CheckForWin() 
	{

		for (int i = 0; i < 3; i++)
			if (this->CheckRow(i) == win)
				return win;
			else if (this->CheckRow(i) == lose)
				return lose;
		for (int i = 0; i < 3; i++)
			if (this->CheckColumn(i) == win)
				return win;
			else if (this->CheckColumn(i) == lose)
				return lose;
		return this->CheckDiagonals();
		
	}


};


void Play(TicTacToePlane& Game)
{
	system("CLS");
	Game.PrintBoard();
	int i = 0;
	for (i; i < 9; i++)
	{
		if (i > 4)
		{
			forgame result = Game.CheckForWin();
			if (result == win)
			{
				cout << endl<<"X wins" << endl;
				break;
			}
			else if (result == lose)
			{
				cout <<endl<< "O wins" << endl;
				break;
			}
		}
		cout << "Enter row and column: " << endl;
		cout << "Row: " << endl; int row; cin >> row;
		cout << "Column: " << endl; int column; cin >> column;

		Game.Turn(row, column, i);
		system("CLS");
		Game.PrintBoard();

	}
	if (i == 9)
		cout <<endl<< "Its a tie" << endl;
}

int main()
{
	TicTacToePlane Game;
	Play(Game);

	return 0;
}
