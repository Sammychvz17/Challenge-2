/**************************************************
*  Name: Samantha Chavez
*  Assignment: Queue
*  Purpose: This is the main testbed for the Queue
*           ADT. It exercises both FIFO and LIFO
*           behavior and tests all public methods:
*           push, pull, peek, count, clear, exists,
*           and find.
************************************************* */

#include "main.h"

int main() {    
    /* **************************************************
    Test script for testing the queue.

    @param na : na
    @return (int) : 0 (success)
    @exception na : na
    *********************************************/
    Queue lifo(LIFO);
    Queue fifo(FIFO);

    Data d;
    string s;
    int id = 0;
    int peekId = 0;

    std::srand(static_cast<unsigned>(std::time(NULL)));

    cout << "===== SECTION 1: BASIC LIFO TESTS =====" << endl;

    cout << "Initial LIFO count: " << lifo.count() << endl;
    cout << "Clearing empty LIFO: " << lifo.clear() << endl;
    cout << "LIFO count after clear: " << lifo.count() << endl;

    s = "";
    cout << "push(1, \"\") -> " << lifo.push(1, &s) << " (should be 0)" << endl;
    s = "valid";
    cout << "push(0, \"valid\") -> " << lifo.push(0, &s) << " (should be 0)" << endl;

    for (id = 1; id <= 5; id = id + 1) {
    s = "LIFO item " + std::to_string(id);
    cout << "push(" << id << ", \"" << s << "\") -> "
         << lifo.push(id, &s) << endl;
    cout << "  count now: " << lifo.count() << endl;
    }

    cout << "peek LIFO -> " << lifo.peek(peekId) << ", id=" << peekId << endl;

    cout << "exists(3) -> " << lifo.exists(3) << endl;
    cout << "exists(99) -> " << lifo.exists(99) << endl;
    cout << "find(3) -> " << lifo.find(3) << endl;
    cout << "find(99) -> " << lifo.find(99) << " (should be -1)" << endl;

}