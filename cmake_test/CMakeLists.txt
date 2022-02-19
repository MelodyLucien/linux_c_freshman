# 1.cmake需要的最低版本
cmake_minimum_required(VERSION 3.20)

# 2.project 名称
project(demo)

# 3.head file path，头文件目录
INCLUDE_DIRECTORIES(include)

# 4. 查找当前目录下的所有源文件,并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)

# 5. 设置c语言版本
set(CMAKE_C_STANDARD 11)

#[[# 6.add executable file，添加要编译的可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRCS} test/tests.c test/tests.cpp)]]

# 7.可以添加多个目标
add_executable(${PROJECT_NAME}2 ${DIR_SRCS})

# 8.可以添加静态库目标
add_library(${PROJECT_NAME}-static STATIC ${DIR_SRCS})

# 静态库链接
# 9. 查找静态库路径
find_library(TestLib ${PROJECT_NAME}-static lib)
target_link_libraries(${PROJECT_NAME}2 LINK_PUBLIC ${TestLib})

# 10. 编译动态链接库
add_library(${PROJECT_NAME}-shared SHARED ${DIR_SRCS})

#[[# 添加子工程
add_subdirectory(test)]]

#[[
 生成动态链接库并进行安装在指定目录
 https://zhuanlan.zhihu.com/p/102955723
]]

#[[
 官方的cmake教程，完美！
 https://cmake.org/cmake/help/latest/guide/tutorial/index.html
]]

