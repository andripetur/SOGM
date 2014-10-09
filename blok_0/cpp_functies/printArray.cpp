#include <iostream>

using namespace std;

void printArray(string array[], int length) {

	for(int i=0; i < length; i++) {
	cout << i+1 << "  " << array[i] << endl;
	}
}


int main() {
	int length=5;
	string array[] ={"This", "is", "an", "array", "."};

	printArray(array,length);

	return 0;
}


	
