#ifndef PTPSCREENINFO_H
#define PTPSCREENINFO_H

#include "screens/PTPScreen.h"

class PTPScreenInfo : public PTPScreen{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenInfo );

    void backButtonAction(CCObject* pSender);
    void resetButtonAction(CCObject* pSender);
    void resetWarningMessageClicked( bool yes );

    virtual void keyBackClicked();
};

#endif // PTPSCREENINFO_H
