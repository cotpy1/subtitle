#pragma once
#include <string>

class SubtitleListNode
{
private:
    std::string time;               // subtitle time (e.g. "00:52:20")
    std::string subtitle;           // subtitle content (e.g. "Right now!")
    SubtitleListNode* next;         // pointer to next subtitle node

public:
    // default constructor
    SubtitleListNode() : time(""), subtitle(""), next(nullptr) {}

    // overloaded constructor (initialize subtitle time and content)
    SubtitleListNode(const std::string& t, const std::string& s)
        : time(t), subtitle(s), next(nullptr) {}

    // accessor methods
    std::string getTime() const          { return time; }
    std::string getSubtitle() const      { return subtitle; }
    SubtitleListNode* getNext() const    { return next; }

    // setter methods
    void setTime(const std::string& t)       { time = t; }
    void setSubtitle(const std::string& s)   { subtitle = s; }
    void setNext(SubtitleListNode* nextNode) { next = nextNode; }
};
