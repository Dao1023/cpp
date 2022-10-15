#include <iostream>
#include <cstring>
 
using namespace std;

int hash[101];

int run(int n) {
    if (hash[n] != -1) return hash[n];
    else {
        int result = run(n-1) + run(n-2);
        hash[n] = result;
        return result;
    }
}

int fib(int n) {
    memset(hash, -1, sizeof(hash));
	hash[0] = 0;
    hash[1] = 1;
	return run(n);
}


int main () {
	for (int i = 0; i < 10; i++) {
		cout << fib(i) << endl;	
	}
	return 0;
} 
