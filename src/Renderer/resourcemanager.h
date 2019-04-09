#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>

#include "src/Texture/Texture.h"

class ResourceManager {
public:
	ResourceManager();
	virtual ~ResourceManager();
	GLuint getTexture(const char* path);
private:
	std::map<std::string, Texture*> textures;
};

#endif
