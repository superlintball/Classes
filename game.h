// header file for video games child class

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class Game : public Media
{
	public:
		Game(char *newTitle, int newYear, int newType, float newRating, char *newPublisher);
		virtual float getRating();
		virtual char *getPublisher();
		~Game();
	protected:
		float rating;
		char *publisher;
};
