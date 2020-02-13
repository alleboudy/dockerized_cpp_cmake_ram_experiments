# CMakeList.txt : CMake project for TestingMemoryLimits, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestingMemoryLimits")

# Add source to this project's executable.
add_executable (TestingMemoryLimits "TestingMemoryLimits.cpp" "TestingMemoryLimits.h" "LRU.h")

# TODO: Add tests and install targets if needed.
cmake_host_system_information(RESULT available_physical_memory QUERY AVAILABLE_PHYSICAL_MEMORY )
cmake_host_system_information(RESULT num_logical_cores QUERY NUMBER_OF_LOGICAL_CORES )
cmake_host_system_information(RESULT num_phy_cores   QUERY NUMBER_OF_PHYSICAL_CORES   )
cmake_host_system_information(RESULT fqdn QUERY FQDN )
cmake_host_system_information(RESULT host_name QUERY HOSTNAME )
cmake_host_system_information(RESULT tot_virt_mem QUERY TOTAL_VIRTUAL_MEMORY )
cmake_host_system_information(RESULT available_virt_mem   QUERY AVAILABLE_VIRTUAL_MEMORY   )

cmake_host_system_information(RESULT total_phy_mem      QUERY TOTAL_PHYSICAL_MEMORY )
cmake_host_system_information(RESULT available_py_mem  QUERY AVAILABLE_PHYSICAL_MEMORY  )


message(STATUS "#########CMAKE available_physical_memory=${available_physical_memory}")
message(STATUS "#########CMAKE num_logical_cores=${num_logical_cores}")
message(STATUS "#########CMAKE num_phy_cores=${num_phy_cores}")
message(STATUS "#########CMAKE fqdn=${fqdn}")
message(STATUS "#########CMAKE host_name=${host_name}")
message(STATUS "#########CMAKE tot_virt_mem=${tot_virt_mem}")
message(STATUS "#########CMAKE available_virt_mem=${available_virt_mem}")
message(STATUS "#########CMAKE total_phy_mem=${total_phy_mem}")
message(STATUS "#########CMAKE available_py_mem=${available_py_mem}")

add_definitions( -DAVAILABLE_PHY_MEM_MB="${available_physical_memory}"  )