// cpp file to go with video game header

#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

Game::Game(char *newTitle, int newYear, int newType, float newRating, char *newPublisher)
{
	title = newTitle;
	year = newYear;
	type = newType;
	rating = newRating;
	publisher = newPublisher;
}

float Game::getRating()
{
	return rating;
}

char* Game::getPublisher()
{
	return publisher;
}
