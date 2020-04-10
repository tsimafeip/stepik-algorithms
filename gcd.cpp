#include <iostream>

int gcd(int a, int b) {
  if (a==0)
      return b;
  else if(b==0)
      return a;
  else if(a>=b)
      return gcd(a%b, b);
  else
      return gcd(a, b%a);
}

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}