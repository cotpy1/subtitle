#pragma once
#include <string>

class SubtitleListNode
{
private:
    std::string time;               // 자막 시간
    std::string subtitle;           // 자막 내용
    SubtitleListNode* next;         // 다음 자막 노드를 가리키는 포인터

public:
    // 기본 생성자
    SubtitleListNode() : time(""), subtitle(""), next(nullptr) {}

    // 오버로드된 생성자 (자막 시간과 내용을 초기화)
    SubtitleListNode(const std::string& t, const std::string& s)
        : time(t), subtitle(s), next(nullptr) {}

    // 접근자 메서드들
    std::string getTime() const          { return time; }
    std::string getSubtitle() const      { return subtitle; }
    SubtitleListNode* getNext() const    { return next; }

    // 설정자 메서드들
    void setTime(const std::string& t)       { time = t; }
    void setSubtitle(const std::string& s)   { subtitle = s; }
    void setNext(SubtitleListNode* nextNode) { next = nextNode; }
};
