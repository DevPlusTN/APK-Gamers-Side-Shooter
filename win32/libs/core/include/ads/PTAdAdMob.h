#ifndef PTADADMOB_H
#define PTADADMOB_H

#include "PTAdObject.h"

class PTAdAdMob : public PTAdObject
{
public:
    PTAdAdMob();
    ~PTAdAdMob();
    static PTAdAdMob* shared();
    virtual void initAdNetork();
    virtual void showBanner();
    virtual void hideBanner();
    virtual void showInterstitial();

    void prebuildInterstitial();

    bool isScheduledForShowing;

private:
    void prebuildBanner();

};

#endif // PTADADMOB_H
