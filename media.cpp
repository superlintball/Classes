// cpp file to go with basic media file

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(char *newTitle, int newYear, int newType)
{
	title = newTitle;
	year = newYear;
	type = newType;
}

char* Media::getTitle()
{
	return title;
}

int Media::getYear()
{
	return year;
}

int Media::getType()
{
	return type;
}
