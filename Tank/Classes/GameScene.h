//
//  GameScene.h
//  Tank
//
//  Created by lang7 on 14-6-8.
//
//

#ifndef __Tank__GameScene__
#define __Tank__GameScene__

#include "cocos2d.h"
#include <iostream>
#include "MapLayer.h"

class GameLayer:public cocos2d::Layer
{
    
public:
    
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::Scene* scene();
    
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    
    
    void initWithMapInformation(int leve,int status ,int life);
    
    void showLife(int numLife);
    
    void showLeve(int inLeve);
    
private:
    
    cocos2d::Label *_1plifeString;
    cocos2d::Label *_leveString;
    
    MapLayer *_mapLayer;
    
    //ControlLayer *_conLayer;
    
    
};


#endif /* defined(__Tank__GameScene__) */
