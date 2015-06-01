#ifndef PTPINPUTCONTROLLER_H
#define PTPINPUTCONTROLLER_H

#include "cocos2d.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "models/PTModelLinker.h"
#include "objects/PTPObjectAssetUnit.h"
#include "objects/PTPObjectAssetCharacter.h"

class PTPObjectAsset;
class PTPObjectButton;
class PTPScreen;

enum PTPInputControllerAction {
    PTPInputControllerActionUnknown,
    PTPInputControllerActionMoveUp,
    PTPInputControllerActionMoveDown,
    PTPInputControllerActionMoveRight,
    PTPInputControllerActionMoveLeft,
    PTPInputControllerActionJump,
    PTPInputControllerActionRotateLeft,
    PTPInputControllerActionRotateRight,
    PTPInputControllerActionShoot,
    PTPInputControllerActionMotorCW,
    PTPInputControllerActionMotorCCW
};

enum PTPInputControllerKey {
    PTPInputControllerKeyUnknown,
    PTPInputControllerKeyLeft,
    PTPInputControllerKeyRight,
    PTPInputControllerKeyUp,
    PTPInputControllerKeyDown,
    PTPInputControllerKeyShoot,
    PTPInputControllerKeyJump,
    PTPInputControllerKeyMotorCW,
    PTPInputControllerKeyMotorCCW,
    PTPInputControllerKeyRotateLeft,
    PTPInputControllerKeyRotateRight,
};

struct PTJointMotorStruct{
    b2RevoluteJoint* joint;
    PTModelLinker* linker;
};

class PTPInputController: public CCObject{

public:
    PTPInputController();
    ~PTPInputController();
    static PTPInputController* shared();
    static void destroy();

    void clear();

    void keyPressed( PTPInputControllerKey key);
    void keyReleased( PTPInputControllerKey key);

    void touchesBegan(CCSet *touches);
    void touchesMoved(CCSet *touches);
    void touchesEnded(CCSet *touches);

    void applyMoveVectorOnCharacters(CCPoint vector);

    void gamepadAxisMoved( int value, int axis );
    void gamepadButtonPressed( int button );
    void gamepadButtonReleased( int button );

    void buttonJumpPressed() { actionBegin( PTPInputControllerActionJump ); }
    void buttonJumpReleased(){ actionEnd( PTPInputControllerActionJump ); }
    void buttonShootPressed() { actionBegin( PTPInputControllerActionShoot ); }
    void buttonShootReleased(){ actionEnd( PTPInputControllerActionShoot ); }
    void buttonRotateLeftPressed(){ actionBegin( PTPInputControllerActionRotateLeft ); }
    void buttonRotateLeftReleased(){ actionEnd( PTPInputControllerActionRotateLeft ); }
    void buttonRotateRightPressed(){ actionBegin( PTPInputControllerActionRotateRight );}
    void buttonRotateRightReleased(){ actionEnd( PTPInputControllerActionRotateRight ); }

    void buttonMoveRightPressed(){ actionBegin( PTPInputControllerActionMoveRight );}
    void buttonMoveRightReleased(){ actionEnd( PTPInputControllerActionMoveRight ); }
    void buttonMoveLeftPressed(){ actionBegin( PTPInputControllerActionMoveLeft );}
    void buttonMoveLeftReleased(){ actionEnd( PTPInputControllerActionMoveLeft ); }
    void buttonMoveUpPressed(){ actionBegin( PTPInputControllerActionMoveUp );}
    void buttonMoveUpReleased(){ actionEnd( PTPInputControllerActionMoveUp ); }
    void buttonMoveDownPressed(){ actionBegin( PTPInputControllerActionMoveDown );}
    void buttonMoveDownReleased(){ actionEnd( PTPInputControllerActionMoveDown ); }

    void buttonMotorCWPressed(){ actionBegin( PTPInputControllerActionMotorCW ); }
    void buttonMotorCWReleased(){ actionEnd( PTPInputControllerActionMotorCW); }
    void buttonMotorCCWPressed(){ actionBegin( PTPInputControllerActionMotorCCW); }
    void buttonMotorCCWReleased(){ actionEnd( PTPInputControllerActionMotorCCW); }

    bool anyCharacterAlive() const;
    void killAllCharacters();
    void addCharacter(PTPObjectAssetCharacter* character);
    CCArray* characters();
    CCPoint charactersAveragePosition();
    CCRect charactersBoundingBox();

    void showCharacters();
    void hideCharacters();

    int characterZDepth();

    void moveCharacters( float dx, float dy);
    void setCharactersPosition( CCPoint p);
    void addMotor(PTJointMotorStruct motor);
    void removeAllMotors();

    void addSpawner( PTPObjectAsset* object, PTPInputControllerAction action);
    void associateSpawnerWithCharacter(PTPObjectAsset* spawner, PTPObjectAsset* character);
    void removeAllSpawners();

    void addKeyBinding( int keyCode, PTPObjectButton *button);
    void removeKeyBinding( int keyCode, PTPObjectButton *button);
    bool handleKeyPressOnScreen( int keyCode, PTPScreen *screenLayer );
    bool handleKeyReleaseOnScreen( int keyCode, PTPScreen *screenLayer );

private:
    void actionBegin(PTPInputControllerAction action);
    void actionEnd(PTPInputControllerAction action);

    CCPoint getActionsResultVector();

    CCArray* _characters;
    typedef std::list<PTPInputControllerAction> PTPInputControllerActionList;
    PTPInputControllerActionList _appliedActions;

    typedef std::list<PTJointMotorStruct> PTJointMotorStructList;
    PTJointMotorStructList _motors;
    typedef std::list<PTPObjectAsset*> PTPObjectAssetList;
    std::map<PTPInputControllerAction, PTPObjectAssetList> _spawnerObjects;
    std::map<PTPObjectAsset*, PTPObjectAsset*> _spawnerCharacterMap;
    
};

#endif // PTPINPUTCONTROLLER_H
