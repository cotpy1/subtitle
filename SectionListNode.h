#pragma once
#include "SubtitleListNode.h"

class SectionListNode
{
private:
    int sectionNumber;                // section number
    SubtitleListNode* firstNode;      // pointer to first subtitle node of section
    SectionListNode* next;            // pointer to next section node

public:
    // constructor
    SectionListNode(int number) : sectionNumber(number), firstNode(nullptr), next(nullptr) {}
    ~SectionListNode() {}

    // accessor methods
    int getSectionNumber() const           { return sectionNumber; }
    SubtitleListNode* getFirstNode() const { return firstNode; }
    SectionListNode* getNext() const       { return next; }

    // setter methods
    void setFirstNode(SubtitleListNode* node) { firstNode = node; }
    void setNext(SectionListNode* nextNode)   { next = nextNode; }
};
