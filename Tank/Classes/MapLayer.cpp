//
//  MapLayer.cpp
//  Tank
//
//  Created by lang7 on 14-6-5.
//
//

#include "MapLayer.h"
#include "GlobalSet.h"

USING_NS_CC;

Scene* MapLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MapLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    return true;
}

void MapLayer::initMapwithTank(int mapLevel,int playerLevel,int playerLife)
{
    _level = mapLevel;
    gameMap = TMXTiledMap::create(String::createWithFormat("map%d.tmx",_level)->getCString());
    
    printf("lllll");
    //缩放比例
    scale = visibleSize.height / gameMap->().height;
    gameMap->setScale(1.59);
    gameMap->setPosition(0,0);
    this->addChild(gameMap,1);
}