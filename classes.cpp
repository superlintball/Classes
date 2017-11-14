/* Author: Raveen Karnik
 * Date: 10-13-17
 * This is the main class for a database which contains different kinds of media that the user can access
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"
#include <vector>

using namespace std;

// define database as a global variable to make it directly accessible to all functions
vector<Media*> database;

//define global constants for each media type
const int GAME = 0;
const int MUSIC = 1;
const int MOVIE = 2;

bool addMedia();
bool searchMedia();
bool deleteMedia();

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

		// if the user wants to add media, run the add function
		if(strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0)
		{
			if(addMedia())
			{
				cout << "Media has been added";
			} else
			{
				cout << "There was an error in adding your media";
			}
		}

		//if the user wants to search media, run the search function
		else if(strcmp(input, "SEARCH") == 0 || strcmp(input, "search") == 0)
		{
			if(searchMedia())
			{
				cout << "Search completed";
			}
			else
			{
				cout << "There was an error running the search.";
			}
		}

		//if the user wants to delete media, run the delete function
		else if(strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0)
		{
			if(deleteMedia())
			{
				cout << "Media deleted";
			}
			else
			{
				cout << "There was an error deleting the media.";
			}
		}

		//if the user wants to quit, set keepGoing to false
		else if(strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0)
		{
			keepGoing = false;
		}

		//anything else, print an error
		else
		{
			cout << "Sorry I couldn't understand that.";
		}
		cout << endl << endl;
	}
	return 0;
}

//function to add media
bool addMedia()
{
	//ask the user for title and year, as those are universal
	cout << "Before I ask you for the type of media, what's the title?" << endl;
	char *title;
	title = new char[100];
	cin.get(title, 100);
	cin.get();

	cout << "And the year it was published?" << endl;
	int year;
	cin >> year;
	cin.get();

	//ask the user what kind of media they want to add
	cout << "Thanks. Now, is this a \"game\", \"music\", or \"movie\"?" << endl;
	char input[20];
	cin.get(input, 20);
	cin.get();

	//if they choose game
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
	} //if they choose music
	else if(strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0)
	{
		//ask the user for the music's duration
		cout << "What is this music's duration?" << endl;
		char *duration;
		duration = new char[20];
		cin.get(duration, 20);
		cin.get();

		//ask the user for the game's publisher
		cout << "Who's the publisher?" << endl;
		char *publisher;
		publisher = new char[100];
		cin.get(publisher, 100);
		cin.get();

		database.push_back(new Music(title, year, duration, publisher));
		return true;
	} //if they choose movie
	else if(strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0)
	{
		//ask the user for the movie's rating
		cout << "What is this movie's rating?" << endl;
		float rating;
		cin >> rating;
		cin.get();

		//ask the user for the movie's duration
		cout << "What is its duration?" << endl;
		char *duration;
		duration = new char[20];
		cin.get(duration, 20);
		cin.get();

		database.push_back(new Movie(title, year, rating, duration));
		return true;
	}

	//if the program has not returned yet, assume it couldn't understand the input
	delete title;
	return false;
}

//function to search media
bool searchMedia()
{
	//ask the user how they want to search
	cout << "Would you like to search by \"title\" or \"year\"?" << endl;
	char input[20];
	cin.get(input, 20);
	cin.get();

	bool matchFound = false;

	//if the user wants to search by title
	if(strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0)
	{
		//ask for the specific title
		cout << "What is the title of the media?" << endl;
		char *title;
		title = new char[100];
		cin.get(title, 100);
		cin.get();
		cout << endl;

		vector<Media*>::iterator it;
		for(it = database.begin(); it != database.end(); it++)
		{
			//check each media item for a matching title, and print if found
			int position = it - database.begin();
			if(strcmp(database[position]->getTitle(), title) == 0)
			{
				//record the fact that a match was a found
				matchFound = true;

				//print based on type of media
				if(database[position]->getType() == GAME)
				{
					cout << "Found a Game" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
					cout << "Publisher: " << database[position]->getPublisher() << endl;
					cout << endl;
				}
				else if(database[position]->getType() == MUSIC)
				{
					cout << "Found a Music" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Duration: " << database[position]->getDuration() << endl;
					cout << "Publisher: " << database[position]->getPublisher() << endl;
					cout << endl;
				}
				else if(database[position]->getType() == MOVIE)
				{
					cout << "Found a Movie" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
					cout << "Duration: " << database[position]->getDuration() << endl;
					cout << endl;
				}

			}
		}
	} //if the user wants to search by year
	else if(strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0)
	{
		//ask for the specific year
		cout << "What is the year the media was published?" << endl;
		int year;
		cin >> year;
		cin.get();
		cout << endl;

		vector<Media*>::iterator it;
		for(it = database.begin(); it != database.end(); it++)
		{
			//check each media item for a matching title, and print if found
			int position = it - database.begin();
			if(database[position]->getYear() == year)
			{
				//record the fact that a match was a found
				matchFound = true;

				//print based on type of media
				if(database[position]->getType() == GAME)
				{
					cout << "Found a Game" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
					cout << "Publisher: " << database[position]->getPublisher() << endl;
					cout << endl;
				}
				else if(database[position]->getType() == MUSIC)
				{
					cout << "Found a Music" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Duration: " << database[position]->getDuration() << endl;
					cout << "Publisher: " << database[position]->getPublisher() << endl;
					cout << endl;
				}
				else if(database[position]->getType() == MOVIE)
				{
					cout << "Found a Movie" << endl;
					cout << "Title: " << database[position]->getTitle() << endl;
					cout << "Year: " << database[position]->getYear() << endl;
					cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
					cout << "Duration: " << database[position]->getDuration() << endl;
					cout << endl;
				}

			}
		}
	} //if the user entered something else
	else
	{
		cout << "Sorry I couldn't understand that." << endl;
		return false;
	}
	if(matchFound)
	{
		return true;
	}
	else
	{
		cout << "No matching media was found." << endl;
		return true;
	}
}

bool deleteMedia()
{
	//ask the user how they want to delete
	cout << "Would you like to delete by \"title\" or \"year\"?" << endl;
	char input[20];
	cin.get(input, 20);
	cin.get();

	bool matchFound = false;

	//if the user wants to delete by title
	if(strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0)
	{
		//ask for the specific title
		cout << "What is the title of the media?" << endl;
		char *title;
		title = new char[100];
		cin.get(title, 100);
		cin.get();
		cout << endl;

		bool done = false;
		int deleted = 0;
		while(!done)
		{
			int found = 0;
			vector<Media*>::iterator it;
			for(it = database.begin(); it != database.end(); it++)
			{
				if(found >= deleted)
				{
					//check each media item for a matching title, and print if found
					int position = it - database.begin();
					if(strcmp(database[position]->getTitle(), title) == 0)
					{
						//record the fact that a match was a found
						matchFound = true;

						//print based on type of media
						int type = database[position]->getType();
						if(type == GAME)
						{
							cout << "Found a Game" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
							cout << "Publisher: " << database[position]->getPublisher() << endl;
							cout << endl;
						}
						else if(type == MUSIC)
						{
							cout << "Found a Music" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Duration: " << database[position]->getDuration() << endl;
							cout << "Publisher: " << database[position]->getPublisher() << endl;
							cout << endl;
						}
						else if(type == MOVIE)
						{
							cout << "Found a Movie" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
							cout << "Duration: " << database[position]->getDuration() << endl;
							cout << endl;
						}

						//ask the user if they want to delete it
						cout << "Delete this object?" << endl;
						char yesNo[10];
						cin.get(yesNo, 10);
						cin.get();
						cout << endl;
						if(strcmp(yesNo, "yes") == 0 || strcmp(yesNo, "YES") == 0 || strcmp(yesNo, "y") == 0 || strcmp(yesNo, "Y") == 0)
						{
							deleted = found;
							delete database[position];
							database.erase(database.begin()+position);
							break;
						}
					}
				}
				found++;
				if(it == database.end()-1)
				{
					done = true;
				}
			}
		}
	} //if the user wants to search by year
	else if(strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0)
	{
		//ask for the specific year
		cout << "What is the year the media was published?" << endl;
		int year;
		cin >> year;
		cin.get();
		cout << endl;

		bool done = false;
		int deleted = 0;
		while (!done)
		{
			int found = 0;
			vector<Media*>::iterator it;
			for(it = database.begin(); it != database.end(); it++)
			{
				if(found >= deleted)
				{
					//check each media item for a matching title, and print if found
					int position = it - database.begin();
					if(database[position]->getYear() == year)
					{
						//record the fact that a match was a found
						matchFound = true;

						//print based on type of media
						int type = database[position]->getType();
						if(type == GAME)
						{
							cout << "Found a Game" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
							cout << "Publisher: " << database[position]->getPublisher() << endl;
							cout << endl;
						}
						else if(type == MUSIC)
						{
							cout << "Found a Music" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Duration: " << database[position]->getDuration() << endl;
							cout << "Publisher: " << database[position]->getPublisher() << endl;
							cout << endl;
						}
						else if(type == MOVIE)
						{
							cout << "Found a Movie" << endl;
							cout << "Title: " << database[position]->getTitle() << endl;
							cout << "Year: " << database[position]->getYear() << endl;
							cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
							cout << "Duration: " << database[position]->getDuration() << endl;
							cout << endl;
						}

						//ask the user if they want to delete it
						cout << "Delete this object?" << endl;
						char yesNo[10];
						cin.get(yesNo, 10);
						cin.get();
						cout << endl;
						if(strcmp(yesNo, "yes") == 0 || strcmp(yesNo, "YES") == 0 || strcmp(yesNo, "y") == 0 || strcmp(yesNo, "Y") == 0)
						{
							deleted = found;
							delete database[position];
							database.erase(database.begin()+position);
							break;
						}
					}
				}
				found++;
				if(it == database.end()-1)
				{
					done=true;
				}
			}
		}
	} //if the user entered something else
	else
	{
		cout << "Sorry I couldn't understand that." << endl;
		return false;
	}
	if(matchFound)
	{
		return true;
	}
	else
	{
		cout << "No matching media was found." << endl;
		return true;
	}

	return false;
}
