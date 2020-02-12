# CMakeList.txt : CMake project for TestingMemoryLimits, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestingMemoryLimits")

# Add source to this project's executable.
add_executable (TestingMemoryLimits "TestingMemoryLimits.cpp" "TestingMemoryLimits.h" "LRU.h")

# TODO: Add tests and install targets if needed.
cmake_host_system_information(RESULT available_physical_memory QUERY AVAILABLE_PHYSICAL_MEMORY )
message(STATUS "CMAKE MEMORY=${available_physical_memory}")
add_definitions( -DAVAILABLE_PHY_MEM_MB="${available_physical_memory}"  )