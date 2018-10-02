/*
 This software provides two functions that

 1) finds the greatest common divisor between two numbers.
 int gcd(int a, int b) // returns gcd(a,b)

 2) It computes the inverse element:
 int inverse(int a, int m) // it returns b such that ab=1(mod m)
*/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
  if (a == 0)
        return b;
    return gcd(b%a, a);
}

int extendedEuclidean(int a, int b, int *x, int *y)
{
  if (a == 0)
  {
    *x = 0;
    *y = 1;
    return b;
  }

  int xStore;
  int yStore;

  int d = extendedEuclidean(b%a, a, &xStore, &yStore);

  *x = yStore - (b/a) * xStore;
  *y = xStore;

  return d;
}

int inverse(int a, int m)
{
  int x;
  int y;
  int residue;

  int recur = extendedEuclidean(a, m, &x, &y);

  if (recur != 1)
  {
    cout << "Inverse doesn't exist" << endl;
    return 0;
  }
  else
  {
    residue = (x%m + m) % m;
  }
  return residue;
}


int main()
{

  cout << "For question 1, d = " << inverse(5,24) << endl;
  cout << "For question 2, d = " << inverse(31, 3599) << endl;

  cout << "The gcd(3,5) is: " << gcd(3,15) << endl;
  cout << "The gcd(27, 7) is: " << gcd(27,7) << endl;
  cout << "The gcd(13234, 2345) is: " << gcd(13234, 2345) << endl;


  return 0;
}
