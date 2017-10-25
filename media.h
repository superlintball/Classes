//header file to build basic media

//header guard to make sure media is not defined multiple times
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

//media constructor
class Media
{
	public: //all possible publicly available functions/variables
		char* getTitle();
		int getYear();
		int getType();
		virtual float getRating();
		virtual char *getDuration();
		virtual char *getPublisher();
	protected: //actual data-storing variables
		char *title;
		int year;
		int type;
};

#endif
