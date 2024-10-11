#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <fstream>
#include "SubtitleQueue.h"
#include "SubtitleBST.h"
#include "SectionList.h"

class Manager {
private:
    SubtitleQueue* queue;  // 자막 데이터를 관리하는 큐
    SubtitleBST* bst;      // 자막 데이터를 관리하는 BST
    SectionList* sectionList; // 섹션 데이터를 관리하는 리스트
    std::ofstream flog;    // 로그 파일 스트림

public:
    // 생성자 및 소멸자
    Manager();
    ~Manager();

    // 명령어 파일을 읽어 처리하는 함수
    void Run(const std::string& commandFile);

    // 각 명령어를 처리하는 함수
    void load(const std::string& subtitleFile);
    void qpop();
    void print(int sectionNumber = -1);  // 섹션 번호가 없으면 전체 출력
    void section(int sectionNumber, const std::string& startTime, const std::string& endTime);
    void deleteSubtitles(const std::string& deleteType, const std::string& time);

    // 성공 및 에러 메시지 출력 함수
    void PrintSuccess(const std::string& cmd);
    void PrintErrorCode(int num);
};

#endif
