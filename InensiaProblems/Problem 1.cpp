#include <iostream>
#include<string>

#include<fstream>
#include<math.h>

bool IsPosInS(string& S, string& position, int PosS, int Posp) //Here we check whether one string contains the other
{
	if (PosS == S.length())
		return false;
	if (position.length() - 1 == Posp && position[Posp] == S[PosS])
		return true;
	if (S[PosS] != position[Posp])
		IsPosInS(S, position, ++PosS, Posp);
	else IsPosInS(S, position, ++PosS, ++Posp);
}

int SalaryPosition(string& S) //Function for converting a string of numbers to an actual whole number
{
	int len = S.length();
	string help="";
	for (int i = 0; i < len; i++)
	{
		if (S[i] >= '0' && S[i] <= '9')
			help += S[i];
	}
	int sum=0;
	int len2 = help.length();
	for (int i = 0; i < len2; i++)
	{
		sum += (int(help[i]) - int('0')) * pow(10, len2-1-i);
	}
	return sum;
}



int main()
{
fstream file;
	file.open("salary.bin", ios::binary|ios::in |ios::out | ios::trunc);
	string S="1";	
	while (1)
	{
		cout << "Enter position and salary:  "<<endl;
		getline(cin, S);
		if (S == "END")
			break;
		file << S<<endl;
	}
	cout << "What position are you interested in? ";
	string position;
	getline(cin, position);

	file.seekg(0);
	float sum = 0;
    int itr = 0;
	while (file.good())
	{

		getline(file, S);
		if (IsPosInS(S, position, 0, 0))
		{
			sum += SalaryPosition(S);
			itr++;
		}
	}
	cout <<"Average "<<position<<" salary is: "<< sum / itr;
}
