# CMakeLists.txt

# Always set the cmake min version.
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

# TODO: doc
SET(PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
PROJECT(raylibCPP VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Add cmake modules folder to cmake path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set this to the minimal version you want to support
FIND_PACKAGE(raylib 3.7) # Let CMake search for a raylib-config.cmake

# TODO: doc
FILE(GLOB_RECURSE RAYLIB_SRCS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.inl"
)

# Set Headers paths
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")

# Create our static library target
ADD_LIBRARY(${PROJECT_NAME} STATIC ${RAYLIB_SRCS})

# TODO: doc
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib)

# TODO: doc
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${RAYLIB_HEADERS_PATH}
)