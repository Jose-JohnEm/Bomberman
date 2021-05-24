CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.11+

INCLUDE(FetchContent)

message("Searching for ressources updates...")

file(DOWNLOAD http://51.77.221.38:8080/last.log .last.log)

execute_process( COMMAND ${CMAKE_COMMAND} -E compare_files 
  "${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log"
  "${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log"
                 RESULT_VARIABLE compare_result
)


if( compare_result EQUAL 0)
    message("No update detected...")
    file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log)
else()
    message("Need to be updated !")

    file(DOWNLOAD http://51.77.221.38:8080/resources.tar.gz resources.tar.gz SHOW_PROGRESS)
    
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E tar xzf resources.tar.gz
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
    )
    file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/resources ${CMAKE_CURRENT_SOURCE_DIR}/resources)

    file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log ${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log)
endif()
