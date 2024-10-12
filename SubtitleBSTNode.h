#pragma once

#include <string>

class SubtitleBSTNode
{
private:
    std::string time;             // subtitle time (e.g. "00:52:20")
    std::string subtitle;         // subtitle content (e.g. "Right now!")
    SubtitleBSTNode* left;        // pointer to left child node
    SubtitleBSTNode* right;       // pointer to right child node

public:
    // default constructor
    SubtitleBSTNode() : left(nullptr), right(nullptr) {}

    // overloaded constructor (initialize subtitle time and content)
    SubtitleBSTNode(const std::string& t, const std::string& s)
        : time(t), subtitle(s), left(nullptr), right(nullptr) {}

    // destructor
    ~SubtitleBSTNode() {}

    // accessor methods
    std::string getTime() const        { return time; }
    std::string getSubtitle() const    { return subtitle; }
    SubtitleBSTNode* getLeft() const   { return left; }
    SubtitleBSTNode* getRight() const  { return right; }
	SubtitleBSTNode*& getLeftRef() { return left; }
    SubtitleBSTNode*& getRightRef() { return right; }

    // setter methods
    void setTime(const std::string& t)     { time = t; }
    void setSubtitle(const std::string& s) { subtitle = s; }
    void setLeft(SubtitleBSTNode* left)    { this->left = left; }
    void setRight(SubtitleBSTNode* right)  { this->right = right; }
};
