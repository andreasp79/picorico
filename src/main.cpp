#include "picosystem.hpp"
#include "system.h"

using namespace picosystem;

int last_frame_time;

char fps_string[64];

void init() 
{
    last_frame_time = time();
    sprintf(fps_string, "FPS: ", 0);
}

void update(uint32_t tick) 
{

}

int numFrames = 0;

void draw(uint32_t tick) 
{
  pen(0, 0, 0);
  clear();

  for (int x = 0; x < 240; ++x)
  {
    for (int y = 0; y < 240; ++y)
    {
      pen(x, y, numFrames);
      pixel(x,y);
    }
  }

  ++numFrames;
  int timeDiff = time() - last_frame_time;
  if (timeDiff >= 1000)
  {
    float fps = (float)numFrames / (float)(timeDiff/1000.0f);

    numFrames = 0;
    last_frame_time = time();

    sprintf(fps_string, "FPS22: %d", (int)fps);
  }

  pen(15, 15, 15);
  text(fps_string, 0, 0);

  char time[255];

  //sprintf(time, "time: %d", sys_gettime()/1000);
  //text(time, 0, 50);

}