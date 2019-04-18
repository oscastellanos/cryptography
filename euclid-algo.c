/*
 This software provides two functions that

 1) finds the greatest common divisor between two numbers.
 int gcd(int a, int b) // returns gcd(a,b)

 2) It computes the inverse element:
 int inverse(int a, int m) // it returns b such that ab=1(mod m)
*/

#include <stdio.h>
#include <gmp.h>

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

  printf("For question 1, d = %d\n", inverse(5,24))
  


  return 0;
}
