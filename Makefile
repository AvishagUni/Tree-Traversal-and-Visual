CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = 
SOURCES = main.cpp tests.cpp
HEADERS = tree.hpp tree_printer.hpp node.hpp complex.hpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = tree_demo
TEST_TARGET = run_tests

.PHONY: all clean test

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_TARGET): tests.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests.o: tests.cpp
	$(CXX) $(CXXFLAGS) -DRUN_TESTS -c tests.cpp -o tests.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_TARGET) *.png *.dot




