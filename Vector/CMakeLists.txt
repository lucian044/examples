
# Requires the `cmake` command to be at least version 2.8.
cmake_minimum_required(VERSION 2.8)


# Declares the project name and its implementation language. "CXX"
# means "C++".
project(vector CXX)

# Determine a usable set of sanitizer flags based on the compiler
# and version. If sanitizers aren't supported, or we don't know if
# they are supported, then set those flags to empty.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "5")
    set(SAN_FLAGS "-fsanitize=address -fsanitize=undefined")
  endif()
else()
  set(SAN_FLAGS "")
endif()

# Update the C++ compiler flags so that we use C++14, not the older
# version of the language, C++03. GCC-4.9, the default compiler in
# our labs works with this setting. So does the default compiler on
# an up-to-date Mac OS X system.
set(CMAKE_CXX_FLAGS -std=c++11)


# Declare that we want to build an executable program named "hello".
# This will produce an executable program with that
add_executable(vector main.cpp vector.cpp string.cpp)


# DO NOT REMOVE OR MODIFY THIS MACRO.
#
# This creates a new target for the make program. After
# including this, you can write:
#
#     make printout
#
# And the build system will assemble a PDF containing the
# formatted text in the files listed above. The PDF will
# be created in the build directory and is named "printout.pdf".
#
# To use this, add the following to this file:
#
#     add_printout(f1.hpp f1.cpp f2.hpp f2.cpp ...)
#
# Where f1 and f2 are the files that you want to include
# in the printout. Note that header files should always
# precede their source files.
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()


# Add files to the output.
add_printout(vector.hpp vector.cpp string.hpp string.cpp main.cpp)
