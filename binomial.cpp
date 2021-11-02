# include <iostream>
# include <time.h>
# include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cin;

int divide_conquer_binomial(int n, int k);
double time_divide_conquer(int n, int k);


int main() {
	
	// output result and time for divide/conquer approach of binomial coefficient
	double s = time_divide_conquer(3, 2);	
	cout << "time for divide/conquer: " << s  << " nanoseconds" << endl;
	
	return 0;
}


// divide/conquer approach of binomial coefficient
int divide_conquer_binomial(int n, int k) {
	if (k == 0 || k == n) return 1;
	
	else return divide_conquer_binomial(n-1, k) + divide_conquer_binomial(n-1, k-1);
}

// timing divide/conquer approach
double time_divide_conquer(int n, int k) {

	auto start = high_resolution_clock::now();
	
	int result = divide_conquer_binomial(n, k);
	cout << "result: " << result << endl;
	
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	
	double s = duration.count();
	
	return s;
}

