#include <iostream>

using namespace std;


int main()
{
    char letter = 97;
    char *letterpointer;
    
    cout << "// Oeffening 1 Voorbeeld " << endl;
    cout << "Inhoud van de variabele letter: ";
    cout << letter << endl;
    
    letterpointer = &letter;
    cout << "Inhoud van de pointer letterpointer: ";
    cout << (unsigned long) letterpointer << endl;
    
    cout << "Inhoud van waar de pointer letterpointer naar wijst: ";
    cout << *letterpointer << endl;
    
    *letterpointer = 'b';
    cout << "De variabele letter heeft via letterpointer een nieuwe waarde gekregen: ";
    cout << *letterpointer << endl;
    
    cout << "Inhoud van de variabele letter: ";
    cout << letter << endl << endl;
    
    // OEFENINGEN
    unsigned short year = 2013;
    unsigned short *yearpointer;
    
    cout << "// Oeffening 1.1 " << endl;
    cout << "Inhoud van de variabele year: ";
    cout << year << endl;
    
    yearpointer = &year;
    cout << "Inhoud van de pointer yearpointer: ";
    cout << (unsigned long) yearpointer << endl;
    
    cout << "Inhoud van waar de pointer yearpointer naar wijst: ";
    cout << *yearpointer << endl;
    
    // geef year via de pointer een nieuwe waarde
    *yearpointer = 4022;
    cout << "Inhoud van de variabele year: ";
    cout << year << endl << endl;
    
    
    // maak nog een pointer genaamd anotheryearpointer en laat deze ook naar
    // year wijzen
    unsigned short *anotheryearpointer = yearpointer;
    
    cout << "// Oeffening 1.2 " << endl;
    cout << "Inhoud van de pointer anotheryearpointer: ";
    cout << (unsigned long) anotheryearpointer << endl;
    
    cout << "Inhoud van waar de pointer anotheryearpointer naar wijst: ";
    cout << *anotheryearpointer << endl;
    
    // geef year via de pointer een nieuwe waarde
    
    *anotheryearpointer = 900;
    cout << "Inhoud van de variabele year: ";
    cout << year << endl;
    
    cout << "Inhoud van waar de pointer yearpointer naar wijst: ";
    cout << *yearpointer << endl << endl;
    
    
} // main()
