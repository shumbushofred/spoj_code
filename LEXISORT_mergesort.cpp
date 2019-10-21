
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list> 
using namespace std;


void merge(string arr[], int l, int m, int r)
{
	 int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    string L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
       if(L[i].compare(R[j]) <=0)
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void sort( string thear[], int l, int h)
{

	if( l < h)
	{
		int m = l + (h - l)/2;
		sort(thear, l, m);
		sort(thear, m + 1, h);
		merge(thear, l, m, h);
	}

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
 		sort(array, 0 ,n - 1);
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
