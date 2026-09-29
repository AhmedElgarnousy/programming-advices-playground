# ==============================================================================
# WHATSAPP C++ BOT MAKEFILE
# ==============================================================================

# 1. Compiler and Flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# 2. Project Paths (Modify if your directory names differ)
ROOT_DIR   := /mnt/e/general_courses/programming-advices/stage1/09_Foundations_L2/codeExs/api/whatsapp-api-cpp
SDK_DIR    := $(ROOT_DIR)/whatsapp-api-client-cpp
VCPKG_DIR  := $(SDK_DIR)/vcpkg/installed/x64-linux

# 3. Header Include Paths (-I)
INCLUDES   := -I$(SDK_DIR)/include \
              -I$(SDK_DIR)/src \
              -I$(VCPKG_DIR)/include

# 4. Library Search Paths (-L)
LIB_PATHS  := -L$(SDK_DIR)/build \
              -L$(SDK_DIR)/build/_deps/cpr-build/cpr \
              -L$(VCPKG_DIR)/lib

# 5. Libraries to Link against (-l)
# Order matters: Static custom libraries must come before core system libraries
LIBS       := -lwhatsapp-api-client-cpp -lcpr -lcurl -lssl -lcrypto -lpthread

# 6. Target Executable Name
TARGET     := whatsapp_app
SRCS       := main.cpp

# ==============================================================================
# BUILD RULES
# ==============================================================================

.PHONY: all clean run

# Default target
all: $(TARGET)

# Compile target executable
$(TARGET): $(SRCS)
	@echo "Compiling $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) $(LIB_PATHS) $(LIBS) -o $(TARGET)
	@echo "Build successful!"

# Run application
run: $(TARGET)
	@echo "Running application..."
	./$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning up..."
	rm -f $(TARGET)
