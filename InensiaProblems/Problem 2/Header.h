#pragma once
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iostream>
#include<string>

class Student {

	string name;
	unsigned int FacNum;
	int grades[N];

public:
	Student();
	void setName(string);
	
	string GetName();
	unsigned int GetNum();

	float getGPA();


	friend istream & operator >>(istream&, Student&);
}
