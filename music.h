//header file for music child class

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

//music is a child of media
class Music : public Media
{
	public: //publicly available functions/variables
		Music(char *newTitle, int newYear, float newDuration, char *newPublisher);
		virtual float getDuration();
		virtual char *getPublisher();
		~Music();
	protected: //data-storing variables
		float duration;
		char *publisher;
};
