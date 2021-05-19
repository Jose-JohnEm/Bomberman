# CMakeLists.txt

# Always set the cmake min version.
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

# TODO: doc
SET(PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
PROJECT(xray VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# TODO: doc
FILE(GLOB XRAY_SRCS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/XRay/*.cpp"
    "${PROJECT_SOURCE_DIR}/XRay/*.inl"
)

# TODO: doc
ADD_SUBDIRECTORY(Raylib)

# Set Headers paths
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Raylib/")
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/")

# Create our static library target
ADD_LIBRARY(${PROJECT_NAME} STATIC ${XRAY_SRCS})

# TODO: doc
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylibCPP)

# TODO: doc
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${RAYLIB_HEADERS_PATH}
    ${ENGINE_HEADERS_PATH}
)