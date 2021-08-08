#include <bits/stdc++.h>
using namespace std;
class student
{
  string name;

public:
  int age;
  bool gender;

  student()
  {
    cout << "Default Constructor" << endl;
  }

  student(string s, int a, bool g)
  {
    cout << "Parameterised Constructor" << endl;
    name = s;
    age = a;
    gender = g;
  }

  student(student &a)
  {
    cout << "Copy Constructor" << endl;
    name = a.name;
    age = a.age;
    gender = a.gender;
  }

  ~student()
  {
    cout << "Destructor Called" << endl;
  }

  bool operator==(student &a)
  {
    if ((name == a.name) && (age == a.age) && (gender == a.gender))
      return true;
    else
      return false;
  }

  void setName(string s)
  {
    name = s;
  }
  void getName()
  {
    cout << name;
  }

  void printInfo()
  {
    cout << "Name :" << name << endl;
    cout << "Age :" << age << endl;
    cout << "Gender :" << gender << endl;
  }
};
int main()
{
  // student a[3];
  // for (int i = 0; i < 3; i++)
  // {
  //   string s;
  //   cout << "Name :";
  //   cin >> s;
  //   a[i].setName(s);
  //   cout << "Age :";
  //   cin >> a[i].age;
  //   cout << "Gender :";
  //   cin >> a[i].gender;
  // }
  // for (int i = 0; i < 3; i++)
  // {
  //   a[i].printInfo();
  // }

  student a("Mohit", 21, 0);
  // a.printInfo();
  student b;
  student c = a;
  if (c == a)
  {
    cout << "Same" << endl;
  }
  else
  {
    cout << "Not Same" << endl;
  }
  return 0;
}