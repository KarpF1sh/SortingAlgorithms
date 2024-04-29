# Makefile for compiling a C++ program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source directory
SRC_DIR = src

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object directory
OBJ_DIR = bin

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

# Executable name
EXEC = $(OBJ_DIR)/p

# Default target
all: $(OBJ_DIR) $(EXEC)

# Rule to create the object files directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to compile .cpp files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files to create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR)/*

# Target to compile and run the program
run: $(EXEC)
	./$(EXEC)
