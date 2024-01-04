include_directories(${PROJECT_SOURCE_DIR}/header)

# 添加源文件路径
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
aux_source_directory(. EXAMPLES_LIST)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# 为每个cpp文件创建一个可执行文件
foreach(EXAMPLE ${EXAMPLES_LIST})
   # 这行代码会获取EXAMPLE文件的名称（不包括扩展名），并将其存储在EXAMPLE_NAME变量中。NAME_WE是一个选项，表示“名称无扩展名”（Name Without Extension）
   get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
   add_executable(${EXAMPLE_NAME} ${EXAMPLE} ${SRC_LIST})
   target_link_libraries(${EXAMPLE_NAME} Threads::Threads)
endforeach()