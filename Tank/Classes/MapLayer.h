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
#include <iostream>



class MapLayer : public cocos2d::Layer
{
    
public:
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MapLayer);
    

    // initMap
    
    void initMapwithTank(int mapLevel,int playerLevel,int playerLife);

private:
    
    int _level;
    float scale;
    
    cocos2d::TMXTiledMap *gameMap;
    cocos2d::TMXObjectGroup *_objects;
    
    cocos2d::Point objectPosition(cocos2d::TMXObjectGroup *group,const char * object);
    
};

#endif /* defined(__Tank__MapLeyer__) */
