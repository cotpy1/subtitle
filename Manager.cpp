#include "Manager.h"
#include <iostream>
#include <fstream>
#include <sstream>

Manager::Manager()
{
    queue = new SubtitleQueue(100);
    bst = new SubtitleBST();
    sectionList = new SectionList();

    // log.txt 파일 열기
    flog.open("log.txt");
    if (!flog.is_open()) {
        std::cerr << "Error: Could not open log.txt for writing!" << std::endl;
        exit(-1);
    }
}

Manager::~Manager()
{
    delete queue;
    delete bst; 
    delete sectionList;

    // log.txt 파일 닫기
    if (flog.is_open()) {
        flog.close();
    }
}

void Manager::Run(const std::string& commandFile)
{
    // Open command file
    std::ifstream fcmd(commandFile);
    std::string command;

    if (!fcmd.is_open()) {
        flog << "Fail to open command file" << std::endl;
        exit(-1);
    }

    // Read and Run commands
    while (getline(fcmd, command)) {
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;  // 명령어를 추출

        if (cmd == "LOAD") {
            load("subtitle.txt");
        } else if (cmd == "QPOP") {
            qpop();
        } else if (cmd == "PRINT") {
            int sectionNumber = 0;  // 기본값으로 0 설정 (섹션 번호가 주어지지 않은 경우)
            if (iss >> sectionNumber) {
                print(sectionNumber);
            } else {
                print();  // 전체를 출력
            }
        } else if (cmd.find("SECTION") == 0) {
            int sectionNumber;
            std::string startTime, endTime;
            iss >> sectionNumber >> startTime >> endTime;
            section(sectionNumber, startTime, endTime);
        } else if (cmd.find("DELETE") == 0) {
            std::string deleteType, time;
            iss >> deleteType >> time;
            deleteSubtitles(deleteType, time);
        } else if (cmd == "EXIT") {
            flog << "Exiting program." << std::endl;
            flog.flush();
            exit(0); // 프로그램 정상 종료
        } else {
            PrintErrorCode(1000); // 잘못된 명령어 처리
        }
    }

    fcmd.close();
}

// 성공 메시지 출력
void Manager::PrintSuccess(const std::string& cmd)
{
    flog << "===== " << cmd << " =====" << std::endl;
    flog << "Success" << std::endl;
    flog << "===============\n" << std::endl;
}

// 에러 코드 출력
void Manager::PrintErrorCode(int num)
{
    flog << "===== ERROR =====" << std::endl;
    flog << num << std::endl;
    flog << "===============\n" << std::endl;
}

// LOAD
void Manager::load(const std::string& subtitleFile) {
    std::ifstream file(subtitleFile);
    std::string time, subtitle;
    flog << "===== LOAD =====" << std::endl;

    if (!file.is_open()) {
        PrintErrorCode(100);
        return;
    }

    while (file >> time) {
        getline(file, subtitle);
        if (!subtitle.empty() && subtitle[0] == ' ') {
            subtitle.erase(0, 1);
        }

        if (!queue->push(time, subtitle)) {
            PrintErrorCode(100);
            file.close();
            return;
        }

        flog << time << " - " << subtitle << std::endl;
    }
    flog << "===============\n" << std::endl;

    file.close();
}

// QPOP
void Manager::qpop() {
    std::string time, subtitle;

    if (queue->isEmpty()) {
        PrintErrorCode(200);
        return;
    }

    while (!queue->isEmpty()) {
        if (queue->pop(time, subtitle)) {
            bst->insert(time, subtitle);
        }
    }

    PrintSuccess("QPOP");
}

// PRINT
void Manager::print(int sectionNumber) {
    if (bst == nullptr) {
        PrintErrorCode(300);
        return;
    }

    if (sectionNumber == 0) {
        // 섹션 넘버가 주어지지 않은 경우 BST전체를 출력
        flog << "===== PRINT =====" << std::endl;
        flog << "SubtitleBST:" << std::endl;
        bst->print(flog);
    } else {
        // 섹션 번호가 주어진 경우 해당 섹션을 출력
        SectionListNode* current = sectionList->getHead();
        while (current != nullptr && current->getSectionNumber() != sectionNumber) {
            current = current->getNext();
        }

        if (current == nullptr) {
            PrintErrorCode(300);
            return;
        }

        flog << "===== PRINT =====" << std::endl;
        flog << "Section " << current->getSectionNumber() << ":\n";
        SubtitleListNode* subtitleNode = current->getFirstNode();
        while (subtitleNode != nullptr) {
            flog << subtitleNode->getTime() << " - " << subtitleNode->getSubtitle() << "\n";
            subtitleNode = subtitleNode->getNext();
        }
        flog << "===============\n" << std::endl;
        flog.flush();  // 로그를 강제로 기록
        
    }

    flog.flush();  // 강제로 플러시
    
}


// SECTION
void Manager::section(int sectionNumber, const std::string& startTime, const std::string& endTime) {
    if (bst == nullptr) {
        PrintErrorCode(400);
        return;
    }

    sectionList->addSection(sectionNumber);
    bst->addSubtitlesToSection(sectionList, sectionNumber, startTime, endTime);

    PrintSuccess("SECTION");
}

// DELETE
void Manager::deleteSubtitles(const std::string& deleteType, const std::string& time) {
    if (bst == nullptr) {
        PrintErrorCode(500);
        return;
    }

    if (deleteType == "EQUAL") {
        bst->deleteEqual(time);
    } else if (deleteType == "UNDER") {
        bst->deleteUnder(time);
    } else {
        PrintErrorCode(1000);
        return;
    }

    PrintSuccess("DELETE");
}


