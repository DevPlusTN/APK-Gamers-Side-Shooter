#ifndef PTPATTRIBUTEPOINT_H
#define PTPATTRIBUTEPOINT_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

class PTPAttributePoint : public PTPAttribute {
public:
    PTPAttributePoint(PTModel *node, PTPAttributeValueType valueType = PTPAttributeValueVariable);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    std::vector<int> keyFrameMarkers();

    CCPoint value();
    void setValue(const CCPoint &value);

    void setDefaultValue(const CCPoint &value);

    CCPoint variableValue() const;
    void setVariableValue(const CCPoint &value);

    virtual void match(PTPAttribute* attribute);
    virtual void print();
private:
    void setKeyFrame(CCPoint value, float time);

    CCPoint _variableValue;
    CCPoint _value;
    CCPoint _defaultValue;

    PTAnimationCurve *_animationCurveX;
    PTAnimationCurve *_animationCurveY;

    friend class PTAnimationEditorWidget;
};

#endif // PTPATTRIBUTEPOINT_H
