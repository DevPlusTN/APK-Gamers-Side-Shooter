#ifndef PTPSETTINGSCONTROLLER_H
#define PTPSETTINGSCONTROLLER_H

#include "cocos2d.h"
#include "models/objects/PTModelAssetPowerup.h"
#include <map>

struct PTPowerupRefillStruct {
   time_t startTime;
   int refillDuration;
   unsigned int id;
   int maxRefils;

};

struct PTPowerupCheckpointStruct{
    float levelPosition;
    CCPoint position;
    CCPoint cameraPosition;
    float distance;
    int levelId;
};

class PTPSettingsController: public CCObject {

public:
    PTPSettingsController();
    virtual ~PTPSettingsController();
    static PTPSettingsController* shared();
    static void resetShared();

    void setPowerupInventoryAmount(PTModelAssetPowerup* powerup, int amount);
    int powerupInventoryAmount( PTModelAssetPowerup* powerup);

    int powerupRefillTime( unsigned int id );
    void scheduleRefillTimer( unsigned int id, int minutes, int maxRefills );

    int coins;
    int coinsSession;
    int bestCoinsSession;
    float distance;
    float bestDistance;

    virtual void save();
    virtual void load();
    void reset();
    void resetInventory();

    void setRemoveAds( bool );
    bool removeAds();

    void setMuteSound( bool );
    bool isMuteSound();

    void setFullscreen( bool value);
    bool isFullscreen();

    void setLowPerformanceMode( bool value);
    bool isLowPerformanceMode();

    PTPowerupCheckpointStruct checkpoint;

    void loadDefaultInventoryMap();

protected:
    typedef std::map<unsigned int, PTPowerupRefillStruct> PTPowerupRefillMap;
    PTPowerupRefillMap _powerupRefillsMap;

private:
    void update(float dt);
    typedef std::map<unsigned int, int> PTPowerupInventoryMap;
    PTPowerupInventoryMap _inventoryMap;

    bool _removeAds;
    bool _muteSound;
    bool _lowPerformanceMode;
    bool _fullscreen;

};

#endif // PTPSETTINGSCONTROLLER_H
