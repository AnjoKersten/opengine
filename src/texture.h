#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad.h>
#include <glfw3.h>

#include "stb_image.h"
#include "shader.h"

class Texture {
public:
  Texture(const char *texFile);
  virtual ~Texture();
  unsigned int texID;
private:
  int width, height, nr;
  unsigned char *data;
};

#endif
