# include <iostream>
# include <time.h>
# include <chrono>

#define M 3
#define N 2

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cin;

int divide_conquer_binomial(int n, int k);
int dynamic_binomial(int n, int k);
int binomial(int n, int k);
int memo_binomial(int n, int k, int **arr);
double time_divide_conquer(int n, int k);
double time_dynamic(int n, int k);
double time_memo(int n, int k);


int main() {
	
	// output result and time for divide/conquer approach of binomial coefficient
	double time = time_divide_conquer(52, 5);	
	cout << "time for divide/conquer: " << time  << " nanoseconds" << endl;
	
	// output result and time for dynamic programming approach of binomial coefficienet
	double time1 = time_dynamic(52, 5);
	cout << "time for dynamic: " << time1 << endl;
	
	int result = binomial(3, 2);
	cout << result << endl;
	
	return 0;
}


// divide/conquer approach of binomial coefficient
int divide_conquer_binomial(int n, int k) {
	if (k == 0 || k == n) return 1;
	
	else return divide_conquer_binomial(n-1, k) + divide_conquer_binomial(n-1, k-1);
}


// dynamic programming approach of binomial coefficient
int dynamic_binomial(int n, int k) {

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


int memo_binomial(int n, int k, int **arr){
	
	if (arr[n][k] == -1) {
		arr[n][k] = memo_binomial(n-1, k, arr) + memo_binomial(n-1, k-1,  arr);
	}
	
	return arr[n][k];
}


int binomial(int n, int k) {
	int **arr;
	arr = new int *[n];
	
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[k];
	}
	
	
	// filling out table with base case
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++) {
		
			if (j == 0 || j == i) {
				arr[i][j] = 1;
			}
			
			else {
				arr[i][j] = -1;
			}
		}
	}
	
	
	return memo_binomial(n, k, arr);
}


// timing divide/conquer approach
double time_divide_conquer(int n, int k) {

	auto start = high_resolution_clock::now();
	
	int result = divide_conquer_binomial(n, k);
	cout << "result (divide/conquer): " << result << endl;
	
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	
	double s = duration.count();
	
	return s;
}


// timing dynamic approach
double time_dynamic(int n, int k) {
	auto start = high_resolution_clock::now();
	
	int result = dynamic_binomial(n, k);
	cout << "result (dynamic): " << result << endl;
	
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	
	double s = duration.count();
	
	return s;
}
