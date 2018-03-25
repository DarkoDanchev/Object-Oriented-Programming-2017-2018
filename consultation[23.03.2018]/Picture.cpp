
#include "Picture.h"


//Constructors
Picture::Picture()
{
	this->link = nullptr;
	 //this->link = new char[0];
}
Picture::Picture(char* link)
{
    this->link = new char[strlen(link) + 1];
	strcpy(this->link,link);
}
//Copy Constructor
Picture::Picture(const Picture& picture)
{
	this->copy(picture);
}
Picture& Picture::operator=(const Picture& picture)
{
	if (this != &picture)
	{
		this->erase();
		this->copy(picture);
	}
	return *this;
}

//Private methods
void Picture::erase()
{
	delete[] this->link;
}
void Picture::copy(const Picture& picture)
{
	if (picture.link ==nullptr)
	{
		this->link = nullptr;
	}
	else
	{
		int lenght = strlen(picture.link) + 1;
		this->link = new char[lenght];
		strcpy(this->link, picture.link);
	}
}
//getter
char* Picture::getLink() const
{
	return this->link;
}
//Destructor
Picture::~Picture()
{
	this->erase();
}


