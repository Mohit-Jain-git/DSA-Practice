#include<bits/stdc++.h>
using namespace std;
int findPeak(int a[],int low,int high,int n)
{ 
    int mid = low + (high-low)/2;
    if((mid==0 || a[mid]>=a[mid-1]) && (mid==n-1 || a[mid]>=a[mid+1]))
    return mid;
    else
    { 
       if(mid>0 && a[mid]<a[mid-1])
        return findPeak(a,low,mid-1,n);
       else 
       return findPeak(a,mid+1,high,n); 
    }
}
int main()
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    cout<<endl;
    cout<<"Peak Element index is: "<<findPeak(a,0,n-1,n);
    return 0;
}