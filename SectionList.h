#pragma once
#include "SectionListNode.h"

class SectionList
{
private:
    SectionListNode* head;

public:
    SectionList();
    ~SectionList();

    SectionListNode* getHead();

    // function to add section (Insert)
    void addSection(int sectionNumber);

    // function to search section (Search)
    SectionListNode* searchSection(int sectionNumber);

    // function to add subtitle (Insert)
    void addSubtitle(int sectionNumber, const std::string& time, const std::string& subtitle);
};
