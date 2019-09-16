# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)

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

add_executable(test src/test.cpp)
target_link_libraries(test ${OpenCV_LIBRARIES})

add_executable(test1 src/test/test1.cpp)
target_link_libraries(test1 ${OpenCV_LIBRARIES})


add_executable(test2 src/test/test2.cpp)
target_link_libraries(test2 ${OpenCV_LIBRARIES})

add_executable(test3 src/test/test3.cpp src/test/colordetector.cpp)
target_link_libraries(test3 ${OpenCV_LIBRARIES})

add_executable(test4 src/test/test4.cpp )
target_link_libraries(test4 ${OpenCV_LIBRARIES})


add_executable(test5 src/test/test5.cpp )
target_link_libraries(test5 ${OpenCV_LIBRARIES})