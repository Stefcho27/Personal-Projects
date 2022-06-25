#include "Header.h"
using namespace std;

istream & operator >>(istream& in, Student& current)
	{
		cout << "Enter name: ";
		cin >> current.name;
		srand(time(NULL));
		current.FacNum = rand() % 10000 + 1;
		cout << "Enter " << N << " Grades: " << endl;
		int i = 1;
		while(i<=N)
		{
			int grade;
			cout << "Grade number " << i << ": ";
			cin >> grade;
			if (grade >= 2 && grade <= 6)
			{
				current.grades[i] = grade;
				i++;
			}
		}
		return in;
	}


int GetStudentsGPA(Student arr[], int size, string S)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetName() == S)
			return arr[i].getGPA(); 
	}
	return 0;
}


int main()
{
 	srand(time(NULL));
	Student arr[6];
	for (int i = 0; i < 6; i++)
	{
		string S;
		getline(cin, S);
		arr[i].setName(S);
	}
	cout << GetStudentsGPA(arr, 6, "Steve");

}
