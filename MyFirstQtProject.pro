TEMPLATE = app
CONFIG += c++11
QT += widgets

# Source files
SOURCES += main.cpp \
           tests.cpp

# Header files
HEADERS += tree.hpp \
           tree_printer.hpp \
           node.hpp \
           complex.hpp

# Output directory
DESTDIR = ./bin

# Include path
INCLUDEPATH += .

# Compiler flags
QMAKE_CXXFLAGS += -Wall -Wextra

# Define a macro to include the test main function if CONFIG contains 'test'
contains(CONFIG, test) {
    DEFINES += RUN_TESTS
    message("Building tests...")
    SOURCES -= main.cpp # Remove main application source
} else {
    message("Building application...")
}







