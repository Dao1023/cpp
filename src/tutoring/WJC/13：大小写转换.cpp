#include <iostream>

using namespace std;

int main() {
	char s;
	cin >> s;

//	putchar(getchar()-'a'+'A');
	
//	s -= 'a' - 'A';
//	cout << s;

	s -= 32;
	cout << s; 

//	cout << (char) (s-32);
	
	return 0;
}
