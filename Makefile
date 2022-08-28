V=1
SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

all: purrfect.z64
.PHONY: all

OBJS = $(BUILD_DIR)/main.o

purrfect.z64: N64_ROM_TITLE="Purrfect Apawcalypse 64"
purrfect.z64: $(BUILD_DIR)/purrfect.dfs

$(BUILD_DIR)/purrfect.dfs: $(wildcard filesystem/*)
$(BUILD_DIR)/purrfect.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
