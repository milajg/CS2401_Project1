#include "person.h"

PersonalInfo::PersonalInfo(){ // Sets default values
    fName = " ";
    mName = " ";
    lName = " ";

    birthDay = Date();
    home = Address();
    used_songs = 0;
}

void PersonalInfo::set_fName(std::string n){ // Sets first name for profile
    fName = n;
}

void PersonalInfo::set_mName(std::string n){ // Sets middle name for profile
    mName = n;
}

void PersonalInfo::set_lName(std::string n){ // Sets last name for profile
    lName = n;
}

void PersonalInfo::set_birthDay(Date b){ // Sets birthday for profile
    birthDay = b;
}

void PersonalInfo::set_address(Address a){ // Sets address for profile
    home = a;
}

std::string PersonalInfo::get_fName() const{ // Returns first name of profile
    return fName;
}

std::string PersonalInfo::get_mName() const{ // Returns middle name of profile
    return mName;
}

std::string PersonalInfo::get_lName() const{ // Returns last name of profile
    return lName;
}

Date PersonalInfo::get_birthDay() const{ // Returns birthday for profile
    return birthDay;
}

Address PersonalInfo::get_home() const{ // Returns address for profile
    return home;
}

   
void PersonalInfo::load(std::istream& ins){
    used_songs = -1;
    ins >> fName;  // Reads first name
    ins >> mName;  // Reads middle name
    ins >> lName;  // Reads last name
    if(ins.peek() == ' ' || ins.peek() == '\n' || ins.peek() == '\t'){ // Ignores white spaces
        ins.ignore();
    }   
    std::getline(ins, home.street); 
    std::getline(ins, home.city); 
    ins >> home.state;
    ins >> home.zip;

    Song s;
    while(!ins.eof()){
        ++used_songs;
        ins >> s;
        favoriteSongs[used_songs] = s;
        if(ins.peek() == ' ' || ins.peek() == '\n' || ins.peek() == '\t'){
        ins.ignore();
    }   

    if(ins.peek() == ' ' || ins.peek() == '\n' || ins.peek() == '\t'){
        ins.ignore();
    }  

    }
}

void PersonalInfo::output(std::ostream& outs){
    outs << "Name: " << fName << " " << mName << " " << lName << std::endl; // Outputs name for the profile
    outs << "Birthday: " << birthDay << std::endl; // Outputs birthday for the profile
    outs << "Address: " << home.street << ", " // Outputs address for the profile
         << home.city << ", " 
         << home.state << " " 
         << home.zip << std::endl;  
        for(int i = 0; i < used_songs; ++i){ // Outputs the song name, artist, and release date
            outs << "Song's name: "  << favoriteSongs[i].get_name() << std::endl;
            outs << "Song's artist: " << favoriteSongs[i].get_artist() << std::endl;
            outs << "Song's release date: " << favoriteSongs[i].get_release() << std::endl;
        }
}

void PersonalInfo::release_sort(){ // Bubble sort to sort from oldest song to newest song
     int i, upper_bound = used_songs - 1; 
    bool done = false;

    while (!done) {
        done = true;  // Assume done is true

        for (i = 0; i < upper_bound; i++) {  // Compare adjacent elements
            if (favoriteSongs[i].get_release() > favoriteSongs[i + 1].get_release()) {
                Song tmp = favoriteSongs[i];
                favoriteSongs[i] = favoriteSongs[i + 1];
                favoriteSongs[i + 1] = tmp;

                done = false;  // Continue sorting
            }
        }
        upper_bound--;
    }
}

void PersonalInfo::name_sort(){ // Insertion sort to sort song names alphabetically
    for(int i = 1; i < used_songs; i++){
        Song next = favoriteSongs[i];
        std::string next_name = next.get_name();
        int j = i;
        while(j > 0 && next_name < favoriteSongs[j - 1].get_name()){
            favoriteSongs[j] = favoriteSongs[j - 1];
            j--;
        }
        favoriteSongs[j] = next;
    }
}

void PersonalInfo::artist_sort(){ // Selection sort to sort artist names alphabetically
    size_t i, j, smallest;
    Song tmp;
    for(i = 0; i < used_songs - 1; i++){
        smallest = i;
        for(j = i + 1; j < used_songs; j++){
            if(favoriteSongs[j].get_artist() < favoriteSongs[smallest].get_artist()){
                smallest = j;
            }
        }
        tmp = favoriteSongs[i];
        favoriteSongs[i] = favoriteSongs[smallest];
        favoriteSongs[smallest] = tmp;
    }
}

void PersonalInfo::add_song(const Song& s){ // Adds new song to array
    if (used_songs >= SIZE) { // Checks to make sure the array is not full
        std::cout << "Favorites list is full!" << std::endl;
        return;
    }

      if (used_songs < SIZE && used_songs >= 0) // If there is room in the array, add the new song

            {

                favoriteSongs[used_songs] = s;

                ++used_songs;

            }

}
 



void PersonalInfo::remove_song(std::string n, std::string a){
    for (int i = 0; i < used_songs; i++) {
        if (favoriteSongs[i].get_name() == n && favoriteSongs[i].get_artist() == a) { // If song in array matches the desried string to remove
            for (size_t j = i; j < used_songs - 1; j++) {
                favoriteSongs[j] = favoriteSongs[j + 1];
            }
            used_songs--; // decrement used
        }
    }
}

bool PersonalInfo::is_song(const Song& s){
    for(int i = 0; i < used_songs; i++){
        if(favoriteSongs[i].get_name() == s.get_name() && 
            favoriteSongs[i].get_artist() == s.get_artist() 
                && favoriteSongs[i].get_release() == s.get_release())
        return true; // Returns true if song exists
    }
    return false; // Returns false if song does not exist
}