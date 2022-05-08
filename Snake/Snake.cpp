#include "Snake.h"

Field::Field()
	{
		for (int i = 0; i < SIZEFIELD; i++)
			for (int j = 0; j < SIZEFIELD; j++)
				if (i == 0 || j == 0 || i == SIZEFIELD - 1 || j == SIZEFIELD - 1)
					arr[i][j] = '#';
				else arr[i][j] = ' ';
	}

void Field::GetField()
	{
		for (int i = 0; i < SIZEFIELD; i++)
		{
			for (int j = 0; j < SIZEFIELD; j++)
			{
				if (i == 0 || j == 0 || i == SIZEFIELD - 1 || j == SIZEFIELD - 1 && arr[i][j] != '#')
					arr[i][j] = '#';
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	void Field::RandomSnack()
	{
		srand(time(NULL));
		while (1)
		{
			int i = rand() % SIZEFIELD;
			if (i == 0)i++; if (i == 19)i--;
			int j = rand() % SIZEFIELD;
			if (j == 0)j++; if (j == 19)j--;
			if (arr[i][j] == 254 || arr[i][j]=='%')
				continue;
			else {
				arr[i][j] = '%';
				break;
			}
		}
	}

	char* Field::getArray()
	{
		return &(arr[0][0]);
	}


int Snake::TailDirection()
	{
		if (head.previous != nullptr)
			head.previous->TailDirection();
		else return head.next->head.current - head.current;
	}

Snake::Snake()
	{
		head.previous = nullptr;
		head.next = nullptr;
		head.current = nullptr;

	}

	void Snake:: operator=(Snake& clone)
	{
		head.current = clone.head.current;
		head.next = clone.head.next;
		head.previous = clone.head.previous;
	}

	char* Snake:: WhereToAdd(int diff)
	{
		if (head.previous != nullptr)
			head.previous->WhereToAdd(diff);
		else
		{
			switch (diff)
			{
			case -1:
				return head.current + 1;
			case SIZEFIELD:
				return head.current - SIZEFIELD;
			case -SIZEFIELD:
				return head.current + SIZEFIELD;
			case 1:
				return head.current - 1;
			}
		}
	}

	void Snake:: AddToTail(char* element)
	{
		if (head.previous != nullptr)
			this->head.previous->AddToTail(element);
		else
		{
			head.previous = new Snake;
			head.previous->head.next = this;
			head.previous->head.current = element;
			*element = 254;
			return;
		}
	}

	void Snake:: Slide(char* cell)
	{
		if (head.previous != nullptr)
			(this->head.previous)->Slide(this->head.current);
		else {
			*(head.current) = ' ';
			(head.current) = cell;
			return;
		};
		head.current = cell;
		if (*cell == '%')
			this->AddToTail(this->WhereToAdd(this->TailDirection()));
		*cell = 254;
		return;
	}

	void Snake:: InitializeToField(Field& plane)
	{
		char* ptr = plane.getArray();
		head.current = ptr+SIZEFIELD+3;
		*(head.current) = 254;
		head.next = nullptr;
		head.previous = new Snake;
		head.previous->head.next = this;
		head.previous->head.current =ptr+SIZEFIELD+2;
		*(head.previous->head.current) = 254;
		head.previous->head.previous = new Snake;
		head.previous->head.previous->head.current =ptr+SIZEFIELD+1 ;
		*(head.previous->head.previous->head.current) = 254;
		head.previous->head.previous->head.next = head.previous;
	}
