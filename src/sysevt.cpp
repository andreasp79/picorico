/*
 * xrick/src/sysevt.c
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

/*
 * 20021010 SDLK_n replaced by SDLK_Fn because some non-US keyboards
 *          requires that SHIFT be pressed to input numbers.
 */

//#include <SDL.h>
#include "picosystem.hpp"

extern "C"
{

#include "system.h"
#include "config.h"
#include "game.h"
#include "debug.h"

#include "control.h"
#include "draw.h"



#define SYSJOY_RANGE 3280

#define SETBIT(x,b) x |= (b)
#define CLRBIT(x,b) x &= ~(b)

//static SDL_Event event;

bool ButtonStates[8] = {0,0,0,0,0,0,0,0};

static int processEvents()
{
  bool NewButtonStates[8] ;
  NewButtonStates[0] = picosystem::button(picosystem::UP);
  NewButtonStates[1] = picosystem::button(picosystem::DOWN);
  NewButtonStates[2] = picosystem::button(picosystem::LEFT);
  NewButtonStates[3] = picosystem::button(picosystem::RIGHT);

  NewButtonStates[4] = picosystem::button(picosystem::A);
  NewButtonStates[5] = picosystem::button(picosystem::B);
  NewButtonStates[6] = picosystem::button(picosystem::X);
  NewButtonStates[7] = picosystem::button(picosystem::Y);

  bool KeyUpWentDown = NewButtonStates[0] && !ButtonStates[0];
  bool KeyDownWentDown = NewButtonStates[1] && !ButtonStates[1];
  bool KeyLeftWentDown = NewButtonStates[2] && !ButtonStates[2];
  bool KeyRightWentDown = NewButtonStates[3] && !ButtonStates[3];

  bool KeyAWentDown = NewButtonStates[4] && !ButtonStates[4];
  bool KeyBpWentDown = NewButtonStates[5] && !ButtonStates[5];
  bool KeyXpWentDown = NewButtonStates[6] && !ButtonStates[6];
  bool KeyYWentDown = NewButtonStates[7] && !ButtonStates[7];

  bool KeyUpWentUp = !NewButtonStates[0] && ButtonStates[0];
  bool KeyDownWentUp = !NewButtonStates[1] && ButtonStates[1];
  bool KeyLeftWentUp = !NewButtonStates[2] && ButtonStates[2];
  bool KeyRightWentUp = !NewButtonStates[3] && ButtonStates[3];

  bool KeyAWentUp = !NewButtonStates[4] && ButtonStates[4];
  bool KeyBpWentUp = !NewButtonStates[5] && ButtonStates[5];
  bool KeyXpWentUp = !NewButtonStates[6] && ButtonStates[6];
  bool KeyYWentUp = !NewButtonStates[7] && ButtonStates[7];


#ifdef ENABLE_FOCUS
	SDL_ActiveEvent *aevent;
#endif

  //case SDL_KEYDOWN:
  if (KeyUpWentDown) {
      SETBIT(control_status, CONTROL_UP);
      control_last = CONTROL_UP;
    }
    else if (KeyDownWentDown) {
      SETBIT(control_status, CONTROL_DOWN);
      control_last = CONTROL_DOWN;
    }
    else if (KeyLeftWentDown) {
      SETBIT(control_status, CONTROL_LEFT);
      control_last = CONTROL_LEFT;
    }
    else if (KeyRightWentDown) {
      SETBIT(control_status, CONTROL_RIGHT);
      control_last = CONTROL_RIGHT;
    }
    else if (KeyXpWentDown) {
      SETBIT(control_status, CONTROL_PAUSE);
      control_last = CONTROL_PAUSE;
    }
    else if (KeyYWentDown) {
      SETBIT(control_status, CONTROL_END);
      control_last = CONTROL_END;
    }
    else if (KeyAWentDown) {
      SETBIT(control_status, CONTROL_EXIT);
      control_last = CONTROL_EXIT;
    }
    else if (KeyBpWentDown) {
      SETBIT(control_status, CONTROL_FIRE);
      control_last = CONTROL_FIRE;
    }
   /* else if (key == SDLK_F1) {
      sysvid_toggleFullscreen();
    }
    else if (key == SDLK_F2) {
      sysvid_zoom(-1);
    }
    else if (key == SDLK_F3) {
      sysvid_zoom(+1);
    }*/
#ifdef ENABLE_SOUND
    else if (key == SDLK_F4) {
      syssnd_toggleMute();
    }
    else if (key == SDLK_F5) {
      syssnd_vol(-1);
    }
    else if (key == SDLK_F6) {
      syssnd_vol(+1);
    }
#endif
#ifdef ENABLE_CHEATS
    else if (key == SDLK_F7) {
      game_toggleCheat(1);
    }
    else if (key == SDLK_F8) {
      game_toggleCheat(2);
    }
    else if (key == SDLK_F9) {
      game_toggleCheat(3);
    }
#endif
  //  break;
  //case SDL_KEYUP:
    //key = event.key.keysym.sym;
    if (KeyUpWentUp) {
      CLRBIT(control_status, CONTROL_UP);
      control_last = CONTROL_UP;
    }
    else if (KeyDownWentUp) {
      CLRBIT(control_status, CONTROL_DOWN);
      control_last = CONTROL_DOWN;
    }
    else if (KeyLeftWentUp) {
      CLRBIT(control_status, CONTROL_LEFT);
      control_last = CONTROL_LEFT;
    }
    else if (KeyRightWentUp) {
      CLRBIT(control_status, CONTROL_RIGHT);
      control_last = CONTROL_RIGHT;
    }
    else if (KeyXpWentUp) {
      CLRBIT(control_status, CONTROL_PAUSE);
      control_last = CONTROL_PAUSE;
    }
    else if (KeyYWentUp) {
      CLRBIT(control_status, CONTROL_END);
      control_last = CONTROL_END;
    }
    else if (KeyAWentUp) {
      CLRBIT(control_status, CONTROL_EXIT);
      control_last = CONTROL_EXIT;
    }
    else if (KeyBpWentUp) {
      CLRBIT(control_status, CONTROL_FIRE);
      control_last = CONTROL_FIRE;
    }
   // break;
  /*case SDL_QUIT:
    // player tries to close the window -- this is the same as pressing ESC 
    SETBIT(control_status, CONTROL_EXIT);
    control_last = CONTROL_EXIT;
    break;*/
#ifdef ENABLE_FOCUS
  case SDL_ACTIVEEVENT: {
    aevent = (SDL_ActiveEvent *)&event;
    IFDEBUG_EVENTS(
      printf("xrick/events: active %x %x\n", aevent->gain, aevent->state);
      );
    if (aevent->gain == 1)
      control_active = TRUE;
    else
      control_active = FALSE;
    }
  break;
#endif
#ifdef ENABLE_JOYSTICK
  case SDL_JOYAXISMOTION:
    IFDEBUG_EVENTS(sys_printf("xrick/events: joystick\n"););
    if (event.jaxis.axis == 0) {  /* left-right */
      if (event.jaxis.value < -SYSJOY_RANGE) {  /* left */
	SETBIT(control_status, CONTROL_LEFT);
	CLRBIT(control_status, CONTROL_RIGHT);
      }
      else if (event.jaxis.value > SYSJOY_RANGE) {  /* right */
	SETBIT(control_status, CONTROL_RIGHT);
	CLRBIT(control_status, CONTROL_LEFT);
      }
      else {  /* center */
	CLRBIT(control_status, CONTROL_RIGHT);
	CLRBIT(control_status, CONTROL_LEFT);
      }
    }
    if (event.jaxis.axis == 1) {  /* up-down */
      if (event.jaxis.value < -SYSJOY_RANGE) {  /* up */
	SETBIT(control_status, CONTROL_UP);
	CLRBIT(control_status, CONTROL_DOWN);
      }
      else if (event.jaxis.value > SYSJOY_RANGE) {  /* down */
	SETBIT(control_status, CONTROL_DOWN);
	CLRBIT(control_status, CONTROL_UP);
      }
      else {  /* center */
	CLRBIT(control_status, CONTROL_DOWN);
	CLRBIT(control_status, CONTROL_UP);
      }
    }
    break;
  case SDL_JOYBUTTONDOWN:
    SETBIT(control_status, CONTROL_FIRE);
    break;
  case SDL_JOYBUTTONUP:
    CLRBIT(control_status, CONTROL_FIRE);
    break;
#endif


  for (int i = 0; i < 8; ++i)
  {
    ButtonStates[i] = NewButtonStates[i];
  }

  return (KeyAWentDown || KeyBpWentDown || KeyXpWentDown || KeyYWentDown || KeyUpWentDown || KeyDownWentDown || KeyLeftWentDown || KeyRightWentDown || 
          KeyAWentUp   || KeyBpWentUp   || KeyXpWentUp   || KeyYWentUp   || KeyUpWentUp ||   KeyDownWentUp   || KeyLeftWentUp   || KeyRightWentUp
        ) ? 1 : 0;

}

/*
 * Process events, if any, then return
 */
void
sysevt_poll(void)
{
  //while (SDL_PollEvent(&event))
    
  processEvents();
}

/*
 * Wait for an event, then process it and return
 */
void
sysevt_wait(void)
{
  // SDL_WaitEvent(&event);
  while (processEvents() == 0)
    ;
}

}
/* eof */



