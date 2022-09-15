// Conditionals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{ 
	string day;
	cout << "What day is it?" << endl;
	cin >> day;

	if (day == "Monday") {
		cout << "Its going to be sunny with a chance of rain." << endl;
	}
	else if (day == "Wednesday" || "Saturday") {
		cout << "Expect thunderstorms." << endl;
	}
	else if (day == "Tuesday" || "Friday") {
		cout << "Cloudy with chance of rain." << endl;
	}
	else if (day == "Thursday") {
		cout << "Its going to be an overcast day today." << endl;
	}
	else if (day == "Sunday") {
		cout << "Sunny all day long today." << endl;
	}
	//terniary operator: 
	//var = (/*condition*/) ? /*valueIfTrue*/ : /*valueIfFalse*/;

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
