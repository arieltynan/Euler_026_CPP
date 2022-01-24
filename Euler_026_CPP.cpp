// Euler_026_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Solved 24 January 2022

// Attempt Three with number theory:
// Take a number in denominator, n
// Remove all factors of 2 and 5
// Find shortest number of "9"s that is divisible by result
// Number of 9s is equal to length of repeating decimal

#include <iostream>
#include <string>

using namespace std;

// Function to find modulus of long numbers in string form
int modLong(string num, int mod)
{
    int rem = 0; // remainder
    for (int i = 0; i < num.length(); i++)
        rem = (rem * 10 + (int)num[i] - '0') % mod;

    return rem;
}

int main()
{
    int ans = 0; // Denom that causes max repeating dec
    int maxRep = 0; //max number of 9s (repeating decimals)
    for (int i = 1; i < 1001; i++)
    {
        int check = 0; // checks if solution found for i
        int count = 0; // checks how many 9s taken to divide i

        if (i % 2 != 0 && i % 5 != 0) // denom will not be divisible by 2 or 5
        {
            //long long int nines = 0;
            string nines;
            string nine = "9";
            while (check == 0)
            {
                nines = nines + nine; //adding a 9 for each loop
                count++; 
               
                if (modLong(nines,i) == 0)
                {
                    if (count > maxRep)
                    {
                        maxRep = count;
                        ans = i;
                    }     

                    check = 1; // ends loop of modulus
                }
            } // end while checking for mod
        } // end of if, each number i not div by 2 or 5
    } // end of for loop, for each number i 

    cout << ans << ": " << maxRep << endl;




}
