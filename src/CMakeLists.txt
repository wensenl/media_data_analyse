##################################################
# 声明CMake的最低要求版本 
cmake_minimum_required(VERSION 2.8)

##################################################
# 指定编译器
SET(CMAKE_STSTEM_NAME Linux)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++) 

##################################################
# 定义项目(工程)名称,  
# 同时定义了以下默认变量:  
# PROJECT_SOURCE_DIR, 代指CMake开始构建的根目录(通常是项目根目录)  
# PROJECT_BINARY_DIR, 代指CMake的编译目录(即执行cmake命令的目录) 
project (ffmpegsample)

##################################################
# 添加头文件的查找目录  
INCLUDE_DIRECTORIES(
./include/ )
# 添加库文件查找目录
#LINK_DIRECTORIES(
#$ENV{install_path_env}/lib/ )

##################################################
# 设定源文件
SET(MEDIA_DATA_SRC 
            ./yuv_rgb_image/yuv_rgb_image.c
            main.c)

##################################################
# 定义库文件
SET(MEDIA_DATA_LIB 
    z 
    m 
    pthread 
    dl)

##################################################
# 设定可执行文件名
SET(MEDIA_DATA_EXE media_data)

##################################################
# 编译可执行程序 
ADD_EXECUTABLE(${MEDIA_DATA_EXE} ${MEDIA_DATA_SRC})

##################################################
# 将指定库文件链接到某个执行文件
TARGET_LINK_LIBRARIES(${MEDIA_DATA_EXE} ${MEDIA_DATA_LIB})
