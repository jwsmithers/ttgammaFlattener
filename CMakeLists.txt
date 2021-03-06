# CMakeLists.txt for event package. It creates a library with dictionary and a main program
set(CMAKE_C_COMPILER /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc493_x86_64_slc6/slc6/gcc49/bin/gcc)
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(ttgammaFlattener)
include_directories(include)


# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist Tree Net Core Matrix Physics)
#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__ttgammaFlatener ttgammaFlattener.h LINKDEF LinkDef.h)
#---Create a shared library with geneated dictionary

add_library(Flattener SHARED Root/ttgammaFlattener.cxx )
target_link_libraries(Flattener ${ROOT_LIBRARIES} )

#---Create  a main program using the library
add_executable(ttgammaFlattener Root/ttgammaFlattener.cxx)
target_link_libraries(ttgammaFlattener Flattener)

add_executable(unshittifyTree Root/unshittifyTree.cxx)
target_link_libraries(unshittifyTree ${ROOT_LIBRARIES})


