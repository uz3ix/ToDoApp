# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ToDo1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ToDo1_autogen.dir\\ParseCache.txt"
  "ToDo1_autogen"
  )
endif()
