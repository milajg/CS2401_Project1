#include "song.h"

using namespace std;

Song::Song(){ // If no input is provided, this constructor sets default values
    name = " ";
    artist = " ";
    release = Date();
}

string Song::get_name()const { // Returns the song name
    return name;
}

Date Song::get_release()const { // Returns the song relase date
    return release;
}

string Song::get_artist()const { // Returns the artist of the song
    return artist;
}

void Song::input(std::istream& ins){
    cout << "Enter the song name: " << endl;
    if(ins.peek() == ' ' || ins.peek() == '\n' || ins.peek() == '\t'){
        ins.ignore();
    }
        getline(ins, name);
    cout << "Enter the artist name: " << endl;
        getline(ins, artist);

        cout << "Enter the release date: " << endl;
        ins >> release;
}

void Song::output(std::ostream& outs)const {
    outs << "Song name: " << name << "Song artist: " << artist <<
        "Song release date: " << release << endl;
}

bool Song::operator == (const Song&other)const { // Compares two songs and returns true if they are the same
    return(name == other.get_name() && release == other.get_release() &&
      artist == other.get_artist());
}

bool Song::operator != (const Song&other)const {
    return(name != other.get_name() && release != other.get_release() && // Returns true if songs are not the same
      artist != other.get_artist());
}


istream& operator >> (std::istream& ins, Song& s){
    s.input(ins);
	return ins;
}

ostream& operator << (std::ostream& outs, const Song& s){
    s.output(outs);
    return outs;
}

