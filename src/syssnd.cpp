/*
 * xrick/src/syssnd.c
 *
 * Copyright (C) 1998-2002 BigOrno (bigorno@bigorno.net). All rights reserved.
 *
 * The use and distribution terms for this software are contained in the file
 * named README, which can be found in the root of this distribution. By
 * using this software in any fashion, you are agreeing to be bound by the
 * terms of this license.
 *
 * You must not remove this notice, or any other, from this software.
 */

#include <stdlib.h>
#include <memory.h>
#include "picosystem.hpp"

using namespace picosystem;

extern "C"
{

#include "config.h"

#ifdef ENABLE_SOUND

#include "system.h"
#include "game.h"
#include "syssnd.h"
#include "debug.h"

picosystem::voice_t v_Walk;


extern void PlayTuneSuperHigh();


static U8 sndMute = FALSE;  /* mute flag */

/*
 * Callback -- this is also where all sound mixing is done
 *
 * Note: it may not be that much a good idea to do all the mixing here ; it
 * may be more efficient to mix samples every frame, or maybe everytime a
 * new sound is sent to be played. I don't know.
 */
void syssnd_callback(UNUSED(void *userdata), U8 *stream, int len)
{
  
}

static void
end_channel(U8 c)
{

}

void
syssnd_init(void)
{
  v_Walk = picosystem::voice(
    200,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    );
}

/*
 * Shutdown
 */
void
syssnd_shutdown(void)
{
  
}

/*
 * Toggle mute
 *
 * When muted, sounds are still managed but not sent to the dsp, hence
 * it is possible to un-mute at any time.
 */
void
syssnd_toggleMute(void)
{
  
  sndMute = !sndMute;
}

void
syssnd_vol(S8 d)
{
  
}

/*
 * Play a sound
 *
 * loop: number of times the sound should be played, -1 to loop forever
 * returns: channel number, or -1 if none was available
 *
 * NOTE if sound is already playing, simply reset it (i.e. can not have
 * twice the same sound playing -- tends to become noisy when too many
 * bad guys die at the same time).
 */
S8
syssnd_play(int sound, S8 loop)
{
  if (sndMute == FALSE)
    return 0;

  if (sound == 1)
  {
    //PlayTuneSuperHigh();
  }
  switch(sound)
  {
    case WAV_WALK:
      picosystem::play(v_Walk, 6000, 500, 100);
      break;

    case WAV_JUMP:
       PlayTuneSuperHigh();
      break;


      case WAV_CRAWL:
      PlayTuneSuperHigh();
      break;

      case 9999999:
      //PlayTuneSuperHigh();
      break;
  }
}

/*
 * Pause
 *
 * pause: TRUE or FALSE
 * clear: TRUE to cleanup all sounds and make sure we start from scratch
 */
void
syssnd_pause(U8 pause, U8 clear)
{
  
}

/*
 * Stop a channel
 */
void
syssnd_stopchan(S8 chan)
{
  
}

/*
 * Stop a sound
 */
void
syssnd_stopsound(int sound)
{
	
}

/*
 * See if a sound is playing
 */
int
syssnd_isplaying(int sound)
{
  return 0;
}


/*
 * Stops all channels.
 */
void
syssnd_stopall(void)
{
	
}


/*
 *
 */
void
syssnd_free(int s)
{
	
}



#endif /* ENABLE_SOUND */

/* eof */


} // extern "C"