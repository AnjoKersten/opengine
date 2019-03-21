#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad.h>
#include <glfw3.h>
#include <string>

#include "stb_image.h"
#include "../Renderer/shader.h"

class Texture {
public:
  Texture();
  virtual ~Texture();
  GLint TextureFromFile(const char *path, std::string directory);
  void loadTexture(const char *file);
  unsigned int texID;
private:
  int width, height, nr;
  unsigned char *data;
};

#endif
