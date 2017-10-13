// header file to build basic media

#include <iostream>
#include <cstring>

using namespace std;

class Media
{
	public:
		Media(char *newTitle, int newYear, int newType);
		char* getTitle();
		int getYear();
		int getType();
	protected:
		char *title;
		int year;
		int type;
};
