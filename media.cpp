//cpp file to go with basic media file

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

//return title
char* Media::getTitle()
{
	return title;
}

//return year
int Media::getYear()
{
	return year;
}

//return type of media
int Media::getType()
{
	return type;
}

//automatically return null if the user asks for a variable which that specific child doesn't possess
char *Media::getDuration() {return NULL;}
float Media::getRating() {return NULL;}
char *Media::getPublisher() {return NULL;}
