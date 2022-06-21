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
    case 0:
    
    case 1:
        fPoints.resize(1,2);
        fWeights.resize(1);
        fPoints(0,0)=1./3.;
        fPoints(0,1)=1./3.;
        fWeights[0]=1./2.;
        break;
    case 2:
        fPoints.resize(3,2);
        fWeights.resize(3);
        fPoints(0,0)=2./3.;
        fPoints(0,1)=1./6.;
        fWeights[0]=1./6.;
        fPoints(1,0)=1./6.;
        fPoints(1,1)=2./3.;
        fWeights[1]=1./6.;
        fPoints(2,0)=1./6.;
        fPoints(2,1)=1./6.;
        fWeights[2]=1./6.;
        break;
        // Alterações a partir DAQUI
    case 3:
    case 4:
        fPoints.resize(6,2);
        fWeights.resize(6);
        fPoints(0,0)=-(1./9.)*sqrt(38.-44.*sqrt(2./5.)) + 1./9.*(1.+sqrt(10.));
        fPoints(0,1)=1./18.*(8.-sqrt(10.)+sqrt(38.-44.*sqrt(2./5.)));
        fWeights[0]=(620.+sqrt(155.*(1375. - 344.*sqrt(10.))))/(3720.*2.);
        fPoints(1,0)=1./18.*(8. - sqrt(10.) + sqrt(38. - 44.*sqrt(2./5.)));
        fPoints(1,1)=-(1./9.)*sqrt(38. - 44.*sqrt(2./5.)) + 1./9.*(1. + sqrt(10.));
        fWeights[1]=(620. + sqrt(155.*(1375.-344.*sqrt(10.))))/(3720.*2.);
        fPoints(2,0)=1./18.*(8. - sqrt(10.) + sqrt(38. - 44.*sqrt(2./5.)));
        fPoints(2,1)=1./18.*(8. - sqrt(10.) + sqrt(38. - 44.*sqrt(2./5.)));
        fWeights[2]=(620. + sqrt(155.*(1375. - 344.*sqrt(10.))))/(3720.*2.);
        fPoints(3,0)=1. + 1./9.*(-8. + sqrt(10.) + sqrt(38. - 44.*sqrt(2./5.)));
        fPoints(3,1)= 1./18.*(8. - sqrt(10.) - sqrt(38. - 44.*sqrt(2./5.)));
        fWeights[3]=(1./6. - 1./24.*sqrt(1./155.*(1375. - 344.*sqrt(10.))))/2.;
        fPoints(4,0)=1./18.*(8. - sqrt(10.) - sqrt(38. - 44.*sqrt(2./5.)));
        fPoints(4,1)= 1. + 1./9.*(-8. + sqrt(10.) + sqrt(38. - 44.*sqrt(2./5.)));
        fWeights[4]=(1./6. - 1./24.*sqrt(1./155.*(1375. - 344.*sqrt(10.))))/2.;
        fPoints(5,0)=1./18.*(8. - sqrt(10.) - sqrt(38. - 44.*sqrt(2./5.)));
        fPoints(5,1)=1./18.*(8. - sqrt(10.) - sqrt(38. - 44.*sqrt(2./5.)));
        fWeights[5]= (1./6. - 1./24.*sqrt(1./155.*(1375. - 344.*sqrt(10.))))/2.;
        break;

    case 5:
        fPoints.resize(7,2);
        fWeights.resize(7);
        fPoints(0,0)=(1./21.)*(9.+2.*sqrt(15.));
        fPoints(0,1)=(1./21.)*(6.-sqrt(15.));
        fWeights[0]= (155. -sqrt(15.))/(1200.*2.);
        fPoints(1,0)= (1./21.)*(6.-sqrt(15.));
        fPoints(1,1)= (1./21.)*(9.+2.*sqrt(15.));
        fWeights[1]= (155.-sqrt(15.))/(1200.*2.);
        fPoints(2,0)= (1./21.)*(6.-sqrt(15.));
        fPoints(2,1)= (1./21.)*(6.-sqrt(15.));
        fWeights[2]=(155.-sqrt(15.))/(1200.*2.);
        fPoints(3,0)= (1./21.)*(9.-2.*sqrt(15.));
        fPoints(3,1)= (1./21.)*(6.+sqrt(15.));
        fWeights[3]= (155.+sqrt(15.))/(1200.*2.);
        fPoints(4,0)= (1./21.)*(6.+sqrt(15.));
        fPoints(4,1)= (1./21.)*(9.-2.*sqrt(15.));
        fWeights[4]=(155.+sqrt(15.))/(1200.*2.);
        fPoints(5,0)= (1./21.)*(6.+sqrt(15.));
        fPoints(5,1)= (1./21.)*(6.+sqrt(15.));
        fWeights[5]=(155.+sqrt(15.))/(1200.*2.);
        fPoints(6,0)= 1./3.;
        fPoints(6,1)= 1./3.;
        fWeights[6]= 9./(40.*2.);
        break;
        // Alterações até AQUI
    default:
        DebugStop();
        break;
    }
}
