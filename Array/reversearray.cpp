#include<bits/stdc++.h>
using namespace std;
string reverseWord(string str);
int main()
{ 
   int t;
   cin>>t;
   while(t--)
   { 
      string s;
      cin>>s;
      cout<<reverseWord(s)<<endl;
   }
   return 0;
}
string reverseWord(string str){
    
    int i=0;
    int length = str.length();
    int j=length-1;
    while(i<j)
    { 
         swap(str[i],str[j]);
         i++;
         j--;
    }
    return str;
}