# Cmake 最低版本要求
cmake_minimum_required(VERSION 3.21)
# 项目信息
project(heidsoft-cpp)

include_directories("${PROJECT_SOURCE_DIR}add") #添加头文件
add_subdirectory(add)                # 添加 add子目录

aux_source_directory(. DIR_SRCS)
add_executable(heidsoft.exe ${DIR_SRCS}) #指定生成目标
target_link_libraries(heidsoft.exe add)  #添加连接库