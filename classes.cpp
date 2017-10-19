/* Author: Raveen Karnik
 * Date: 10-13-17
 * This is the main class for a database which contains different kinds of media that the user can access
 */

#include <iostream>
#include <cstring>
#include "media.h"
#include "game.h"
#include <vector>

using namespace std;

// define database as a global variable to make it directly accessible to all functions
vector<Media*> database;

//function to add media
void addMedia()
{
	
}

// main function for program
int main()
{
	// boolean to stay true until the user signals to quit
	bool keepGoing = true;
	while(keepGoing)
	{
		// prompt user to add, search, or delete media
		cout << "Do you wnat to \"ADD\", \"SEARCH\", or \"DELETE\" media?" << endl;
		cout << "Type \"QUIT\" to exit." << endl;
		cin.get();
		char input[20];
		cin.get(input, 20);
		cin.get();

		// if the user wants to add media, add it and notify when done
		if(strcmp(input, "ADD") || strcmp(input, "add"))
		{
			addMedia();
			cout << "Media has been added" << endl << endl;
		}
		
		//if the user wants to quit, set keepGoing to false
		else if(strcmp(input, "QUIT") || strcmp(input, "quit"))
		{
			keepGoing = false;
		}
	}
	return 0;
}
