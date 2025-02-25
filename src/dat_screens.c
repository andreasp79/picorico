/*
 * xrick/src/scr_data.c
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

#include "system.h"
#include "screens.h"

/*
 * map intro, sprites lists
 */
U8 screen_imapsl[] = {
  0x1b, 0x00,
  0x1c, 0x1d, 0x00,
  0x01, 0x00,
  0x02, 0x03, 0x04, 0x05, 0x06, 0x00,
  0x1e, 0x00,
  0x0d, 0x00,
  0x13, 0x14, 0x00,
  0x1f, 0x00
};

/*
 * map intro, steps
 */
screen_imapsteps_t screen_imapsteps[] = {
  { 0x0000, 0x0002, 0x0002, 0x0000 },

  { 0x000b, 0x0000, 0x0001, 0x0000 },
  { 0x0008, 0x0001, 0x0000, 0x0002 },

  { 0x0000, 0x0000, 0x000c, 0x0000 },

  { 0x000a, 0x0000, 0x0000, 0x0005 },
  { 0x0006, 0x0002, 0x0000, 0x0007 },
  { 0x0005, 0x0000, 0x0000, 0x0005 },

  { 0x0000, 0x0006, 0x0000, 0x0000 },

  { 0x000c, 0x0000, 0x0001, 0x0000 },
  { 0x0005, 0x0000, 0x0000, 0x000d },

  { 0x0000, 0x000c, 0x000c, 0x0000 },

  { 0x0005, 0x0000, 0x0000, 0x0005 },
  { 0x000a, 0x0000, 0x0000, 0x000f },
  { 0x000c, 0xffff, 0x0000, 0x0011 },
  { 0x0005, 0x0000, 0x0000, 0x000f },

  { 0x0000, 0x0006, 0x0001, 0x0000 },

  { 0x000a, 0x0000, 0x0000, 0x0014 },
  { 0x0006, 0x0000, 0x0001, 0x0014 },
  { 0x0005, 0x0000, 0x0000, 0x0014 },
  { 0x0003, 0x0001, 0x0000, 0x0014 },
  { 0x0006, 0xffff, 0x0000, 0x0014 },
  { 0x0003, 0x0000, 0xffff, 0x0014 },

  { 0x0000, 0x0000, 0x0000, 0x0000 }
};

/*
 * map intro, step offset per map
 */
U8 screen_imapsofs[] = {
  0x00, 0x03, 0x07, 0x0a, 0x0f
};

/*
 * map intro, text
 * (from ds + 0x8810 + 0x2000, 0x2138, 0x2251, 0x236a, 0x2464)
 *
 * \376=0xfe \377=0xff
 */
U8 screen_imaptext_amazon[] = "\
@@@@@SOUTH@AMERICA@1945@@@@@@@\377\
RICK@DANGEROUS@CRASH@LANDS@HIS\377\
@PLANE@OVER@THE@AMAZON@WHILE@@\377\
@SEARCHING@FOR@THE@LOST@GOOLU@\377\
@@@@@@@@@@@@TRIBE.@@@@@@@@@@@@\377\377\
@BUT,@BY@A@TERRIBLE@TWIST@OF@@\377\
FATE@HE@LANDS@IN@THE@MIDDLE@OF\377\
@@@A@BUNCH@OF@WILD@GOOLUS.@@@@\377\377\
@@CAN@RICK@ESCAPE@THESE@ANGRY@\377\
@@@AMAZONIAN@ANTAGONISTS@?@@@@\376";

U8 screen_imaptext_egypt[] = "\
@@@@EGYPT,@SOMETIMES@LATER@@@@\377\
RICK@HEADS@FOR@THE@PYRAMIDS@AT\377\
@@@@THE@REQUEST@OF@LONDON.@@@@\377\377\
HE@IS@TO@RECOVER@THE@JEWEL@OF@\377\
ANKHEL@THAT@HAS@BEEN@STOLEN@BY\377\
FANATICS@WHO@THREATEN@TO@SMASH\377\
@IT,@IF@A@RANSOM@IS@NOT@PAID.@\377\377\
CAN@RICK@SAVE@THE@GEM,@OR@WILL\377\
HE@JUST@GET@A@BROKEN@ANKHEL@?@\376";

