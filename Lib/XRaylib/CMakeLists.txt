# CMakeLists.txt

# Always set the cmake min version.
cmake_minimum_required(VERSION 3.17)

set (PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
project(XRay VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

FILE(GLOB XRAY_SRCS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/XRay/*.cpp"
    "${PROJECT_SOURCE_DIR}/XRay/*.hpp"
    "${PROJECT_SOURCE_DIR}/XRay/*.inl"
    "${PROJECT_SOURCE_DIR}/../../Engine/Interfaces/*.hpp"
)

add_subdirectory(Raylib)

# Set Headers paths
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Raylib/")
SET(INTERFACES_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/Interfaces/")
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/Interfaces/")
# Create our library target
add_library(${PROJECT_NAME} STATIC ${XRAY_SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib-cpp)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${RAYLIB_HEADERS_PATH}
    ${INTERFACES_HEADERS_PATH}
    ${ENGINE_HEADERS_PATH}
)