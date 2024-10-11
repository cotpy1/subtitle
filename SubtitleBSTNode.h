#pragma once

#include <string>

class SubtitleBSTNode
{
private:
    std::string time;             // 자막 시간 (예: "00:52:20")
    std::string subtitle;         // 자막 내용 (예: "Right now!")
    SubtitleBSTNode* left;        // 왼쪽 자식 노드를 가리키는 포인터
    SubtitleBSTNode* right;       // 오른쪽 자식 노드를 가리키는 포인터

public:
    // 기본 생성자
    SubtitleBSTNode() : left(nullptr), right(nullptr) {}

    // 오버로드된 생성자 (자막 시간과 내용을 초기화)
    SubtitleBSTNode(const std::string& t, const std::string& s)
        : time(t), subtitle(s), left(nullptr), right(nullptr) {}

    // 소멸자
    ~SubtitleBSTNode() {}

    // 접근자 메소드들
    std::string getTime() const        { return time; }
    std::string getSubtitle() const    { return subtitle; }
    SubtitleBSTNode* getLeft() const   { return left; }
    SubtitleBSTNode* getRight() const  { return right; }
	SubtitleBSTNode*& getLeftRef() { return left; }
    SubtitleBSTNode*& getRightRef() { return right; }

    // 설정자 메소드들
    void setTime(const std::string& t)     { time = t; }
    void setSubtitle(const std::string& s) { subtitle = s; }
    void setLeft(SubtitleBSTNode* left)    { this->left = left; }
    void setRight(SubtitleBSTNode* right)  { this->right = right; }
};
