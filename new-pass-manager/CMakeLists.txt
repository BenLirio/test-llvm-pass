cmake_minimum_required(VERSION 3.4.3)
project(HelloLLVM)

# Set the desired LLVM version
set(LLVM_DESIRED_VERSION "10.0")

# Find the LLVM package with the specified version
find_package(LLVM ${LLVM_DESIRED_VERSION} REQUIRED CONFIG)

# Print the actual LLVM version being used
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_library(HelloLLVM MODULE
  HelloLLVM.cpp
)

llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(HelloLLVM LLVM)
