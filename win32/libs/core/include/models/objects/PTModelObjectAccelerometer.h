#ifndef PTMODELOBJECTACCELEROMETER_H
#define PTMODELOBJECTACCELEROMETER_H

#include "PTModelObjectManipulator.h"

class PTModelObjectAccelerometer : public PTModelObjectManipulator
{
public:
    PTModelObjectAccelerometer(CCString className = "PTModelObjectAccelerometer");

    static PTModel * create() {
        return new PTModelObjectAccelerometer();
    }

};

#endif // PTMODELOBJECTACCELEROMETER_H
