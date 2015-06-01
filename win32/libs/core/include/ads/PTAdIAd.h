#ifndef PTADIAD_H
#define PTADIAD_H

#include "PTAdObject.h"

class PTAdIAd : public PTAdObject
{
public:
    PTAdIAd();
    ~PTAdIAd();
    static PTAdIAd* shared();
    virtual void showBanner();
    virtual void hideBanner();
};

#endif // PTADIAD_H
