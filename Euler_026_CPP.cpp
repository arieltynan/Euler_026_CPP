// Euler_026_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    long long int x = 1;
    int n = 1000;
    int count = 0;

    
    vector<string> strings; // initial vector of 1/n from n = 1-1000 converted to strings
    vector<string> sCheck; // first sieve finding looping decimals 
    vector<string> sCheck2; // second sieve narrowing potential solutions
        // doing second sieve even though answer was found by looking through sCheck

    for (int i = 1; i < n - 1; i++)
    {
        strings.push_back(to_string(10000000000000000000 * x / i)); // decimals multiplied to long long int form, and into string
    }

    cout << "First check potential solutions: " << endl;
    for (string a : strings) // iterating through vector of all decimals 1-1000
    {
        int matches = 0;
        count++;
        for (int j = 0; j < 1; j++)
        {
            if (a[j] == a[j + 17]) //checks each digit with digit 10 places after
            {
                matches++;
            }
        }

        if (matches == 1) //checks for at least 7 consecutive recurring digits at 10 digits apart
        {
            sCheck.push_back(a);
            cout << count << ":  " << a << endl;
        }
    }
    cout << endl;

    cout << "Second check potential solutions: " << endl;
    for (string b : sCheck) //checking for loops divisible by 10: 1,2,5
    {
        int matches1 = 0, matches2 = 0, matches4 = 0, matches8 = 0;
        for (int j = 0; j < 10; j++)
        {
            if ((b[j] == b[j + 1]))
                matches1++;

            if ((b[j] == b[j + 2]))
                matches2++;

            if ((b[j] == b[j + 4]))
                matches4++;

            if ((b[j] == b[j + 8]))
                matches8++;
        }
        if (matches1 < 10 && matches2 < 7 && matches4 < 5 && matches8 < 5) //checks for at least 7 consecutive recurring digits at 10 digits apart
        {
            sCheck2.push_back(b);
            cout << b << endl;
        }
    } 
}
