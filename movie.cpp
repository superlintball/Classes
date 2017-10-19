// cpp file to go with movie header

#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

Movie::Movie(char *newTitle, int newYear, int newType, float newRating, float newDuration)
{
	title = newTitle;
	year = newYear;
	type = newType;
	rating = newRating;
	duration = newDuration;
}

float Movie::getRating()
{
	return rating;
}

float Movie::getDuration()
{
	return duration;
}

Movie::~Movie()
{
	delete &title;
	delete &year;
	delete &type;
	delete &rating;
	delete &duration;
}
