# Tên của thư mục build
BUILD_DIR = build
# Tên của dự án (được lấy từ CMakeLists.txt)
PROJECT_NAME = MusicPlayer

# Cờ CMake và Make
CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release
MAKE_FLAGS = -j$(shell nproc)

# Mục tiêu mặc định khi chạy make
all: $(BUILD_DIR)
	@$(MAKE) -C $(BUILD_DIR) $(MAKE_FLAGS)

# Tạo thư mục build và chạy CMake
$(BUILD_DIR):
	@echo "Creating build directory..."
	@mkdir -p $(BUILD_DIR)
	@echo "Running CMake..."
	@cd $(BUILD_DIR) && cmake $(CMAKE_FLAGS) ..

# Dọn dẹp file build
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

# Build lại từ đầu
rebuild: clean all

.PHONY: all clean rebuild
