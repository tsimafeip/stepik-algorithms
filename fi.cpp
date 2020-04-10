#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
	
	if (n <= 1)
		return n;
	
	int prev = 0; 
	int cur = 1;
	
	for (int i = 2; i <= n; i++){
        int new_cur = prev+cur;
		prev = cur;
		cur = new_cur;
    }
	
	return cur;
	
    // static std::vector<int> arr;
	// arr.resize(n+1);
    // arr[0] = 0;
    // arr[1] = 1;
    // for (int i = 2; i <= n; i++){
        // arr[i]=arr[i-1]+arr[i-2];
    // }
    // return arr[n];
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}