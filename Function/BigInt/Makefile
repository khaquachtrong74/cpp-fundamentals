#GPT MADE
CXX = g++

CXXFLAGS = -Wall -std=c++17

SRCS = main.cpp BigInt.cpp LinkList.cpp

HEADERS = BigInt.h LinkList.h

OBJS = $(SRCS:.cpp=.o)

TARGET = program

#Quy tắc mặc định
all: $(TARGET)

# Quy tắc biên dịch
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

#Quy tắc tạo tệp .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Quy tắc làm sạch
clean:
	rm -f $(OBJS) $(TARGET)
