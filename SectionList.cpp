#include "SectionList.h"
#include <iostream>

// 생성자: 섹션 리스트의 헤드 포인터를 초기화
SectionList::SectionList() : head(nullptr) {}

// 소멸자: 리스트의 모든 노드들을 삭제하여 메모리 해제
SectionList::~SectionList()
{
    SectionListNode* current = head;
    while (current != nullptr) {
        // 현재 섹션의 자막 노드들 삭제
        SubtitleListNode* subtitleNode = current->getFirstNode();
        while (subtitleNode != nullptr) {
            SubtitleListNode* temp = subtitleNode;
            subtitleNode = subtitleNode->getNext();
            delete temp;
        }

        // 현재 섹션 노드 삭제
        SectionListNode* temp = current;
        current = current->getNext();
        delete temp;
    }
}

// 헤드 노드를 반환
SectionListNode* SectionList::getHead()
{
    return head;
}

// 섹션 추가 (Insert)
void SectionList::addSection(int sectionNumber)
{
    // 새로운 섹션 노드 생성
    SectionListNode* newNode = new SectionListNode(sectionNumber);

    // 리스트가 비어 있으면 새 노드를 헤드로 설정
    if (head == nullptr) {
        head = newNode;
    } else {
        // 리스트가 비어 있지 않으면 마지막에 추가
        SectionListNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

// 섹션 검색 (Search)
SectionListNode* SectionList::searchSection(int sectionNumber)
{
    SectionListNode* current = head;

    // 주어진 섹션 번호를 가진 노드를 찾음
    while (current != nullptr) {
        if (current->getSectionNumber() == sectionNumber) {
            return current;
        }
        current = current->getNext();
    }

    // 섹션 번호를 찾지 못한 경우 nullptr 반환
    return nullptr;
}

void SectionList::addSubtitle(int sectionNumber, const std::string& time, const std::string& subtitle) {
    // 실제 메서드 구현 내용
    SectionListNode* current = searchSection(sectionNumber);
    if (current == nullptr) {
        std::cerr << "Error: Section not found." << std::endl;
        return;
    }

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

