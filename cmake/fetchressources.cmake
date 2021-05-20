CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.11+

message(VERBOSE "Hey")


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

message(VERBOSE "End")