U8 screen_imaptext_castle[] = "\
@@@@EUROPE,@LATER@THAT@WEEK@@@\377\
@@RICK@RECEIVES@A@COMMUNIQUE@@\377\
@@FROM@BRITISH@INTELLIGENCE@@@\377\
@@ASKING@HIM@TO@RESCUE@ALLIED@\377\
@PRISONERS@FROM@THE@NOTORIOUS@\377\
@@@@SCHWARZENDUMPF@CASTLE.@@@@\377\377\
@@RICK@ACCEPTS@THE@MISSION.@@@\377\377\
@@@BUT@CAN@HE@LIBERATE@THE@@@@\377\
@CRUELLY@CAPTURED@COOMANDOS@?@\376";

U8 screen_imaptext_missile[] = "\
@@@@@@EUROPE,@EVEN@LATER@@@@@@\377\
RICK@LEARNS@FROM@THE@PRISONERS\377\
@THAT@THE@ENEMY@ARE@TO@LAUNCH@\377\
AN@ATTACK@ON@LONDON@FROM@THEIR\377\
@@@@@SECRET@MISSILE@BASE.@@@@@\377\377\
WITHOUT@HESITATION,@HE@DECIDES\377\
@@@TO@INFILTRATE@THE@BASE.@@@@\377\377\
CAN@RICK@SAVE@LONDON@IN@TIME@?\376";

U8 screen_imaptext_muchlater[] = "\
@@@LONDON,@MUCH,@MUCH@LATER@@@\377\
@RICK@RETURNS@TO@A@TRIUMPHANT@\377\
@@WELCOME@HOME@HAVING@HELPED@@\377\
@@@@SECURE@ALLIED@VICTORY.@@@@\377\377\
BUT,@MEANWHILE,@IN@SPACE,@THE@\377\
@@@MASSED@STARSHIPS@OF@THE@@@@\377\
@@@BARFIAN@EMPIRE@ARE@POISED@@\377\
@@@@@TO@INVADE@THE@EARTH.@@@@@\377\377\
@WHAT@WILL@RICK@DO@NEXT@...@?@\376";

U8 *screen_imaptext[5] =
{ screen_imaptext_amazon,
  screen_imaptext_egypt,
  screen_imaptext_castle,
  screen_imaptext_missile,
  screen_imaptext_muchlater
};

/*
 * main intro, hall of fame title
 * (from ds + 0x8810 + 0x2642)
 */
U8 screen_imainhoft[] =
{ 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0xd4, 0xb7, 0xb1,
  0xac, 0xc6, 0x2f, 0xc6, 0x2f, 0x2f, 0xa4, 0xac,
  0x9b, 0xc1, 0x2f, 0x9b, 0xc1, 0xb1, 0xac, 0xb6,
  0xbd, 0x9b, 0xc1, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f,
  0xff,
  0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0xb2, 0xb3, 0xb2,
  0xb3, 0xad, 0x2f, 0xad, 0x2f, 0x2f, 0xa6, 0xae,
  0xc2, 0xc3, 0x2f, 0xc2, 0xc3, 0xb2, 0xb3, 0xbe,
  0xbf, 0xc2, 0xc3, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f,
  0xff,
  0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x9f, 0xc0, 0xb4,
  0xb5, 0xaf, 0xc4, 0xaf, 0xc4, 0x2f, 0xa7, 0xb0,
  0xb4, 0x2f, 0x2f, 0xb4, 0x2f, 0xb4, 0xb5, 0xb4,
  0xb5, 0xaf, 0xc4, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f,
  0xfe
};

/*
 * main intro, Rick Dangerous title
 * (from ds + 0x8810 + 0x27a1)
 */
