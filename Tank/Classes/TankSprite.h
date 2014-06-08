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
#include "MapLayer.h"

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

class TankSprite:public cocos2d::Sprite
{
    
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TankSprite);
    
    static TankSprite *initWithDelegate(int numLife,int tKind,cocos2d::Size mSize);
    //Tank Attritube  属性
    int _speed;
    int _life;
    
    //MapSize
    cocos2d::Size _mapSize;
    
    //Tank 种类
    TankKind kind;
    
    //Tank Action 方向
    TankAction kaction;

};



#endif /* defined(__Tank__TankLayer__) */
