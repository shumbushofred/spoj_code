#include <iostream>
#include <stdio.h>
//#include <int.h>
#include <stdlib.h>
#include <list> 
#include<climits>
#define ll long long int
using namespace std;




bool can(int mid,int arr[], int n, int k)
 {
  int tmpK = k;
  
  for(int i = 0 ; i < n; i++) {
    tmpK -= (arr[i]/mid);
    
  }
  if(tmpK <= 0) return true;
   return false;
}

int binarysearch(int array[], int low, int high, int n, int k)
{
   int l = 1;
   int r = 1000000000;
   int res = 0;
    int mid = 0;

 while(l <= r) {
      mid = (l + r) / 2;
      
      if(can(mid, array, n, k)) {
        res = res < mid ? mid : res;
        l = mid + 1;
      } else
        r = mid - 1;
    }

//cout <<"the r is "<<res<<endl;
return res;
}




int main()
{
    int testcases = 0;
    cin >> testcases;
    
    list<int> thelist;
    for(int s = 0; s < testcases; s++)
    {
        int N = 0;
        int K = 0;

        cin >> N >> K;
        
        int array[N];
        for(int i = 0; i < N; i++)
        {
            cin >> array[i];
        }
        int yo = 0;
      // quickSort(array, 0 ,N - 1);
        int R = 0;
       R = binarysearch(array, 0 ,N - 1, N, K);
       
        
       // cout<< "rrrrr"<<R<<endl;
            thelist.push_back(R);
        
    }
    list <int> :: iterator it; 
    for(it = thelist.begin(); it != thelist.end(); ++it) 
    {
        cout << *it; 
        cout << '\n'; 
    }
}
