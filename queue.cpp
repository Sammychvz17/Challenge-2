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

    if (information != nullptr && !information->empty() && id > 0) {
        Node* newNode = new Node;
        newNode->data.id = id;
        newNode->data.information = *information;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        itemCount++;
        added = true;
    }

    return added;
}

bool Queue::clear() {
/* **************************************************
This method clears all items from the queue.
@param : none
@return : bool cleared (true / false)
* ************************************************* */
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    itemCount = 0;

    return true;
}

