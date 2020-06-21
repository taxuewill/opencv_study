# set minimum required version for cmake
cmake_minimum_required(VERSION 3.10)

# define the project name
set(project_name "opencv_studey")

# set the project name
project("${project_name}")

# this is a C++11 project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add opencv package to the project
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( 
    ${OpenCV_INCLUDE_DIRS} 
    src/include
    ) 
SET(OpenCV_LIBRARIES ${OpenCV_LIBS})

#add_executable(test src/test.cpp)
#target_link_libraries(test ${OpenCV_LIBRARIES})

#add_executable(test1 src/test/test1.cpp)
#target_link_libraries(test1 ${OpenCV_LIBRARIES})


#[[add_executable(test2 src/test/test2.cpp)
target_link_libraries(test2 ${OpenCV_LIBRARIES})

add_executable(test3 src/test/test3.cpp src/test/colordetector.cpp)
target_link_libraries(test3 ${OpenCV_LIBRARIES})

add_executable(test4 src/test/test4.cpp )
target_link_libraries(test4 ${OpenCV_LIBRARIES})


add_executable(test5 src/test/test5.cpp )
target_link_libraries(test5 ${OpenCV_LIBRARIES})

add_executable(test6 src/test/test6.cpp )
target_link_libraries(test6 ${OpenCV_LIBRARIES})

add_executable(test7 src/test/test7.cpp )
target_link_libraries(test7 ${OpenCV_LIBRARIES})

add_executable(test8 src/test/test8.cpp )
target_link_libraries(test8 ${OpenCV_LIBRARIES})


add_executable(c5t1 src/chapter5/c5t1.cpp )
target_link_libraries(c5t1 ${OpenCV_LIBRARIES})

add_executable(c5t2 src/chapter5/c5t2.cpp )
target_link_libraries(c5t2 ${OpenCV_LIBRARIES})

add_executable(c5t3 src/chapter5/c5t3.cpp )
target_link_libraries(c5t3 ${OpenCV_LIBRARIES})

add_executable(c5t4 src/chapter5/c5t4.cpp )
target_link_libraries(c5t4 ${OpenCV_LIBRARIES})

add_executable(c5t5 src/chapter5/c5t5.cpp )
target_link_libraries(c5t5 ${OpenCV_LIBRARIES})

add_executable(c6t1 src/chapter6/c6t1.cpp)
target_link_libraries(c6t1 ${OpenCV_LIBRARIES})
]]
add_executable(tools src/tools/tool.cpp)
target_link_libraries(tools ${OpenCV_LIBRARIES})

add_executable(maptool src/tools/maptool.cpp)
target_link_libraries(maptool ${OpenCV_LIBRARIES})