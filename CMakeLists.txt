cmake_minimum_required(VERSION 3.5)

project(testcapnp)

get_filename_component(PARENT_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CAPNPC_SRC_PREFIX "capnp")
set(CAPNPC_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gen/)

find_package(CapnProto REQUIRED)

add_definitions(${CAPNP_DEFINITIONS})
file(MAKE_DIRECTORY ${CAPNPC_OUTPUT_DIR})
capnp_generate_cpp(CAPNP_SRCS CAPNP_HDRS ${CAPNPC_SRC_PREFIX}/data.capnp)

add_executable(testcapnp main.cpp ${CAPNP_SRCS})
target_link_libraries(testcapnp ${CAPNP_LIBRARIES})

