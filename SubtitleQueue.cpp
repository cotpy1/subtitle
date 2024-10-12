#include "SubtitleQueue.h"
#include <iostream>
#include <fstream>

// 생성자: 큐를 초기화
SubtitleQueue::SubtitleQueue(int maxSize) : maxSize(maxSize) {
    front = nullptr;
    rear = nullptr;
    currentSize = 0;

}

// 소멸자: 모든 노드를 삭제하여 메모리 해제
SubtitleQueue::~SubtitleQueue() {
    while (!isEmpty()) {
        std::string tempTime, tempSubtitle;
        pop(tempTime, tempSubtitle);  // 큐에서 데이터를 꺼내면서 노드를 삭제
    }
}

// 큐가 비어 있는지 확인
bool SubtitleQueue::isEmpty() {
    return currentSize == 0;
}

// 큐가 가득 찼는지 확인
bool SubtitleQueue::isFull() {
    return currentSize == maxSize;
}

// 큐에 자막 데이터를 추가하는 함수
bool SubtitleQueue::push(std::string time, std::string subtitle) {
    if (isFull()) {
        return false;  // 큐가 가득 찼다면 추가할 수 없음
    }

    SubtitleQueueNode* newNode = new SubtitleQueueNode(time, subtitle);

    if (isEmpty()) {
        // 큐가 비어 있을 때
        front = newNode;
        rear = newNode;
    } else {
        // 큐에 이미 노드가 있을 때
        rear->setNext(newNode);  // rear의 다음 노드를 설정
        rear = newNode;
    }

    currentSize++;
    return true;
}

// 큐에서 자막 데이터를 제거하는 함수
bool SubtitleQueue::pop(std::string &time, std::string &subtitle) {
    if (isEmpty()) {
        return false;  // 큐가 비어 있다면 제거할 수 없음
    }

    // 앞쪽 노드의 데이터를 복사
    SubtitleQueueNode* temp = front;
    time = temp->getTime();
    subtitle = temp->getSubtitle();

    // 앞쪽 노드를 큐에서 제거
    front = front->getNext();
    delete temp;

    currentSize--;
    if (isEmpty()) {
        rear = nullptr;
    }

    return true;
}

// 큐의 모든 내용을 출력하는 함수
void SubtitleQueue::printQueue(std::ostream& out) const {
    SubtitleQueueNode* current = front;

    // 큐의 모든 노드를 순회하면서 출력
    while (current != nullptr) {
        out << current->getTime() << " - " << current->getSubtitle() << std::endl;
        current = current->getNext();
    }

}

