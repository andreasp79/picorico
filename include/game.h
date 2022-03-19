/*
 * xrick/include/game.h
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

#ifndef _GAME_H
#define _GAME_H

#include <stddef.h> /* NULL */

#include "system.h"
#include "config.h"

#include "rects.h"

#define GAME_LEFT 1
#define GAME_RIGHT 0

#define TRUE 1
#define FALSE 0

#define GAME_PERIOD 75

#define GAME_BOMBS_INIT 6
#define GAME_BULLETS_INIT 6

typedef struct {
  U32 score;
  U8 name[10];
} hscore_t;

extern U8 game_lives;      /* lives counter */
extern U8 game_bombs;      /* bombs counter */
extern U8 game_bullets;    /* bullets counter */

extern U32 game_score;     /* score */

extern hscore_t game_hscores[8];  /* highest scores (hall of fame) */

extern U16 game_map;       /* current map */
extern U16 game_submap;    /* current submap */

extern U8 game_dir;        /* direction (GAME_LEFT, GAME_RIGHT) */
extern U8 game_chsm;       /* change submap request (TRUE, FALSE) */

extern U8 game_waitevt;    /* wait for events (TRUE, FALSE) */
extern U8 game_period;     /* time between each frame, in millisecond */

extern rect_t *game_rects; /* rectangles to redraw at each frame */

extern void game_init();
extern int game_update();
extern void game_draw();
extern void game_shutdown();

//extern void game_run(void);
extern void game_setmusic(char *name, U8 loop);
extern void game_stopmusic(void);


#ifdef ENABLE_SOUND
#define WAV_GAMEOVER (1)
#define WAV_SBONUS2  (2)
#define WAV_BULLET  (3)
#define WAV_BOMBSHHT (4)
#define WAV_EXPLODE (5)
#define WAV_STICK (6)
#define WAV_WALK (7)
#define WAV_CRAWL (8)
#define WAV_JUMP (9)
#define WAV_PAD (10)
#define WAV_BOX (11)
#define WAV_BONUS (12)
#define WAV_SBONUS1 (13)
#define WAV_DIE (14)
//#define WAV_ENTITY[]=;
#endif

#endif

/* eof */


