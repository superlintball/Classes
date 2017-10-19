// header file for music child class

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class Music : public Media
{
	public:
		Music(char *newTitle, int newYear, int newType, float newDuration, char *newPublisher);
		virtual float getDuration();
		virtual char *getPublisher();
		~Music();
	protected:
		float duration;
		char *publisher;
};
