/*
 * PlayList.cpp
 *Lorrayya Williams
 *  Created on: Sep 11, 2018
 *  Begun by: Joel Adams, for CS 112 at Calvin College
 *      Author: llw5
 */

#include "PlayList.h"	// Playlist Class
#include "Song.h"		// Song Class
#include <fstream>      // ifstream
#include <cassert>      // assert()
#include <iostream>
#include <list>
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}

/*Search by Year
@param: year
Return: a vector containing all the SOngs in mySongs by year.*/

vector<Song> PlayList::searchByYear(unsigned year) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i].getYear() == year ) {
			v.push_back( mySongs[i] );
		}
	}
	return v;

}

/*Search by Title Phrase
@param: phrase
Return: a vector containing all the Songs in mySongs by phrase*/

vector<Song> PlayList::searchByTitlePhrase(const string& phrase) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
			if (mySongs[i].getTitle() == phrase) {
				v.push_back( mySongs[i] );
			}
		}
		return v;

}

/*
Add Songs to mySongs
@param: song
Return: Nothing
*/

void  PlayList::addSong(const Song& newSong){
	mySongs.push_back(newSong);

}

/*
Remove Songs from mySongs
@param: Song
Return:N/a
*/

void PlayList::removeSong(const Song& aSong) {
	for (unsigned i = 0; i < mySongs.size(); i++){
		if(mySongs[i] == aSong){
			mySongs.erase(mySongs.begin() +i);
		}
	}
}


/*Saves playlist to file.
@param: N/a
Return: N/a*/

void PlayList::save() const {
	//use a loop that uses the write to function
	ofstream fout("testSong.txt");
	for (unsigned i = 0; i< mySongs.size(); i++){
		mySongs[i].writeTo(fout);
	}
	fout.close();
	//save title of text file in constructor so that the same file can be used.

}
