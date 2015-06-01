#ifndef PTPSCREEN_H
#define PTPSCREEN_H

#include "cocos2d.h"
#include "models/PTModelScreen.h"
#include "models/objects/PTModelObjectLabel.h"
#include "objects/PTPObjectButton.h"

#include "ads/PTAdObject.h"

#define kRootCCMenuItemTag 100

class PTPScreenScene;
class PTModelAssetPowerup;

class PTPScreen : public CCLayer
{
public:
	PTPScreen();
    ~PTPScreen();
    virtual bool init();
    static cocos2d::CCScene* scene();
    static PTPScreen *getRunningScreen();

    CREATE_FUNC( PTPScreen );

    bool load(const char* key);
    PTPObjectButton* getButton( const char* key );
    PTModelObjectLabel* getLabel( const char* key);
    void addCustomVectors();
    void update(float dt);

    virtual void onKeyUp( int keyCode );

    void stopBackgroundMusic();
    void playBackgroundMusic();

    void reset();
    virtual void removeAds();

    virtual void deleteObject(PTModelObject *model);
    void hideAds();
    void showAds();

    virtual PTPScreenScene *parentScreenScene();
    virtual void onBackToParentScreen();
    virtual void defaultBackActionHandler();

    virtual void activatePowerup( PTModelAssetPowerup* powerup, bool aboveCharacter = true);

    PTPScreen *getChildScreen();
    static PTPScreen *getTopScreen();

protected:
    PTModelScreen* _model;

    void powerupButtonAction(CCObject* sender);
    void purchaseButtonAction(CCObject* sender);
    virtual void coinShopAction(CCObject* sender);
    void restorePurchasesButtonAction(CCObject* pSender);

    std::map<PTModelObject*, CCNode*> _objectMap;


    PTAdObject* adBanner;

private:

    PTAdObject* adFullscreen;

    CCLabelBMFont *_distanceSessionLabel;
    CCLabelBMFont *_distanceBestLabel;

    CCLabelBMFont *_coinsSessionLabel;
    CCLabelBMFont *_coinsTotalLabel;

};

#endif // PTPSCREEN_H
