/* Author: Raveen Karnik
 * Date: 10-13-17
 * This is the main class for a database which contains different kinds of media that the user can access
 */

#include <iostream>
#include <cstring>
#include "Media.h"
#include <vector>

using namespace std;

vector<Media*> database;

// main function for program
int main()
{
	char *title = "media one";
	database.push_back(new Media(title, 1956, 2));
	cout << database[0]->getTitle() << endl;
	cout << database[0]->getYear() << endl;
	cout << database[0]->getType() << endl;
	return 0;
}
