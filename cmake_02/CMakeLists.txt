# Cmake 最低版本要求
cmake_minimum_required(VERSION 3.21)

# 项目信息
project(heidsoft-cpp)

# 该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(heidsoft.exe ${DIR_SRCS})