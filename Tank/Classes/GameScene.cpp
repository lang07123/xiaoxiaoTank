//
//  GameScene.cpp
//  Tank
//
//  Created by lang7 on 14-6-8.
//
//

#include "cocos2d.h"
#include "GameScene.h"
#include "GlobalSet.h"

using namespace CocosDenshion;
USING_NS_CC;

Scene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    return true;
}


//初始化地图信息
void GameLayer::initWithMapInformation(int leve, int status, int life)
{
    Size wSize=visibleSize;
    
    //开始音乐
    SimpleAudioEngine::getInstance()->playEffect("start.aif");
    
    
    //创建一个颜色层
    LayerColor *backColor=LayerColor::create(Color4B(192, 192, 192, 255));
    
    this->addChild(backColor,1);
    
    //精灵帧类,提高效率
    SpriteFrameCache *frameCache=SpriteFrameCache::getInstance();
    
    frameCache->addSpriteFramesWithFile("images.plist");
    
    frameCache->autorelease();
    
    //场景内一些精灵的创建
    Sprite *ipLife=Sprite::createWithSpriteFrameName("IP.png");
    ipLife->setPosition(Point(wSize.width-200, wSize.height/2-50));
    ipLife->setScale(2.0f);
    this->addChild(ipLife,1);
    
    Sprite *ipLifeIcok=Sprite::createWithSpriteFrameName("p1.png");
    ipLifeIcok->setPosition(Point(wSize.width-215, wSize.height/2-80));
    ipLifeIcok->setScale(1.0f);
    this->addChild(ipLifeIcok,1);
    this->showLife(life);
    
    Sprite *flag=Sprite::createWithSpriteFrameName("flag.png");
    flag->setPosition(Point(wSize.width-200, wSize.height/2-200));
    flag->setScale(2.0f);
    this->addChild(flag,1);
    this->showLeve(leve);
    
    _mapLayer=MapLayer::create();
    
    _mapLayer->initMapwithTank(leve, status, life);
    
    //设置图片位置
    _mapLayer->setPosition(Point(wSize.height/3, 0));
    
    //设置背景缩放比例
    _mapLayer->setScale(1);
    
    this->addChild(_mapLayer,1);
    
    
    
    //_conLayer=ControlLayer::create();
    //_conLayer->_mapLayer=_mapLayer;
    
    //this->addChild(_conLayer, 1);
    
    this->showEnemyRoboot(20);
    
}


//显示life
void GameLayer::showLife(int numLife)
{
    Size wSize=visibleSize;
    
    if (_1plifeString!=NULL) {
        
        
        _1plifeString->removeFromParentAndCleanup(true);
        
    }
    _1plifeString=Label::create(CCString::createWithFormat("%d",numLife)->getCString(), "Courier-Bold", 40);
    _1plifeString->setColor(Color3B(0, 0, 0));
    _1plifeString->setPosition(Point(wSize.width-180, wSize.height/2-80));
    this->addChild(_1plifeString,1);
    
}


//显示关卡
void GameLayer::showLeve(int inLeve)
{
    Size wSize=visibleSize;
    
    if (_leveString!=NULL) {
        
        _leveString->removeFromParentAndCleanup(true);
        
    }
    _leveString=Label::create(CCString::createWithFormat("%d",inLeve)->getCString(), "Courier-Bold", 40);
    _leveString->setColor(Color3B(0, 0, 0));
    _leveString->setPosition(Point(wSize.width-180, wSize.height/2-240));
    this->addChild(_leveString,1);
    
    
}


void GameLayer::showEnemyRoboot(int enemyLife)
{
    
    Size wSize=visibleSize;
    
    //SpriteBatchNode *enemyNode =SpriteBatchNode::createWithTexture("enemy.png",20);
    int y=50;
    int x=215;
    
    for (int i =1; i<=enemyLife; ++i) {
        
        Sprite *flag=Sprite::createWithSpriteFrameName("enemy.png");
        flag->setPosition(Point(wSize.width-x, wSize.height-y));
        flag->setScale(2.0f);
        
        this->addChild(flag,1);
        
        if (i%2==0) {
            x=215;
            y+=20;
            
        }
        else {
            x=195;
            
        }
    }
    

}


