//header file for music child class

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

//music is a child of media
class Music : public Media
{
	public: //publicly available functions/variables
		Music(char *newTitle, int newYear, char *newDuration, char *newPublisher);
		virtual char *getDuration();
		virtual char *getPublisher();
		~Music();
	protected: //data-storing variables
		char *duration;
		char *publisher;
};
