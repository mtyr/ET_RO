/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PIDCalculator.cpp
 * Author: Nagomibiyori
 * 
 * Created on 2017/09/02, 18:02
 */

#include "PIDCalculator.h"

PIDCalculator::PIDCalculator() {
    this->_Kp = 0.0f;
    this->_Ki = 0.0f;
    this->_kd = 0.0f;
    this->_diffRefIndex = 0;
    this->_diffRefIndexOld = 0;
    this->_diffSize = 0;
    this->_totalIntegral = 0.0f;
    this->_deltaTime = 0.004f;
}

PIDCalculator::~PIDCalculator() {
    if(this->_diff != 0)delete[] this->_diff;
}

void PIDCalculator::Reset() {
    this->_diffRefIndex = 0;
    this->_diffRefIndexOld = 0;
    for(int i = 0; i < this->_diffSize; i ++) {
        this->_diff[i] = 0;
    }
    this->_totalIntegral = 0;
    this->_target = this->_defaultTarget;
}

void PIDCalculator::SetPID(float Kp, float Ki, float Kd, int integralCount) {
    this->_Kp = Kp;
    this->_Ki = Ki;
    this->_kd = Kd;
    this->_diff = new float[integralCount];
    this->_diffSize = integralCount;
}

/*	引数：目標値	*/
void PIDCalculator::SetTarget(float target) {
    this->_defaultTarget = target;
    this->_target = target;
}

						/*	引数：現在カラー	*/
float PIDCalculator::Get(float current) {
    float p = 0.0f;
    float i = 0.0f;
    float d = 0.0f;
    
    //現在の参照場所に偏差を格納
    this->_diff[this->_diffRefIndex] = (float)(current - this->_target);
    //平均値計算
    this->_average = 0;
    for(int n = 0; n < this->_diffSize; n ++) {
        this->_average += this->_diff[n];
    }
    this->_average /= this->_diffSize;
    
    //積分値更新
    i = this->_average * this->_deltaTime;
    this->_totalIntegral += i;
    
    //P値
    p = this->_Kp * this->_diff[this->_diffRefIndex];
    //I値
    i = this->_Ki * this->_totalIntegral;
    //D値
    d = this->_kd * ((this->_diff[this->_diffRefIndex] - this->_diff[this->_diffRefIndexOld]) / this->_deltaTime);
    
    //参照場所の更新
    this->_diffRefIndexOld = this->_diffRefIndex++;
    if(this->_diffRefIndex == this->_diffSize) this->_diffRefIndex = 0;
    
    return (p + i + d); //(this->_average - this->_target) * 0.0f;
}

float PIDCalculator::GetAverage() {
    return this->_average;
}

