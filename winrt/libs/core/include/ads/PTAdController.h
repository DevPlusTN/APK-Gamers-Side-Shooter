#ifndef PTADCONTROLLER_H
#define PTADCONTROLLER_H

#include "ads/PTAdObject.h"
#include "attributes/PTPAttributeAction.h"

class PTAdController
{
public:
    PTAdController();

    static PTAdController* shared();

    void initAdNetworks();

    bool isBannerVisible();

    void showBanner( const char* adNetworkId );
    void hideBanner();
    void showInterstitial( const char* adNetworkId );
    void hideInterstitial( );

    void bannerDidFail(const char* adNetworkId);
    void interstitialDidFail(const char* adNetworkId);

    PTAdObject* bannerObject(const char* adNetworkId);
    PTAdObject* intesrtitialObject(const char* adNetworkId);

    const char* bannerBackup(const char* adNetworkId);
    const char* interstitialBackup(const char* adNetworkId);
    
private:
    PTAdObject* _adBanner;
    PTAdObject* _adInterstitial;

};

#endif // PTADCONTROLLER_H
