#ifndef PTPOBJECTASSET_H
#define PTPOBJECTASSET_H

#include "PTPObject.h"
#include "models/objects/PTModelAsset.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "models/PTModelGeneralSettings.h"

enum PTPObjectAssetCollisionType{
    PTPObjectAssetCollisionNo = 0,
    PTPObjectAssetCollisionCharacter,
    PTPObjectAssetCollisionDestroy
};

enum PTPObjectAssetWakeupType{
    PTPObjectAssetWakeupNo = 0,
    PTPObjectAssetWakeupDistance,
    PTPObjectAssetWakeupCollide
};

enum PTPObjectAssetSleepType{
    PTPObjectAssetSleepNo = 0,
    PTPObjectAssetSleepDistance,

};

class PTPObjectAsset : public PTPObject
{
public:
    PTPObjectAsset(PTModelObjectAsset* model);
    virtual ~PTPObjectAsset();

    static PTPObjectAsset* create(PTModelObject* model);

    virtual void initPhysics(b2World* world);
    virtual void update(float dt);

    virtual void beginContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void endContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void preSolve( PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);
    bool isMovementTypeLinear();

    bool isLinked();
    void setLinked( bool linked);
    bool isSpawnEnabled();
    void setSpawnEnabled( bool spawnEnabled );
    CCPoint linearMoveSpeed();
    void setLinearMoveSpeed( CCPoint moveSpeed );
    virtual void spawnObject();
    virtual float wakeUpDistance();

    float distance(); //distance betwwen character and object (can be negative of object behind character related to game direction)

    virtual float sleepDistance();

    PTPObjectAssetCollisionType collisionType();

    void setParentLevelSectionId( unsigned int id);
    unsigned int parentLevelSectionId();

    virtual void updateContentRect();

    virtual PTModelObjectAsset *model();

protected:

    PTModelGeneralSettings* _generalSettingsModel;
    PTPObjectAssetCollisionType _collisionType;
    PTPObjectAssetWakeupType _wakeupType;
    PTPObjectAssetSleepType _sleepType;



    float _linearRotationSpeed;
    CCPoint _linearMoveSpeed;
    bool _movementTypeLinear;

    bool _sleep;
    float _travelDistance;
    bool _linked;
    bool _spawnEnabled;
    float _spawnCounter;

    unsigned int _parentLevelSectionId;

private:
    PTModelObjectAsset* _model;

};

#endif // PTPOBJECTASSET_H
