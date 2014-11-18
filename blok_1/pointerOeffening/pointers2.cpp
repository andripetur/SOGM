#include <iostream>

using namespace std;

void processVariable(unsigned long *pointerToVariable)
{
    *pointerToVariable *= 3;
}

unsigned long processVariable(unsigned long variable)
{
    variable *= 0.5;
    return variable;
}


int main()
{
    unsigned long iAmAVariable = 666;
    unsigned long *iAmAPointerToAVariable;
    
    // Assign the adress of the variable to the pointer
    iAmAPointerToAVariable = &iAmAVariable;
    
    // Print the value of variable(through variable and pointer).
    // And the adress of variable(stored in pointer).
    cout << "// Variable intial value  - - - - - " << endl;
    
    cout << "iAmAVariable value: " << iAmAVariable << endl;
    cout << "iAmAPointerToAVariable value: " << *iAmAPointerToAVariable << endl << endl;
//    cout << "iAmAPointerToAVariable adress: " << (unsigned long) iAmAPointerToAVariable << endl;

    
    //Give the variable a new value through pointer
    cout << "// Give a variable a new value through pointer - - - - - " << endl;
    *iAmAPointerToAVariable = 291412;
    
    //Print new value to console (from variable)
    cout << "iAmAVariable value: " << iAmAVariable << endl;
    //and from pointer
    cout << "iAmAPointerToAVariable value: " << *iAmAPointerToAVariable << endl << endl;
    
    cout << "// Give a variable to a function - - - - - " << endl;
    //Give a variable to a function the old fashioned way we all know and love.
    iAmAVariable = processVariable(iAmAVariable);
    cout << "iAmAVariable value: " << iAmAVariable << endl << endl;
    
    cout << "// Give a pointer to a function - - - - - " << endl;
    //Give a variable a new value, by passing it in to a function via a pointer.
    processVariable(iAmAPointerToAVariable);
    cout << "iAmAVariable value: " << iAmAVariable << endl << endl;
    
    cout << "// Give adress to a function - - - - - " << endl;
    //Give another variable a new value, by giving it's adress(point) to the function.
    unsigned long iAmAAnotherVariable = 777;
    processVariable(&iAmAAnotherVariable);
    cout << "iAmAnotherVariable value: " << iAmAAnotherVariable << endl << endl;
    
    
}// main()
