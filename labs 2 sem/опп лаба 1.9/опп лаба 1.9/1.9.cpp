//9. Создать абстрактный класс «живое существо».
// 
//Создать класс «человек» (наследник абстрактного класса), имеющий имя, возраст, вес.
//Определить конструкторы, деструктор и функцию вывода.
// 
//Создать public - производный класс – совершеннолетний (от человек), имеющий номер паспорта.
//Определить конструкторы по умолчанию и с разным числом параметров, деструкторы, функцию вывода.
//Определить функции переназначения возраста и номера паспорта.
// 
//Использовать статическую переменную для хранения количества созданных объектов классов-наследников
//и константы для хранения идентификационных номеров в абстрактном классе, в классах-наследниках.

#include <iostream>
#include <string>

using namespace std;

class LiveCreatures
{
protected:
	const int id;

public:
	static int count;

	LiveCreatures(int id) : id(id) 
	{
		count++;
	}

	//virtual ~LiveCreatures() 
	//{
    //  count--;
    //}

	virtual void Show() = 0;
};


int LiveCreatures::count = 0;


class Human : public LiveCreatures
{
protected:
	string name;
	int age;
	double weight;

public:
	Human(int id) : LiveCreatures(id)
	{
		name = "Gleb";
		age = 18;
		weight = 70;
	}

	Human(int id, string name, int age, double weight) : LiveCreatures(id)
	{
		this->name = name;
		this->age = age;
		this->weight = weight;
	}

	~Human() {}

	Human(const Human& other) : LiveCreatures(other.id)
	{
		name = other.name;
		age = other.age;
		weight = other.weight;
	}

	void Show()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Weight: " << weight << endl;
	}
};

class Adult : public Human
{
private:
	string passportNumber;

public:
	Adult(int id) : Human(id)
	{
		name = "Gleb";
		age = 18;
		weight = 70;
		passportNumber = "AB0000000";
	}

	Adult(int id, string name, int age, double weight, string passportNumber) : Human(id)
	{
		if (age < 18)
		{
			cout << "Incorrect input! The age is automatically set to 18." << endl;
			this->age = 18;
			this->name = name;
			this->weight = weight;
			this->passportNumber = passportNumber;
		}
		else
		{
			this->name = name;
			this->age = age;
			this->weight = weight;
			this->passportNumber = passportNumber;
		}
	}

	Adult(int id, string name, int age, double weight) : Human(id)
	{
		if (age < 18)
		{
			cout << "Incorrect input! The age is automatically set to 18." << endl;
			this->age = 18;
			this->name = name;
			this->weight = weight;
			passportNumber = "AB0000000";
		}
		else
		{
		this->name = name;
		this->age = age;
		this->weight = weight;
		passportNumber = "AB0000000";
		}
	}

	~Adult() {}

	Adult(const Adult& other) : Human(other.id)
	{
		name = other.name;
		age = other.age;
		weight = other.weight;
		passportNumber = other.passportNumber;
	}

	void SetAge(int otherAge)
	{
		age = otherAge;
	}

	void SetPassportNumber(string otherPassportNumber)
	{
		passportNumber = otherPassportNumber;
	}

	void Show()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Weight: " << weight << endl;
		cout << "Passport number: " << passportNumber << endl;
	}
};

int main()
{
	Human human(1);
	human.Show();
	cout << endl;

	Adult adult1(2,"Anastasia", 18, 55, "AB1234870");
	adult1.Show();
	cout << endl;

	Adult adult2(3,"Karina", 11, 30.5);
	adult2.Show();
	cout << endl;

	Adult adult3(4);
	adult3.Show();
	cout << endl;

	adult3.SetPassportNumber("PB9803241");
	adult3.SetAge(69);
	adult3.Show();
	cout << endl;


	cout << LiveCreatures::count << endl;
	return 0;
}