#ifndef CONFIG_H
#define CONFIG_H

/**
 A structure for configuration variables
 */
struct config {
  float xRes = 1280;
  float yRes = 720;
  bool isFullscreen = false;
  int fov = 90;
};

#endif
