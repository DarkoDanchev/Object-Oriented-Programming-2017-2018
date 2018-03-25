// ConsoleApplication18.cpp : Defines the entry point for the console application.
//


#include "UserDB.h"

/*
    Just some lame testing.
*/

int main()
{
	UserDB DB;
	Picture pic("link");
	User u(1,"username7","password7","email7",pic);
	User u2(8, "username2", "password2", "email2", pic);
	User u3(17, "username3", "password3", "email3", pic);
	User u4(42, "username4", "password4", "email4", pic);
	User u5(9, "username5", "password5", "email5", pic);
	User u6(23712, "username6", "password6", "email6", pic);

	u.write();
	u2.read(1);

	std::cout<<u2.getID();
	DB.add(u);
	DB.add(u2);
	DB.add(u3);
	DB.add(u4);
	DB.add(u5);
	DB.add(u6);
	DB.write();
	DB.read();
	DB.add(u);
	DB.write();


    return 0;
}

