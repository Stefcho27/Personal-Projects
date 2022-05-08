#pragma once
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>    
#include <time.h> 

class Field
{

protected:
	char arr [SIZEFIELD][SIZEFIELD];

public:

	Field();
  void GetField();
  void RandomSnack();
  char* getArray();
  
}


class Snake
{
protected:
	struct Node
	{
		Snake* previous;
		Snake* next;
		char* current;
	};
	Node head;
	int TailDirection();
  
  public:
	Snake();
  void operator=(Snake& clone);
  char* WhereToAdd(int diff);
	void AddToTail(char* element);
  void Slide(char* cell);
	void InitializeToField(Field& plane);

}

