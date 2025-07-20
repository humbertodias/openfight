#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "graphics.h"
#include "graphicsCore.h"

Graphics::Graphics()
{
   camera = new Camera();
}

Graphics::~Graphics()
{
   delete camera;
}

void Graphics::initialize(int w, int h)
{
   width  = w;
   height = h;

   glClearColor( 0.0f, 0.0f, 0.0f, 0.5f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   glEnable(GL_TEXTURE_2D);

   resizeWindow(w, h);
}

void Graphics::resizeWindow(int w, int h)
{
   GLfloat ratio;

   if(h == 0)
      h = 1;

   ratio = (GLfloat)w/(GLfloat)h;
   glViewport(0, 0, (GLint)w, (GLint)h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glm::mat4 projection = glm::perspective(glm::radians(45.0f), ratio, 0.1f, 200.0f);
   glLoadMatrixf(glm::value_ptr(projection));

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
}

int Graphics::getScreenWidth()
{
   return width;
}

int Graphics::getScreenHeight()
{
   return height;
}
