//
//  joystick.h
//  Tank
//
//  Created by lang7 on 14-6-13.
//
//

#ifndef __Tank__joystick__
#define __Tank__joystick__

#include "cocos2d.h"


class joystickDelegate
{
public:
    // 移动，direction为向量，distance是与起点的直线距离
    virtual void onWalk(cocos2d::Point direction, float distance) = 0;
    // 攻击
    virtual void onAttack() = 0;
    // 停止移动
    virtual void onStop() = 0;
};

class joystickLayer : public cocos2d::Layer
{
public:
    joystickLayer();
    ~joystickLayer();
    
    virtual bool init();
    CREATE_FUNC(joystickLayer);
    
    // 触控的三个事件函数重载
    void TouchesBegan(cocos2d::Set *ts, cocos2d::Event *e);
    void TouchesMoved(cocos2d::Set *ts, cocos2d::Event *e);
    void TouchesEnded(cocos2d::Set *ts, cocos2d::Event *e);
    
    // 委托者
    CC_SYNTHESIZE(joystickDelegate*, _delegator, Delegator);
    
private:
    // 摇杆，分为“摇杆”、“摇杆基座”两个部分
    cocos2d::Sprite *_joystick;
    cocos2d::Sprite *_joystick_bg;
    // 激活“摇杆精灵”，并更新其坐标
    void _activityJoystick(cocos2d::Point position);
    // 隐藏“摇杆精灵”，并将“摇杆”置于“摇杆基座”中心
    void _inactivityJoystick();
    // 刷新“摇杆”相对于“摇杆基座”的位置（根据触控手势）
    void _updateJoystick(cocos2d::Point direction, float distance);
};

#endif /* defined(__Tank__joystick__) */
