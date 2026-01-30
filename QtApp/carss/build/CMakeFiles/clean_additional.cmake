# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\carss_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\carss_autogen.dir\\ParseCache.txt"
  "carss_autogen"
  )
endif()
