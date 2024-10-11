#pragma once
#include "SubtitleBSTNode.h"
#include <string>
#include <fstream>

// 전방 선언 (forward declaration)
class SectionList;

class SubtitleBST
{
private:
    SubtitleBSTNode* root;  // 트리의 루트 노드

    // 헬퍼 메서드들
    SubtitleBSTNode* insertNode(SubtitleBSTNode* node, const std::string& time, const std::string& subtitle);
    void inOrder(SubtitleBSTNode* node, std::ofstream& out);
    SubtitleBSTNode* searchNode(SubtitleBSTNode* node, const std::string& time);
    SubtitleBSTNode* deleteNodeRec(SubtitleBSTNode* node, const std::string& time);
    SubtitleBSTNode* findMin(SubtitleBSTNode* node);
    void deleteTree(SubtitleBSTNode* node);

    // SectionList 관련 헬퍼 메서드들
    void deleteUnderHelper(SubtitleBSTNode*& node, const std::string& time);
    void addSubtitlesToSectionHelper(SubtitleBSTNode* node, SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime);

public:
    SubtitleBST();
    ~SubtitleBST();

    // SectionList와 관련된 메서드들
    void addSubtitlesToSection(SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime);
    void deleteEqual(const std::string& time);
    void deleteUnder(const std::string& time);

    // 트리의 루트 노드를 반환하는 함수
    SubtitleBSTNode* getRoot();

    // 트리에 노드를 삽입하는 함수
    void insert(const std::string& time, const std::string& subtitle);

    // 트리의 데이터를 출력하는 함수 (중위 순회)
    void print(std::ofstream& out);

    // 특정 시간을 기준으로 노드를 찾는 함수
    SubtitleBSTNode* search(const std::string& time);

    // 특정 시간을 기준으로 노드를 삭제하는 함수
    void deleteNode(const std::string& time);
};
