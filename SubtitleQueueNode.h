#ifndef SUBTITLEQUEUENODE_H
#define SUBTITLEQUEUENODE_H

#include <string>

class SubtitleQueueNode {
private:
    std::string time;               // subtitle time
    std::string subtitle;           // subtitle content
    SubtitleQueueNode* next;        // pointer to next node

public:
    // default constructor
    SubtitleQueueNode() : time(""), subtitle(""), next(nullptr) {}

    // overloaded constructor (initialize subtitle time and content)
    SubtitleQueueNode(const std::string& t, const std::string& s)
        : time(t), subtitle(s), next(nullptr) {}

    // accessor methods
    std::string getTime() const          { return time; }
    std::string getSubtitle() const      { return subtitle; }
    SubtitleQueueNode* getNext() const   { return next; }

    // setter methods
    void setTime(const std::string& t)         { time = t; }
    void setSubtitle(const std::string& s)     { subtitle = s; }
    void setNext(SubtitleQueueNode* nextNode)  { next = nextNode; }
};

#endif
