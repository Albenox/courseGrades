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
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//A struct for students
struct student {
    //Variables for student struct
    string name;
    int id;
	//Pointer to an array of test scores, which will be dynamically allocated later
    int* testScores;
    double average;
	char letterGrade;
};

//Function to extract the number of students and tests from the first line of the file, linked to the addresses so the values do not need to be returned, and can be a void function
void studentsTests(const string& line, int& numStudents, int& numTests);

//Function to print the report of students, their test scores, averages, and letter grades in a formatted manner
void printReport(const student* students, int numStudents, int numTests);

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
		//Declares double variable to track the total of all test scores for a student, which will be used to calculate the average test score for each student
		double testTotal = 0;
		
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

			//Dynamically allocates an array of test scores inside each struct, with the size of the array equal to the number of tests declared on the first line
            students[i].testScores = new int[numTests];

            //Resets the total variable to 0 for the next student
            testTotal = 0;

			//A for loop that runs sets a number of tokens into the current student's test score array equal to the number of tests declared on the first line
            for (int x = 0; x < numTests; x++) {
                //Extracts the test score for the current test and stores it in the current student's test score array at the index of the current test
                ss >> students[i].testScores[x];
				testTotal += students[i].testScores[x];
            }
            
            //Calculates the average test score for the current student
            students[i].average = testTotal / numTests;

            //Assigns a letter grade to the current student based on their average test score using the provided grading scale, and stores it in the current student's letter grade variable
            if (students[i].average >= 90) {
                students[i].letterGrade = 'A';
            }
            else if (students[i].average >= 80) {
                students[i].letterGrade = 'B';
            }
            else if (students[i].average >= 70) {
                students[i].letterGrade = 'C';
            }
            else if (students[i].average >= 60) {
                students[i].letterGrade = 'D';
            }
            else {
                students[i].letterGrade = 'F';
            }
		}
		//Function to print the report of students, their test scores, averages, and letter grades in a formatted manner
        printReport(students, numStudents, numTests);
		
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
}

void printReport(const student* students, int numStudents, int numTests) {
    cout << "\n===== Course Grade Report =====\n\n";

    //Set formatting for decimals
    cout << fixed << setprecision(2);

    //Header row (aligned columns)
    cout << left << setw(12) << "Name"
        << setw(10) << "ID"
        << setw(20) << "Scores"
        << setw(10) << "Average"
        << setw(6) << "Grade" << endl;

    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < numStudents; i++) {
        //Name and ID
        cout << left << setw(12) << students[i].name
            << setw(10) << students[i].id;

        //Scores (print inline)
        for (int j = 0; j < numTests; j++) {
            cout << students[i].testScores[j] << " ";
        }

        //Adjust spacing after scores and keeps columns aligned
        cout << setw(20 - (numTests * 3)) << " "; 

        //Average and grade
        cout << setw(10) << students[i].average
            << setw(6) << students[i].letterGrade << endl;
    }
}