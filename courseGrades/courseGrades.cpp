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

//Function to extract the number of students and tests from the first line of the file, linked to the addresses so the values do not need to be returned, and can be a void function
void studentsTests(const string &line, int &numStudents, int &numTests);

//A struct for students
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
        //Variables for the number of students and tests, which will be extracted from the first line of the file
        int numStudents, numTests;
        //Declares the string variable "line", which will hold the current line read from getline()
        string line;
		
        //Grabs a line from the file and stores it into the string variable "line", which automatically progresses to the next line for the next time getline is called 
        //Sidenote, getline is perfect and makes this SO MUCH EASIER I LOVE IT!!!
        getline(file, line);
        
        //Function to extract the number of students and tests from the first line of the file, linked to the addresses so the values do not need to be returned, and can be a void function
        studentsTests(line, numStudents, numTests);

        //Creates a pointer, "students", that points to an array of student structs, which will dynamically allocate an amount of memory for the students
        student* students = new student[numStudents];

		//A forloop that runs through a number of lines from the file equal tothe number of students, to ensure each are covered
        for (int i = 0; i < numStudents; i++) {
            //An automatically advancing method to read the next line of the file and store it into the string variable "line"
            getline(file, line);
            //stringstream creates a copy of the string "line" and sets the stringstream variable "ss" as a copy that can be used to break the line into tokens
            stringstream ss(line);
            //A series of extractions from the stringstream variable "ss" that extracts by tokens to fill out each student's information in order
            ss >> students[i].name;
			ss >> students[i].id;

			//A for loop that runs sets a number of tokens into the current student's test score array equal to the number of tests declared on the first line
            for (int x = 0; x < numTests; x++) {
                //Extracts the test score for the current test and stores it in the current student's test score array at the index of the current test
                ss >> students[i].testScores[x];
            }
		}

		//Returns 0 to indicate that the program ended successfully
        return 0;
    }
}

//Function to extract the number of students and tests from the first line of the file, linked to the addresses so the values do not need to be returned, and can be a void function
void studentsTests(const string &line, int &numStudents, int &numTests) {
    //stringstream creates a copy of the string "line" and sets the stringstream variable "ss" as a copy that can be used to break the line into tokens
    stringstream ss(line);

    //Extracts and automatically runs through tokens of the line each time ss is called
    ss >> numStudents;
    ss >> numTests;

    cout << "Testing number of students: " << numStudents << endl;
    cout << "Testing number of tests: " << numTests << endl;
}
