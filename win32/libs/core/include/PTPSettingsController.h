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
    static PTPSettingsController* shared();

    void setPowerupInventoryAmount(PTModelAssetPowerup* powerup, int amount);
    int powerupInventoryAmount( PTModelAssetPowerup* powerup);

    int powerupRefillTime( unsigned int id );
    void scheduleRefillTimer( unsigned int id, int minutes, int maxRefills );

    int coins;
    int coinsSession;
    float distance;
    float bestDistance;

    virtual void save();
    virtual void load();
    void reset();

    void setRemoveAds( bool );
    bool removeAds();

    void setMuteSound( bool );
    bool isMuteSound();

    void setLowPerformanceMode( bool value);
    bool isLowPerformanceMode();

    PTPowerupCheckpointStruct checkpoint;

    void loadInventoryMap();

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

};

#endif // PTPSETTINGSCONTROLLER_H
