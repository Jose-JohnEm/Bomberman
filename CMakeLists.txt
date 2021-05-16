CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(bomberman VERSION 1.0)

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Add cmake modules folder to cmake path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set this to the minimal version you want to support
FIND_PACKAGE(raylib 3.7) # Let CMake search for a raylib-config.cmake

# Generate a list of files
FILE(GLOB_RECURSE BOMBERMAN_SRCS CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.hpp"
    "src/*.inl"
)

# Set Headers paths
SET(CORE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/Core")
SET(LIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/Lib/")

# This is the main part:
ADD_EXECUTABLE(${PROJECT_NAME} ${BOMBERMAN_SRCS} ${HEADERS_FILES})
# This part downloads raylib and builds it if it's not installed on your system
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib) # Specify libraries or flags to use when linking a given target and/or its dependents

# Specify include directories to use when compiling a given target
# PRIVATE keyword ensure a complete compilation beetwin dependencies
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${CORE_HEADERS_PATH}
    ${LIB_HEADERS_PATH}
)

# That's it! You should have an bomberman executable that you can run. Have fun!