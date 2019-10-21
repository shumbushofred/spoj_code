
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list> 
using namespace std;


void quickSort(string array[], int low, int high)
{
    int i = low;
    int j = high;
    string pivot = array[(i + j) / 2];
    string temp;

    while (i <= j)
    {
        while (array[i].compare(pivot) < 0)
            i++;
        while (array[j].compare(pivot) > 0)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main()
{
    int testcases = 0;
    cin >> testcases;
    list<string> thelist;
    for(int s = 0; s < testcases; s++)
    {
        int n;
        cin >>n;
        string array[n];
        for(int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        quickSort(array, 0 ,n - 1);
        for(int i =0; i <n; i++)
        {
            thelist.push_back(array[i]);
        }
    }
    list <string> :: iterator it; 
    for(it = thelist.begin(); it != thelist.end(); ++it) 
    {
        cout << *it; 
        cout << '\n'; 
    }
}
