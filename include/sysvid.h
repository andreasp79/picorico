/*
 * xrick/include/sysvid.h
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

#ifndef _VIDEOEX_H
#define _VIDEOEX_H

#include "system.h"

extern U16 *sysvid_fb;  /* frame buffer */

extern U16 get_sys_palette_color(U8 colorIdx);

#endif

/* eof */


