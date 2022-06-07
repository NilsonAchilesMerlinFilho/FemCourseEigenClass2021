/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

///\cond
#include <iostream> 
///\endcond
#include "IntRuleTriangle.h"

IntRuleTriangle::IntRuleTriangle(){

}

IntRuleTriangle::IntRuleTriangle(int order) {
    SetOrder(order);
}

void IntRuleTriangle::SetOrder(int order) {
    fOrder = order;
    if(order < 0 || order > MaxOrder()){
        DebugStop();
    }

    switch (order)
    {
    case 1:
        fPoints.resize(1,2);
        fWeights.resize(1);
        fPoints(0,0)=1/3;
        fPoints(0,1)=1/3;
        fWeights[0]=1;
        break;
    case 2:
        fPoints.resize(3,2);
        fWeights.resize(3);
        fPoints(0,0)=2/3;
        fPoints(0,1)=1/6;
        fWeights[0]=1/3;
        fPoints(1,0)=1/6;
        fPoints(1,1)=2/3;
        fWeights[1]=1/3;
        fPoints(2,0)=1/6;
        fPoints(2,1)=1/6;
        fWeights[2]=1/3;
        break;
    
    default:
        DebugStop();
        break;
    }
}
