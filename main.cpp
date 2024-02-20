/*
  Author: Abhishek Shrestha
  CSC 402 - Program #3
  Operator overloading, Inheritance, Polymorphism
  mySets, OrderedSets,

  Program Description:
  This program implements a class hierarchy consisting of two classes: mySet and OrderedSet. The mySet class represents a mathematical set containing unique integers, while the OrderedSet class inherits from mySet and maintains its elements in sorted order. The program demonstrates operator overloading, inheritance, and polymorphism.

    The main function of the program performs the following actions:
    1. Reads integers from input files and inserts them into mySet objects S1 and S2.
    2. Performs set operations such as Union, Intersection, and Difference on S1 and S2.
    3. Tests the equivalence of sets using the == operator.
    4. Adds additional elements to S1 and prints the updated set.
    5. Deletes elements from S1 and prints the updated set.
    6. Repeats the above steps for OrderedSet objects OS1 and OS2.
    7. Prints appropriate messages to indicate successful operations and completion of the program.

  Date: 02/19/2024
*/




#include <iostream>
#include <fstream>
#include "mySet.h"
#include "OrderedSet.h"
using namespace std;

ostream& operator<<(ostream& ost, const mySet& S) {
    if (S.elts.size()==0) {
        ost << "Set is EMPTY"<<endl;
    } else {
        ost << "{ ";
        int count = 0;
        for (int i = 0; i < S.elts.size(); ++i) {
            if (i == S.elts.size() - 1) {
                ost << S.elts[i];
            } else {
                ost << S.elts[i] << " ,";
            }
            count++;
            if (count == 10 && i != S.elts.size() - 1) {
                ost << "\n";
                count = 0;
            }
        }
        ost << " }";
        if (count != 0) {  // If count is not 0, meaning there are remaining elements
            ost << "\n";    // Move to the next line before printing the closing brace
        }
    }
    return ost;
}


