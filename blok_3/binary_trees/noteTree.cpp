#include <iostream>
#include <string>

using namespace std;

class Note
{
public:
    Note(long timeStamp, char note);
    void insert(Note* note);
    void print();
    
private:
    // content of note
    long timeStamp;
    string notes;
    
    // Pointers to branches
    Note* left;
    Note* right;
    
    // Operator overloading
    bool operator> (Note b) {
        return (timeStamp > b.timeStamp);
    }
    
    bool operator< (Note b) {
        return (timeStamp < b.timeStamp);
    }
};

Note::Note(long timeStamp, char note)
{
    this->timeStamp = timeStamp;
    notes.append(&note);
}

void Note::insert(Note* note)
{
    if( *note > *this) {                // if new note t is higher than current notes t.
        if(right) right->insert(note);  // if there is a right branch, call that notes insert function
        else {                          // else make new note the right branch.
            cout << "new branch R"<< endl;
            right = note;
        }
    }
    else
        if(*note < *this) {
            if(left) left->insert(note);
            else {
                cout << "new branch L"<< endl;
                left = note;
            }
        }
    
        else {                          // if new note has the same t current note, add new note to note string
            cout << "added "<< note->notes << " at t:"<< timeStamp << endl;
            notes.append(note->notes);
        }
} // insert

// A recursive print function, first prints left note, then current note, and at last right note.
void Note::print()
{
    if(left) left->print();
    cout << timeStamp <<","<< notes <<  endl;
    if(right) right->print();
} // print

int main ()
{
    Note* tree;
    
    tree = new Note(3, 'C');
    tree-> insert(new Note(5, 'D'));
    tree-> insert(new Note(1, 'E'));
    tree-> insert(new Note(10, 'F'));
    tree-> insert(new Note(2, 'G'));
    tree-> insert(new Note(6, 'D'));
    tree-> insert(new Note(3, 'E'));
    tree-> insert(new Note(8, 'F'));
    tree-> insert(new Note(4, 'G'));
    
    tree-> insert(new Note(6, 'C'));
    tree-> insert(new Note(2, 'F'));
    tree-> insert(new Note(9, 'G'));
    tree-> insert(new Note(3, 'A'));
    tree-> insert(new Note(3, 'D'));
    tree-> insert(new Note(7, 'B'));
    tree-> insert(new Note(8, 'F'));
    tree-> insert(new Note(5, 'D'));
    cout<<endl;
    
    tree-> print();
    return 0;
}


