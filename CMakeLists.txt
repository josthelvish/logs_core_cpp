cmake_minimum_required(VERSION 3.9.6)
project(logs_core_cpp)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -O3 -fPIC ")
#set(Casablanca_LIBRARIES "-lboost_system -lcrypto -lssl -lcpprest")


link_directories(dependencies/libs/Linux/64/)
include_directories(dependencies/include)


add_executable(logs_core_cpp main.cpp)
#target_link_libraries(logs_core_cpp  ${Casablanca_LIBRARIES})
target_link_libraries(logs_core_cpp
        cpprest
        boost_system
        ssl
        crypto
        dl
        pthread
        )
