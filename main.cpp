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
*   This function is the application driver. It uses
*    and tests the functions of the Queue class.
*
*    @param na : na
*    @return (int) : 0 (success)
*    @exception na : na
*********************************************/

    cout << "Seeding random number generator..." << endl;
    srand(time(NULL));
    cout << "Random seed set." << endl << endl;

    cout << "creating LIFO queue...";
    Queue lifo(LIFO);
    cout << "done" << endl;

    cout << "creating FIFO queue...";
    Queue fifo(FIFO);
    cout << "done" << endl << endl;

    Data data;
    string info;
    int id = 0;
    int peekId = 0;
    int i = 0;
    int method = 0;

    cout << "===== BASIC LIFO TESTS =====" << endl << endl;

    cout << "checking LIFO queue..." << endl;
    cout << "\tThere are " << lifo.count() << " items." << endl << endl;

    cout << "clearing empty LIFO..." << endl;
    if (lifo.clear()) {
        cout << "\tsuccess" << endl;
    } else {
        cout << "\tfailed" << endl;
    }
    cout << "LIFO count after clear: " << lifo.count() << endl << endl;

    cout << "testing invalid pushes to LIFO..." << endl;

    info.clear();
    cout << "  push(1, \"\")... ";
    if (lifo.push(1, &info)) {
        cout << "success " << endl;
    } else {
        cout << "failed " << endl;
    }

    info = "valid";
    cout << "  push(0, \"valid\")... ";
    if (lifo.push(0, &info)) {
        cout << "success " << endl;
    } else {
        cout << "failed " << endl;
    }

    cout << "LIFO count: " << lifo.count() << endl << endl;

    cout << "adding LIFO test items (first set)..." << endl;
    id = 1;
    while (id <= 3) {
        info = "LIFO item A" + to_string(id);
        cout << "  adding " << id << ": " << info << "... ";
        if (lifo.push(id, &info)) {
            cout << "success";
        } else {
            cout << "failed";
        }
        cout << " (count = " << lifo.count() << ")" << endl;
        id = id + 1;
    }
    cout << endl;

    cout << "testing LIFO clear on non-empty queue..." << endl;
    if (lifo.clear()) {
        cout << "\tsuccess" << endl;
    } else {
        cout << "\tfailed" << endl;
    }
    cout << "LIFO count after clear: " << lifo.count() << endl << endl;

    cout << "adding LIFO test items (second set)..." << endl;
    id = 1;
    while (id <= 5) {
        info = "LIFO item " + to_string(id);
        cout << "  adding " << id << ": " << info << "... ";
        if (lifo.push(id, &info)) {
            cout << "success";
        } else {
            cout << "failed";
        }
        cout << " (count = " << lifo.count() << ")" << endl;
        id = id + 1;
    }
    cout << endl;

    cout << "testing LIFO peek..." << endl;
    peekId = -1;
    if (lifo.peek(peekId)) {
        cout << "  peek successful, id = " << peekId << endl;
    } else {
        cout << "  peek failed, queue empty, id = " << peekId << endl;
    }
    cout << endl;

    cout << "testing LIFO exists/find..." << endl;

    cout << "  exists(3) -> ";
    if (lifo.exists(3)) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    cout << "  exists(99) -> ";
    if (lifo.exists(99)) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    cout << "  find(3) -> position " << lifo.find(3) << endl;
    cout << "  find(99) -> position " << lifo.find(99)<< endl;


    cout << "pulling all items from LIFO..." << endl;
    while (lifo.count() > 0) {
        lifo.pull(&data);
        cout << "  pulled: id=" << data.id
             << ", info=\"" << data.information << "\""
             << ", count now=" << lifo.count() << endl;
    }
    cout << endl;

    cout << "testing LIFO operations on empty queue..." << endl;

    data.id = 123;
    data.information = "not empty";
    lifo.pull(&data);
    cout << "  pull on empty -> id=" << data.id
         << ", info=\"" << data.information << "\"" << endl;

    peekId = 123;
    lifo.peek(peekId);
    cout << "  peek on empty -> id=" << peekId << endl << endl;

    cout << "===== BASIC FIFO TESTS =====" << endl << endl;

    cout << "checking FIFO queue..." << endl;
    cout << "\tThere are " << fifo.count() << " items." << endl << endl;

    cout << "clearing empty FIFO..." << endl;
    if (fifo.clear()) {
        cout << "\tsuccess" << endl;
    } else {
        cout << "\tfailed" << endl;
    }
    cout << "FIFO count after clear: " << fifo.count() << endl << endl;
    cout << "adding FIFO test items (first set)..." << endl;
    id = 1;
    while (id <= 3) {
        info = "FIFO item A" + to_string(id);
        cout << "  adding " << id << ": " << info << "... ";
        if (fifo.push(id, &info)) {
            cout << "success";
        } else {
            cout << "failed";
        }
        cout << " (count = " << fifo.count() << ")" << endl;
        id = id + 1;
    }
    cout << endl;

    cout << "testing FIFO clear on non-empty queue..." << endl;
    if (fifo.clear()) {
        cout << "\tsuccess" << endl;
    } else {
        cout << "\tfailed" << endl;
    }
    cout << "FIFO count after clear: " << fifo.count() << endl << endl;

    cout << "adding FIFO test items (second set)..." << endl;
    id = 1;
    while (id <= 5) {
        info = "FIFO item " + to_string(id);
        cout << "  adding " << id << ": " << info << "... ";
        if (fifo.push(id, &info)) {
            cout << "success";
        } else {
            cout << "failed";
        }
        cout << " (count = " << fifo.count() << ")" << endl;
        id = id + 1;
    }
    cout << endl;

    cout << "testing FIFO peek..." << endl;
    peekId = -1;
    if (fifo.peek(peekId)) {
        cout << "  peek successful, id = " << peekId << endl;
    } else {
        cout << "  peek failed, queue empty, id = " << peekId << endl;
    }
    cout << endl;

    cout << "testing FIFO exists/find..." << endl;

    cout << "  exists(2) -> ";
    if (fifo.exists(2)) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    cout << "  exists(99) -> ";
    if (fifo.exists(99)) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    cout << "  find(2) -> position " << fifo.find(2) << endl;
    cout << "  find(99) -> position " << fifo.find(99)
         << " (should be -1)" << endl << endl;

    cout << "pulling all items from FIFO..." << endl;
    while (fifo.count() > 0) {
        fifo.pull(&data);
        cout << "  pulled: id=" << data.id
             << ", info=\"" << data.information << "\""
             << ", count now=" << fifo.count() << endl;
    }
    cout << endl;

    cout << "===== RANDOM LIFO STRESS TEST =====" << endl << endl;

    cout << "starting random LIFO test with count = "
         << lifo.count() << endl << endl;

    for (i = 0; i < 60; i = i + 1) {
        method = rand() % 5; 

        if (method == 0) {
            id = (rand() % 20) + 1;
            info = "rand LIFO " + to_string(id);
            cout << "[LIFO] push(" << id << ", \"" << info << "\")... ";
            if (lifo.push(id, &info)) {
                cout << "success";
            } else {
                cout << "failed";
            }
            cout << " (count = " << lifo.count() << ")" << endl;
        } else if (method == 1) {
            lifo.pull(&data);
            cout << "[LIFO] pull -> id=" << data.id
                 << ", info=\"" << data.information << "\""
                 << ", count=" << lifo.count() << endl;
        } else if (method == 2) {
            lifo.peek(peekId);
            cout << "[LIFO] peek -> id=" << peekId
                 << ", count=" << lifo.count() << endl;
        } else if (method == 3) {
            id = (rand() % 20) + 1;
            cout << "[LIFO] exists(" << id << ") -> ";
            if (lifo.exists(id)) {
                cout << "found";
            } else {
                cout << "not found";
            }
            cout << endl;
        } else {
            id = (rand() % 20) + 1;
            cout << "[LIFO] find(" << id << ") -> "
                 << lifo.find(id) << endl;
        }
    }

    cout << endl;
    cout << "Final LIFO count after random test: "
         << lifo.count() << endl << endl;

    cout << "===== RANDOM FIFO STRESS TEST =====" << endl << endl;

    cout << "clearing FIFO before random test..." << endl;
    if (fifo.clear()) {
        cout << "\tsuccess" << endl;
    } else {
        cout << "\tfailed" << endl;
    }
    cout << "starting random FIFO test with count = "
         << fifo.count() << endl << endl;

    for (i = 0; i < 60; i = i + 1) {
        method = rand() % 5; 

        if (method == 0) {
            id = (rand() % 20) + 1;
            info = "rand FIFO " + to_string(id);
            cout << "[FIFO] push(" << id << ", \"" << info << "\")... ";
            if (fifo.push(id, &info)) {
                cout << "success";
            } else {
                cout << "failed";
            }
            cout << " (count = " << fifo.count() << ")" << endl;
        } else if (method == 1) {
            fifo.pull(&data);
            cout << "[FIFO] pull -> id=" << data.id
                 << ", info=\"" << data.information << "\""
                 << ", count=" << fifo.count() << endl;
        } else if (method == 2) {
            fifo.peek(peekId);
            cout << "[FIFO] peek -> id=" << peekId
                 << ", count=" << fifo.count() << endl;
        } else if (method == 3) {
            id = (rand() % 20) + 1;
            cout << "[FIFO] exists(" << id << ") -> ";
            if (fifo.exists(id)) {
                cout << "found";
            } else {
                cout << "not found";
            }
            cout << endl;
        } else {
            id = (rand() % 20) + 1;
            cout << "[FIFO] find(" << id << ") -> "
                 << fifo.find(id) << endl;
        }
    }

    cout << endl;
    cout << "Final FIFO count after random test: "
         << fifo.count() << endl << endl;

    return 0;

}