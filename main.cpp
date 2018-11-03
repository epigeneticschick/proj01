/*
 * main.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: llw5
 */
   /* main.cpp tests the classes in our project.
    * Student Name: Lorrayya Williams
    * Date: September 11, 2018
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */
#include "SongTester.h"
#include "PlaylistTester.h"
#include "Application.h"

int main() {
	SongTester sTester;
    sTester.runTests();
    PlaylistTester plTester;
    plTester.runTests();
    Application app;
    app.interface();
}
