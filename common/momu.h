/*----------------------------------------------------------------------------
  MoMu: A Mobile Music Toolkit
  Copyright (c) 2010 Nicholas J. Bryan, Jorge Herrera, Jieun Oh, and Ge Wang
  All rights reserved.
    http://momu.stanford.edu/toolkit/
 
  Mobile Music Research @ CCRMA
  Music, Computing, Design Group
  Stanford University
    http://momu.stanford.edu/
    http://ccrma.stanford.edu/groups/mcd/
 
 MoMu is distributed under the following BSD style open source license:
 
 Permission is hereby granted, free of charge, to any person obtaining a 
 copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:
 
 The authors encourage users of MoMu to include this copyright notice,
 and to let us know that you are using MoMu. Any person wishing to 
 distribute modifications to the Software is encouraged to send the 
 modifications to the original authors so that they can be incorporated 
 into the canonical version.
 
 The Software is provided "as is", WITHOUT ANY WARRANTY, express or implied,
 including but not limited to the warranties of MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE and NONINFRINGEMENT.  In no event shall the authors
 or copyright holders by liable for any claim, damages, or other liability,
 whether in an actino of a contract, tort or otherwise, arising from, out of
 or in connection with the Software or the use or other dealings in the 
 software.
 -----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/*! 
 @mainpage MoMu: A Mobile Music Toolkit 
 
 MoMu is a light-weight software toolkit for creating musical instruments and
 experiences on mobile device, and currently supports the iPhone platform 
 (iPhone, iPad, iPod Touches). MoMu provides API's for real-time full-duplex 
 audio, accelerometer, location, multi-touch, networking (via OpenSoundControl),
 graphics, and utilities. The MoMu Toolkit was developed as part of the Mobile
 Music research initiative in Music, Computing & Design group at Stanford 
 University's CCRMA, in collaboration with Smule. MoMu is released under a 
 BSD-like license; while not required, we'd love to know how you are using MoMu
 in your research and products! Email us!
*/
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/*! 
    @file momu.h
	@brief MoMu API uber header
	@author Ge Wang, Nicholas J. Bryan, Jieun Oh, Jorge Hererra
	@date Fall 2009
	@version 1.0.0
 
	Mobile Music research @ CCRMA, Stanford University:
	http://momu.stanford.edu/
*/
/*----------------------------------------------------------------------------*/


#ifndef __MOMU_H__
#define __MOMU_H__


// main mopho API
#include "mo_def.h"
#include "mo_accel.h"
#include "mo_audio.h"
#include "mo_colormap.h"
#include "mo_compass.h"
#include "mo_fft.h"
#include "mo_filter.h"
#include "mo_fun.h"
#include "mo_gfx.h"
#include "mo_io.h"
#include "mo_location.h"
#include "mo_net.h"
#include "mo_thread.h"
#include "mo_touch.h"


#endif
