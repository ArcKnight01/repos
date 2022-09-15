// RoboticsC++Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //library allows us to interact w/ users
#include "main.h"
using namespace std; //allows us to use pre written code , saving time


void main()
{
    void add(int a, int b);
    //writing text to console: 
    //in C++, there are MANY ways to write text to the terminal console.
    //Though ways like print() and printf() using libraries like stdio.h, the easiest and most common way is cout
    //cout is implemented through the iostream library which allows interaction with the seperate console/terminal
    // for example:
    std::cout << "Hello World!\n"; //using namespace std allows you to take out the std::cout, and just write cout
    cout << "What is your name?" << endl; //endl is used at the end to create a new line, like the escape code "\n"
    // in order to input info, just like cout, there is cin. This takes input from a terminal and stores it in a variable.
    string myName; // a string variable (will learn more about this later)
    cin >> myName;
    cout << "Your name is " << myName << endl;
    
    //Variables "store" a value in a variable

    //types of variables:
    //initialized by their data type (int, float, char, etc)

    //integer (int): int variable = value;
    int number = 8;
    //float (8 bits) or double (4 bits):
    float decimalf = 8.8;
    double decimald = 8.9;
    //char (single letter): 
    char letter = 'a'; //one/single letter ''
    string words = "My name is Aidan"; //many characters/words & sentences
    string name; //declare string variable: name.
    //boolean (bool): true / false , 1 / 0
    bool conditional = false;

    //functions:
    //functions group / organize a sequence of written code to be run as an output.

    //operators: used to perform maths
    int a = 2;
    int b = 22;
    int sum;
    sum = a + b;
    cout << "The sum of " << a << " and " << b << " is " << sum << endl;
    add(1, 2);
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
