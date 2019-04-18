/*
 This software provides two functions that

 1) finds the greatest common divisor between two numbers.
 int gcd(int a, int b) // returns gcd(a,b)

 2) It computes the inverse element:
 int inverse(int a, int m) // it returns b such that ab=1(mod m)
*/

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

mpz_class gcd(mpz_class a, mpz_class b)
{
  
  if (a == 0)
        return b;
    return gcd(b%a, a);
}

mpz_class extendedEuclidean(mpz_class a, mpz_class b, mpz_class *x, mpz_class *y)
{
  if (a == 0)
  {
    *x = 0;
    *y = 1;
    return b;
  }

  mpz_class xStore;
  mpz_class yStore;

  mpz_class d = extendedEuclidean(b%a, a, &xStore, &yStore);

  *x = yStore - (b/a) * xStore;
  *y = xStore;

  return d;
}

mpz_class inverse(mpz_class a, mpz_class m)
{
  mpz_class x;
  mpz_class y;
  mpz_class residue;

  mpz_class recur = extendedEuclidean(a, m, &x, &y);

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

  cout << "The gcd(3,5) is: " << gcd(3,5) << endl;
  cout << "The gcd(5,3) is: " << gcd(5,3) << endl;
  
  cout << "The gcd(13234, 2345) is: " << gcd(13234, 2345) << endl;
  cout << "The gcd(2345, 13234) is: " << gcd(2345, 13234) << endl;
  cout << endl;

  long a, b, c, d;
  a = 32320;
  b = 5464432;
  c = 54564231;
  d = (a+b)*c;

  cout << "The value is: " << d << endl;
  cout << endl;

  
  cout << "The gcd(54564231, 299926045877712) is: " << gcd(c, d) << endl;

  long huge, big;

  huge = 123213543526875461;
  big = 654652315323;

  cout << "The gcd(123213543526875462, 654652308) is: " << gcd(huge, big) << endl;


  return 0;
}
