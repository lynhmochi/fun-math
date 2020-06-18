#include <stdio.h>
#include <stdlib.h>

void egcd(int a, int b){
  int q, r, m, n;
  int gcd1 = a, gcd2 = b, x = 0, y = 1, u = 1, v = 0;
  while (gcd1 != 0){
    q = gcd2 / gcd1, r = gcd2 % gcd1;
    m = x - u * q, n = y - v * q;
    gcd2 = gcd1, gcd1 = r, x = u, y = v, u = m, v = n;
  }
  printf("(%d)(%d) + (%d)(%d) = %d", x, a, y, b, gcd2);
}

int main(int argc, char const *argv[]){
  char *p;
  int a = strtol(argv[1], &p, 10);
  int b = strtol(argv[2], &p, 10);
  egcd(a,b);
}