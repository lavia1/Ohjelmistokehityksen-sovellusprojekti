# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cardatabase_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cardatabase_autogen.dir\\ParseCache.txt"
  "cardatabase_autogen"
  )
endif()
