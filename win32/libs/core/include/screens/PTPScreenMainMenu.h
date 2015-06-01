#ifndef PTPSCREENMAINMENU_H
#define PTPSCREENMAINMENU_H

#include "PTPScreenScene.h"

class PTModelAssetPowerup;

class PTPScreenMainMenu : public PTPScreenScene
{
public:
    static PTPScreenMainMenu *shared();
    PTPScreenMainMenu();
    ~PTPScreenMainMenu();

    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenMainMenu );

    virtual void update(float dt);
    void startButtonAction(CCObject* pSender);
    void startCheckpointButton(CCObject* pSender);
    void infoButtonAction(CCObject* pSender);
    void gameServicesButtonAction(CCObject* pSender);
    virtual void shareButtonAction(CCObject* pSender);

    virtual void keyBackClicked();

    void soundOffAction(CCObject *pSender);
    void soundOnAction(CCObject* pSender);

    virtual void onBackFromChildScreen();

    virtual void activatePowerup( PTModelAssetPowerup* powerup, bool aboveCharacter = true);

private:
    PTPObjectButton* _soundOnButton;
    PTPObjectButton* _soundOffButton;
    
    bool _schedulePlayBackgroundMusic;
};

#endif // PTPSCREENMAINMENU_H
