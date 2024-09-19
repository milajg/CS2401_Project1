CS 2401 - Fall 2024
# Project 1 - Container Class
Due: 11:59 PM Wednesday, September 18th  

*** 
This assignment is to be completed on your own. Refer to the plagiarism policy in the syllabus.
You are not allowed to use any libraries or functions that we have not discussed in class.  
*** 

A basic container class is one that stores a collection of a certain type of data. This means that there will be an array as one of the private data members. There can be other pieces of data included as well, but there must be an array for the class to be a "container".  

For this assignment, you will be working with 3 different classes:
1. The date class is already completed for you. This class has input and output operators (>> and <<) that use the format mm/dd/yyyy to read in and output dates. There are also comparison operators.  [DONE]
2. The Song class should be used to store information about a single song (the name, artist, and release date). I have given you a header file for this class. **You must comment this file, add "const" markers for appropriate functions, and write the corresponding song.cc file.** [DONE]
3. The PersonalInfo class stores information about a single person. This includes their first, middle, and last names, their birthday, their home address, and a list of their favorite songs. I have give you a header file for this class as well. **You must comment this file, add "const" markers for appropriate functions, add a correctly qualified SIZE variable, and write the corresponding person.cc file.**  

***

I have provided a main program that functions as a system someone could use to create personal profiles. The program does the following:  

* Prompts the user for a data file. If the file exists, it will load the user's data. If it does not exist, you will begin with a newly constructed object.  
* Begins a sentinel loop that offers the user the following options:
    1. See your profile information.  
	2. Add a song to your favorites list.  
	3. Sort your songs by name, release date, or artist.  
	4. Remove a song from your favorites.  
    5. Update your name.  
    6. Update your birthday.  
    7. Update your address.  
* The user can exit the program by entering 9.  

You can use this program to incrementally implement the class functions. I have commented out all PersonalInfo object function calls so you can add new functions one at a time.  

***

Useful reminders:
1. You can read in dates like:
    ```
    Date d;
    stream >> d;
    ```
    where "stream" can be cin or a file.  
2. To read in strings that include spaces, you must use ```getline(stream, var)``` not ```stream >> var```.  
3. When you go to use getline() after the >> operator, you must clear white space before the getline() call.  
4. Input file format:
    ```
    First Name  
    Middle Name  
    Last Name  
    Birthday  
    House number and street  
    City  
    State  
    Zip code  
    Song 1 Name  
    Song 1 Artist  
    Song 1 Release date  
    ```  

    There can be as many songs as you want with the pieces of information in the same order (name, artist, date).  

***  
There are some automatic tests that will run when you push your code to GitHub (if you add run-tests to your commit message), but you should be testing things on your own as you develop. Do not rely solely on the GitHub tests. You can run the tests that GitHub will use by running "make run_tests" on your own machine. Before making a commit, you should be reasonably sure that the feature you just finished coding is working correctly.   

**Your GitHub repository should include** your original song.cc and person.cc files, the data file you were testing with, and the 2 header files with documentation and "const" markers added.