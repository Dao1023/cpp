#include <iostream>

using namespace std;

int main () {
	double m, h;
	cin >> m >> h;
	
	double s = m / h / h;
	if (s < 18.5) 				  { cout << "Underweight"; } 
	else if (s >= 18.5 && s < 24) { cout << "Normal"; } 
	else 						  { cout << s << endl << "Overweight"; } 
	
	return 0;
} 
