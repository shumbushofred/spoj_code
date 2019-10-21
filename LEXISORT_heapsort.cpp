
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list> 
using namespace std;



 void swap(string arr[], int ii, int jj)
{
    string temp = arr[ii];
    string tempt = arr[jj];
    arr[ii] = tempt;
    arr[jj] = temp;
}
void heap(string thear[], int j, int i)
{
  int left = 2 * i;
  int right = 2 * i + 1;

  int last = i;

 if (left < j && thear[last] < thear[left]) {
    last = left;
  }

  if (right < j && thear[last] < thear[right]) {
    last = right;
  }

  if (last != i) {
    swap(thear, last, i);
    heap(thear, j, last);
  }
}


void sort(string thear[], int l, int h)
{
  
  for (int i=(h/2); i>=0; --i) heap(thear, h, i );

  for (int i=h ; i > 0; --i) 
  {
    swap(thear,i, 0);
    heap(thear, i, 0);
  }
}


int main()
{
	int testcases = 0;
	cin >> testcases;
	list<string> thelist;
	for(int s = 0; s < testcases; s++)
	{
		int n = 0;
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
    //cout<<"output starts here"<<endl;
 	list <string> :: iterator it; 
 	for(it = thelist.begin(); it != thelist.end(); ++it) 
 	{
        cout << *it; 
 		cout << '\n'; 
	}
}
