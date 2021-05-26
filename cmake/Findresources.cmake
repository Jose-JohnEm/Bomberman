# Specify the CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

message("Searching for resources updates...")

# Download the last log from the resources' server
file(DOWNLOAD http://51.77.221.38:8080/last.log .last.log)

# Check for new updates by comparing the local timestamp and the server timestamp
execute_process( COMMAND ${CMAKE_COMMAND} -E compare_files
  "${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log"
  "${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log"
                 RESULT_VARIABLE compare_result
)

# If the 2 timestamps are the same, so there's nothing to update
if( compare_result EQUAL 0)
    message("No update detected...")
    file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log)
# Otherwise (if the timestamp are different are even the local timestamp doesn't exist yet),
# so we have to update
else()
    message("Need to be updated !")

    # Download the resources as a compressed tar.gz file
    file(DOWNLOAD http://51.77.221.38:8080/resources.tar.gz resources.tar.gz SHOW_PROGRESS)

    # Uncompress the resource.tar.gz
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E tar xzf resources.tar.gz
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
    )

    # Remove the old resources, then replace by the new resources and set the new timestamp
    file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/resources ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log ${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log)

endif()

#TODO: keyword in majuscule regarder les autres .cmake comme example