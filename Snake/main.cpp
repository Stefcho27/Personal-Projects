#include "Snake.h"

void PlayGame()
{
	Field plane;
	Snake player;
	player.InitializeToField(plane);
	char* ptr = plane.getArray();
	ptr += SIZEFIELD + 3;
	plane.RandomSnack();
	while (1)
	{
		plane.GetField();

		char ch = _getch();

	switch (ch)
		{
		case'a': 
			if (*(ptr - 1) == '%')
				plane.RandomSnack();
			player.Slide(ptr-1);
			ptr--;
			break;
		case's':  
			if (*(ptr + SIZEFIELD) == '%')
				plane.RandomSnack(); player.Slide(ptr + SIZEFIELD);
			ptr += SIZEFIELD;
			break;
		case'w':
			if (*(ptr - SIZEFIELD) == '%')
				plane.RandomSnack();
			player.Slide(ptr - SIZEFIELD);
			ptr -= SIZEFIELD;
			break;
		case'd': 
			if (*(ptr + 1) == '%')
				plane.RandomSnack();
			player.Slide(ptr+1);
			ptr++;
			break;
		}
		system("CLS");
	}
}

int main()
{
	PlayGame();
}
