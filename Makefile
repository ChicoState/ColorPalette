# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = --std=c++17

# Source file
SRC = main.cpp

# Executable name
TARGET = Palette

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean
clean:
	rm -f $(TARGET)
