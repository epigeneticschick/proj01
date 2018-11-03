/*
 * PlaylistTester.h tests the Playlist Class
 *Lorrayya Williams
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 *  Sep 15, 2018
 * Author: llw5
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

class PlaylistTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testsearchbyYear();
	void testsearchbyTitlePhrase();
	void testaddSong();
	void testremovesong();
	void testsave();

};

#endif /* PLAYLISTTESTER_H_ */
