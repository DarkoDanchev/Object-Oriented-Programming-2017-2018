
#include "UserDB.h"

//Constructors
UserDB::UserDB()
{
	this->size = 0;
	this->capacity = 8;
	this->container = new User[this->capacity];
}
UserDB::UserDB(const UserDB& userDB)
{
	this->copy(userDB);
}
//operators
UserDB& UserDB::operator=(const UserDB& userDB)
{
	if (this != &userDB)
	{
		this->erase();
		this->copy(userDB);
	}
	return *this;
}
//Methods
void UserDB::add(User user)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->container[this->size++] = user;
}
void UserDB::read()
{
	std::ifstream stream("database.txt", std::ios::in);
	if (!stream)
	{
		std::cout << "file can't load : database.txt" << std::endl;
		return;
	}
	while (!stream.eof())
	{
		long id;
		stream >> id;
		if (id != 0)
		{
			User temp;
			temp.read(id);
			this->add(temp);
			std::cout << std::endl;
		}
		std::cout << std::endl;

	}
}


void UserDB::write()
{
	std::ofstream stream("database.txt", std::ios::out);
	if (!stream)
	{
		std::cout << "File can't load : database.txt" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->size; i++)
	{
		this->container[i].write();
	}
	for (size_t i = 0; i < this->size; i++)
	{
		stream << this->container[i].getID();
		stream << " ";
	}

}
//Pricate methods
void UserDB::resize()
{
	this->capacity *= 2;

	User* temp = new User[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->container[i];
	}
	delete[] this->container;
	this->container = temp;

}
void UserDB::copy(const UserDB& userDB)
{
	this->size = userDB.size;
	this->capacity = userDB.capacity;
	this->container = new User[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		this->container[i] = userDB.container[i];
	}
}
void UserDB::erase()
{
	delete[] this->container;
}
//Destructor
UserDB::~UserDB()
{
	this->erase();
}
