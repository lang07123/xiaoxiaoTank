//
//  TankLayer.cpp
//  Tank
//
//  Created by lang7 on 14-6-8.
//
//

#include "TankSprite.h"
#include "GlobalSet.h"
#include "GameScene.h"


USING_NS_CC;

bool TankSprite::init()
{
    if(!Sprite::init())
        
    {
        return false;
    }

    return true;
}

TankSprite *TankSprite::initWithDelegate(int numLife,int tKind,Size mSize)
{
    TankSprite *tank;
    
    switch (tKind) {
        case kBorn:
            
            tank=(TankSprite *)CCSprite::createWithSpriteFrameName("p1.png");
            
            tank->_speed=1;
            
            break;
        case kPlusStarOne:
            
            break;
            
        case kPlusStarTwo:
            
            break;
            
        case kPlusStarThree:
            
            break;
            
        default:
            
            break;
    }
    tank->_life=numLife;
    tank->_mapSize=mSize;
    tank->kind=(TankKind)tKind;
    tank->setScale(0.7);
    //
    tank->kaction=kUp;
    
    return tank;
}