#ifndef _graphics_h
#define _graphics_h

#include "gl.h"

#include <SDL2/SDL_opengl.h>

class Graphics
{
   private:
      bool global_loaded;
      int width;
      int height;
   public:
      Graphics();
      ~Graphics();
      void initialize(int w, int h);
      void resizeWindow(int w, int h);
      int  getScreenWidth();
      int  getScreenHeight();
};

const char *SDL_GetCompiledVersion();

#endif
