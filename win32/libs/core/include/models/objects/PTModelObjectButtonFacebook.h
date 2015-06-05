#ifndef PTMODELOBJECTBUTTONFACEBOOK_H
#define PTMODELOBJECTBUTTONFACEBOOK_H

#include "PTModelObjectButton.h"

class PTModelObjectButtonFacebook : public PTModelObjectButton
{
public:
    PTModelObjectButtonFacebook(CCString className = "PTModelObjectButtonFacebook");

    virtual PTModelObject* duplicated();


    static PTModel * create() {
        return new PTModelObjectButtonFacebook();
    }

    CCString facebookURL();
    CCString facebookID();

private:
    PTPAttributeString* _facebookURLAttribute;
    PTPAttributeString* _facebookIdAttribute;
};

#endif // PTMODELOBJECTBUTTONFACEBOOK_H
