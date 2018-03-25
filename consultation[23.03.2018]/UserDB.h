#pragma once
#include "User.h"

class UserDB
{
public:
	UserDB();
	UserDB(const UserDB& userDB);
	void add(User user);
	UserDB& operator=(const UserDB& userDB);
	~UserDB();
	void read();
	void write();

private:

	void erase();
	void copy(const UserDB& userDB);
	void resize();

	User* container;
	size_t size;
	size_t capacity;


};
