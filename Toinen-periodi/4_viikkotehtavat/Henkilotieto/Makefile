# Name of the executable
EXECUTABLE = henkilotieto.exe

# Compiler
CC = g++

# Compiler flags
CFLAGS = 

# Linker flags
LDFLAGS = 

# Source files
SRC = $(wildcard *.cpp)

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	del $(OBJ)

# Rule to build object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
.PHONY: clean
clean:
	del $(OBJ) $(EXECUTABLE)

#Run with: mingw32-make all
#Run with: mingw32-make clean