##############################################################################
# Common make file for ligth barrier application
##############################################################################

# Defines
##############################################################################

# tools
CXX=g++
MKDIR=mkdir -p 

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++17 $(INCLUDE_FLAG)

# Paths 
##############################################################################

# Includes 
INCLUDE=./src
INCLUDE+=./test
INCLUDE_FLAG=$(addprefix -I,$(INCLUDE))

OUT=./out

VPATH=$(INCLUDE)

# Objects 
##############################################################################

# OBJECTS
OBJECTS = pulse.o

# Test - objects
T_OBJ=pulse.o
T_OBJ+=t_pulse.o

T_OBJECTS=$(addprefix $(OUT)/,$(T_OBJ))
# Targets Definition 
##############################################################################

# test targets
TEST_TARGET = test_pulse 


# Targets  
##############################################################################

all: $(TEST_TARGET)

# Rule to build all test targets
.PHONY: $(OUT) $(TEST_TARGET)
$(TEST_TARGET): $(OUT) $(T_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(OUT)/$@ $(T_OBJECTS)
	$(OUT)/$@

$(OUT):
	$(MKDIR) $(OUT)

# Rules  
##############################################################################

# Rule to build objects
$(OUT)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
