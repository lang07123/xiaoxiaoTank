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
    
   // printf('gogo');


}