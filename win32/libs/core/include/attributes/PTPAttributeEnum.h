#ifndef PTPATTRIBUTEENUM_H
#define PTPATTRIBUTEENUM_H

#include "PTPAttribute.h"

class PTPAttributeEnum : public PTPAttribute
{
public:
    PTPAttributeEnum(CCObject* node, PTPAttributeValueType valueType = PTPAttributeValueExact);
    ~PTPAttributeEnum();

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary* getDictionary();

    void addItem(const CCString *name, const CCString* key);
    CCDictionary* getListOfEnums();

    void setStringValue( CCString value);
    CCString stringValue();

    virtual void match(PTPAttribute* attribute);

private:
    CCDictionary* _enumDictionary;
    CCString _stringValue;

};

#endif // PTPATTRIBUTEENUM_H
