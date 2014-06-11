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
    
    Size LvisibleSize = visibleSize;
    
    scale = LvisibleSize.height / gameMap->getContentSize().height;
    gameMap->setScale(scale);
    gameMap->setPosition(0,0);
    this->addChild(gameMap,1);
    
    _p1Layer=gameMap->getLayer("bg1");
    _p2Layer=gameMap->getLayer("bg2");
    
    //  暂时不显示铁皮城堡
    _p2Layer->setVisible(false);
    
    //  获取TMX objects 图层
    _objectGroup=gameMap->getObjectGroup("objects");

    
    // 增加老家图片
    _home=Sprite::createWithSpriteFrameName("home.png");
    Point homePoint=this->objectPosition(_objectGroup, "home");
    _home->setPosition(Point(homePoint.x+_home->boundingBox().size.width/2, homePoint.y+_home->boundingBox().size.height/2));
    gameMap->addChild(_home, -1);
    
    
    
    //  增加P1进入游戏
    _tank1=Sprite::createWithSpriteFrameName("p1.png");
    
    //_tank1 =TankSprite::initWithDelegate(playerLevel, playerLife, _p1Layer->getContentSize());
    //_tank1->_mapLayer=this;
    //_tank1->gameMap=gameMap;
    Point tankPoint=this->objectPosition(_objectGroup, "pl1");
    
    _tank1->setPosition(Point(tankPoint.x+_tank1->boundingBox().size.width/2, tankPoint.y+_tank1->boundingBox().size.height/2));

    
    //_tank1->setScale(0.7f);
    gameMap->addChild(_tank1, -1);

    
}

Point MapLayer::objectPosition(TMXObjectGroup *group, const char *object)
{
    Point objectPoint;
    
    auto spawnPoint=group->getObject(object);
    objectPoint.x=spawnPoint["x"].asFloat();
    objectPoint.y=spawnPoint["y"].asFloat();
    
    return objectPoint;

}
