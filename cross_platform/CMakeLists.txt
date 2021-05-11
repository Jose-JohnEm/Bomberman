CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(bomberman VERSION 1.0)

# Add cmake modules folder to cmake path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set this to the minimal version you want to support
FIND_PACKAGE(raylib 3.7) # Let CMake search for a raylib-config.cmake

# Generate a list of files
FILE(GLOB_RECURSE BOMBERMAN_SRCS CONFIGURE_DEPENDS
    "src/*.cpp"
)

# This is the main part:
ADD_EXECUTABLE(${PROJECT_NAME} ${BOMBERMAN_SRCS})
# This part downloads raylib and builds it if it's not installed on your system
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib)

# That's it! You should have an bomberman executable that you can run. Have fun!