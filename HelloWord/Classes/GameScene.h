#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include "GameMenu.h"
#include "GameMap.h"

using namespace cocos2d;
class GameScene : public cocos2d::Layer
{
public:
    int banhxe;
    int tire;
    int rider;
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameScene);

};

#endif // __HELLOWORLD_SCENE_H__
