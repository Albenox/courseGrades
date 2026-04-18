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
using namespace std;

//Main function
int main()
{
	//Declares a pointer to a file stream and initializes it to nullptr
    FILE *pF = nullptr;
	//Open the file for reading
    fopen_s(&pF, "student_data.txt", "r");

	//Checks if the file was successfully opened, which if not, ending the program with an error message
    if (pF == NULL) {
        cout << "Error: file could not be opened." << endl;
        return 1;
    }
    //Allows the program to continue if the file was successfully opened

    else {
		//Declares a character buffer to hold each line read from the file, with a maximum size of 255 characters
        char buffer[255];

		//Reads the file line by line and prints each line to the console until the end of the file is reached
        //This is done by running fgets and checking to see if it returns NULL, which indicates the end of the file if so, ending the loop
        while (fgets(buffer, 255, pF) != NULL) {
			//Prints the contents of the buffer, which is the line read from the file, to the console
            printf("%s", buffer);
        }

		//Closes the file after reading is complete
        fclose(pF);

        return 0;
    }
}