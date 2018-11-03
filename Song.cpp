/*
 * Song.cpp defines the methods for class Song (see Song.h).
 *
    * Student Name: Lorrayya Williams
    * Date: September 15, 2018
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

#include "Song.h"
#include <fstream>

 /* Song default constructor
    * Postcondition: myTitle and myArtist are empty strings
    *            && myYear == 0.
    */
Song::Song() {
	myTitle = "";
	myArtist = "";
	myYear = 0;
}
Song::Song(const string& title, const string& artist, unsigned year) {
	myTitle = title;
	myArtist = artist;
	myYear = year;
}
/* getter method for myTitle
* Return: myTitle
*/
string Song::getTitle() const {
  return myTitle;
}

/* getter method for myArtist
* Return: myArtist
*/
string Song::getArtist() const {
  return myArtist;
}

/* getter method for myYear
* Return: myYear
*/
unsigned Song::getYear() const {
  return myYear;
}

void Song::readFrom(istream& in) {
	getline(in, myTitle);
	getline(in, myArtist);
	string yearString;
	getline(in, yearString);
	myYear = atoi( yearString.c_str() );
}

void Song::writeTo(ostream& out) const {
		out << myTitle << '\n'
				<< myArtist << '\n'
				<< myYear  << '\n';
}

/*Intializes == operator
@param: song2
Return: True or False based on conditions.*/

bool Song::operator==(const Song& song2){
	if (getTitle() == song2.getTitle() && getArtist() == song2.getArtist() && getYear() == song2.getYear()){
		return true;
	}
	return false;
}

/*
Intializes != operator
@param: song2
Return: True or False based on conditions.
*/

bool Song::operator!=(const Song& song2){
	if (getTitle() != song2.getTitle() || getArtist() != song2.getArtist() || getYear() != song2.getYear()){
		return true;
	}
	return false;
}
