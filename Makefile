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
INCLUDE=./lib
INCLUDE+=./test
INCLUDE_FLAG=$(addprefix -I,$(INCLUDE))

OUT=./out

VPATH=$(INCLUDE)

# Objects 
##############################################################################

# OBJECTS
OBJECTS = Pulse.o
OBJECTS+= Trigger.o
OBJECTS+= LightBarrier.o
OBJECTS+= CallbackManager.o


# Test - objects
T_OBJ=Pulse.o
T_OBJ+=Trigger.o
T_OBJ+=CallbackManager.o

T_OBJ_PULSE = $(T_OBJ)
T_OBJ_PULSE+=t_pulse.o


T_OBJ_LB = $(T_OBJ)
T_OBJ_LB +=LightBarrier.o
T_OBJ_LB +=t_light_barrier.o


T_OBJECTS=$(addprefix $(OUT)/,$(T_OBJ))
# Targets Definition 
##############################################################################

# test targets
TEST_TARGET = test_pulse 
TEST_TARGET += test_light_barrier 


# Targets  
##############################################################################

all: $(TEST_TARGET)

# Rule to build all test targets
.PHONY: $(OUT) $(TEST_TARGET)

test_pulse: $(OUT) $(T_OBJ_PULSE)
	$(CXX) $(CXXFLAGS) -o $(OUT)/$@ $(T_OBJ_PULSE)
	$(OUT)/$@

test_light_barrier: $(OUT) $(T_OBJ_LB)
	$(CXX) $(CXXFLAGS) -o $(OUT)/$@ $(T_OBJ_LB)
	$(OUT)/$@


$(OUT):
	$(MKDIR) $(OUT)

clean:
	$(RM) -f $(T_OBJECTS) $(OBJECTS) $(TEST_TARGET)
# Rules  
##############################################################################

# Rule to build objects
$(OUT)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
