TARGET_EXEC ?= crackme

BUILD_DIR ?= ./build
SRC_DIRS ?= ./source
BIN_DIR ?= ./bin
INSTALL_DIR ?= /bin

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find ./include -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXX := g++
STANDARD := -std=c++11
OPT := -O3
WARN_FLAGS := -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual -Wcast-align
DEBUG_FLAGS := -g -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
ASAN := -fsanitize=address,undefined

CPPFLAGS = $(INC_FLAGS) $(STANDARD) $(OPT) $(WARN_FLAGS) $(DEBUG_FLAGS) $(ASAN) -MMD -MP

.PHONY: all
all: $(BUILD_DIR)/$(TARGET_EXEC) $(BIN_DIR)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(BIN_DIR)

$(BIN_DIR):
	$(MKDIR_P) $(BIN_DIR)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp $(BUILD_DIR)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)

.PHONY: install
install: $(BUILD_DIR)/$(TARGET_EXEC) $(INSTALL_DIR)
	sudo cp $(BUILD_DIR)/$(TARGET_EXEC) $(INSTALL_DIR)

$(INSTALL_DIR):
	$(MKDIR_P) $(INSTALL_DIR)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
