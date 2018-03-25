
#include "User.h"

User::User()
{
	this->id = 0;
	this->username = nullptr;
	this->password = nullptr;
	strcpy(this->email, "default@default.com");
	Picture picy;
	this->pic = picy;
}
User::User(long id, char* username, char* password, char* email, Picture pic)
{
	this->load(id,username,password,email,pic);
}

void User::load(long id, char* username, char* password, char* email, Picture pic)
{
	this->id = id;
	this->pic = pic;
	int length = strlen(email) + 1;
	strcpy(this->email, email);

	length = strlen(username) + 1;
	this->username = new char[length];
	strcpy(this->username, username);

	length = strlen(password) + 1;
	this->password = new char[length];
	strcpy(this->password, password);
}

User::User(const User& user)
{
	this->copy(user);
}

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		this->erase();
		this->copy(user);
	}
	return *this;
}

//Private methods
void User::copy(const User& user)
{
	this->id = user.id;
	int length = strlen(user.email) + 1;
	strcpy(this->email, user.email);
	this->pic = user.pic;

	if (user.username == nullptr)
	{
		this->username = nullptr;
	}
	else
	{
		length = strlen(user.username) + 1;
		this->username = new char[length];
		strcpy(this->username, user.username);

	}

	if (user.password == nullptr)
	{
		this->password = nullptr;
	}
	else
	{
		length = strlen(user.password) + 1;
		this->password = new char[length];
		strcpy(this->password, user.password);

	}

}
void User::write()
{
	std::string name;
	name = std::to_string(this->id) + ".txt";
	std::ofstream stream(name);
	if (!stream)
	{
		std::cout << "file : " << name << "can't open" << std::endl;
		return;
	}
	stream << id;
	stream << " ";
	int length = strlen(this->username);
	stream.write(this->username, length);
	stream << " ";
	length = strlen(this->password);
	stream.write(this->password, length);
	stream << " ";
	length = strlen(this->email);
	stream << " ";
	stream.write(this->email, length);
	length = strlen(this->pic.getLink());
	stream << " ";
	stream.write(this->pic.getLink(), length);

}
void User::read() //fix
{
	if (this->username != nullptr)
	{
		delete[] this->username;
	}
	if (this->password != nullptr)
	{
		delete[] this->password;
	}
	std::string name;
	name = std::to_string(this->id) + ".txt";
	std::ifstream stream(name, std::ios::in);
	if (!stream)
	{
		std::cout << "file : " << name << "can't open" << name << std::endl;
		return;
	}
	stream >> this->id;
	char c;
	int length = 0;
	while (length++ && stream.get(c) && (c != ' ' && c != '\n'));
	stream.seekg(-length + 1, std::ios::cur);
	this->username = new char[length];
	stream >> this->username;



	c = '\0';
	length = 0;
	while (length++ && stream.get(c) && (c != ' ' && c != '\n'));
	stream.seekg(-length, std::ios::cur);
	this->password = new char[length + 1];
	stream >> this->password;
	//this->password[length] = '\0';

	c = '\0';
	length = 0;
	while (length++ && stream.get(c) && (c != ' ' && c != '\n'));
	stream.seekg(-length, std::ios::cur);
	stream >> this->email;
	this->email[length] = '\0';


	c = '\0';
	length = 0;
	while (length++ && stream.get(c) && (c != ' ' && c != '\n'));
	stream.seekg(-length, std::ios::cur);
	char* temp = new char[length + 1];
	stream >> temp;
	temp[length] = '\0';
	this->pic = Picture(temp);
	delete[] temp;

}
long User::getID() const
{
	return this->id;
}
void User::read(long id)
{
	if (this->username != nullptr)
	{
		delete[] this->username;
	}
	if (this->password != nullptr)
	{
		delete[] this->password;
	}
	std::string name;

	name = std::to_string(id) + ".txt";
	std::ifstream stream(name, std::ios::in);
	if (!stream)
	{
		std::cout << "file : " << name << "can't open" << name << std::endl;
		return;
	}
	stream >> this->id;

	std::cout << this->id << std::endl;

	char c;
	int length = 0;
	stream.get(c);
	while (++length && stream.get(c) && c != ' ' && c != '\n');
	stream.seekg(-length, std::ios::cur);
	this->username = new char[length];
	stream >> this->username;



	c = '\0';
	length = 0;
	//stream.get(c);
	while (++length && stream.get(c) && c != ' ' && c != '\n');
	stream.seekg(-length , std::ios::cur);
	this->password = new char[length];
	stream >> this->password;

	c = '\0';
	length = 0;
	stream.get(c);
	stream.get(c);
	stream.get(c);
	while (++length && stream.get(c) && c != ' ' && c != '\n');
	stream.seekg(-length, std::ios::cur);
	stream.read(this->email, length);


	c = '\0';
	length = 0;
	stream.get(c);
	while (++length && stream.get(c) && c != ' ' && c != '\n');
	stream.seekg(-length + 1, std::ios::cur);
	char* temp = new char[length + 1];

	stream >> temp;
	temp[length] = '\0';
	Picture pici(temp);
	this->pic = pici;
	delete[] temp;

}

void User::erase()
{
	delete[] this->password;
	delete[] this->username;
}
//Destructor
User::~User()
{
	this->erase();
}
