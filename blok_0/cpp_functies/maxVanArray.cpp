#include <iostream>

using namespace std;

int maxVanArray(int array[], int length){
	int deMax=0;

	for(int i=0; i < length; i++){
	  if(array[i] > deMax){
	  deMax=array[i];
	  }	
	}

return deMax;

}

void printArray(int array[], int length) {
	cout << "The Array: " << endl;
        cout << "{ ";

	  for(int i = 0; i < length; i++) {
	  cout << array[i] << " ";
	  }
	cout << "}" << endl;

}


int main(){
	int length = 8;
	int myArray[] = {4, 6, 7, 75, 87, 22, 57, 4};
	
	printArray(myArray, length);
	cout << "Max value of the array: " <<maxVanArray(myArray,length) << endl;

return 0;

}
