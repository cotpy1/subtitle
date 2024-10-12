#ifndef SUBTITLEQUEUE_H
#define SUBTITLEQUEUE_H

#include "SubtitleQueueNode.h"
#include <string>

class SubtitleQueue {
private:
    SubtitleQueueNode* front;    // 큐의 앞쪽을 가리키는 포인터
    SubtitleQueueNode* rear;     // 큐의 뒤쪽을 가리키는 포인터
    int maxSize;                 // 큐의 최대 크기
    int currentSize;             // 현재 큐의 크기

public:
    // 생성자 및 소멸자
    SubtitleQueue(int maxSize = 100);  // 기본값을 100으로 설정
    ~SubtitleQueue();

    // 큐가 비어 있는지 확인하는 함수
    bool isEmpty();

    // 큐가 가득 찼는지 확인하는 함수
    bool isFull();

    // 자막 데이터를 큐에 추가하는 함수
    bool push(std::string time, std::string subtitle);

    // 자막 데이터를 큐에서 제거하고 반환하는 함수
    bool pop(std::string &time, std::string &subtitle);

    // 큐의 모든 내용을 출력하는 함수
    void printQueue(std::ostream& out) const;
};

#endif
