#ifndef PTMODELOBJECTBUTTONPURCHASE_H
#define PTMODELOBJECTBUTTONPURCHASE_H

#include "PTModelObjectButton.h"


class PTModelObjectButtonPurchase : public PTModelObjectButton
{
public:
    PTModelObjectButtonPurchase(CCString className = "PTModelObjectButtonPurchase");

    static PTModel * create() {
        return new PTModelObjectButtonPurchase();
    }

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual PTModelObject* duplicated();

    float visibilityThreshold();

    CCString storeIdentifier();
    CCString actionType();

    bool isBuyAndUse();
    bool isInAppPurchase();
    float price();
    int quantity();

private:
    PTPAttributeEnum *_actionTypeAttribute;
    PTPAttributeString* _storeIdentifierAttribute;
    PTPAttributeBoolean* _inAppPurchase;
    PTPAttributeBoolean* _buyAndUseAttribute;
    PTPAttributeFloat* _priceAttribute;
    PTPAttributeFloat* _quantityAttribute;
    PTPAttributeFloat* _visibilityThresholdAttribute;

};

#endif // PTMODELOBJECTBUTTONPURCHASE_H
