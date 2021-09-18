# 适合单元测试

# 自动每个.cc 文件生成对应名称的可执行文件
# 自动创建bin文件夹
.PHONY: all clean

SOURCE = $(wildcard *.cc)                 # 当前目录的所有 .cc 文件
TARGETS = $(patsubst %.cc,%,$(SOURCE))    # 将源文件的.cc后缀名去掉

CC = gcc
CXX = g++
CXXFLAGS = --std=c++11 # 这里可以添加头文件寻找的路径 -g -Iinclude -Isrc
# CFLAGS += --std=c++11 -g
LDFLAGS = -lglog       # 链接库，指定搜索路径 -lpmem -lpmemobj -lpthread -lpmem2 -rpath=. -L..

BUILD_DIR = bin
P_DIR = ..

DEPENCES =       # 依赖头文件，只用来检测更新关系
OBJ_SOURCE =     # 被测试的源文件
OBJ_NAME = $(notdir $(OBJ_SOURCE))
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(OBJ_NAME))

all: ${BUILD_DIR} $(TARGETS)

# 编译其他目录的依赖
$(OBJS):$(BUILD_DIR)/%.o:$(P_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)

%:%.cc $(OBJS) $(DEPENCES)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $< $(OBJS) $(LDFLAGS)

${BUILD_DIR}:
	$(shell if [ ! -e $(BUILD_DIR) ];then mkdir -p $(BUILD_DIR); fi)

clean:
	rm -rf $(BUILD_DIR)
