cmake_minimum_required (VERSION 2.8)

# project name
project (mural)

# version number
set (MURAL_VERSION_MAJOR 1)
set (MURAL_VERSION_MINOR 0)

# options
option (MURAL_USE_MPI "Enable MPI for cluster configurations" OFF)

# find MPI if enabled
if (MURAL_USE_MPI)
    find_package(MPI)
endif ()

# configure a header file to pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

# directories to search for .h files
if (MURAL_USE_MPI)
    include_directories (
        "${PROJECT_BINARY_DIR}"
        "${MPI_INCLUDE_PATH}"
        )
else ()
    include_directories (
        "${PROJECT_BINARY_DIR}"
        )
endif ()

# add the executable
add_executable(mural src/mural.cpp)

# add libraries to link against
if (MURAL_USE_MPI)
    target_link_libraries (mural ${MPI_C_LIBRARIES})
endif ()

