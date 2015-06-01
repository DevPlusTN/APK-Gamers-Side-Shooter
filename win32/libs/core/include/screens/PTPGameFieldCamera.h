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
    void setFocusRect( CCRect focusRect );

    CCPoint deltaMove();

    bool isInside(b2Fixture* fixture);
    b2AABB focusBoundingBox();

    float movementSmooth;

private:
    CCPoint fitPointInRect(CCPoint p, CCRect rect);
    CCPoint fitRectInRect(CCRect rIn, CCRect rOut);
    CCPoint _focusPoint;
    CCRect _focusRect;
    CCRect _boundingRect;
    CCPoint _deltaMove;
    PTModelGeneralSettings* _settings;

    b2Body *_edgesBody[ 4 ];
};

#endif // PTPGAMEFIELDCAMERA_H
