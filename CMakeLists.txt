CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(bomberman VERSION 1.0)

INCLUDE(FetchContent)
FetchContent_Declare(
  ressources
  URL https://github.com/Jose-JohnEm/indie-studio-ressources/raw/master/ressources.zip
)

SET(FETCHCONTENT_QUIET NO)
FetchContent_GetProperties(ressources)
if (NOT ressources_POPULATED)
    FetchContent_Populate(ressources)
endif ()

file(RENAME ${ressources_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/r-test)

#FetchContent_MakeAvailable(ressources SUBBUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/r-test)

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Make XRay CMakeList meta-compile XRay library that himself
# will make Raylib-cpp meta compile
# It will be linked with our Bomberman project
ADD_SUBDIRECTORY(Lib/XRaylib)

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
TARGET_LINK_LIBRARIES(${PROJECT_NAME} xray) # Specify libraries or flags to use when linking a given target and/or its dependents

# Specify include directories to use when compiling a given target
# PRIVATE keyword ensure a complete compilation beetwin dependencies
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${ENGINE_HEADERS_PATH}
    ${XRAY_HEADERS_PATH}
    ${RAYLIB_HEADERS_PATH}
)

# That's it! You should have an bomberman executable that you can run. Have fun!