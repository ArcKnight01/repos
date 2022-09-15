// screentime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    double screentime[7];
    double sum = 0;
    double avg;
    for (int i = 0; i < 7; i++) {
        cout << "How many hours of screen time did you have on day " << (i+1) << "?" << endl;
        cin >> screentime[i];
        sum += screentime[i];
        cout << "Total screentime so far is: " << sum << endl;
    }
    avg = sum / 7;
    cout << sum << " hours of screen time total this week." << endl;
    cout << avg << "hours of screen time per day on average." << endl;
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
