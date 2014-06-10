//
//  MapLeyer.h
//  Tank
//
//  Created by lang7 on 14-6-5.
//
//

#ifndef __Tank__MapLeyer__
#define __Tank__MapLeyer__

#include "cocos2d.h"
#include "TankSprite.h"

USING_NS_CC;

class TankSprite;

class MapLayer : public cocos2d::LayerColor
{
    
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MapLayer);

    // initMap
    void initMapwithTank(int mapLevel,int playerLevel,int playerLife);
    
    //tank
    TankSprite *_tank1;
    
    Point tankPoint;
    
    cocos2d::Point tileCoordinateFromPosition(cocos2d::Point pos);
    
    int tileIDFromPosition(cocos2d::Point pos);


private:
    
    int _level;
    float scale;
    
    cocos2d::TMXTiledMap *gameMap;
    cocos2d::TMXObjectGroup *_objects;
    
    cocos2d::TMXLayer *_p1Layer;
    cocos2d::TMXLayer *_p2Layer;
    
    cocos2d::Point objectPosition(cocos2d::TMXObjectGroup *group,const char * object);
    
};

#endif /* defined(__Tank__MapLeyer__) */
