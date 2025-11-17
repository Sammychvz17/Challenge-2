/**************************************************
*  Name: Samantha Chavez
*  Assignment: Queue
*  Purpose: This is the implementation file for the
*           linked-list based queue ADT that can
*           operate in either FIFO or LIFO mode.
************************************************* */
#include "queue.h"


Queue::Queue(QueueType type) {
/* **************************************************
Constructor for Queue class.
Initializes the queue type and sets up the linked list.
@param : QueueType type
@return : void
* ************************************************* */
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    mode = type;
}

Queue::~Queue() {
/* **************************************************
Destructor for Queue class.
Cleans up all nodes in the linked list.
@param : none
@return : void
* ************************************************* */
    clear();
}

bool Queue::push(int id, string* information) {
/* **************************************************
This method adds a new item to the queue.
@param : int id, string* information
@return : bool added (true / false)
* ************************************************* */
    bool added = false;

    if (id > 0 && information != nullptr && !information->empty()) {
        Node* n = new Node;
        n->data.id = id;
        n->data.information = *information;
        n->prev = nullptr;
        n->next = head;

        if (head != nullptr) {
            head->prev = n;
        }

        head = n;

        if (tail == nullptr) {
            tail = n;
        }

        itemCount = itemCount + 1;
        added = true;
    }

    return added;
}

bool Queue::pull(Data* outData) {
/* **************************************************
This method removes an item from the queue based on the queue type (FIFO or LIFO).
@param : Data* outData
@return : bool pulled (true / false)
* ************************************************* */
    bool pulled = false;

    if (outData != nullptr && itemCount > 0) {
        Node* n = (mode == LIFO ? head : tail);

        outData->id = n->data.id;
        outData->information = n->data.information;

        if (n->prev != nullptr) {
            n->prev->next = n->next;
        } else {
            head = n->next;
        }

        if (n->next != nullptr) {
            n->next->prev = n->prev;
        } else {
            tail = n->prev;
        }

        delete n;
        itemCount = itemCount - 1;
        pulled = true;
    }

    if (!pulled && outData != nullptr) {
        outData->id = -1;
        outData->information.clear();
    }

    return pulled;
}

bool Queue::clear() {
/* **************************************************
This method clears all items from the queue.
@param : none
@return : bool cleared (true / false)
* ************************************************* */
    Node* n = head;
    Node* next = nullptr;

    while (n != nullptr) {
        next = n->next;
        delete n;
        n = next;
    }

    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    return true;
}

bool Queue::peek(int& id) const {
    bool found = false;
    id = -1;

    if (itemCount > 0) {
        Node* n = (mode == LIFO ? head : tail);
        if (n != nullptr) {
            id = n->data.id;
            found = true;
        }
    }

    return found;
}

