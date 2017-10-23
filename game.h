//header file for video games child class

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

//game is a child of media
class Game : public Media
{
	public: //publicly available variables/functions
		Game(char *newTitle, int newYear, float newRating, char *newPublisher);
		virtual float getRating();
		virtual char *getPublisher();
		~Game();
	protected: //actual variables unique to game
		float rating;
		char *publisher;
};
