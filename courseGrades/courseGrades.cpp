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
#include <stdio.h>
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

	int numStudents;
	int numTests;

	//Declares a pointer to a file stream and initializes it to nullptr
    FILE *pFile = nullptr;
	//Open the file for reading
    fopen_s(&pFile, "student_data.txt", "r");

	//Checks if the file was successfully opened, which if not, ending the program with an error message
    if (pFile == NULL) {
        cout << "Error: file could not be opened." << endl;
        return 1;
    }
    //Allows the program to continue if the file was successfully opened
    else {
		//Declares a character buffer to hold each line read from the file, with a maximum size of 255 characters
        char buffer[255];
        

        fgets(buffer, sizeof(buffer), pFile);
        string line = buffer;
        //stringstream ss(line) automaticall creates tokens from the line seperated by spaces, that automatically progresses through the line each time ss is called
		//This allows us to call ss twice in a row, and since the first line will always be the number of students and tests, both variables are easily populated
        stringstream ss(line);
        //First token that is the number of students
        ss >> numStudents;
		//Second token that is the number of tests
        ss >> numTests;

		cout << "Number of students: " << numStudents << endl;
		cout << "Number of tests: " << numTests << endl;

        //TESTING STRING
		int TESTnumStudents;
		int TESTnumTests;
		ifstream TESTfile("student_data.txt");
        string TESTline;
        getline(TESTfile , TESTline);
        stringstream TESTss(TESTline);
		TESTss >> TESTnumStudents;
		TESTss >> TESTnumTests;
		cout << "Testing number of students: " << TESTnumStudents << endl;
		cout << "Testing number of tests: " << TESTnumTests << endl;
        //TESTING STRING


		//Reads the file line by line and prints each line to the console until the end of the file is reached
        //This is done by running fgets and checking to see if it returns NULL, which indicates the end of the file if so, ending the loop
        while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
			//Prints the contents of the buffer, which is the line read from the file, to the console
            printf("%s", buffer);
        }

		//Closes the file after reading is complete
        fclose(pFile);

		//Returns 0 to indicate that the program ended successfully
        return 0;
    }
}
/*
string studentsTests(char buffer) {
    cout << "WIP";
}
*/