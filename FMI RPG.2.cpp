#include "Header.h"
using namespace std;

const Teacher Algebra1("Algebra", "Professor", 29, { "MentalPower+2", "HP+30", "Questions+10" });
const Teacher Algebra2("Algebra", "Assisstant", 21, { "MentalPower+1", "HP+50", "Questions+5" });
const Teacher Analysis1("Analysis", "Professor", 23, { "MentalPower+2", "HP+30", "Questions+11" });
const Teacher Analysis2("Analysis", "Assisstant", 21, { "MentalPower+2", "HP+40", "Questions+6" });
const Teacher Programming1("Programming", "Professor", 25, { "MentalPower+2", "HP+30", "Questions+10" });
const Teacher Programming2("Programming", "Assisstant", 20, { "MentalPower+1", "HP+50", "Questions+7" });

const Student Default("You", 3, 100, 100, 10, 20, {"Bread Sticks", "Bread Sticks", "Pillow","Textbook"});

bool IsThereItem(list<string> inv, string item)
{
	while (!inv.empty())
	{
		if (inv.front() == item)
			return true;
		inv.pop_front();
	}return false;
}

double getStringNumbers(string str)
{
	int lenght = str.size(); int sum = 0; int k = 1;
	for (int i = lenght - 1; i >= 0; i--, k *= 10)
	{
		if (str[i] < '0' || str[i]>'9')
			break;
		else sum += (str[i] - '0') * k;
	}
	return sum;
}

void SwitchCase(int k, queue<Block>&day)
{
	Block current;
	switch (k)
	{
	case 1: 
	{
		current.Time = k; day.push(current);
	}break;
	case 2: 
	{
		current.Time = k;   int j = rand() % 2 + 1;
		switch (j)
		{
		case 1: {current.Prepodavatel = Analysis2; day.push(current); }break;
		case 2: {current.Prepodavatel = Programming2; day.push(current); }break;
		}

	}break;
	case 4: 
	{
		int j = rand() % 2 + 1; current.Time = k;
		switch (j)
		{
		case 1: { current.Prepodavatel = Programming1; day.push(current);}break;
		case 2: {current.Prepodavatel = Analysis1; day.push(current); }break;
		}
	}break;
	case 3: 
	{
		int j = rand() % 2 + 1; current.Time = k;
		switch (j)
		{
		case 1: { current.Prepodavatel = Algebra1; day.push(current); }break;
		case 2: {current.Prepodavatel = Algebra2; day.push(current);}break;
		}
	}break;
	}
}

void CreateWeek(list<queue<Block>>& week)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		queue<Block>day;
		int time = 0;
		while (time<=9)
		{
			int k = rand() % 4 + 1;
			if ((k != 1 || time + 1 < 6))
			{
				time += k;
				SwitchCase(k, day);
			}
			else if(time>=6)break;

		}week.push_front(day);
	}
}

void ClearQueue(queue<Block>& current)
{
	while (!current.empty())
		current.pop();
}

bool IfHpZero(Student& you)
{
	if (you.HP <= 0)
	{
		you--;
		you.HP = you.InitialHP * 0.6;
		return true;
	}
	else return false;
}

void DuringShortBreak(Student& you, ofstream& myfile)
{
	cout << "Stats: " << endl << "Reamining Fails: " << you.getFails()<< endl<<"Remaining HP: "<<you.getHP()<<endl<<"Chance for a question: "<<you.getPercent()<<endl;
	cout << "Mental Strenght: " << you.getMental()<< endl<<endl;
	cout << "Choose between the following: " << endl;
	cout << "Meditation (+5 Health). (*)" << endl;
	cout << "Use an item from inventory. (**)";if(you.getInventory().empty())cout<<" It is empty"<< endl;
	string str; cout << endl;
	getline(cin, str); cout << endl;
	if (str == "*") { you + 5;myfile<<"You chose Meditation. Your HP is now: " << you.getHP() << "\n";}
	if (str == "**" && !you.getInventory().empty())
	{
		list<string> inv = you.getInventory();
		cout << "Chose an item: ";
		while (!inv.empty())
		{
			if (inv.size() == 1)
				cout << inv.front();
			else cout << inv.front() << ", ";
			inv.pop_front();
		}cout << endl;
		string answer; cout << endl;
		getline(cin, answer); list<string> current = you.getInventory();
		if (answer == "Bread Sticks" && IsThereItem(current, "Bread Sticks")) { you + 9; you.RemoveItem("Bread Sticks");
		myfile << "You chose Bread Sticks (+9 HP). Your HP is now: "<<you.getHP()<<"\n"; }

		if (answer == "Pillow" && IsThereItem(current, "Pillow")) { you + 20; you.RemoveItem("Pillow");
		myfile << "You chose Pillow (+20 HP). Your HP is now: " << you.getHP ()<< "\n";}

		if (answer == "Textbook" && IsThereItem(current, "Textbook")) { you ^ 4; you % 1; you.RemoveItem("Textbook");
		myfile << "You chose Textbook (+4 Mental strenght and +1% Smart quesitons). Your Mental Strenght is now: "
		<< you.getMental ()<< " and your chance for a confusing question is: "<<you.getPercent()<<"\n";
		}
	}cout << endl;
}    
 
