#include "picosystem.hpp"

extern "C"
{
#include "system.h"
#include "game.h"

extern S16 e_bullet_xc ;
}

using namespace picosystem;

int last_frame_time;

char fps_string[64];

voice_t v;
 
 extern "C"
 {
 void PlayTuneLow()
{
  play(v, 400, 500, 100);
  sleep(1000);
}

void PlayTuneHigh()
{
  play(v, 2000, 500, 100);
  sleep(1000);
}

void PlayTuneSuperHigh()
{
  play(v, 6000, 500, 100);
  sleep(1000);
}
 }

void init() 
{
   v = voice(
    200,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    );

    last_frame_time = time();
    sprintf(fps_string, "FPS: ", 0);

    sys_init();
        
    game_init();
}



void update(uint32_t tick) 
{
  //PlayTuneLow();

  game_update();

  //PlayTuneHigh();
   
}

int numFrames = 0;

void draw(uint32_t tick) 
{
  pen(0, 0, 0);
  clear();

  /*

  for (int x = 0; x < 240; ++x)
  {
    for (int y = 0; y < 240; ++y)
    {
      pen(x, y, numFrames);
      pixel(x,y);
    }
  }

  */

  game_draw();

  ++numFrames;
  int timeDiff = time() - last_frame_time;
  if (timeDiff >= 1000)
  {
    float fps = (float)numFrames / (float)(timeDiff/1000.0f);

    numFrames = 0;
    last_frame_time = time();

    sprintf(fps_string, "FPS: %d, var: %d", (int)fps, e_bullet_xc);
  }

  pen(15, 15, 15);
  text(fps_string, 0, 0);

  //char time[255];

  //sprintf(time, "time: %d", sys_gettime()/1000);
  //text(time, 0, 50);

}