# include <iostream>
# include <time.h>
# include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cin;

int divide_conquer_binomial(int n, int k);

int main() {
	
	int result = divide_conquer_binomial(52, 5);
	
	cout << result << endl;
	
	return 0;
}


int divide_conquer_binomial(int n, int k) {
	if (k == 0 || k == n) return 1;
	
	else return divide_conquer_binomial(n-1, k) + divide_conquer_binomial(n-1, k-1);
}
