//cpp file to go with video game header

#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

//game constructor
Game::Game(char *newTitle, int newYear, float newRating, char *newPublisher)
{
	title = newTitle;
	year = newYear;
	rating = newRating;
	publisher = newPublisher;
	type = 0;
}

//return rating
float Game::getRating()
{
	return rating;
}

//return publisher
char* Game::getPublisher()
{
	return publisher;
}

//deconstructor
Game::~Game()
{
	delete &title;
	delete &year;
	delete &type;
	delete &rating;
	delete &publisher;
}
