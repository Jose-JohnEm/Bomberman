CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.11+

message(VERBOSE "Hey")


INCLUDE(FetchContent)
FetchContent_Declare(
  ressources
  URL http://51.77.221.38:8080/resources.tar.gz
)

SET(FETCHCONTENT_QUIET NO)
FetchContent_GetProperties(ressources)
if (NOT ressources_POPULATED)
    FetchContent_Populate(ressources)
endif ()

file(RENAME ${ressources_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/resources)

message(VERBOSE "End")