cmake_minimum_required (VERSION 3.0)

# project name
project (mural VERSION 1.0.0 DESCRIPTION "multi-screen unified-canvas rendering abstraction library")



#################################
# MURAL Library
#################################

# version number
set (MURAL_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set (MURAL_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set (MURAL_VERSION_PATCH ${PROJECT_VERSION_PATCH})


# options
option (MURAL_USE_MPI "Enable MPI for cluster configurations" OFF)
set (OPENGL_ENTENSION_LIBRARY "GLEW" CACHE STRING "OpenGL extension library to configure MURAL to use")
set_property (CACHE OPENGL_ENTENSION_LIBRARY PROPERTY STRINGS GLEW GLAD EPOXY)


# configure a header file to pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )


# find FreeType
find_package(FreeType REQUIRED)

# find MPI if enabled
if (MURAL_USE_MPI)
    find_package(MPI REQUIRED)
    include_directories ("${MPI_INCLUDE_PATH}")
endif ()

# directories to search for .h files
include_directories (
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
    "${FREETYPE_INCLUDE_DIRS}"
    )

# add the library
add_library(mural SHARED 
    src/mural.cpp
    )

# add libraries to link against
if (MURAL_USE_MPI)
    target_link_libraries (mural 
        ${FREETYPE_LIBRARIES}
        ${MPI_C_LIBRARIES}
        )
else()
    target_link_libraries (mural 
        ${FREETYPE_LIBRARIES}
        )
endif ()



#################################
# MURAL Demo App
#################################

# add the executable
add_executable(demo 
    example/demo.cpp
    )

# add libraries to link against
link_directories(${PROJECT_BINARY_DIR})

if (MURAL_USE_MPI)
    target_link_libraries (demo 
        ${FREETYPE_LIBRARIES}
        ${MPI_C_LIBRARIES}
        mural
        )
else()
    target_link_libraries (mural 
        ${FREETYPE_LIBRARIES}
        mural
        )
endif ()
