// fn71781vB.cpp : Defines the entry point for the console application.

/*
	1 for 1)
	1 for 2)
	0.9 for 3)
	1 for 4)
	0 for 5)
	0 for 6)
	1 for 7)
	1 for 8)
*/

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class Elf
{
private:
	char* name;
	size_t age;
	size_t ability;
	void copy(const Elf& other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
		this->ability = other.ability;
	}
	void erase()
	{
		delete[] this->name;
	}
public:
	Elf()
	{
		/*char* name = new char[1];
		strcpy(this->name, "");*/
		char* name = new char[1];
		this->age = 0;
		this->ability = 1;
	}
	Elf(const char* _name, const size_t _age, const size_t _ability)
	{
		this->name = new char[strlen(_name) + 1];
		strcpy(this->name, _name);
		if (_age > 300)
			this->age = 0;
		else
		this->age = _age;
		if (_ability == 0 || _ability > 15)
		{
			this->ability = 1;
		}
		else
		{
			this->ability = _ability;
		}
	}
	Elf(const Elf& other)
	{
		copy(other);
	}
	Elf& operator = (const Elf& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}
	bool operator > (const Elf& other)
	{
		if (this->age < other.age && this->ability > other.ability)
			return true;
		return false;
	}
	bool operator < (const Elf& other)
	{
		if (this->age > other.age && this->ability < other.ability)
			return true;
		return false;
	}
	bool operator == (const Elf& other)
	{
		if (this->age == other.age && this->ability == other.ability)
			return true;
		return false;
	}
	~Elf()
	{
		this->erase();
	}
	char* getName()const
	{
		return this->name;
	}
	size_t getAge()const
	{
		return this->age;
	}
	size_t getAbility()const
	{
		return this->ability;
	}
	void setName(const char* _name)
	{
		strcpy(this->name, _name);
	}
	void setAge(const size_t _age)
	{
		this->age = _age;
	}
	void setAbility(const size_t _ability)
	{
		this->ability = _ability;
	}
};


std::ostream &operator << (std::ostream &output,const Elf e1)
{
	output << "Name: " << e1.getName() << endl;
	output << "Age : " << e1.getAge() << endl;
	output << "Ability : " << e1.getAbility() << endl;
	return output;
}

class ElfTeam
{
private:
	char name[30];
	Elf array[50];
	size_t currentMembers;
	void copy(const ElfTeam& other)
	{
		strcpy(this->name, other.name );
		this->currentMembers = other.currentMembers;
		for (size_t i = 0; i < this->currentMembers; i++)
		{
			this->array[i] = other.array[i];
		}
	}
public:
	ElfTeam()
	{
		//strcpy(this->name, "");
		//this->currentMembers = 0;

	}
	ElfTeam(const char* _name, size_t _currentMembers)
	{
		strcpy(this->name, _name);
		this->currentMembers = _currentMembers;
	}
	/*ElfTeam(const ElfTeam& other)
	{
		copy(other);
	}
	ElfTeam& operator = (const ElfTeam& other)
	{
		if(this != &other)
		copy(other);
		return *this;
	}*/
	void addMember(const Elf _member)
	{
		this->array[++this->currentMembers] = _member; //nope, nope , nope
	}
	Elf operator [] (const size_t index)
	{
		return this->array[index];
	}
	size_t getCurrentSize()const
	{
		return this->currentMembers;
	}
	size_t getStrenght()const
	{
		size_t max = this->array[0].getAbility();
		for (size_t i = 1; i < this->currentMembers; i++)
		{
			if (max < this->array[i].getAbility())
				max = this->array[i].getAbility();
		}
		return max;
	}
	bool containsEqual(const Elf& e1)
	{
		/*for (size_t index = 0; index < this->currentMembers; index++)
		{
			if (this->array[index].getName() == e1.getName() && this->array[index].getAge() == e1.getAge()
				&& this->array[index].getAbility() = e1.getAbility())
				return true;
		}
		*/
		return false;
	}
	ElfTeam operator * (const ElfTeam& other)
	{
		//������ ���� ��� ���� ����� ����� �������� ������ , ���� ���� ������ , � ������� �����
	}
};
ElfTeam analyse(const ElfTeam* arrayTeam,const size_t size)
{
	ElfTeam max;
	/*max.getStrenght() = arrayTeam[0].getStrenght();
	for (size_t i = 1; i < size; i++)
	{
		if (max.getStrenght() < arrayTeam[i].getStrenght())
			max.getStrenght() = arrayTeam[i].getStrenght();
	}
	*/
	return max;
}
std::ostream &operator << (std::ostream &output, ElfTeam t1)
{
	for (size_t i = 0; i < t1.getCurrentSize(); i++)
		output << t1[i] << endl;
	return output;
}

int main()
{
	Elf e1("Elf", 10, 4);

	Elf e3("Elf2", 255, 3);

	ElfTeam t1("bla",1);
	//t1.addMember(e1);
	//t1.addMember(e3);
	//cout << t1;

    return 0;
}

