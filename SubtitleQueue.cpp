#include "SubtitleQueue.h"
#include <iostream>
#include <fstream>

// constructor: initialize queue
SubtitleQueue::SubtitleQueue(int maxSize) : maxSize(maxSize) {
    front = nullptr;
    rear = nullptr;
    currentSize = 0;

}

// destructor: delete all nodes to free memory
SubtitleQueue::~SubtitleQueue() {
    while (!isEmpty()) {
        std::string tempTime, tempSubtitle;
        pop(tempTime, tempSubtitle);  // pop data from queue and delete node
    }
}

// check if queue is empty
inline bool SubtitleQueue::isEmpty() {
    return currentSize == 0;
}

// check if queue is full
inline bool SubtitleQueue::isFull() {
    return currentSize == maxSize;
}

// add subtitle data to queue
bool SubtitleQueue::push(std::string time, std::string subtitle) {
    if (isFull()) {
        return false;  // cannot add if queue is full
    }

    SubtitleQueueNode* newNode = new SubtitleQueueNode(time, subtitle);

    if (isEmpty()) {
        // queue is empty
        front = newNode;
        rear = newNode;
    } else {
        // queue already has nodes
        rear->setNext(newNode);  // set next node of rear
        rear = newNode;
    }

    currentSize++;
    return true;
}

// remove subtitle data from queue
bool SubtitleQueue::pop(std::string &time, std::string &subtitle) {
    if (isEmpty()) {
        return false;  // cannot remove if queue is empty
    }

    // copy data of front node
    SubtitleQueueNode* temp = front;
    time = temp->getTime();
    subtitle = temp->getSubtitle();

    // remove front node from queue
    front = front->getNext();
    delete temp;

    currentSize--;
    if (isEmpty()) {
        rear = nullptr;
    }

    return true;
}

// print all data in queue
void SubtitleQueue::printQueue(std::ostream& out) const {
    SubtitleQueueNode* current = front;

    // traverse all nodes in queue and print data
    while (current != nullptr) {
        out << current->getTime() << " - " << current->getSubtitle() << std::endl;
        current = current->getNext();
    }

}

