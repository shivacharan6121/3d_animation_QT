# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "ASAM_miss_autogen"
  "CMakeFiles/ASAM_miss_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ASAM_miss_autogen.dir/ParseCache.txt"
  )
endif()
