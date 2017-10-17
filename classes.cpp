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

vector<Media*> database;

// main function for program
int main()
{
	char *title = "media one";
	char *publisher = "Raveen Karnik";
	database.push_back(new Game(title, 1956, 2, 4.3, publisher));
	cout << database[0]->getTitle() << endl;
	cout << database[0]->getYear() << endl;
	cout << database[0]->getType() << endl;
	cout << static_cast<Game*>(database[0])->getRating() << endl;
	cout << static_cast<Game*>(database[0])->getPublisher() << endl;
	return 0;
}
