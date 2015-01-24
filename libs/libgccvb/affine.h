// affine.h
// v0.1 beta (preliminary scaling functions added)
//  functions and macros to make affine transformations easier
//  for use with gccVB
//  written by Parasyte (parasytic_i[at]yahoo.com)


#ifndef __AFFINE_H
#define __AFFINE_H

#include "types.h"
#include "video.h"


#define fixed_7_9(n)		(f32)(n * (1<<9))			//convert from float\int\etc to 7.9 fixed
#define fixed_13_3(n)		(f16)(n * (1<<3))			//convert from float\int\etc to 13.3 fixed
#define inverse_fixed(n)	(f16)((1<<18)/fixed_7_9(n))	//convert from float\int\etc to 7.9 fixed (with inversion)

 //clear a world's affine param table based on world height
void affine_clr_param(u8 world);

//scale an affine background
//world: number of the world to apply scaling to, must be using affine BGM
//centerX/centerY: center point (relative to the world) to scale around.
//imageW/imageH: original image width and height
//scaleX/scaleY: scale factor per axis.
//  lowest positive:  0.0156254
//  highest positive: 512
//  lowest negative:  -512
//  highest negative: -0.015625
//'1' is 100% scale, '2' is 200%, '0.05' is 5%, etc
void affine_scale(u8 world, s16 centerX, s16 centerY, u16 imageW, u16 imageH, float scaleX, float scaleY);

//scale an affine background
//world: number of the world to apply scaling to, must be using affine BGM
//scale: scale factor.
//  lowest positive:  0.0156254
//  highest positive: 512
//  lowest negative:  -512
//  highest negative: -0.015625
//'1' is 100% scale, '2' is 200%, '0.05' is 5%, etc
void affine_fast_scale(u8 world, float scale);

#endif
