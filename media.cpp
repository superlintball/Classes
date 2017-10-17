// cpp file to go with basic media file

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

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
