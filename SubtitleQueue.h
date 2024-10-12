#ifndef SUBTITLEQUEUE_H
#define SUBTITLEQUEUE_H

#include "SubtitleQueueNode.h"
#include <string>

class SubtitleQueue {
private:
    SubtitleQueueNode* front;    // pointer to front of queue
    SubtitleQueueNode* rear;     // pointer to rear of queue
    int maxSize;                 // maximum size of queue
    int currentSize;             // current size of queue

public:
    // constructor and destructor
    SubtitleQueue(int maxSize = 100);  // default value is 100
    ~SubtitleQueue();

    // check if queue is empty
    bool isEmpty();

    // check if queue is full
    bool isFull();

    // add subtitle data to queue
    bool push(std::string time, std::string subtitle);

    // remove subtitle data from queue and return it
    bool pop(std::string &time, std::string &subtitle);

    // print all data in queue
    void printQueue(std::ostream& out) const;
};

#endif
