#include <bits/stdc++.h>
using namespace std;
class Complex
{
  int real;
  int imag;

public:
  Complex(int r = 0, int i = 0)
  {
    real = r;
    imag = i;
  }
  Complex operator+(Complex const &obj)
  {
    Complex res;
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }
  void display()
  {
    cout << real << " + i" << imag;
  }
};
int main()
{
  Complex c1(2, 4);
  Complex c2(4, 8);
  Complex c3 = c1 + c2;
  c3.display();
  return 0;
}