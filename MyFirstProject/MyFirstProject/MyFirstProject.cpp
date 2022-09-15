// MyFirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //library allows us to interact w/ users
using namespace std; //allows us to use pre written code , saving time
int main()
{
    //types of variables:

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
    bool isACamper = false;

    //pointers access the value and memory location, kinda makes a copy of value
    //type then asterix (int*) = pointer ... point = &value (& means adress of value)
    //example for int number = 8;
    float* pointer2;
    pointer2 = &decimalf;
    cout << "value of number is " << decimalf << endl; //prints value of variable number
    cout << "memory address is: " << pointer2 << endl; //prints out memory address
    cout << "value ay given address is: " << *pointer2 << endl; //prints value at the given memory address
    int* pointer;
    pointer = &number;
    cout << "value of number is " << number << endl; //prints value of variable number
    cout << "memory address is: " << pointer << endl; //prints out memory address
    cout << "value ay given address is: " << *pointer << endl; //prints value at the given memory address
    char* pointer3;
    pointer3 = &letter;
    cout << "value of number is " << letter << endl; //prints value of variable number
    cout << "memory address is: " << pointer3 << endl; //prints out memory address
    cout << "value ay given address is: " << *pointer3 << endl; //prints value at the given memory address


    cout << words << endl; // should print out "My name is Aidan".
    cout << letter << endl; // should print out "a"
    cout << number << endl; //should print out 8
    cout << decimalf << endl; //should print out 8.8
    cout << decimald << endl; //should print out 8.9
    cout << words << " " << number << endl;

    cout << "What is your name?" << endl;
    // extracter operator, uses ">>"
    cin >> name; //input name.
    cout << "Hello " << name << endl; //should print out Hello [inputted name].
    cout << isACamper << endl; //booleans print out 0 if false, 1 if true
    //print statements

    //each part is seperated by an insertion operator "<<".
    std::cout << "Without namespace std!\n"; //without namespace
    cout << "With namespace std!\n"; //with namespace and slash n (for newline)
    cout << "With and endl instead!"<< endl; //endl : end line (same as \n)


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
