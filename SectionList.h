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

    // 섹션을 추가하는 함수 (Insert)
    void addSection(int sectionNumber);

    // 섹션을 검색하는 함수 (Search)
    SectionListNode* searchSection(int sectionNumber);

    // addSubtitle 메서드가 public으로 선언되어 있는지 확인
    void addSubtitle(int sectionNumber, const std::string& time, const std::string& subtitle);
};
