#include <iostream>

using namespace std;

int tweeIntOptellen(int number1, int number2){
	return number1 + number2;
}

int main() {
	int number1;
	int number2;

	cout<< "number 1 and 2 ";
	cin >> number1 >> number2;

	int result = tweeIntOptellen(number1, number2);
	
	cout << result << endl;
}
