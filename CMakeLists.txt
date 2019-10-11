cmake_minimum_required(VERSION 3.12...3.15)

project(CMakeTest 
	VERSION 1.0
	DESCRIPTION "CMakeTest"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
	
set(SRC_DOCTEST
	ExtLibs/doctest/doctest.h
)
source_group("doctest" FILES ${SRC_DOCTEST})
set(SRC_PUGIXML
	ExtLibs/pugixml/pugiconfig.hpp
	ExtLibs/pugixml/pugixml.cpp
	ExtLibs/pugixml/pugixml.hpp
)
source_group("pugixml" FILES ${SRC_PUGIXML})
add_library(CMakeTestExtLib STATIC
	${SRC_DOCTEST}
	${SRC_PUGIXML}
)
target_include_directories(CMakeTestExtLib PUBLIC ExtLibs)
	
set(SRC_MYLIB
	MyLib/func.cpp
	MyLib/func.hpp
)
source_group("MyLib" FILES ${SRC_MYLIB})
add_library(CMakeTestMyLib STATIC
	${SRC_MYLIB}
)
target_include_directories(CMakeTestMyLib PUBLIC MyLib)
target_link_libraries(CMakeTestMyLib PUBLIC CMakeTestExtLib)
	
add_executable(CMakeTestExecutable
	MySource/main.cpp
)
target_link_libraries(CMakeTestExecutable PRIVATE CMakeTestMyLib)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_executable(CMakeTestTest
		Test/main.cpp
	)
	target_link_libraries(CMakeTestTest PRIVATE CMakeTestMyLib)
endif()
