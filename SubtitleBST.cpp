#include "SubtitleBST.h"
#include "SectionList.h"
#include <iostream>
#include <fstream>

// default constructor: initialize root node to nullptr
SubtitleBST::SubtitleBST() : root(nullptr) {}

// destructor: delete all nodes of tree to free memory
SubtitleBST::~SubtitleBST() {
    deleteTree(root);
}

// return root node of tree
SubtitleBSTNode* SubtitleBST::getRoot() {
    return root;
}

// insert node to tree
void SubtitleBST::insert(const std::string& time, const std::string& subtitle) {
    root = insertNode(root, time, subtitle);
}

// print subtitles of tree in in-order traversal
void SubtitleBST::print(std::ofstream& out) {
    inOrder(root, out);
}

// search node with given time
SubtitleBSTNode* SubtitleBST::search(const std::string& time) {
    return searchNode(root, time);
}

// delete node with given time
void SubtitleBST::deleteNode(const std::string& time) {
    root = deleteNodeRec(root, time);
}

// delete all nodes of tree to free memory (recursively)
void SubtitleBST::deleteTree(SubtitleBSTNode* node) {
    if (node != nullptr) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}

// insert node to tree (recursively)
SubtitleBSTNode* SubtitleBST::insertNode(SubtitleBSTNode* node, const std::string& time, const std::string& subtitle) {
    if (node == nullptr) {
        return new SubtitleBSTNode(time, subtitle);
    }

    if (time < node->getTime()) {
        node->setLeft(insertNode(node->getLeft(), time, subtitle));
    } else if (time > node->getTime()) {
        node->setRight(insertNode(node->getRight(), time, subtitle));
    }

    return node;
}

// add subtitles to SectionList
void SubtitleBST::addSubtitlesToSection(SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime) {
    addSubtitlesToSectionHelper(root, sectionList, sectionNumber, startTime, endTime);
}

// add subtitles to SectionList helper function
void SubtitleBST::addSubtitlesToSectionHelper(SubtitleBSTNode* node, SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime) {
    if (node == nullptr) return;

    addSubtitlesToSectionHelper(node->getLeft(), sectionList, sectionNumber, startTime, endTime);

    if (node->getTime() >= startTime && node->getTime() <= endTime) {
        sectionList->addSubtitle(sectionNumber, node->getTime(), node->getSubtitle());
    }

    addSubtitlesToSectionHelper(node->getRight(), sectionList, sectionNumber, startTime, endTime);
}

// in-order traversal to print tree (recursively)
void SubtitleBST::inOrder(SubtitleBSTNode* node, std::ofstream& out) {
    if (node == nullptr) return;

    inOrder(node->getLeft(), out);
    out << node->getTime() << " - " << node->getSubtitle() << std::endl;
    inOrder(node->getRight(), out);
}

// search node with given time (recursively)
SubtitleBSTNode* SubtitleBST::searchNode(SubtitleBSTNode* node, const std::string& time) {
    if (node == nullptr || node->getTime() == time) {
        return node;
    }

    if (time < node->getTime()) {
        return searchNode(node->getLeft(), time);
    } else {
        return searchNode(node->getRight(), time);
    }
}

// delete node with given time (recursively)
SubtitleBSTNode* SubtitleBST::deleteNodeRec(SubtitleBSTNode* node, const std::string& time) {
    if (node == nullptr) return nullptr;

    if (time < node->getTime()) {
        node->setLeft(deleteNodeRec(node->getLeft(), time));
    } else if (time > node->getTime()) {
        node->setRight(deleteNodeRec(node->getRight(), time));
    } else {
        // if node to delete is found
        if (node->getLeft() == nullptr) {
            SubtitleBSTNode* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            SubtitleBSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        // if both children are present
        SubtitleBSTNode* minNode = findMin(node->getRight());
        node->setTime(minNode->getTime());
        node->setSubtitle(minNode->getSubtitle());
        node->setRight(deleteNodeRec(node->getRight(), minNode->getTime()));
    }

    return node;
}

// find minimum value (leftmost node) of tree
SubtitleBSTNode* SubtitleBST::findMin(SubtitleBSTNode* node) {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

// delete node with given time
void SubtitleBST::deleteEqual(const std::string& time) {
    root = deleteNodeRec(root, time);
}

// delete all nodes with time less than given time
void SubtitleBST::deleteUnder(const std::string& time) {
    deleteUnderHelper(root, time);
}

// delete all nodes with time less than given time helper function
void SubtitleBST::deleteUnderHelper(SubtitleBSTNode*& node, const std::string& time) {
    if (node == nullptr) return;

    if (node->getTime() < time) {
        node = deleteNodeRec(node, node->getTime());
        deleteUnderHelper(node, time);
    } else {
        deleteUnderHelper(node->getLeftRef(), time);  
    }
}