void TeacherHit(int chance, Student& You, Teacher& him, ofstream& myfile)
{
	myfile << him.getSubject() << " " << him.getTitle() << " attacks\n";
	int k = 100 - chance;
	double hitpercent = rand() % k + chance; hitpercent /= 100;
	double studentpercent = rand() % 60 + 40; studentpercent /= 100;
	double hit = hitpercent * him.getPoints(); int procent = rand() % 100 + 1;
	if (procent <= You.getPercent())
	{
		double damage = (0.75 * (hit - studentpercent * You.getMental()));
		You - damage; myfile << "You managed to ask a confusing quesiton.\n" << "Damage dealt: " << damage<<" Your HP is now: "<<You.getHP()<<"\n";
	}
	else 
	{ double damage= (hit - studentpercent * You.getMental());
	You - damage; 
	myfile << "You did not manage to ask a confusing quesiton.\n" << "Damage dealt: "
		<< damage << " Your HP is now: " << You.getHP() << "\n";
	}
}

void TeacherBonus(Teacher& him ,Student& you, ofstream& myfile)
{
	int k = rand() % 3 + 1; list<string> current = him.getBonus();
	switch (k)
	{
	case 1: 
	{
		string str = current.front(); double h = getStringNumbers(str); you^ h; myfile << "You have been rewarded Mental Strenght + " << h << "\n";
	}break;
    case 2: 
	{
		current.pop_front(); string str = current.front(); double h = getStringNumbers(str); you + h; myfile << "You have been rewarded HP + " << h << "\n";
	}break;
	case 3:
	{
		string str = current.back(); double h = getStringNumbers(str); you% h; myfile << "You have been rewarded Chance for a question + " << h << "\n";
	}break;
	}
}

void ClassBattle(Student& You, list<queue<Block>>& week, queue<Block>& memory, ofstream& myfile)
{
	int chance; Teacher him = week.front().front().Prepodavatel;
	int time = week.front().front().Time;
	if (week.front().front().Prepodavatel.getTitle() == "Professor")
		chance = 80; else chance = 60; 
	int fail = 0;
for(int j=0; j<time; j++)
{
	for (int i = 0; i < 4; i++)
	{
		TeacherHit(chance, You, him, myfile);

		if (IfHpZero(You))
		{
			myfile << "You have lost your HP. You now have: " << You.getFails() << " remaining fails.\n";
			while (!week.front().empty())
			{
				memory.push(week.front().front()); week.front().pop(); 
			}fail++;
			break;
		}
	}if (fail != 0)break; 
	if (j < time - 1)
	{ myfile << "Time for a short break.\n"; DuringShortBreak(You, myfile); }
}if (fail == 0) { TeacherBonus(him, You,myfile); memory.push(week.front().front()); week.front().pop(); }
}

