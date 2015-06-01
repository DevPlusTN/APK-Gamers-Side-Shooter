#ifndef PTMODELASSETPOWERUP_H
#define PTMODELASSETPOWERUP_H

#include "models/objects/PTModelAsset.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeAnimation.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeSound.h"

class PTModelAssetPowerup : public PTModelAsset {
public:
    PTModelAssetPowerup(CCString name = "Powerup");

    virtual PTModelSpriteContainer *sprite();
    virtual void attributeDidUpdated(PTPAttribute *attr);

    void setIdleSpriteAnimation(PTModelSpriteContainer *sprite);
    PTModelAnimation* idelAnimation();
    PTModelAnimation* startAnimation();
    PTModelAnimation* endAnimation();

    CCString constraintType();

    int reward() const ;
    int appearanceChance() const ;
    float cameraShake() const;
    float cameraFlash() const;
    float duration() const;
    int price() const;

    void setPowerupType(CCString);
    CCString powerupType();
    CCString animationRepeat();
    CCString animationBehaviour();

    PTModelSound* idleSoundAttribute() const;
    PTModelSound* startSoundAttribute() const;
    PTModelSound* endSoundAttribute() const;

    static PTModel * create() {
        return new PTModelAssetPowerup();
    }

private:

    PTPAttributeFloat* _rewardAttribute;
    PTPAttributeFloat* _appearanceChanceAttribute;
    PTPAttributeEnum* _powerupType;
    PTPAttributeFloat* _priceAttribute;
    PTPAttributeFloat* _cameraShake;
    PTPAttributeFloat* _cameraFlash;
    PTPAttributeFloat* _durationAttribute;
    PTPAttributeEnum* _constraintTypeAttribute;
    PTPAttributeEnum* _animationBehaviorAttribute;
    PTPAttributeEnum* _animationRepeatAttribute;
    PTPAttributeAnimation* _idleAnimationAttribute;
    PTPAttributeAnimation* _startAnimationAttribute;
    PTPAttributeAnimation* _endAnimationAttribute;

    PTPAttributeSound *_idleSoundAttribute;
    PTPAttributeSound *_startSoundAttribute;
    PTPAttributeSound *_endSoundAttribute;

    friend class PTLevelEditorScreen;
};

#endif // PTMODELASSETPOWERUP_H
