CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra `pkg-config --cflags --libs Qt5Widgets`

# Define the target executable
TARGET = tree_demo

# Define the source files
SRCS = main.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the header files
HEADERS = node.hpp tree.hpp tree_printer.hpp complex.hpp

# Default rule to build the target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean




