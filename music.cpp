// cpp file to go with music header

#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(char *newTitle, int newYear, int newType, float newDuration, char *newPublisher)
{
	title = newTitle;
	year = newYear;
	type = newType;
	duration = newDuration;
	publisher = newPublisher;
}

float Music::getDuration()
{
	return duration;
}

char* Music::getPublisher()
{
	return publisher;
}

Music::~Music()
{
	delete &title;
	delete &year;
	delete &type;
	delete &duration;
	delete &publisher;
}
