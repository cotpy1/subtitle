#include "SectionList.h"
#include <iostream>

// constructor: initialize head pointer of section list
SectionList::SectionList() : head(nullptr) {}

// destructor: delete all nodes of list to free memory
SectionList::~SectionList()
{
    SectionListNode* current = head;
    while (current != nullptr) {
        // delete subtitles of current section
        SubtitleListNode* subtitleNode = current->getFirstNode();
        while (subtitleNode != nullptr) {
            SubtitleListNode* temp = subtitleNode;
            subtitleNode = subtitleNode->getNext();
            delete temp;
        }

        // delete current section node
        SectionListNode* temp = current;
        current = current->getNext();
        delete temp;
    }
}

// return head node
SectionListNode* SectionList::getHead()
{
    return head;
}

// add section (Insert)
void SectionList::addSection(int sectionNumber)
{
    // create new section node
    SectionListNode* newNode = new SectionListNode(sectionNumber);

    // if list is empty, set new node as head
    if (head == nullptr) {
        head = newNode;
    } else {
        // if list is not empty, add new node to the end
        SectionListNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

// search section (Search)
SectionListNode* SectionList::searchSection(int sectionNumber)
{
    SectionListNode* current = head;

    // find node with given section number
    while (current != nullptr) {
        if (current->getSectionNumber() == sectionNumber) {
            return current;
        }
        current = current->getNext();
    }

    // if section number is not found, return nullptr
    return nullptr;
}

// add subtitle
void SectionList::addSubtitle(int sectionNumber, const std::string& time, const std::string& subtitle) {
    SectionListNode* current = searchSection(sectionNumber);
    if (current == nullptr) {
        std::cerr << "Error: Section not found." << std::endl;
        return;
    }
    // create new subtitle node
    SubtitleListNode* newSubtitle = new SubtitleListNode(time, subtitle);
    if (current->getFirstNode() == nullptr) {
        current->setFirstNode(newSubtitle);
    } else {
        SubtitleListNode* subtitleNode = current->getFirstNode();
        while (subtitleNode->getNext() != nullptr) {
            subtitleNode = subtitleNode->getNext();
        }
        subtitleNode->setNext(newSubtitle);
    }
}