void DuringLongBreak(Student& you, ofstream &myfile) 
{
	cout << "Stats: " << endl << "Reamining Fails: " << you.getFails() << endl << "Remaining HP: " << you.getHP() << endl << "Chance for a question: " << you.getPercent() << endl;
	cout << "Mental Strenght: " << you.getMental() << endl << endl;
	cout << "Chose one of the following: (*) Two one-point actions or (**) One\ntwo-point action " << endl<<endl;
	string answer;
	getline(cin, answer); cout << endl;
	if (answer == "*") { DuringShortBreak(you,myfile); DuringShortBreak(you,myfile); }
	if (answer == "**")
	{
		cout << "Stats: " << endl << "Reamining Fails: " << you.getFails() << endl << "Remaining HP: " << you.getHP() << endl << "Chance for a question: " << you.getPercent() << endl;
		cout << "Mental Strenght: " << you.getMental() << endl << endl;
		cout << endl;
		cout << "Choose one of the following: " << endl<<endl;
		cout << "Eat a bar (HP+15)  (*)" << endl;
		cout << "Eavesdrop a conversation (PercentSmartQuestion + 1, 5)  (**) " << endl;
		cout << "Buy Bread Sticks (Inventory + 3 and HP + 9 when used)  (***)" << endl;
		string option; cout << endl;
		getline(cin, option);
		if (option == "*") { you + 15; myfile<<"You chose to eat a bar.  Your HP is now: " << you.getHP() << "\n";}
		if (option == "**") { you % 1.5; myfile<<"You chose to eavesdrop a conversation. Your Chance for a confusing smart question is now: " 
			<< you.getPercent() << "%\n";}
		if (option == "***") { for (int i = 0; i < 3; i++) you || ("Bread Sticks"); myfile << "You chose to resupply with 3 packets of Bread Sticks (each + 9HP when used ).\n";}
	}cout << endl;
}

void DuringGap(Student & you, ofstream& myfile)
{
	cout << "Stats: " << endl << "Reamining Fails: " << you.getFails() << endl << "Remaining HP: " << you.getHP() << endl << "Chance for a question: " << you.getPercent() << endl;
	cout << "Mental Strenght: " << you.getMental() << endl << endl;
	cout << "Chose one of the following:" << endl << "(*) Two 2-point actions " << endl << "(**) One 3-point action and one 1-point action " << endl
		<< "(***) Four 1-point actions" << endl << "(****) One 2-point action and Two 1-point actions" << endl << endl;
	string answer;
	getline(cin, answer); cout << endl;
	if (answer == "*") { DuringLongBreak(you, myfile), DuringLongBreak(you, myfile); }
	if (answer == "***") { for (int i = 0; i < 4; i++)  DuringShortBreak(you, myfile); }
	if (answer == "****") { DuringLongBreak(you, myfile); for (int i = 0; i < 2; i++)DuringShortBreak(you, myfile);  }
	if (answer == "**")
	{
		DuringShortBreak(you, myfile);
		cout << "Choose between the following: " << endl;
		cout << "Take a nap (+20HP)  (*)" << endl;
		cout << "Study (Chance for smart question + 4 and Mental Strenght + 4)  (**)" << endl;
		string option; getline(cin, option);
		if (option == "*") { you + 20; myfile << "You chose to take a nap. Your HP is now: " << you.getHP() << "\n"; }
		if (option == "**") {
			you ^ 4; you % 4; myfile << "You chose to study during the gap. Yor Mental Strenght is now: " << you.getMental()
				<< " and your Chance for a confusing question is: " << you.getPercent() << "%\n";
		}
	}
}

void DuringClass(list<queue<Block>>&week, Student& You, ofstream& myfile)
{
	queue<Block>memory;
		int count = 0;
		while (You.getFails()>0)
		{
			if (week.front().empty()) { week.pop_front(); week.push_back(memory); ClearQueue(memory); }
			if (week.front().front().Time != 1)
			{
				if (count != 0)
				{
					myfile << "Time for a long break.\n";
					DuringLongBreak(You, myfile);
				}
				count++; myfile << "You now have " << week.front().front().Time << " hours " << week.front().front().Prepodavatel.getSubject() << " with a "
				<< week.front().front().Prepodavatel.getTitle() << "\n";
				ClassBattle(You, week, memory, myfile);
			}
			else { count = 0; myfile << "You have a 1 hour Gap.\n "; DuringGap(You, myfile); memory.push(week.front().front()); week.front().pop(); }
		}
}

int main()
{
	ofstream text;
	text.open("myfile.txt");
	list<queue<Block>> week;
	Student Az; Az = Default;
	CreateWeek(week);
	DuringClass(week, Az, text);
	text.close();
	return 0;
}