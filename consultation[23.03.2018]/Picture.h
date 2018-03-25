#pragma once
#include <cstring>

class Picture
{
public:
	Picture();
	Picture(char* link);
	Picture(const Picture& picture);
	char* getLink() const;
	Picture& operator=(const Picture& picture);
	~Picture();
	void load(char* link);
private:

	
	void copy(const Picture& picture);
	void erase();

	char* link;

};
