#pragma once
#include<iostream>
#include<list>
#include <iterator>
#include<string>
#include <queue>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>    
#include <fstream>
using namespace std;


class Student {

	string Name;
	int AllowedFails;
	double HP;
	double InitialHP;
	double MentalPower;
	double PercentSmartQuestion;
	list <string> Inventory;

public:
	Student();
	Student(string, int, double,double, double, double, list<string>);
	void operator=(const Student&);
	void operator+(double);
	void operator-(double);
	void operator^(double);
	void operator%(double);
	void operator--(int);
	void operator||(string);
	int getFails() { return AllowedFails; }
	double getHP() { return HP; }
	double getMental() { return MentalPower; }
	double getPercent() { return PercentSmartQuestion; }
	list<string> getInventory() { return Inventory; }
	friend bool IfHpZero(Student&);
	void RemoveItem(string);
};


class Teacher {

	string Subject;
	string Title;
	double TeachPoints;
	list <string> Bonus;

public:
	Teacher();
	Teacher(string, string, double, list<string>);
	string getSubject() { return Subject; }
	string getTitle() { return Title; }
	double getPoints() { return TeachPoints; }
	list<string> getBonus() { return Bonus; }
};

struct Block {

	int Time;
	Teacher Prepodavatel;
};
