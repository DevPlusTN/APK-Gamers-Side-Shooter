#ifndef PTPObjectAccelerometer_H
#define PTPObjectAccelerometer_H


#include "PTPObjectManipulator.h"
#include "cocos2d.h"

using namespace cocos2d;

class PTModelObject;

class PTPObjectAccelerometer : public PTPObjectManipulator, public CCAccelerometerDelegate
{
public:
    PTPObjectAccelerometer();
    static PTPObjectAccelerometer * create(PTModelObject *model);

    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
};

#endif // PTPObjectAccelerometer_H
