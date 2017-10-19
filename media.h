// header file to build basic media
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media
{
	public:
		char* getTitle();
		int getYear();
		int getType();
		virtual float getRating();
		virtual float getDuration();
		virtual char *getPublisher();
	protected:
		char *title;
		int year;
		int type;
};

#endif
