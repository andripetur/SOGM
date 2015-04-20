#include <iostream>
class Event;
typedef Event* EventPtr;

static long number = 0;
using namespace std;

class Event
{
    long number;
    long ID;
    long time;
    EventPtr next, prev;
    
public:
    Event(long time) {
        ID = number++;
        next = prev = NULL;
        this -> time = time;
    }
    
    EventPtr insert(EventPtr ev) {
        EventPtr temp = next;
        next = ev;
        ev->prev = this;
        ev->next  = temp;
        if(temp) temp->prev = ev;
        return ev;
    }
    
    void show() {
        cout << "ID: " << ID << endl;
        cout << "time: " << time << endl;
    }
    
    void setNext(Event* ep) {
        this->next = ep;
    }
    
    void setPrew(Event* ep) {
        this->prev = ep;
    }
};



int main()
{
    Event firstEvent(100);
    Event secondEvent(200);
    
    firstEvent.show();
    secondEvent.show();
    
    Event inbetween(150);
    
    firstEvent.insert(&inbetween);
    
    firstEvent.show();
    inbetween.show();
    secondEvent.show();
    
    
    return 0;
}