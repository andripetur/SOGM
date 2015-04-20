#include <iostream>

using namespace std;

class Node
{
public:
    Node(long value);
    void insert(long value);
    void print();
private:
    long contents;
    Node* left;
    Node* right;
    long counter;
};

Node::Node(long value)
{
    contents = value;
    counter = 1;
}

void Node::insert(long value)
{
    if( value > contents) {
        if(right) right->insert(value);
        else {
            cout << "nieuwe tak R"<< endl;
            right = new Node(value);
        }
    }
    else
        if(value < contents) {
            if(left) left->insert(value);
            else {
                cout << "nieuwe tak L"<< endl;
                left = new Node(value);
            }
        }
    
    else ++counter;
} // insert

void Node::print()
{
    if(left) left->print();
    cout << contents << " counter: " << counter << endl;
    if(right) right->print();
} // print

int main ()
{
    Node* tree;
    
    tree = new Node(25);
    tree -> insert(45);
    tree -> insert(54);
    tree -> insert(7);
    tree -> insert(50);
    tree -> insert(50);
    tree -> insert(75);
    tree -> insert(15);
    tree -> insert(42);
    tree -> insert(50);
    tree ->print();
    return 0;
}


