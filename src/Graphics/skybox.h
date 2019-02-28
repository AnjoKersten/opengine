#ifndef SKYBOX_H
#define SKYBOX_H

#include <iostream>
#include <vector>
#include "../Texture/stb_image.h"

using namespace std;

class Skybox {
public:
  Skybox() {

  }

  virtual ~Skybox() {}

  unsigned int loadSkybox(string frontPath, string backPath, string bottomPath, string topPath, string leftPath, string rightPath) {
    unsigned int texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces(frontPath, backPath, bottomPath, topPath, leftPath, rightPath).size(); i++)
    {
        unsigned char *data = stbi_load(faces(frontPath, backPath, bottomPath, topPath, leftPath, rightPath)[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            //std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return texID;
  }

  vector<string> faces(string frontPath, string backPath, string bottomPath, string topPath, string leftPath, string rightPath) {
    rightPath,
    leftPath,
    topPath,
    bottomPath,
    frontPath,
    backPath;
  }

private:

};

#endif
