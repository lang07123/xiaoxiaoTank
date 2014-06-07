//
//  TankLayer.h
//  Tank
//
//  Created by lang7 on 14-6-8.
//
//

#ifndef __Tank__TankLayer__
#define __Tank__TankLayer__

#include "cocos2d.h"
#include <iostream>

typedef enum{
    kBorn=1,
    kPlusStartOne,
    kPlusStartTwo,
    kPlusStartThree
}TankKind;

typedef enum{
    kUp=1,
    kDown,
    kLeft,
    kRight,
    kFire,
    kStay,
    kPause
}TankAction;

class MapLayer;

class TankLayer:public cocos2d::Sprite
{
    
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TankLayer);
};



#endif /* defined(__Tank__TankLayer__) */
