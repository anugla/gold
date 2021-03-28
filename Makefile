# OOB
TARGET_EXEC ?= goldlinux

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
RESOURCE_DIRS ?= ./rsc
RELEASE_DIRS ?= ./release
GOLDSO_DIRS ?= ./goldso

ARGS ?= dev
SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
GSRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
RSCS := $(shell find $(RESOURCE_DIRS))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wint-conversion

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -ldl -lncurses -lcurses -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

./goldso/gold.so:
	cd goldso && make

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) ./goldso/gold.so
	$(RM) ./goldso/gold.o
	$(RM) -r ./build/games

.PHONY: goldso

goldso: ./goldso/gold.so
	cp ./goldso/gold.so .

.PHONY: preprun
	
preprun: ./build/goldlinux ./goldso/gold.so
	mkdir -p ./build/games
	mkdir -p ./build/games/gold
	cp ./goldso/gold.so ./build/games/gold/gold.so

.PHONY: run

run: preprun
	cd build && ./goldlinux $(ARGS)

debug: preprun
	cd build && gdb --args ./goldlinux $(ARGS)

package: preprun LICENSE README.md
	cp ./LICENSE ./build/
	cp ./README.md ./build/

-include $(DEPS)

MKDIR_P ?= mkdir -p

