#include <iostream>
using namespace std;

int main () {
	int y, m;
	cin >> y >> m;
	
	int leap = 0;
	if (y % 4 != 0) 				  {  }
	if (y % 100 == 0 && y % 400 != 0) {  }
									  { leap = 1; }
	
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) { cout << 31; return 0;}
	if (m == 4 || m == 6 || m == 9 || m == 11) { cout << 30; return 0;}
	if (m == 2 && leap) { cout << 29; return 0;}
									  
} 
