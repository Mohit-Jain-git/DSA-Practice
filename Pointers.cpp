#include<iostream>
using namespace std;
// int main()
// { 
//     int arr[]={10,20,30};
//     cout<<*(arr)<<endl;
//     int *ptr = arr;
//     for(int i=0;i<3;i++)
//     { 
//         cout<<*(arr+i)<<endl;
//     }
// }
// void swap(int *a,int *b)
// { 
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// { 
//     int a=2,b=4;
//     swap(&a,&b);
//     cout<<a<<" "<<b<<endl;
//     return 0;
// }
void increment(int *a)
{ 
    ++*a;
}
int main()
{ 
   int a=2;
   increment(&a);
   cout<<a;
   return 0;
}