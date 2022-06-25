Student::Student() 
{
	name = "Steve";
	FacNum = rand() % 10000 + 1;
	for (int i = 0; i < N; i++)
	{
		grades[i] = rand() % 5 + 2;
	}
}

string Student::GetName() { return name;}

unsigned int Student::GetNum() { return FacNum;}

void Student::setName(string S) { name = S; }

float Student::getGPA()
{
	float sum=0;
	for (int i = 0; i < N; i++)
	{
		sum += grades[i];
	}
	return sum / N;
}
