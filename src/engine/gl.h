#ifndef ENGINE_GL_BRIDGE
#define ENGINE_GL_BRIDGE
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#ifndef __APPLE__
#include <GL/gl.h>
#else
#include <OpenGL/gl.h>
#endif
#define CHECK_GL_ERROR(name) {\
    int glerror = glGetError(); \
    if (glerror != 0) \
        std::cout << "error in " << name<< ":" << glerror \
    			  << " @ " __FILE__ << ":" << __LINE__ \
    			  << std::endl; \
}

#define PRINT_GL_CONTEXT { \
	std::cout << "Context @ " << __FILE__ << ":" << __LINE__ << std::endl; \
    std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl; \
    std::cout << "GL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; \
    std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << std::endl; \
    std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << std::endl; \
}

#endif // ENGINE_GL_BRIDGE