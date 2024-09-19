/*************************************************************************
    Project 1		CS2401		Fall 2024

    This is the main for your first project, a project which works with 
    the concepts of a simple container class, searching, and sorting.

    In order to make this main work you will need to write two classes,
    one called Song and one called PersonalInfo. Going through the code
    below you should be able to figure out what member functions are
    needed for each.

        Patricia Lindner    Fall 2024       Ohio University EECS
*************************************************************************/
    

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "song.h"
#include "person.h"
using namespace std;

/**
 * @brief Display the main menu to the user and read in their selection
 * 
 * @return int - the menu option the user chose
 */
int menu();

int main(){

    Song song;
    PersonalInfo me;

    string songname, artist, username, filename, sorting, info;
    int choice;
    Date bday_in;
    Address a;

    ifstream fin;
    ofstream fout;

	cout << "Welcome to Your Profile Builder.\n\n";
	cout << "Begin by entering your username: ";
	getline(cin, username);

	filename = username + ".txt";
	fin.open(filename.c_str());

    if(!fin.fail()){
	    me.load(fin);
    }
	fin.close();

	choice = 0;
	
	while(choice != 9){
	    choice = menu();
	    switch(choice){
            case 1:
            me.output(cout);
                cout << endl;
                break;
            case 2:
                cin >> song;
                if(me.is_song(song)){
                    cout << "That song is already in your favorites.\n";
                }
               else{
                    me.add_song(song);
               }
               break;
            case 3:
                cout << "Do you want to sort by name, date, or artist: ";
                cin >> sorting;
                if(sorting == "name"){
                    me.name_sort();
                }
                else if(sorting == "date"){
                    me.release_sort();
                }
                else if(sorting == "artist"){
                    me.artist_sort();
                }
                else{
                    cout << "Invalid choice, returning to menu" << endl;
                }
                break;
            case 4:
                cout << "Enter the name of the song: ";
                cin >> ws;
                getline(cin, songname);
                cout << "Enter the artist: ";
                cin >> ws;
                getline(cin, artist);

                me.remove_song(songname, artist);
                break;
            case 5:
                cout << "Enter the new first name: ";
                cin >> ws;
                getline(cin, info);
                me.set_fName(info);
                cout << "Enter the new middle name: ";
                getline(cin, info);
                me.set_mName(info);
                cout << "Enter the new last name: ";
                getline(cin, info);
                me.set_lName(info);
                break;
            case 6:
                cout << "Enter your birthday: ";
                cin >> bday_in;
                me.set_birthDay(bday_in);
                break;
            case 7:
                cout << "Enter the house number and street (as one line): ";
                cin >> ws;
                getline(cin, a.street);
                cout << "Enter the city: ";
                getline(cin, a.city);
                cout << "Enter the state: ";
                getline(cin, a.state);
                cout << "Enter the zip code: ";
                getline(cin, a.zip);
                me.set_address(a);
                break;
            default:
                break;
		} // bottom of the switch
	} // bottom of the while
	fout.open(filename.c_str());
    if(!fout.fail()){
        me.output(fout);
    }
	else{
	    cout << "Unable to save data.\n";
    }
	fout.close();

	cout << "Goodbye! Update your information again soon.\n";
    return 0;
}
	
int menu(){
	int ans;

	cout << "Choose from the options below:\n";
	cout << "1 - See your profile information.\n";
	cout << "2 - Add a song to your favorites list.\n";
	cout << "3 - Sort your songs by name, release date, or artist.\n";
	cout << "4 - Remove a song from your favorites.\n";
    cout << "5 - Update your name.\n";
    cout << "6 - Update your birthday.\n";
    cout << "7 - Update your address.\n";
	cout << "9 - Leave the program.\n";

	cin >> ans;
    return ans;
}