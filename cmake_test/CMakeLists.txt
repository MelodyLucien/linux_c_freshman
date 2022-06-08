# 1.cmake需要的最低版本
cmake_minimum_required(VERSION 3.20)

# 2.project 名称
project(demo)

# 3.head file path，头文件目录，可以添加多个
INCLUDE_DIRECTORIES(include)

# 4. 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)

# 5. 设置c语言版本
set(CMAKE_C_STANDARD 11)

# 设置c++版本
set(CMAKE_CXX_STANDARD 17)

#[[# 6.add executable file，添加要编译的可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRCS} test/tests.c test/tests.cpp)]]

# 7.可以添加多个目标
add_executable(${PROJECT_NAME}2 ${DIR_SRCS})

# 8.可以添加静态库目标
add_library(${PROJECT_NAME}-static STATIC ${DIR_SRCS})

# 静态库链接
## 9. 查找静态库路径
find_library(TestLib ${PROJECT_NAME}-static lib)
target_link_libraries(${PROJECT_NAME}2 LINK_PUBLIC ${TestLib})

## 导入引用的静态库
add_library(mmkv STATIC IMPORTED)
set_property(TARGET mmkv PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libmmkv.a)

# 10. 编译动态链接库
add_library(${PROJECT_NAME}-shared SHARED ${DIR_SRCS})

# add gdb debug info
#set(CMAKE_CXX_FLAGS   "-g")
# don't optimize code
#set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )

# 添加编译选项 
option(USE_CONSOLE_LOG "Use console log for dev" ON)

# 根据编译选项添加宏定义
if(USE_CONSOLE_LOG)
    add_definitions(-DDEBUG)
endif()

#add options
option(USE_DEBUG_VERSION "Use debug for development" ON)

#[[# 添加子工程
add_subdirectory(test)]]

# 输出宿主机系统名称，如Linux
message(${CMAKE_HOST_SYSTEM_NAME})

# 输出宿主机处理器架构
message(${CMAKE_HOST_SYSTEM_PROCESSOR})

#[[
 生成动态链接库并进行安装在指定目录
 https://zhuanlan.zhihu.com/p/102955723
]]

#[[
 官方的cmake教程，完美！
 https://cmake.org/cmake/help/latest/guide/tutorial/index.html
]]

