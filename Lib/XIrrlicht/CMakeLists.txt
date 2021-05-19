# CMakeLists.txt

# Always set the cmake min version.
cmake_minimum_required(VERSION 3.17)

set (PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
project(XIrrlicht VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

FILE(GLOB XIRRLICHT_SRCS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/XIrrlicht/*.cpp"
    "${PROJECT_SOURCE_DIR}/XIrrlicht/*.hpp"
    "${PROJECT_SOURCE_DIR}/XIrrlicht/*.inl"
    "${PROJECT_SOURCE_DIR}/../interfaces/*.hpp"
)

SET(INTERFACES_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../interfaces/")

add_library(${PROJECT_NAME} STATIC ${XIRRLICHT_SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} irrlicht)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${INTERFACES_HEADERS_PATH}
)
