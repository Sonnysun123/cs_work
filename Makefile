# Your requested flags
CXXFLAGS := -fdiagnostics-color=always \
            -g \
            -Wall \
            -Wextra \
            -D_GLIBCXX_DEBUG \
            -Wshadow \
            -O2 \
            -std=c++17

TARGET := my_program.exe

# AUTOMATION: Find all .cpp files in current folder
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f $(OBJS) $(TARGET)