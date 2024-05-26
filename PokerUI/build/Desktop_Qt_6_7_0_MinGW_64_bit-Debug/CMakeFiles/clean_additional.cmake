# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PokerUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PokerUI_autogen.dir\\ParseCache.txt"
  "PokerUI_autogen"
  )
endif()
