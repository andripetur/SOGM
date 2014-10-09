#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>



using namespace std;

void printArray(string array[], int length) {

	for(int i=0; i < length; i++) {
	cout << i+1 << "  " << array[i] << endl;
	}
}


void stringToArray(string sInput,string daArray[], int length){

	int i = 0;
	stringstream ssin(sInput);
	while (ssin.good() && i < length){
		ssin >> daArray[i];
		++i;
	}
}


/*
void stringToArray(char* str,string array[], int length){

	const char* ptr = str;
	for(int i = 0; i < length; i++){
   	array[i] = ptr;
  	 ptr += strlen(ptr)+1;
	}
}
*/
	

int main() {
	int length;
	string input; 
	
	cout << "The length of the array: ";
	cin >> length;

	string *array = new string[length];

	cout << "The array: ";
	cin >> input;

	stringToArray(input, array, length);

	printArray(array,length);

	return 0;
}


/*
int main() {
	int length=5;
	string array[] ={"This", "is", "an", "array", "."};

	printArray(array,length);

	return 0;
}

*/	
	
