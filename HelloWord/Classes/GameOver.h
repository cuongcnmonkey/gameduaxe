#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__
#include "cocos2d.h"
#include "GameMap.h"

class GameOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(GameOver);
};

#endif // __HELLOWORLD_SCENE_H__