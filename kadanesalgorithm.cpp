#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	 int n;
	 cin>>n;
	 int a[n];
	 int i;
	 for(i=0;i<n;i++)
	  cin>>a[i];
    int curr=a[0],maxt=a[0];
		for(i=1;i<n;i++)
		{ 
			 curr = max(a[i],curr+a[i]);
			 maxt = max(curr,maxt);
		}
		cout<<maxt<<endl;
		return 0;
}