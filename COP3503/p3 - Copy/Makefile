# ===== CONFIG =====
BUILD_DIR = build
EXEC = $(BUILD_DIR)/SFMLTest.exe

# ===== DEFAULT =====
all: build

# ===== BUILD =====
build:
	cmake -S . -B $(BUILD_DIR) -G Ninja
	cmake --build $(BUILD_DIR)

# ===== RUN =====
run: build
	./$(EXEC)

# ===== CLEAN =====
clean:
	rm -rf $(BUILD_DIR)

# ===== FORCE REBUILD =====
rebuild: clean build