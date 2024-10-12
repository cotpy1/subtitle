#pragma once
#include "SubtitleBSTNode.h"
#include <string>
#include <fstream>

// forward declaration
class SectionList;

class SubtitleBST
{
private:
    SubtitleBSTNode* root;  // root node of tree

    // helper methods
    SubtitleBSTNode* insertNode(SubtitleBSTNode* node, const std::string& time, const std::string& subtitle);
    void inOrder(SubtitleBSTNode* node, std::ofstream& out);
    SubtitleBSTNode* searchNode(SubtitleBSTNode* node, const std::string& time);
    SubtitleBSTNode* deleteNodeRec(SubtitleBSTNode* node, const std::string& time);
    SubtitleBSTNode* findMin(SubtitleBSTNode* node);
    void deleteTree(SubtitleBSTNode* node);

    // SectionList related helper methods
    void deleteUnderHelper(SubtitleBSTNode*& node, const std::string& time);
    void addSubtitlesToSectionHelper(SubtitleBSTNode* node, SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime);

public:
    SubtitleBST();
    ~SubtitleBST();

    // SectionList related methods
    void addSubtitlesToSection(SectionList* sectionList, int sectionNumber, const std::string& startTime, const std::string& endTime);
    void deleteEqual(const std::string& time);
    void deleteUnder(const std::string& time);

    // return root node of tree
    SubtitleBSTNode* getRoot();

    // insert node to tree
    void insert(const std::string& time, const std::string& subtitle);

    // print data of tree (in-order traversal)
    void print(std::ofstream& out);

    // search node with given time
    SubtitleBSTNode* search(const std::string& time);

    // delete node with given time
    void deleteNode(const std::string& time);
};
