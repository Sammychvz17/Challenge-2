/**************************************************
*  Name: Samantha Chavez
*  Assignment: Queue
*  Purpose: This is the header file for the linked-list
*           based queue ADT that can operate in either
*           FIFO or LIFO mode.
************************************************* */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using std::string;

/**************************************************
*  Struct: Data
*  Purpose: Store the id and information for each
*           item in the queue.
************************************************* */
struct Data {
    int id;
    string information;
};

/**************************************************
*  Enum: QueueType
*  Purpose: Selects the algorithm used by the queue:
*           FIFO or LIFO.
************************************************* */
enum QueueType {
    FIFO = 0,
    LIFO = 1
};

class Queue {

    public:
     /**********************
    *  Constructors / Destructor
    ***********************/
        Queue(QueueType type = FIFO);
        ~Queue();

    /**********************
    *  Mutators
    ***********************/
        bool clear();
        bool push(int id, string* information);
        bool pull(Data* outData);
    
    /**********************
    *  Accessors
    ***********************/
        bool peek(int& id) const;
        int count() const;
        bool exists(int id) const;
        int find(int id) const;

private:
    /**************************************************
    *  Struct: Node
    *  Purpose: Internal linked list node that stores
    *           Data and pointers to neighboring nodes.
    ************************************************* */
        struct Node {
        Data data;
        Node *next;
        Node *prev;
        };

    /**********************
    *  Attributes
    ***********************/
        Node* head;
        Node* tail;
        int   itemCount;
        QueueType mode;

};




#endif // QUEUE_H