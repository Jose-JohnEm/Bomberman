CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(bomberman VERSION 1.0)

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
# Call the fetch_ressources module
include(cmake/fetchressources.cmake)

# Make XRay CMakeList meta-compile XRay library that himself
# will make Raylib-cpp meta compile
# It will be linked with our Bomberman project
ADD_SUBDIRECTORY(Lib/XRaylib)
=======
# Set modules
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
SET(Irrlicht_DIR "${CMAKE_SOURCE_DIR}/modules/Irrlicht/")
SET(SFMLAudio_DIR "${CMAKE_SOURCE_DIR}/modules/SFMLAudio/")

# Add cmake modules folder to cmake path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set this to the minimal version you want to support
FIND_PACKAGE(raylib 3.7) # Let CMake search for a raylib-config.cmake
FIND_PACKAGE(Irrlicht REQUIRED)
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES(${Irrlicht_INCLUDE_DIRS})
>>>>>>> 947524d (Push)

# Generate a list of files
FILE(GLOB_RECURSE SRCS CONFIGURE_DEPENDS
    "Engine/*.cpp"
    "Engine/*.inl"
)

# Set Headers paths
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Engine/")
SET(XRAY_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Lib/XRaylib/XRay/")
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Lib/XRaylib/Raylib/")

# This is the main part:
ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS} ${HEADERS_FILES})
# This part downloads raylib and builds it if it's not installed on your system
<<<<<<< HEAD
TARGET_LINK_LIBRARIES(${PROJECT_NAME} xray) # Specify libraries or flags to use when linking a given target and/or its dependents
=======
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib) # Specify libraries or flags to use when linking a given target and/or its dependents
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Irrlicht) # Specify libraries or flags to use when linking a given target and/or its dependents
>>>>>>> 947524d (Push)

# Specify include directories to use when compiling a given target
# PRIVATE keyword ensure a complete compilation beetwin dependencies
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${ENGINE_HEADERS_PATH}
    ${XRAY_HEADERS_PATH}
    ${RAYLIB_HEADERS_PATH}
)

# That's it! You should have an bomberman executable that you can run. Have fun!