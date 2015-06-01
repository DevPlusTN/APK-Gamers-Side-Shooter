#ifndef PTMODELOBJECTASSETPOWERUP_H
#define PTMODELOBJECTASSETPOWERUP_H

#include "PTModelObjectAsset.h"
#include "models/PTModelAnimation.h"

class PTModelSound;

class PTModelObjectAssetPowerup : public PTModelObjectAsset {
public:
    PTModelObjectAssetPowerup();
    static PTModel * create() {
        return new PTModelObjectAssetPowerup();
    }

    virtual PTModelObjectAssetPowerup *duplicated();

    int reward() const;
    int appearanceChance() const;
    float cameraShake() const;
    float cameraFlash() const;
    float duration() const;

    PTModelAnimation *startAnimation() const;
    PTModelAnimation *endAnimation() const;
    PTModelAnimation *idleAnimation() const;
    CCString constraintType() const;
    CCString animationRepeat() const;
    CCString animationBehaviour() const;
    CCString powerupType() const;

    PTModelSound* idleSound() const ;
    PTModelSound* startSound() const ;
    PTModelSound* endSound() const ;
};

#endif // PTMODELOBJECTASSETPOWERUP_H
