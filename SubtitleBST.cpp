#include "SubtitleBST.h"
#include "SectionList.h"
#include <iostream>
#include <fstream>

// 기본 생성자: 트리의 루트 노드를 nullptr로 초기화
SubtitleBST::SubtitleBST() : root(nullptr) {}

// 소멸자: 트리의 모든 노드를 삭제하여 메모리 해제
SubtitleBST::~SubtitleBST() {
    deleteTree(root);
}

// 트리의 루트 노드를 반환
SubtitleBSTNode* SubtitleBST::getRoot() {
    return root;
}

// 트리에 노드를 삽입하는 함수
void SubtitleBST::insert(const std::string& time, const std::string& subtitle) {
    root = insertNode(root, time, subtitle);
}

// 중위 순회 방식으로 트리의 자막 데이터를 출력하는 함수
void SubtitleBST::print(std::ofstream& out) {
    inOrder(root, out);
}

// 특정 시간에 해당하는 노드를 찾는 함수
SubtitleBSTNode* SubtitleBST::search(const std::string& time) {
    return searchNode(root, time);
}

// 특정 시간에 해당하는 노드를 삭제하는 함수
void SubtitleBST::deleteNode(const std::string& time) {
    root = deleteNodeRec(root, time);
}

// 트리의 메모리를 해제하는 함수 (재귀적)
void SubtitleBST::deleteTree(SubtitleBSTNode* node) {
    if (node != nullptr) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}

// 노드를 삽입하는 함수 (재귀적)
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

// SectionList에 자막을 추가하는 함수
void SubtitleBST::addSubtitlesToSection(SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime) {
    addSubtitlesToSectionHelper(root, sectionList, sectionNumber, startTime, endTime);
}

// 섹션 리스트에 자막을 추가하는 헬퍼 함수
void SubtitleBST::addSubtitlesToSectionHelper(SubtitleBSTNode* node, SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime) {
    if (node == nullptr) return;

    addSubtitlesToSectionHelper(node->getLeft(), sectionList, sectionNumber, startTime, endTime);

    if (node->getTime() >= startTime && node->getTime() <= endTime) {
        sectionList->addSubtitle(sectionNumber, node->getTime(), node->getSubtitle());
    }

    addSubtitlesToSectionHelper(node->getRight(), sectionList, sectionNumber, startTime, endTime);
}

// 중위 순회 방식으로 트리를 탐색하며 출력 (재귀적)
void SubtitleBST::inOrder(SubtitleBSTNode* node, std::ofstream& out) {
    if (node == nullptr) return;

    inOrder(node->getLeft(), out);
    out << node->getTime() << " - " << node->getSubtitle() << std::endl;
    inOrder(node->getRight(), out);
}

// 특정 시간에 해당하는 노드를 찾는 함수 (재귀적)
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

// 특정 시간에 해당하는 노드를 삭제하는 함수 (재귀적)
SubtitleBSTNode* SubtitleBST::deleteNodeRec(SubtitleBSTNode* node, const std::string& time) {
    if (node == nullptr) return nullptr;

    if (time < node->getTime()) {
        node->setLeft(deleteNodeRec(node->getLeft(), time));
    } else if (time > node->getTime()) {
        node->setRight(deleteNodeRec(node->getRight(), time));
    } else {
        // 삭제할 노드를 찾은 경우
        if (node->getLeft() == nullptr) {
            SubtitleBSTNode* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            SubtitleBSTNode* temp = node->getLeft();
            delete node;
            return temp;
        }

        // 양쪽 자식이 모두 있는 경우
        SubtitleBSTNode* minNode = findMin(node->getRight());
        node->setTime(minNode->getTime());
        node->setSubtitle(minNode->getSubtitle());
        node->setRight(deleteNodeRec(node->getRight(), minNode->getTime()));
    }

    return node;
}

// 트리의 최소값(가장 왼쪽 노드)을 찾는 함수
SubtitleBSTNode* SubtitleBST::findMin(SubtitleBSTNode* node) {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

// 특정 시간과 일치하는 노드를 삭제
void SubtitleBST::deleteEqual(const std::string& time) {
    root = deleteNodeRec(root, time);
}

// 특정 시간보다 작은 모든 노드를 삭제
void SubtitleBST::deleteUnder(const std::string& time) {
    deleteUnderHelper(root, time);
}

// 특정 시간보다 작은 노드를 삭제하는 헬퍼 함수
void SubtitleBST::deleteUnderHelper(SubtitleBSTNode*& node, const std::string& time) {
    if (node == nullptr) return;

    if (node->getTime() < time) {
        node = deleteNodeRec(node, node->getTime());
        deleteUnderHelper(node, time);
    } else {
        deleteUnderHelper(node->getLeftRef(), time);  // getLeftRef()를 사용하여 참조 전달
    }
}



