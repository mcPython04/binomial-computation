# include <iostream>
# include <time.h>
# include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cin;

int divide_conquer_binomial(int n, int k);
int divide_conquer_dynamic(int n, int k);
double time_divide_conquer(int n, int k);


int main() {
	
	// output result and time for divide/conquer approach of binomial coefficient
	double s = time_divide_conquer(52, 5);	
	cout << "time for divide/conquer: " << s  << " nanoseconds" << endl;
	
	// output result and time for dynamic programming approach of binomial coefficienet
	int result = divide_conquer_dynamic(52, 5);
	cout << "result dynamic: " << result << endl;
	
	return 0;
}


// divide/conquer approach of binomial coefficient
int divide_conquer_binomial(int n, int k) {
	if (k == 0 || k == n) return 1;
	
	else return divide_conquer_binomial(n-1, k) + divide_conquer_binomial(n-1, k-1);
}


// dynamic programming approach of binomial coefficient
int divide_conquer_dynamic(int n, int k) {

	// create 2D table
	int arr[n+1][k+1];
	
	// filling out table with recurrence
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++) {
		
			if (j == 0 || j == i) {
				arr[i][j] = 1;
			}
			
			else if (j > i) {
				arr[i][j] = 0;
			}
			
			else {
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
	}
	
	// return binomial coefficient result
	return arr[n][k];	
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
