// header file for movies child class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media
{
	public:
		Movie(char *newTitle, int newYear, int newType, float newRating, float newDuration);
		virtual float getRating();
		virtual float getDuration();
		~Movie();
	protected:
		float rating;
		float duration;
};
