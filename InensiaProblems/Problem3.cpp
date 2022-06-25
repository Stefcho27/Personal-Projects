#include <iostream>
#include<string>

void Concat(string& S, int n, string& seperator)
{
	if (n <= 2)
	{
		seperator += S;
		 S += seperator;
	}
	else {
		Concat(S, --n, seperator);
		S += seperator;
	}
}


int main()
{
  string S = "Inensia";
	string seperator = "<3";
	Concat(S, 4, seperator);
	cout << S;
}
