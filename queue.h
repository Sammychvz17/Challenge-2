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

/**************************************************
*  Class: Queue
*  Purpose: Linked-list based queue that can behave
*           as either FIFO or LIFO depending on the
*           constructor flag.
************************************************* */
class Queue {

public:
    /**********************
    *  Constructors / Destructor
    ***********************/


    /**********************
    *  Mutators
    ***********************/
    
    /**********************
    *  Accessors
    ***********************/

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

};




#endif // QUEUE_H