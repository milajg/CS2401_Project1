#include <string>
#include <iostream>
#include "structs.h"
#include "song.h"

class PersonalInfo{
    public:
        // add a correctly formatted SIZE variable for the array 
        
        PersonalInfo();

        void set_fName(std::string n);
        void set_mName(std::string n);
        void set_lName(std::string n);
        void set_birthDay(Date b);
        void set_address(Address a);

        std::string get_fName() const;
        std::string get_mName() const;
        std::string get_lName() const;
        Date get_birthDay() const;
        Address get_home() const ;

        void load(std::istream& ins);
        void output(std::ostream& outs);

        void release_sort();
        void name_sort();
        void artist_sort();

        void add_song(const Song& s);
        void remove_song(std::string n, std::string a);
        bool is_song(const Song& s);

    private:
        std::string fName;
        std::string mName;
        std::string lName;

        Date birthDay;
        Address home;

        static const int SIZE = 100;
        Song favoriteSongs[SIZE];
        int used_songs;

};