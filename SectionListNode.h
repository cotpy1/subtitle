#pragma once
#include "SubtitleListNode.h"

class SectionListNode
{
private:
    int sectionNumber;                // 섹션 번호
    SubtitleListNode* firstNode;      // 섹션의 첫 번째 자막 노드를 가리키는 포인터
    SectionListNode* next;            // 다음 섹션 노드를 가리키는 포인터

public:
    // 생성자
    SectionListNode(int number) : sectionNumber(number), firstNode(nullptr), next(nullptr) {}
    ~SectionListNode() {}

    // 접근자 메서드들
    int getSectionNumber() const           { return sectionNumber; }
    SubtitleListNode* getFirstNode() const { return firstNode; }
    SectionListNode* getNext() const       { return next; }

    // 설정자 메서드들
    void setFirstNode(SubtitleListNode* node) { firstNode = node; }
    void setNext(SectionListNode* nextNode)   { next = nextNode; }
};
