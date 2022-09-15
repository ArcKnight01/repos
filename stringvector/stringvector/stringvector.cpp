// stringvector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findElement(vector<int> _vector, int element);
int findElement(vector<string> _vector, string element);

int main()
{   
   
    vector<string> stringVector;
    vector<string> listVector;
  //  stringVector = { "apple", "bannana", "orange" };
    vector<int> numbers;
   // int searched = 79;
  //  numbers.push_back(searched);
   // numbers.push_back(value);
   // numbers.pop_back(); //removes last number in vector
    //value++;
    //numbers.insert(numbers.begin() + 0, value);
   // numbers.push_back(value);
/*
    for (int element : numbers) {
        cout << element << endl;
    }

   int index = findElement(numbers, 79);
    cout << index << " is index" << endl;
    numbers.insert(numbers.begin() + index, 70);

    //int indx = findElement(stringVector, "red");
    
    for (int i = 0; i < numbers.size(); i++) {
        cout << "numbers[" << i << "]: " << numbers[i] << endl; //prints number at index i
    }
    */
    //cout << indx << " is index for " << stringVector[indx] << endl;
   // stringVector.push_back("kiwi");
    //stringVector.push_back("watermelon");
    
    bool accepted = false;
    int a = 1;
    while (!accepted) {
        string searched;
        cout << "enter item #" << a << ": ";
        cin >> searched;
        //cout << "," << endl;
        if (searched == "exit" || searched == "X" || searched == "x" || searched == "Exit" || searched == "EXIT") {
            accepted = true;
            break;
        }
        if (findElement(listVector, searched) == -1) {
            listVector.push_back(searched);
            a++;
        }
        else {
            cout << "the item " << searched << " already exists!" << endl;
        }
    }
    cout << "--" << endl;
    for (string element : listVector) {
        int indx = findElement(listVector, element);
        if (indx != -1) {
            cout << element << " is available item [" << indx << "]. " << endl;
        }
    }
    cout << "--" << endl;
    accepted = false;
    a = 1;
    while (!accepted) {
        string searched;
        cout << "enter wanted item #" << a << ": ";
        cin >> searched;
        //cout << "," << endl;
        if (searched == "exit" || searched == "X" || searched == "x" || searched == "Exit" || searched == "EXIT" ) {
            accepted = true;
            break;
        }
        if (findElement(stringVector, searched) == -1) {
            if (findElement(listVector, searched) != -1) {
                stringVector.push_back(searched);
                int e = findElement(listVector, searched);
                listVector.erase(listVector.begin() + e);
                a++;
            }
            else {
                cout << "this item isn't available." << endl;
            }
            
        }
        else {
            cout << "the item " << searched << " already exists!" << endl;
        }
    }
    cout << "--" << endl;
    for (string element : stringVector) {
        int indx = findElement(stringVector, element);
        if (indx != -1) {
            cout << element << " = wanted item [" << indx << "]. " << endl;
        }
        else {
            cout << "element doesn't exist";
        }
    }
    cout << "--" << endl;
    for (string element : listVector) {
        int indx = findElement(listVector, element);
        if (indx != -1) {
            cout << element << " is available item [" << indx << "]. " << endl;
        }
    }
    //now create object for each wanted item with string name, x & y pos, 

    // same as loop above but using iterators.
   // for (vector<string>::iterator it = stringVector.begin(); it < stringVector.end(); it++) {
   //    cout << *it << endl;
   // }
}
void removeElement(vector<string>  _vector, string element)
{
    for (int i = 0; i < _vector.size(); i++) {
        if ( _vector[i] == element) {
            _vector.erase(_vector.begin() + i);
            break;
        }
    }
}
 int findElement(vector<int>  _vector, int element)
{
    for (int i = 0; i < _vector.size(); i++) {
        if (_vector[i] == element) {
            //_vector.erase(_vector.begin() + i);
            return (i);
            break;
        }
    }
}
 
int findElement(vector<string>  _vector, string element)
 {  
    int elementIndex;
    int elementExists = false;
    int numberOfElements = 0;
     for (int i = 0; i < _vector.size(); i++) {
         if (_vector[i] == element) {
            if(!elementExists){ 
                elementIndex = i; 
                numberOfElements = 1;
            }
            else {
                numberOfElements++;
            }
             elementExists = true;
         }
     }
     if (elementExists) {
         return elementIndex;
     }
     else {
        // cout << "element " << element  << " doesn't exist in vector!" << endl;
         return -1;
     }
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
