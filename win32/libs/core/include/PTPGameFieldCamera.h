#ifndef PTPGAMEFIELDCAMERA_H
#define PTPGAMEFIELDCAMERA_H

#include "cocos2d.h"
#include "box2D/Box2D.h"
#include "models/PTModelGeneralSettings.h"

class PTPGameFieldCamera : public CCNode {
public:
    PTPGameFieldCamera();
    static PTPGameFieldCamera *create();

    void reset();

    void initPhysics(b2World* world);

    virtual void update(float delta);

    void setFocusPoint( CCPoint point );

    CCPoint deltaMove();

    bool isInside(b2Fixture* fixture);
    b2AABB focusBoundingBox();

private:
    CCPoint fitPointInRect(CCPoint p, CCRect rect);
    CCPoint _focusPoint;
    CCRect _focusRect;
    CCPoint _deltaMove;

    PTModelGeneralSettings* _settings;

    b2Body *_edgesBody[ 4 ];
};

#endif // PTPGAMEFIELDCAMERA_H
