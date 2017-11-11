#include "mural.h"

int main(int argc, char** argv)
{
    Mural *canvas = new Mural();
    canvas->Initialize(argc, argv);

    printf("OpenGL Extension: %d\n", OPENGL_ENTENSION_LIBRARY);

    return 0;
}