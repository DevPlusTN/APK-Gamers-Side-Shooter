#ifndef PTPObjectManipulator_H
#define PTPObjectManipulator_H

#include "cocos2d.h"

using namespace cocos2d;

class PTModelObject;
class PTModelObjectManipulator;

class PTPObjectManipulator : public CCNode
{
public:
    PTPObjectManipulator();
    static PTPObjectManipulator * create();

    void setModel( PTModelObject* model);
    PTModelObjectManipulator* model();

    float sensitivity();
    bool isAbsoluteControlStyle();

private:
    PTModelObjectManipulator *_model;
    bool _absoluteControlStyle;
};

#endif // PTPObjectManipulator_H
