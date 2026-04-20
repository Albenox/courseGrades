/*
1. Read the header values indicating the number of students and tests.
2. Dynamically allocate an array of student structs.
3. Dynamically allocate an array of test scores inside each struct.
4. Store student name, ID, test scores, average, and letter grade.
5. Calculate average test scores.
6. Assign letter grades using the provided grading scale.
7. Produce a neatly formatted report.
8. Deallocate memory in the correct order:
8.1- Test score arrays
8.2- Student array
*/

//Libraries and namespace
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//string studentsTests(char buffer);

struct student {
    //Variables for student struct
    string name;
    int id;
	//Pointer to an array of test scores, which will be dynamically allocated later
    double* testScores;
    double average;
	char letterGrade;
};

//Main function
int main()  {
	//Variables for the number of students and tests, which will be extracted from the first line of the file
	int numStudents;
	int numTests;

    //Grabs the file and creates a stream that is similar to cin, that can be used to extract values for the program
    //Additionally, I no longer need to close the file at the end of the program as the ifstream object will close automatically at the end of the program
    ifstream file("student_data.txt");

	//Checks if the file was successfully opened, which if not, ending the program with an error message
    if (!file) {
        cout << "Error: file could not be opened." << endl;
        return 1;
    }
    //Allows the program to continue if the file was successfully opened
    else {
        //Declares the string variable "line", which will hold the current line read from getline()
        string line;
		
        //Grabs a line from the file and stores it into the string variable "line", which automatically progresses to the next line for the next time getline is called 
        //Sidenote, getline is perfect and makes this SO MUCH EASIER I LOVE IT!!!
        getline(file, line);
        
        //stringstream creates a copy of the string "line" and sets the stringstream variable "ss" as a copy that can be used to break the line into tokens
        stringstream ss(line);
        
        //Extracts and automatically runs through tokens of the line each time ss is called
		ss >> numStudents;
		ss >> numTests;
		
        cout << "Testing number of students: " << numStudents << endl;
		cout << "Testing number of tests: " << numTests << endl;


		//Reads the file line by line and prints each line to the console until the end of the file is reached
        //This is done by running fgets and checking to see if it returns NULL, which indicates the end of the file if so, ending the loop
        for (int i = 0; i < numStudents; i++) {
            getline(file, line);
		}

		//Returns 0 to indicate that the program ended successfully
        return 0;
    }
}
/*
string studentsTests(char buffer) {
    cout << "WIP";
}
*/