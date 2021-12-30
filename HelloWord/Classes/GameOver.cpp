#include "GameOver.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameMap.h"
USING_NS_CC;

Scene* GameOver::createScene()
{
    
    auto scene = Scene::create();

    auto layer = GameOver::create();

    scene->addChild(layer);

    return scene;
}

bool GameOver::init()
{
    if (!Layer::init())
    {
        return false;
    }
 //   speed = GameMap::create(1);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto mainMenu = CSLoader::getInstance()->createNode("csb/lv.csb");
    this->addChild(mainMenu);

    auto button = mainMenu->getChildByName<ui::Button*>("Button_1");
    button->setPressedActionEnabled(true);
    button->addClickEventListener([=](Ref*) {
        Director::getInstance()->replaceScene(GameMap::createScene(0.005, "Tires/01/1.png", "Car/1.png", "Riders/0.png"));
        });
    //thay đổi Init ở GameMap để dùng ở GameOver
    return true;
}

