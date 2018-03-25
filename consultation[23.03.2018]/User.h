#pragma once
#include "Picture.h"
#include <fstream>
#include <string>
#include <iostream>


class User
{
public:
	User();
	User(long id, char* username, char* password, char* email, Picture pic);
	User(const User& user);
	User& operator=(const User& user);
	~User();
	long getID() const;
	void load(long id, char* username, char* password, char* email, Picture pic);
	void write();
	void read();
	void read(long id);

private:


	void erase();
	void copy(const User& user);


	long id; 
	char* username;
	char* password;
	char email[256];
	Picture pic;
};
