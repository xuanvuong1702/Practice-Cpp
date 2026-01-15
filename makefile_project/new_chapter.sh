#!/bin/bash
# Script để tạo chapter mới cho C Learning Project

set -e

# Kiểm tra argument
if [ "$#" -ne 1 ]; then
    echo "Usage: ./new_chapter.sh <chapter_number>"
    echo "Example: ./new_chapter.sh 04"
    exit 1
fi

CHAPTER_NUM=$1
CHAPTER_NAME="chapter_$CHAPTER_NUM"

# Kiểm tra chapter đã tồn tại chưa
if [ -d "$CHAPTER_NAME" ]; then
    echo "Error: $CHAPTER_NAME already exists!"
    exit 1
fi

echo "Creating new chapter: $CHAPTER_NAME"

# Tạo cấu trúc thư mục
mkdir -p "$CHAPTER_NAME"/{include,src}

# Tạo Makefile
cat > "$CHAPTER_NAME/Makefile" << 'EOF'
# Makefile cho Chapter XX Executable

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
INCLUDES = -I./include -I../common/include -I../source/include
LDFLAGS = -L../build/lib -lsource -lcommon

# Directories
SRC_DIR = src
OBJ_DIR = ../build/obj/CHAPTER_NAME
BIN_DIR = ../build/bin
LIB_DIR = ../build/lib

# Files
TARGET = $(BIN_DIR)/CHAPTER_NAME
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Dependencies
COMMON_LIB = $(LIB_DIR)/libcommon.a
SOURCE_LIB = $(LIB_DIR)/libsource.a

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS) $(COMMON_LIB) $(SOURCE_LIB) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Created executable: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

run: $(TARGET)
	@echo "Running CHAPTER_NAME..."
	@./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Cleaned CHAPTER_NAME"
EOF

# Thay thế CHAPTER_NAME trong Makefile
sed -i "s/CHAPTER_NAME/$CHAPTER_NAME/g" "$CHAPTER_NAME/Makefile"

# Tạo main.c template
cat > "$CHAPTER_NAME/src/main.c" << 'EOF'
#include <stdio.h>
#include "utils.h"      // từ common library
#include "basics.h"     // từ source library

int main(void) {
    printf("===========================================\n");
    printf("    C Learning - CHAPTER_TITLE     \n");
    printf("===========================================\n");
    
    // Viết code của bạn ở đây
    
    printf("\nChapter exercises completed!\n");
    
    return 0;
}
EOF

# Thay thế CHAPTER_TITLE
CHAPTER_TITLE="Chapter $CHAPTER_NUM Exercises"
sed -i "s/CHAPTER_TITLE/$CHAPTER_TITLE/g" "$CHAPTER_NAME/src/main.c"

echo ""
echo "✅ Created $CHAPTER_NAME successfully!"
echo ""
echo "Next steps:"
echo "1. Edit $CHAPTER_NAME/src/main.c to add your code"
echo "2. Add '$CHAPTER_NAME' to MODULES in root Makefile"
echo "3. Run: make $CHAPTER_NAME"
echo ""
echo "Root Makefile update needed:"
echo "MODULES = common source chapter_03 $CHAPTER_NAME"
