/*
 * Lorrayya Williams
 * For CS 112 Project 1
 *  Created on: Sep 15, 2018
 *
 */

#include "Application.h"
#include "PlayList.h"
#include <vector>
#include <string>
#include "Song.h"
#include <fstream>
#include <iostream>
Application::Application() {


}


void Application::interface() {

	// intializes the variables.
	unsigned option = 0;
	string artist = "";
	unsigned year = 0;
	string title = "";

	PlayList pList("testSongs.txt");
	while (true) {
		cout << "Welcome to the Playlist Manager! \n"  << flush;
		cout << "Please enter: \n" << flush;
		cout << " 1 - to search the playlist for songs by a given artist \n" << flush;
		cout << " 2 - to search the playlist for songs from a given year \n" << flush;
		cout << " 3 - to search the playlist for songs with a given phrase in their title \n" << flush;
		cout << " 4 - to add a new song to the playlist \n" << flush;
		cout << " 5 - to remove a song from the playlist \n" << flush;
		cout << " 6 - to save the playlist \n" << flush;
		cout << " 0 - to exit program \n" << flush;
		cin >> option;
		cin.ignore();
		if (option == 0 ){
			//quits function
			break;
		}
		if(option == 1) {
			// Begins search by artist function
			cout << "Enter Artist: " << flush;
			getline(cin, artist);
			vector<Song> searchResult = pList.searchByArtist(artist);
			if (searchResult.size() == 0) {
				cout << "There are no songs by that artist.\n" << flush;
			}
			else {
			//returns the song
				for ( unsigned i = 0; i< searchResult.size(); ++i){
					cout << searchResult[i].getArtist() << endl;
					cout << searchResult[i].getTitle() << endl;
					cout << searchResult[i].getYear() << endl;
				}
			}

		}
		if(option == 2) {
			//Begins Search for song in a particular year
			cout << "Enter Year: " << flush;
			cin >> year;
			cin.ignore();
			vector<Song> searchResult = pList.searchByYear(year);
			if (searchResult.size() == 0) {
				cout << "There was no song from that year found in the playlist. \n" << flush;
			}
			//returns the song
			for (unsigned i = 0; i < searchResult.size(); ++i){
				cout << searchResult[i].getArtist() << endl;
				cout << searchResult[i].getTitle() << endl;
				cout << searchResult[i].getYear() << endl;
			}

		}
		if(option == 3){
			//Initiates the search for song by title function
			cout << "Enter Title: " << endl;
			getline(cin, title);
			vector<Song> searchResult = pList.searchByTitlePhrase(title);
			if (searchResult.size() == 0) {
				cout << "There are no songs by that artist.\n" << flush;
			}
			else {
				//returns the song
				for ( unsigned i = 0; i< searchResult.size(); ++i){
					cout << searchResult[i].getArtist() << endl;
					cout << searchResult[i].getTitle() << endl;
					cout << searchResult[i].getYear() << endl;
				}
			}

		}
		if (option == 4) {
		//Initiates Add New Song
			cout << "Enter Aritst: " << flush;
			getline(cin, artist);
			cout << "Enter Title: ";
			getline(cin, title);
			cout << "Enter Year: ";
			cin >> year;
			cin.ignore();
			Song s(title, artist, year);
			pList.addSong(s);

		}
		if (option ==5) {
			// Initiates the Remove Song Method
			cout << "Enter A song to Remove \n" << flush;
			cout << "Enter Aritst: " << flush;
			getline(cin, artist);
			cout << "Enter Title: ";
			getline(cin, title);
			cout << "Enter Year: ";
			cin >> year;
			cin.ignore();
			Song s(title, artist, year);
			pList.removeSong(s);
		}
		if (option == 6) {
			// Initiates the Save Method
			pList.save();
		}
	}
}