int main() {
    // Declare mySet objects
    mySet S1, S2, S3, S4, S5, S6;

    // Declare OrderedSet objects
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;

    // Prompt user for the path to the first input file
    string inputFilePath1;
    cout << "Please enter a path to an input file : ";
    cin >> inputFilePath1;

    // Open the first input file
    ifstream inputFile1(inputFilePath1);
    if (!inputFile1.is_open()) {
        cerr << "Error: Unable to open the first input file." << endl;
        return 1;
    }

    // Read integers from the first input file and insert them into S1
    int num;
    while (inputFile1 >> num) {
        S1.addelt(num);
    }
    inputFile1.close();

    // Prompt user for the path to the second input file
    string inputFilePath2;
    cout << "Please enter a path to a second input file : ";
    cin >> inputFilePath2;

    // Open the second input file
    ifstream inputFile2(inputFilePath2);
    if (!inputFile2.is_open()) {
        cerr << "Error: Unable to open the second input file." << endl;
        return 1;
    }

    // Read integers from the second input file and insert them into S2
    while (inputFile2 >> num) {
        S2.addelt(num);
    }
    inputFile2.close();

    // Print mySet S1
    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl;

    // Print mySet S2
    cout <<"MySet S2 Contents"<<endl <<"_____________"<<endl<< S2 << endl;

    // Print mySet S3 (empty set)
    cout << "MySet S3 Contents"<<endl <<"_____________"<<endl<< S3 << endl;

    // Assign Union of S1 and S2 to S3
    S3 = S1.Union(S2);
    cout << "After UNION Operation of S1 and S2"<< endl;

    cout << "MySet S3 Contents"<<endl <<"_____________"<<endl<< S3 << endl;

    // Print mySet S1
    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl;

    // Print mySet S2
    cout <<"MySet S2 Contents"<<endl <<"_____________"<<endl<< S2 << endl;

    // Assign Intersection of S1 and S2 to S4
    S4 = S1.Intersection(S2);
    cout << "After INTERSECTION Operation of S1 and S2"<< endl;

    cout <<"MySet S4 Contents"<<endl <<"_____________"<<endl<< S4 << endl;

    // Print mySet S1
    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl;

    // Print mySet S2
    cout <<"MySet S2 Contents"<<endl <<"_____________"<<endl<< S2 << endl;

    // Assign Difference of S1 and S2 to S5
    S5 = S1.Difference(S2);
    cout<<"After DIFFERENCE Operation of S1 and S2"<<endl;

    cout <<"MySet S5 Contents"<<endl <<"_____________"<<endl<< S5 << endl;

    // Print mySet S1
    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl;

    // Print mySet S2
    cout << "MySet S2 Contents"<<endl <<"_____________"<<endl<< S2 << endl;

    // Test equivalence of S3 and S6
    S6 = S1.Union(S3);
    cout << "S3 and S6 are " << (S3 == S6 ? "EQUAL" : "NOT EQUAL") << endl;

    // Test equivalence of S1 and S6
    cout << "S1 and S6 are " << (S1 == S6 ? "EQUAL" : "NOT EQUAL") << endl;

    // Prompt user for the path to the third input file
    string inputFilePath3;
    cout << "Please enter a path to a third input file : ";
    cin >> inputFilePath3;

    // Open the third input file
    ifstream inputFile3(inputFilePath3);
    if (!inputFile3.is_open()) {
        cerr << "Error: Unable to open the third input file." << endl;
        return 1;
    }
    // input file to mySet S1
    while (inputFile3 >> num) {
        bool added = S1.addelt(num);
        cout << num <<(added ? " was successfully added to " : " ALREADY PRESENT IN ") << "S1" << endl;
    }
    cout<<endl;
    inputFile3.close();

    // Print mySet S1 after adding elements
    cout<<"S1 AFTER ADDITION of elements"<<endl;
    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl;

    // Prompt user for the path to the fourth input file
    string inputFilePath4;
    cout << "Please enter a path to a fourth input file : ";
    cin >> inputFilePath4;

    // Open the fourth input file
    ifstream inputFile4(inputFilePath4);
    if (!inputFile4.is_open()) {
        cerr << "Error: Unable to open the fourth input file." << endl;
        return 1;
    }

    // Add elements from the fourth input file to S2
    while (inputFile4 >> num) {
        bool deleted = S1.deleteelt(num);
        cout <<num<< (deleted ? " was successfullly deleted from S1 " : " NOT FOUND ")<< endl;
    }
    cout<<endl;
    inputFile4.close();

    // Print mySet S2 after adding elements
    cout << "S1 AFTER DELETION of elements "<< endl;

    cout << "MySet S1 Contents"<<endl <<"_____________"<<endl<< S1 << endl<<endl;

    cout<<"OUTPUT FOR ORDERED SETS"<<endl<<endl;



    // Prompt user for the path to the first input file
    string inputFilePath5;
    cout << "Please enter a path to an input file : ";
    cin >> inputFilePath5;

// Open the first input file
    ifstream inputFile5(inputFilePath5);
    if (!inputFile5.is_open()) {
        cerr << "Error: Unable to open the first input file." << endl;
        return 1;
    }

// Read integers from the first input file and insert them into OS1
    while (inputFile5 >> num) {
        OS1.addelt(num);
    }
    inputFile5.close();

// Prompt user for the path to the second input file
    string inputFilePath6;
    cout << "Please enter a path to a second input file : ";
    cin >> inputFilePath6;

// Open the second input file
    ifstream inputFile6(inputFilePath6);
    if (!inputFile6.is_open()) {
        cerr << "Error: Unable to open the second input file." << endl;
        return 1;
    }

// Read integers from the second input file and insert them into OS2
    while (inputFile6 >> num) {
        OS2.addelt(num);
    }
    inputFile6.close();

// Print OrderedSet OS1
    cout << "OrderedSet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;

// Print OrderedSet OS2
    cout <<"OrderedSet OS2 Contents"<<endl <<"_____________"<<endl<< OS2 << endl;

// Print OrderedSet OS3 (empty set)
    cout << "OrderedSet OS3 Contents"<<endl <<"_____________"<<endl<< OS3 << endl;

// Assign Union of OS1 and OS2 to OS3
    OS3 = OS1.Union(OS2);
    cout << "After UNION Operation of OS1 and OS2"<< endl;

    cout << "OrderedSet OS3 Contents"<<endl <<"_____________"<<endl<< OS3 << endl;

// Print OrderedSet OS1
    cout << "OrderedSet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;

// Print OrderedSet OS2
    cout <<"OrderedSet OS2 Contents"<<endl <<"_____________"<<endl<< OS2 << endl;

// Assign Intersection of OS1 and OS2 to OS4
    OS4 = OS1.Intersection(OS2);
    cout << "After INTERSECTION Operation of OS1 and OS2"<< endl;

    cout <<"OrderedSet OS4 Contents"<<endl <<"_____________"<<endl<< OS4 << endl;

// Print OrderedSet OS1
    cout << "OrderedSet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;

// Print OrderedSet OS2
    cout <<"OrderedSet OS2 Contents"<<endl <<"_____________"<<endl<< OS2 << endl;

// Assign Difference of OS1 and OS2 to OS5
    OS5 = OS1.Difference(OS2);
    cout<<"After DIFFERENCE Operation of OS1 and OS2"<<endl;

    cout <<"MySet OS5 Contents"<<endl <<"_____________"<<endl<< OS5 << endl;

// Print OrderedSet OS1
    cout << "MySet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;

// Print OrderedSet OS2
    cout << "MySet OS2 Contents"<<endl <<"_____________"<<endl<< OS2 << endl;

// Test equivalence of OS3 and OS6
    OS6 = OS1.Union(OS3);
    cout << "OS3 and OS6 are " << (OS3 == OS6 ? "EQUAL" : "NOT EQUAL") << endl;

// Test equivalence of OS1 and OS6
    cout << "OS1 and OS6 are " << (OS1 == OS6 ? "EQUAL" : "NOT EQUAL") << endl;

// Prompt user for the path to the third input file
    string inputFilePath7;
    cout << "Please enter a path to a third input file : ";
    cin >> inputFilePath7;

// Open the third input file
    ifstream inputFile7(inputFilePath7);
    if (!inputFile7.is_open()) {
        cerr << "Error: Unable to open the third input file." << endl;
        return 1;
    }
// input file to OrderedSet OS1
    while (inputFile7 >> num) {
        bool added = OS1.addelt(num);
        cout << num <<(added ? " was successfully added to " : " ALREADY PRESENT IN ") << "OS1" << endl<<endl;
    }
    inputFile3.close();

// Print OrderedSet OS1 after adding elements
    cout<<"OS1 AFTER ADDITION of elements"<<endl;
    cout << "OrderedSet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;

// Prompt user for the path to the fourth input file
    string inputFilePath8;
    cout << "Please enter a path to a fourth input file : ";
    cin >> inputFilePath8;

// Open the fourth input file
    ifstream inputFile8(inputFilePath8);
    if (!inputFile8.is_open()) {
        cerr << "Error: Unable to open the fourth input file." << endl;
        return 1;
    }

// Add elements from the fourth input file to OS2
    while (inputFile8 >> num) {
        bool deleted = OS1.deleteelt(num);
        cout <<num<< (deleted ? " was successfullly deleted from OS1 " : " NOT FOUND ")<< endl<<endl;
    }
    inputFile4.close();

// Print OrderedSet OS2 after adding elements
    cout << "OS1 AFTER DELETION of elements "<< endl;

    cout << "OrderedSet OS1 Contents"<<endl <<"_____________"<<endl<< OS1 << endl;
    cout<<"PROGRAM COMPLETE";

    return 0;
}

