#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <fstream>
#include "SubtitleQueue.h"
#include "SubtitleBST.h"
#include "SectionList.h"

class Manager {
private:
    SubtitleQueue* queue;  // queue to manage subtitle data
    SubtitleBST* bst;      // BST to manage subtitle data
    SectionList* sectionList; // list to manage section data
    std::ofstream flog;    // log file stream

public:
    // constructor and destructor
    Manager();
    ~Manager();

    // function to read command file and process
    void Run(const std::string& commandFile);

    // function to process each command
    void load(const std::string& subtitleFile);
    void qpop();
    void print(int sectionNumber = -1);  // if section number is not given, print whole
    void section(int sectionNumber, const std::string& startTime, const std::string& endTime);
    void deleteSubtitles(const std::string& deleteType, const std::string& time);

    // function to print success and error message
    void PrintSuccess(const std::string& cmd);
    void PrintErrorCode(int num);
};

#endif
