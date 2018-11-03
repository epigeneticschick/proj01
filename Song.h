/*
 * Song.h
 *
 *  Created on: Sep 15, 2018
 *      Author: llw5
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	bool operator==(const Song& song2);
	bool operator!=(const Song& song2);


private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
