#ifndef PTMODELBUTTON_H
#define PTMODELBUTTON_H

#include "PTModelObjectImage.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeKey.h"

class PTModelObjectButton : public PTModelObjectImage {
public:
    PTModelObjectButton(CCString className = "PTModelObjectButton");

    CCString action();
    PTPAttributeEnum* actionAttribute();

    int keyboardKey();
    void setKeyboardKey( int );

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();
    static PTModel * create() {
        return new PTModelObjectButton();
    }

protected:
    PTPAttributeEnum *_actionAttribute;
    PTPAttributeKey *_keyboardKeyAttribute;
};

#endif // PTMODELBUTTON_H
