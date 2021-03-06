#include "HelloTank.h"

USING_NS_CC;

Scene* HelloTank::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloTank::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloTank::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloTank::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("HelloTank", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("BattleCity.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2+100));
    
    //BattleCity 放大
    sprite->setScale(2.0f);
    // add the sprite as a child to this layer
    this->addChild(sprite, 1);
    
    //创建菜单
    
    MenuItemFont *startItemMenu=MenuItemFont::create("开始游戏",CC_CALLBACK_0(HelloTank::startGame,this));
    
    startItemMenu->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-100));
    startItemMenu->setFontSizeObj(55);
    startItemMenu->setFontNameObj("Georgia-Bold");
    Menu *pMenu=Menu::create(startItemMenu,NULL);
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu,0);
    
    
    return true;
}

void HelloTank::startGame()
{
    Scene *mapScene=Scene::create();
    GameLayer *withGameLayer=GameLayer::create();
    mapScene->addChild(withGameLayer);
    withGameLayer->initWithMapInformation(2, 1, 3);
    //动画跳转
    Director::getInstance()->replaceScene(CCTransitionJumpZoom::create(1.2f,mapScene));
    

}

void HelloTank::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
