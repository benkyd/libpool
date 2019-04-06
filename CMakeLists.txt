cmake_minimum_required(VERSION 3.7)
Project(libpool)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD)
set(CMAKE_BUILD_TYPE Release)

set(executable output)
set(SrcDIR ./test)
set(IncludeDIR ./include)

include_directories(${executable} ./libpool)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

file(GLOB SourceFiles 
	${SrcDIR}/*
)

add_executable(${executable} ${SourceFiles})

set_target_properties(${executable} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_link_libraries(${executable}
	Threads::Threads
)
