
# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -std=c++11

# Define any directories containing header files
INCLUDES = -Iincludes

# Define the source directory
SRC_DIR = src

# Define source files
SOURCES = $(SRC_DIR)/main.cpp  $(SRC_DIR)/dots.cpp $(SRC_DIR)/motor.cpp $(SRC_DIR)/utils.cpp $(SRC_DIR)/AccelStepperSim.cpp

# Define the object files from the source files
OBJECTS = $(SOURCES:.cpp=.o)

# Define the executable file
EXECUTABLE = main

# The first rule is the one executed when no parameters are fed to the Makefile
all: $(EXECUTABLE)

# Rule for linking the final executable
# Depends on the object files (the .o files)
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Rule for compiling the source files into object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Define a clean rule to remove compiled files
clean:
	rm -f $(SRC_DIR)/*.o $(EXECUTABLE)

# Define a rule for rebuilding the project
rebuild: clean all
