// include configuration options
#include "config.h"


// include standard libraries
#include <iostream>
#include <string>


// include OpenGL and extension handler (based on options)
#if OPENGL_ENTENSION_LIBRARY == GLEW
    #include <GL/glew.h>
    #ifdef __APPLE__
        #include <OpenGL/gl.h>
    #else
        #include <GL/gl.h>
    #endif
#elif OPENGL_ENTENSION_LIBRARY == GLAD
    #ifdef _WIN32
        #define APIENTRY __stdcall
    #endif
    #include <glad/glad.h>
#else // OPENGL_ENTENSION_LIBRARY == EPOXY
    #ifdef __APPLE__
        extern "C" {
            #include <epoxy/gl.h>
        }
    #elif _WIN32
        extern "C" {
            #include <epoxy/gl.h>
            #include <epoxy/wgl.h>
        }
    #else // LINUX
        extern "C" {
            #include <epoxy/gl.h>
            #include <epoxy/glx.h>
    }
    #endif
#endif


// include FreeType
#include <ft2build.h>
#include FT_FREETYPE_H


// include MPI
#ifdef MURAL_USE_MPI
    #include <mpi.h>
#endif


// define MURAL class
class Mural {
private:
    int rank;
    int num_ranks;
    bool mpi_enabled;

public:
    Mural();
    ~Mural();

    void Initialize(int argc, char **argv);
};
