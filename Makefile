# Makefile

# 컴파일러와 플래그 설정
CXX = g++
CXXFLAGS = -std=c++11 -g

# 소스 파일과 헤더 파일
SOURCES = Manager.cpp SectionList.cpp SubtitleBST.cpp SubtitleQueue.cpp main.cpp
HEADERS = Manager.h SectionList.h SectionListNode.h SubtitleBST.h SubtitleBSTNode.h SubtitleListNode.h SubtitleQueue.h SubtitleQueueNode.h

# 오브젝트 파일
OBJECTS = $(SOURCES:.cpp=.o)

# 실행 파일 이름
EXECUTABLE = run

# 기본 타겟
all: $(EXECUTABLE)

# 실행 파일 생성
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 개별 소스 파일 컴파일
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# 청소
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)