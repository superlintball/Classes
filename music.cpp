//cpp file to go with music header

#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//music constructor
Music::Music(char *newTitle, int newYear, float newDuration, char *newPublisher)
{
	title = newTitle;
	year = newYear;
	duration = newDuration;
	publisher = newPublisher;
	type = 1;
}

//return music's length
float Music::getDuration()
{
	return duration;
}

//return music's publisher
char* Music::getPublisher()
{
	return publisher;
}

//deconstructor
Music::~Music()
{
	delete &title;
	delete &year;
	delete &type;
	delete &duration;
	delete &publisher;
}
