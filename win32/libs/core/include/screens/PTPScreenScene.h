#ifndef PTPSCREENSCENE_H
#define PTPSCREENSCENE_H

#include "PTPScreen.h"
#include "PTPGameFieldCamera.h"
#include "box2D/Box2D.h"
#include "models/PTModelGeneralSettings.h"
#include "models/PTModelLevelSection.h"
#include "objects/PTPObjectAsset.h"

struct PTPScreenSceneCreationQueue {
    CCPoint position;
    CCArray *objects;
    int index;
    PTModelLevelSection *model;
    CCArray* createdObjects;
};

class PTPScreenScene : public PTPScreen
{
public:
    PTPScreenScene();
    ~PTPScreenScene();

    CREATE_FUNC( PTPScreenScene );

    virtual bool init();
    virtual void update(float dt);
    virtual void updateCameraObjects( float dt );

    void cameraShake( float cameraShake );
    void cameraFlash( float cameraFlash );

    void addAsset( PTPObjectAsset *asset, CCNode *sender );
    CCArray *getAssetsList();

    bool updateObjectCreationQueue();

    PTPGameFieldCamera* camera();

    void deleteAsset(PTModelObjectAsset* assetModel);

    virtual void onBackFromChildScreen();

protected:
    float addLevelSection(  PTModelLevelSection *model, float position ); // return width of added level section
    PTPObjectAsset* createAsset(PTModelObject* assetModel, int levelSectionModelId, CCPoint levelSectionPosition );

    PTPGameFieldCamera *_camera;
    PTModelGeneralSettings* _generalSettings;
    b2World *_world;

private:

    void checkForDeletion(PTPObject *obj);

    float _cameraShake;
    float _cameraFlash;
    float _cameraFlashDuration;
    CCSprite *_cameraFlashSprite;
    float _simulationTimeAccumulator;

    std::vector<PTPScreenSceneCreationQueue> objectCreationList;

};

#endif // PTPSCREENSCENE_H
