#include "resourcemanager.h"

ResourceManager::ResourceManager() {
	std::cout << "_____________________________________"
	std::cout << "New Resource Manager created!" << std::endl;	

}

ResourceManager::~ResourceManager() {

}

GLuint ResourceManager::getTexture(const char* path) {
	if (textures[path] != NULL) {
		return textures[path];
	} else {
		Texture* tex = new Texture();
		tex.loadTexture(path);
		textures[path] = tex;
		std::cout << "return new Texture: " << path << std::endl;
		return tex;
	}
}
