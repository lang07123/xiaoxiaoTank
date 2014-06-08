//
//  MapLayer.cpp
//  Tank
//
//  Created by lang7 on 14-6-5.
//
//

#include "MapLayer.h"
#include "GlobalSet.h"
#include "TankSprite.h"


USING_NS_CC;

Scene* MapLayer::createScene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    MapLayer *layer = MapLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MapLayer::init()
{
    Size wSize=visibleSize;

    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0, 0, 0, 255), wSize.height, wSize.height))
    {
        return false;
    }
    
    return true;
}

void MapLayer::initMapwithTank(int mapLevel,int playerLevel,int playerLife)
{
    _level = mapLevel;
    gameMap = TMXTiledMap::create(String::createWithFormat("map%d.tmx",mapLevel)->getCString());
    
    //缩放比例
    Size gameH=gameMap->getContentSize();
    Size LvisibleSize = visibleSize;
    
    scale = LvisibleSize.height / gameH.height;
    gameMap->setScale(scale);
    
    gameMap->setPosition(0,0);
    this->addChild(gameMap,1);
    
    _p1Layer=gameMap->getLayer("bg1");
    //_p2Layer=gameMap->getLayer("bg2");
    
    //暂时不显示P2
    //_p2Layer->setVisible(false);
    
    _objects=gameMap->getObjectGroup("object");
    
    _tank1 =TankSprite::initWithDelegate(playerLevel, playerLife, _p1Layer->getContentSize());
    _tank1->_mapLayer=this;
    _tank1->gameMap=gameMap;
    //Point tankPoint=this->objectPosition(_objects, "pl1");
    
    //_tank1->setPosition(Point(tankPoint.x+_tank1->boundingBox().size.width/2, tankPoint.y+_tank1->boundingBox().size.height/2));
    
    //gameMap->addChild(_tank1, 2);

    
    
    
    
    
}