U8 screen_imainrdt[] =
{ 0x2f, 0x2f, 0x2f, 0x9b, 0x9c, 0xa1, 0xa4, 0xa5,
  0xa9, 0xaa, 0x2f, 0x9b, 0xac, 0xb1, 0xac, 0xb6,
  0xb7, 0xa4, 0xa5, 0x9b, 0xc1, 0x9b, 0x9c, 0xa4,
  0xac, 0xc6, 0xc7, 0xc8, 0xc9, 0x2f, 0x2f, 0x2f,
  0xff,
  0x2f, 0x2f, 0x2f, 0x9d, 0x9e, 0xa2, 0xa6, 0x2f,
  0x9d, 0xab, 0x2f, 0xad, 0xae, 0xb2, 0xb3, 0xb8,
  0xb9, 0xa6, 0xbb, 0xc2, 0xc3, 0x9d, 0x9e, 0xa6,
  0xae, 0xad, 0xae, 0xca, 0xcb, 0x2f, 0x2f, 0x2f,
  0xff,
  0x2f, 0x2f, 0x2f, 0x9f, 0xa0, 0xa3, 0xa7, 0xa8,
  0x9f, 0xa0, 0x2f, 0xaf, 0xb0, 0xb4, 0xb5, 0x9f,
  0xba, 0xa7, 0xbc, 0xaf, 0xc4, 0x9f, 0xa0, 0xa7,
  0xb0, 0xc5, 0xb0, 0xcc, 0xb0, 0x2f, 0x2f, 0x2f,
  0xfe
};

/*
 * congratulations
 * (from ds + 0x8810 + 0x257d)
 */
 
U8 screen_congrats[] =
{ 0xa4, 0xa5, 0xa4, 0xac, 0xb6, 0xb7, 0xa4, 0xa5,
  0x9b, 0x9c, 0xb1, 0xac, 0xcd, 0xce, 0xc6, 0xc7,
  0xd3, 0x2f, 0xb1, 0xac, 0xcd, 0xce, 0xa1, 0xa4,
  0xac, 0xb6, 0xb7, 0xc8, 0xc9, 0x2f, 0xd5, 0xd6,
  0xff,
  0xa6, 0x2f, 0xa6, 0xae, 0xb8, 0xb9, 0xa6, 0xbb,
  0x9d, 0x9e, 0xb2, 0xb3, 0xcf, 0xd0, 0xad, 0xae,
  0xad, 0x2f, 0xb2, 0xb3, 0xcf, 0xd0, 0xa2, 0xa6,
  0xae, 0xb8, 0xb9, 0xca, 0xcb, 0x2f, 0xd7, 0xd8,
  0xff,
  0xa7, 0xa8, 0xa7, 0xb0, 0x9f, 0xba, 0xa7, 0xbc,
  0x9f, 0xa0, 0xb4, 0xb5, 0xd1, 0xd2, 0xc5, 0xb0,
  0xaf, 0xc4, 0xb4, 0xb5, 0xd1, 0xd2, 0xa3, 0xa7,
  0xb0, 0x9f, 0xba, 0xcc, 0xb0, 0x2f, 0xd9, 0xda,
  0xfe
};

/*
 * main intro, Core Design copyright text
 * (from ds + 0x8810 + 0x2288)
 *
 * \376=0xfe \377=0xff
 */
U8 screen_imaincdc[] = "\
@@@@@@@@@@@@@@@@@@@\377\377\
(C)@1989@CORE@DESIGN\377\377\377\
@PRESS@SPACE@TO@START\376";

/*
 * gameover
 * (from ds + 0x8810 + 0x2864)
 *
 * \376=0xfe \377=0xff
 */
U8 screen_gameovertxt[] = "\
@@@@@@@@@@@\377\
@GAME@OVER@\377\
@@@@@@@@@@@\376";

/*
 * paused
 *
 * \376=0xfe \377=0xff
 */
U8 screen_pausedtxt[] = "\
@@@@@@@@@@\377\
@@PAUSED@@\377\
@@@@@@@@@@\376";

/* eof */








