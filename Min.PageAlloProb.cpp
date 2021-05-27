#include<bits/stdc++.h>
using namespace std;
bool isPossible(int a[],int n,int m,int min)
{ 
    int studentsReq = 1,sum = 0;
    for(int i=0;i<n;i++)
    { 
        if(a[i]>min)
        { 
           return false;
        }
        if(sum+a[i]>min)
        { 
            studentsReq++;
            sum = a[i];

            if(studentsReq > m)
            return false;
        }
            else
            sum+=a[i];
    }
    return true;
}
int minAllopages(int a[],int n,int m)
{ 
    int sum=0;
    if(m>n)
    return -1;
    for(int i=0;i<n;i++)
    sum = sum + a[i];

    int start=0, end = sum , ans = INT_MAX;
    while(start<=end)
    { 
         int mid = (start+end)/2;
         if(isPossible(a,n,m,mid))
         { 
             ans = min(sum,ans);
             end = mid-1;
         }
         else
         { 
           start = mid+1;
         }
    }
}
int main()
{ 
   int n,m;
   cin>>n>>m;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   cout<<"Min. no. of Pages: "<<minAllopages(a,n,m);
   return 0;
}