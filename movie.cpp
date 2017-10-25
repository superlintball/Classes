//cpp file to go with movie header

#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//movie constructor
Movie::Movie(char *newTitle, int newYear, float newRating, char *newDuration)
{
	title = newTitle;
	year = newYear;
	rating = newRating;
	duration = newDuration;
	type = 2;
}

//returns movie's rating
float Movie::getRating()
{
	return rating;
}

//returns movie's length
char *Movie::getDuration()
{
	return duration;
}

//deconstructor
Movie::~Movie()
{
	delete &title;
	delete &year;
	delete &type;
	delete &rating;
	delete &duration;
}
