#include "Header.h"

Student::Student()
{
	AllowedFails = 0;
	HP = 0;
	InitialHP = 0;
	MentalPower = 0;
	PercentSmartQuestion = 0;
	Inventory.clear();
}

Student::Student(string ime, int proval, double zhivot, double initiallife, double mental, double procent, list<string> inventar)
{
	Name = ime;
	if (proval >= 0)AllowedFails = proval; else AllowedFails = 0;
	HP = zhivot; 
	InitialHP = initiallife; 
	MentalPower = mental;
	PercentSmartQuestion = procent;
	Inventory = inventar;
}

void Student:: operator=(const Student& uchenik)
{
	Name = uchenik.Name;
	AllowedFails = uchenik.AllowedFails;
	HP = uchenik.HP;
	InitialHP = uchenik.InitialHP;
	MentalPower = uchenik.MentalPower;
	PercentSmartQuestion = uchenik.PercentSmartQuestion;
	Inventory = uchenik.Inventory;
}

void Student::operator+(double hp)
{
	HP += hp;
}

void Student::operator-(double hp)
{
	HP -= hp;
}

void Student::operator^(double mental)
{
	MentalPower += mental;
}

void Student::operator%(double procent)
{
	PercentSmartQuestion += procent;
}

void Student::operator--(int)
{
	AllowedFails--;
}

void Student::operator||(string item)
{
	Inventory.push_front(item);
}

void Student::RemoveItem(string item)
{
	list<string> temp; int i = 0; 
	while (!Inventory.empty())
	{
		if (i == 0) {
			if (Inventory.front() != item)
			{
				temp.push_front(Inventory.front());
				Inventory.pop_front();
			}
			else { Inventory.pop_front(); i++; }
		}
		else {
			temp.push_front(Inventory.front());
			Inventory.pop_front();
		}
	}
	Inventory = temp;
}


Teacher::Teacher()
{
	Subject = "";
	Title = "";
	TeachPoints = 0;
	Bonus.clear();
}

Teacher::Teacher(string subject, string title, double points, list<string> bonus)
{
	Subject = subject;
	Title = title;
	if (points >= 0)
		TeachPoints = points;
	else TeachPoints = 0;
	Bonus = bonus;
}

