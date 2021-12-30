#ifndef __GameMenu_H__
#define __GameMenu_H__

#include "cocos2d.h"

class GameMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    

    
    virtual bool init();
    

    CREATE_FUNC(GameMenu);
};

#endif // __HELLOWORLD_SCENE_H__
