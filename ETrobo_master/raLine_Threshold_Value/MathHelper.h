/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathHelper.h
 * Author: Nagomibiyori
 *
 * Created on 2017/09/02, 13:17
 */

#ifndef MATHHELPER_H
#define MATHHELPER_H

#include "ev3api.h"

class MathHelper {
public:
    static float Clamp(float f, float min, float max);
    static int8_t Clamp(int8_t f, int8_t min, int8_t max);
    static int8_t Abs(int8_t num);
    static float Abs(float num);
private:
};

#endif /* MATHHELPER_H */

