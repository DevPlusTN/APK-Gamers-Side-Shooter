#ifndef PTMODELOBJECTINSTANCE_H
#define PTMODELOBJECTINSTANCE_H

#include "PTModelObject.h"
#include "PTModelObjectAsset.h"

class PTModelObjectInstance : public PTModelObject
{
public:
    PTModelObjectInstance( CCString className = "PTModelObjectInstance");
    static PTModel * create() {
        return new PTModelObjectInstance();
    }

    virtual CCDictionary* getDictionary();
    virtual void initConnectionsWithDictionary(CCDictionary* dict);

    PTModelObjectAsset *referenceModel();
    void setReferenceModel(PTModelObjectAsset* model);

    virtual PTModelSpriteContainer *sprite();


private:
    PTModelObjectAsset* _referenceModel;
};

#endif // PTMODELOBJECTINSTANCE_H
