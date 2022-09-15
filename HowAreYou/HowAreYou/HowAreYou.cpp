// HowAreYou.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void howAreYou();

int main()
{
    howAreYou();
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

void howAreYou()
{
    string emotion, text;
    cout << "How are you?" << endl;
    cin >> emotion;
    text = (emotion == "happy" || emotion == "good") ? "Im glad you are happy" :
        (emotion == "sad") ? "aww I'm sorry" :
        (emotion == "excited") ? "cool!" :
        (emotion == "mad" || emotion == "angry") ? "what are you mad about?" :
        (emotion == "tired" || emotion == "exausted") ? "why are you so tired?" :
        "Why do you feel that way?";
    cout << text << endl;
    /*  if (emotion == "excited")
        cout << "Cool" << endl;
    else if (emotion == "sad")
        cout << "Aww im sorry" << endl;
    else if (emotion == "happy")
        cout << "Good for you" << endl;
    else if (emotion == "mad")
        cout << "Why are u mad?" << endl;
    else if (emotion == "tired")
        cout << "Why are u tired?" << endl;
    else
        cout << "Why are u " << emotion << endl; */
}
