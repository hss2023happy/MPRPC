#设置cmake的最低版本和项目名称
cmake_minimum_required(VERSION 3.16)
project(MPRPC)

#设置可执行文件输出路径
set(EXECUTABLE_OUTPUT ${PROJECT_SOURCE_DIR}/bin)

#设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置项目编译头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/example)

#设置项目库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

#add_subdirectory(src)
add_subdirectory(example)