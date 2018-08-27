/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PIDCalculator.h
 * Author: Nagomibiyori
 *
 * Created on 2017/09/02, 18:02
 */

#ifndef PIDCALCULATOR_H
#define PIDCALCULATOR_H

#include "ev3api.h"

class PIDCalculator {
public:
    PIDCalculator();
    virtual ~PIDCalculator();
    
    void Reset();
    void SetPID(float Kp, float Ki, float Kd, int integralCount);
    void SetTarget(float target);
    float Get(float current);
    float GetAverage();
private:
    float _defaultTarget;
    float _target;
    float _deltaTime;
    float _Kp;
    float _Ki;
    float _kd;
    float *_diff;
    int _diffSize;
    int _diffRefIndex;
    int _diffRefIndexOld;
    float _average;
    float _totalIntegral;
};

#endif /* PIDCALCULATOR_H */

