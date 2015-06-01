#ifndef PTADOBJECT_H
#define PTADOBJECT_H

#include "cocos2d.h"

class PTAdObject
{
public:
    PTAdObject();
    virtual ~PTAdObject();
    virtual void initAdNetork();
    virtual void showBanner();
    virtual void hideBanner();
    virtual void showInterstitial();

};

#endif // PTADOBJECT_H
