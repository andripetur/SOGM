#include <iostream>

using namespace std;

int rotateArrayLeft(int array[],int length) {
//The rotate function overwrites the original array!
	
	for(int i = 0; i < length; i++) {
	  int ni = i-1;
          int temp;


	  if(ni < 0) {
	    ni = length-1;
	    temp = array[ni];
	  } 
        
          if(i == length-1){
  	    array[ni]= temp;
 	  } else {
	    array[ni]=array[i];
	    }
	  }
	
	return 0;
}

void printArray(int array[], int length) {
        cout << "{ ";

	for(int i = 0; i < length; i++) {
	  cout << array[i] << " ";
	  }
	cout << "}" << endl;

}

int main() {
	int length = 8;
	int myArray[] = {4, 6, 7, 75, 87, 22, 57, 42};

	cout << "The original array: " << endl;
	printArray(myArray, length);

	cout << "The rotated array: " << endl;
        rotateArrayLeft(myArray,length);
	printArray(myArray, length);
	

return 0;
}
	
	  

