#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   int n;
   cin>>n;
   int arr[n];
   int i;
   for(i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    int k;
    cin>>k;
    cout<<arr[k-1]<<endl;
    return 0;
}