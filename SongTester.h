/*
 * SongTester.h declares a test-class for class Song.
 * Lorrayya Williams
 *  *
 *  Created on: Sep 15, 2018
 *      Author: llw5
 *	Begun by: Joel Adamas, for CS 112 at Calvin College.
 */

#ifndef SONGTESTER_H_
#define SONGTESTER_H_
#include <fstream>

class SongTester {
public:
	SongTester();
	void runTests();
	void testConstructors();
	void testReadFrom();
	void testWriteTo();
	void testoperator();
};

#endif /* SONGTESTER_H_ */
