/*************************************************************************
 *
 *	Test cases for CS2401 Project 1
 *	Made by Patricia Lindner, lindnerp@ohio.edu
 *	Last updated 8/30/2024
 *	For automatic grading to work, do not change this file.
 *	Students are encouraged to read through to understand
 *		project requirements, however.
 *
 * **********************************************************************/
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include <sstream>
#include "catch.hpp"
#include "../song.h"
#include "../person.h"
#include "../date.h"

using namespace std;

static int score = 0;

TEST_CASE("Testing Song Class") {
	SECTION("Extraction Operator and Getters") {
		cout << "Testing Extraction Operator and Getters...\n";

		// open data file
		ifstream test_file;
		test_file.open("_TEST/song_test.txt");
		if (test_file.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// read a song in from the file
		Song s;
		test_file >> s;
		test_file.close();	
		
		// test that name, date, and artist are correct
		REQUIRE(s.get_name() == "Fishing for Fishies");
		REQUIRE(s.get_release() == Date(26, 4, 2019));
		REQUIRE(s.get_artist() == "King Gizzard and the Lizard Wizard");
		

		cout << "Extraction Operator and Getters passed.\n";
		score += 1;
	}

	SECTION("Equality") {
		cout << "Testing Equality Operator...\n";

		// open data file
		ifstream test_file;
		test_file.open("_TEST/song_test.txt");
		if (test_file.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}
		
		// read first song from data file
		Song s1;
		test_file >> s1;
		
		// reset file pointer so s2 matches s1, read in 2 more songs
		test_file.seekg(0, std::ios::beg);
		
		Song s2;
		test_file >> s2;

		Song s3;
		test_file >> s3;
		
		test_file.close();

		// s1 is the same as s2, s3 is different than both
		REQUIRE(s1 == s2);
		REQUIRE(!(s1 == s3));

		cout << "Equality Operator passed.\n";
		score += 1;
	}

	SECTION("Inequality") {
		cout << "Testing Inequality Operator...\n";

		// open data file
		ifstream test_file;
		test_file.open("_TEST/song_test.txt");
		if (test_file.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}
		
		// read in song from data file
		Song s1;
		test_file >> s1;
		
		test_file.close();

		// open data file again
		test_file.open("_TEST/song_test.txt");
		if (test_file.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}
		
		// read in first 2 songs
		Song s2;
		test_file >> s2;

		Song s3;
		test_file >> s3;
		
		test_file.close();
		
		// s1 is the same as s2, s3 is different than both
		REQUIRE(s1 != s3);
		REQUIRE(!(s1 != s2));

		cout << "Inequality Operator passed.\n";
		score += 1;
	}

}

TEST_CASE("Testing PersonalInfo Class") {
	SECTION("load and show_all") {
		cout << "Testing load and show_all...\n";
		PersonalInfo p;
		ifstream fin;

		// open data file
		fin.open("_TEST/full_profile.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		stringstream ss1;
		stringstream ss2;

		// load data into PersonalInfo object using member functions and output data
		p.load(fin);
		p.output(ss1);
		
		// reset file pointer to beginning, read data directly into stream
		fin.clear();
		fin.seekg(0, std::ios::beg);

		ss2 << fin.rdbuf();
		fin.close();
		
		// make sure data in object matches data in file
		REQUIRE(ss1.str() == ss2.str());

		cout << "load and show_all passed.\n";
		score += 1;
	}

	SECTION("Remove") {
		cout << "Testing remove_song...\n";
		PersonalInfo p;
		
		// open data file
		ifstream fin;
		fin.open("_TEST/full_profile.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// set stream to compare to
		stringstream ss1;
		stringstream ss_remove;
		ss_remove.str("Rufus\nThe\nBobcat\n9/2/2006\n1 Ohio University\nAthens\nOH\n45701\n"
			"Fishing for Fishies\nKing Gizzard and the Lizard Wizard\n4/26/2019\n"
			"Space Cowboy\nflipturn\n4/20/2023\n");

		// load data from file and remove a song
		p.load(fin);

		p.remove_song("Minor Setback", "GUM feat. Ambrose Kenny-Smith");

		p.output(ss1);
		fin.close();

		// make sure loaded data minus song is as expected
		REQUIRE(ss1.str() == ss_remove.str());

		cout << "remove_song passed.\n";
		score += 1;
	}

	SECTION("Add Song") {
		cout << "Testing add_song...\n";
		PersonalInfo p;

		// open input file
		ifstream fin;
		fin.open("_TEST/full_profile.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// load data from file
		p.load(fin);
		stringstream ss_add;
		stringstream ss1;

		// set expected stream
		ss_add.str("Rufus\nThe\nBobcat\n9/2/2006\n1 Ohio University\nAthens\nOH\n45701\n"
			"Fishing for Fishies\nKing Gizzard and the Lizard Wizard\n4/26/2019\n"
			"Minor Setback\nGUM feat. Ambrose Kenny-Smith\n4/23/2023\n"
			"Space Cowboy\nflipturn\n4/20/2023\n"
			"Paradise Garage\nBabe Rainbow\n6/22/2023\n");

		// add a new song
		Song s1;
		stringstream ss_song_add;
		ss_song_add.str("Paradise Garage\nBabe Rainbow\n6/22/2023\n");
		ss_song_add >> s1;

		p.add_song(s1);

		p.output(ss1);

		fin.close();

		// make sure output matches expected
		REQUIRE(ss1.str() == ss_add.str());

		cout << "add_song passed.\n";
		score += 1;
	}

	SECTION("Sorts") {
		cout << "Testing sorts...\n";
		PersonalInfo p;

		// open data file
		ifstream fin;
		fin.open("_TEST/full_profile.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// load data into object
		p.load(fin);
		stringstream ss_artist;
		stringstream ss_release;
		stringstream ss_name;

		// set expected output streams
		ss_artist.str("Rufus\nThe\nBobcat\n9/2/2006\n1 Ohio University\nAthens\nOH\n45701\n"
			"Minor Setback\nGUM feat. Ambrose Kenny-Smith\n4/23/2023\n"
			"Fishing for Fishies\nKing Gizzard and the Lizard Wizard\n4/26/2019\n"
			"Space Cowboy\nflipturn\n4/20/2023\n");

		ss_release.str("Rufus\nThe\nBobcat\n9/2/2006\n1 Ohio University\nAthens\nOH\n45701\n"
			"Fishing for Fishies\nKing Gizzard and the Lizard Wizard\n4/26/2019\n"
			"Space Cowboy\nflipturn\n4/20/2023\n"
			"Minor Setback\nGUM feat. Ambrose Kenny-Smith\n4/23/2023\n");

		ss_name.str("Rufus\nThe\nBobcat\n9/2/2006\n1 Ohio University\nAthens\nOH\n45701\n"
			"Fishing for Fishies\nKing Gizzard and the Lizard Wizard\n4/26/2019\n"
			"Minor Setback\nGUM feat. Ambrose Kenny-Smith\n4/23/2023\n"
			"Space Cowboy\nflipturn\n4/20/2023\n");

		stringstream ss_sorted_artist;
		stringstream ss_sorted_release;
		stringstream ss_sorted_name;

		// call sorts, compare to expected
		p.artist_sort();
		p.output(ss_sorted_artist);
		REQUIRE(ss_sorted_artist.str() == ss_artist.str());

		p.release_sort();
		p.output(ss_sorted_release);
		REQUIRE(ss_sorted_release.str() == ss_release.str());

		p.name_sort();
		p.output(ss_sorted_name);
		REQUIRE(ss_sorted_name.str() == ss_name.str());

		fin.close();

		cout << "Sorting passed.\n";
		score += 1;
	}

	SECTION("is_song") {
		cout << "Testing is_song...\n";
		PersonalInfo p;

		// open data file
		ifstream fin;
		fin.open("_TEST/full_profile.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// load file into object
		p.load(fin);

		// set up streams for 2 songs
		stringstream ss_song1;
		stringstream ss_song2;
		ss_song1.str("Space Cowboy\nflipturn\n4/20/2023\n");
		ss_song2.str("Hell\nKing Gizzard and the Lizard Wizard\n8/16/2019\n");
		Song s1;
		Song s2;
		ss_song1 >> s1;
		ss_song2 >> s2;
		fin.close();

		// make sure s1 is in the list but s2 is not
		REQUIRE(p.is_song(s1) == true);
		REQUIRE(p.is_song(s2) == false);

		cout << "is_song passed.\n";
		score += 1;
	}

	SECTION("save") {
		cout << "Testing save...\n";
		PersonalInfo p;

		// open input and output files
		ifstream fin;
		fin.open("_TEST/full_profile.txt");
		ofstream fout;
		fout.open("_TEST/full_profile_save.txt");

		if (fin.fail() || fout.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// load data into object
		p.load(fin);

		stringstream ss_after_save;
		stringstream ss_before_save;
		stringstream ss_song;
		ss_song.str("Hell\nKing Gizzard and the Lizard Wizard\n8/16/2019\n");
		Song s;
		ss_song >> s;

		// add a song and output to file
		p.add_song(s);
		p.output(ss_before_save);
		p.output(fout);
		fout.close();
		fin.close();

		// reopen output file as input
		fin.open("_TEST/full_profile_save.txt");

		if (fin.fail()) {
			cout << " \u001b[31mFailed to open test file. Did you mess with something?\e[0m\n";
			return;
		}

		// read edited input 
		PersonalInfo p2;
		p2.load(fin);
		p2.output(ss_after_save);
		fin.close();

		// make sure save and load didn't corrupt the data
		REQUIRE(ss_before_save.str() == ss_after_save.str());

		cout << "save passed.\n";
		score += 1;
	}

	SECTION("Score") {
		cout << "FOR ALL ERROR MESSAGES, THE FIRST VALUE IS THE ONE PROVIDED BY YOUR CLASS,\nAND THE SECOND VALUE IS THE DESIRED OUTPUT.\n";
		cout << "START AT THE TOP AND WORK DOWNWARDS\n";
		cout << "Score: " << score << " / 9\n";
	}
}
