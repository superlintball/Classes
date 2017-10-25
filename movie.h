// header file for movies child class

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

//movie is a child of media
class Movie : public Media
{
	public: //publicly available functions/variables
		Movie(char *newTitle, int newYear, float newRating, char *newDuration);
		virtual float getRating();
		virtual char *getDuration();
		~Movie();
	protected: //variables specific to movie
		float rating;
		char *duration;
};
