/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathHelper.cpp
 * Author: Nagomibiyori
 * 
 * Created on 2017/09/02, 13:17
 */

#include "MathHelper.h"

float MathHelper::Clamp(float f, float min, float max) {
    float ret = f;
    if(ret < min) ret = min;
    else if(ret > max) ret = max;
    return ret;
}

int8_t MathHelper::Clamp(int8_t f, int8_t min, int8_t max) {
    int8_t ret = f;
    if(ret < min) ret = min;
    else if(ret > max) ret = max;
    return ret;
}

int8_t MathHelper::Abs(int8_t num) {
    if(num < 0) return -num;
    return num;
}

float MathHelper::Abs(float num) {
    if(num < 0) return -num;
    return num;
}
