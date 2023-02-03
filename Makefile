#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#
TARGET := IPGwidgetApp
# define the Cpp compiler to use
CXX = g++
GDB = gdb
# define any compile-time flags
CXXFLAGS	:= -std=c++11 -Wall -Wextra -lpthread 

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define output directory
OUTPUT	:= output

# define source directory
SRC		:= src

# define include directory
INCLUDE	:= include

# define lib directory
LIB		:= lib

# define tests directory
TESTS		:= tests

ifeq ($(OS),Windows_NT)
MAIN	:= $(TARGET).exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
LIBDIRS		:= $(LIB)
TESTSDIR    := $(TESTS)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
else
MAIN	:= $(TARGET)
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
TESTSDIR    := $(shell find $(TESTS) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# define the C libs
LIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

# define the C source files
SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# define the C object files 
OBJECTS		:= $(SOURCES:.cpp=.o)

# Test source and object files
TEST_SOURCES = $(wildcard $(patsubst %,%/*.cpp, $(TESTSDIR)))
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Lib source and object files
LIB_SOURCES = $(wildcard $(patsubst %,%/*.cpp, $(LIBDIRS)))
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@


OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))


all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(LIB_OBJECTS)  $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(LIB_OBJECTS) $(OBJECTS) $(LFLAGS) $(LIBS)


# Debug target
debug: CXXFLAGS += -g
debug: $(OUTPUT) $(MAIN); $(GDB) $(OUTPUTMAIN)

# Test target
test: CXXFLAGS +=  -lgtest -lgtest_main
test: $(LIB_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o unitTests $(LIB_OBJECTS) $(TEST_OBJECTS) $(LFLAGS) $(LIBS)
	./unitTests #--gtest_filter=logging*
	@rm -f unitTests

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(LIB_OBJECTS))
	$(RM) $(call FIXPATH,$(TEST_OBJECTS))
	$(RM) $(call FIXPATH,$(OBJECTS))


	@echo Cleanup complete!


# Force target
.PHONY: FORCE
# Documentation target
docs: FORCE
	doxygen Doxyfile


run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!