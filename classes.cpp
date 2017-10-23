/* Author: Raveen Karnik
 * Date: 10-13-17
 * This is the main class for a database which contains different kinds of media that the user can access
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "media.h"
#include "game.h"
#include <vector>

using namespace std;

// define database as a global variable to make it directly accessible to all functions
vector<Media*> database;

//define global constants for each media type
const int GAME = 0;
const int MUSIC = 1;
const int MOVIE = 2;

//function to add media
bool addMedia()
{
	//ask the user for title and year, as those are universal
	cout << "Before I ask you for the type of media, what's the title?" << endl;
	char *title;
	title = new char[100];
	cin.get(title, 100);
	cin.get();

	cout << "And the year?" << endl;
	int year;
	cin >> year;
	cin.get();

	//ask the user what kind of media they want to add
	cout << "Thanks. Now, is this a \"game\", \"music\", or \"movie\"?" << endl;
	char input[20];
	cin.get(input, 20);
	cin.get();
	
	if(strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0)
	{
		//ask the user for the game's rating
		cout << "What is this game's rating?" << endl;
		float rating;
		cin >> rating;
		cin.get();

		//ask the user for the game's publisher
		cout << "Who's the publisher?" << endl;
		char *publisher;
		publisher = new char[100];
		cin.get(publisher, 100);
		cin.get();

		database.push_back(new Game(title, year, rating, publisher));

		return true;
	}
	else if(strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0)
	{
		return true;
	}
	else if(strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0)
	{
		return true;
	}

	delete title;
	return false;
}

// main function for program
int main()
{
	// boolean to stay true until the user signals to quit
	bool keepGoing = true;
	while(keepGoing)
	{
		// prompt user to add, search, or delete media
		cout << "Do you want to \"ADD\", \"SEARCH\", or \"DELETE\" media?" << endl;
		cout << "Type \"QUIT\" to exit." << endl;
		char input[20];
		cin.get(input, 20);
		cin.get();

		// if the user wants to add media, add it and notify when done
		if(strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0)
		{
			if(addMedia())
			{
				cout << "Media has been added" << endl << endl;

				cout << database[0]->getTitle() << endl;
				cout << database[0]->getYear() << endl;
				cout << database[0]->getPublisher() << endl;
				cout << setprecision(2) << fixed << database[0]->getRating() << endl;
			} else
			{
				cout << "There was an error in adding your media" << endl << endl;
			}
		}
		
		//if the user wants to quit, set keepGoing to false
		else if(strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0)
		{
			keepGoing = false;
		}
	}
	return 0;
}
