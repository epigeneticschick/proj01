/*
 * PlaylistTester.cpp
 *Lorrayya Williams
 *September 15, 2018
 *Begun by: Joel Adams, for CS 112 at Calvin College
 *  Created on: Sep 11, 2018
 *      Author: llw5
 */

#include "PlaylistTester.h"
#include "PlayList.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;


void PlaylistTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testsearchbyYear();
	testsearchbyTitlePhrase();
	testaddSong();
	testremovesong();
	testsave();
	cout << "All tests passed!" << endl;
}

void PlaylistTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}

void PlaylistTester::testSearchByArtist() {
	cout << "- searchByArtist()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void PlaylistTester::testsearchbyYear() {
	cout << "- searchByYear()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByYear(3000);
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getYear() == 2012 );
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getYear() == 1967 );
	assert( searchResult[1].getYear() == 1967 );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;

}

void PlaylistTester::testsearchbyTitlePhrase() {
	cout << "- searchByTitlePhrase()... " << flush;
		// load a playlist with test songs
		PlayList pList("testSongs.txt");

		// empty case (0)
		vector<Song> searchResult = pList.searchByTitlePhrase("Hot Mess");
		assert( searchResult.size() == 0 );
		cout << " 0 " << flush;

		// case of 1
		searchResult = pList.searchByTitlePhrase("Call Me Maybe");
		assert( searchResult.size() == 1 );
		assert( searchResult[0].getTitle() == "Call Me Maybe" );
		cout << " 1 " << flush;

		// case of 2
		searchResult = pList.searchByTitlePhrase("Let It Be");
		assert( searchResult.size() == 2 );
		assert( searchResult[0].getTitle() == "Let It Be" );
		assert( searchResult[1].getTitle() == "Let It Be" );
		cout << " 2 " << flush;

		cout << " Passed!" << endl;
}

void PlaylistTester::testaddSong() {
	cout << "-addSong()..." << flush;
	Song s("jhsgha","Rihanna", 1987);
	PlayList pl("testSongs.txt");

	// empty case
	assert(pl.getNumSongs()== 4);
	pl.addSong(s);
	cout << " 0 " << flush;

	// case 1
	assert(pl.getNumSongs() == 5);
	vector<Song>searchresult = pl.searchByTitlePhrase("jhsgha");
	assert(searchresult.size()== 1);
	cout <<  " 1 " << flush;
	cout << " Passed! " << endl;

}

void PlaylistTester::testremovesong() {
	cout << "-removeSong..." << flush;
	PlayList pl("testSongs.txt");
	Song s("jhsgha","Rihanna", 1987);
	pl.removeSong(s);
	assert(pl.getNumSongs()==4);
	cout << " 0 " << flush;
	cout << " Passed! " <<  endl;

}

void PlaylistTester::testsave(){

	//make sure test save function was done correctly.
	cout << " -testsave..." << flush;

	Song s("Disturbia","Rihanna", 1987);
	PlayList pl("testSongs.txt");
	pl.addSong(s);
	pl.save();
	vector<Song> searchResult = pl.searchByTitlePhrase("Disturbia");
	assert( searchResult.size() == 1 );



	cout << " 0 " << flush;
	cout << " Passed! " << endl;


}
