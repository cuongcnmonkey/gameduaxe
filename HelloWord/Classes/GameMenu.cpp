#include "GameMenu.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"

USING_NS_CC;
Scene* GameMenu::createScene()
{
    //static float speedGame = 0.005f;
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto mainMenu = CSLoader::getInstance()->createNode("csb/gameMenu.csb");
    this->addChild(mainMenu);

    auto button = mainMenu->getChildByName<ui::Button*>("Button_1");
    button->setPressedActionEnabled(true);
    button->addClickEventListener([=](Ref*) {
        Director::getInstance()->replaceScene(GameScene::createScene());
        });


    return true;
}

