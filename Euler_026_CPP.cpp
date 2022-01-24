// Euler_026_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> primes(int n)
{
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < n; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
            //cout << i << " ";
        }
    }
    return primes;
}

vector<int> fibbonaci(int n)
{
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    for (int i = 2; i < n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

int main()
{
    int arr[1000];
    int n = 1000;
    long double curr;
    int fibn = 16;

    //prime number genrator
    vector<int> primeList = primes(n);
    vector<int> fibList = fibbonaci(fibn);

    for (int i = 0; i < primeList.size(); i++)
    {
        //cout << primeList[i] << " ";
        curr = 1 /(primeList[i]*1.0);
        //cout << fixed << setprecision(16) << primeList[i] << ": " << curr << endl;
    }

    for (int i = 1; i < 32; i++)
    {
        //cout << primeList[i] << " ";
        curr = 1 / (pow(i,2) * 1.0);
        //cout << fixed << setprecision(16) << i*i << ": " << curr << endl;
    }

    for (int i = 1; i < 10; i++)
    {
        //cout << primeList[i] << " ";
        curr = 1 / (pow(2, i) * 1.0 + 1);
        //cout << fixed << setprecision(16) << pow(2,i) << ": " << curr << endl;
    }

    for (int i = 0; i < fibn; i++)
    {
        curr = 1 / (fibList[i] * 1.0 + 1);
        cout << fixed << setprecision(16) << fibList[i] << ": " << curr << endl;
    }

    //n = 289;
    //cout << fixed << setprecision(16) << n << ": " << 1/(n*1.0) << endl;

}
