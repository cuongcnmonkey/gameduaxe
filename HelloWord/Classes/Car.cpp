#include "Car.h"
#include"GameScene.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include "cocos2d.h"
USING_NS_CC;


Car* Car::createView(cocos2d::Layer* layer, std::string cc1, std::string cc2, std::string cc3)
{
    auto node = new Car;
    if (node)
    {
        node->loadData(layer, cc1, cc2, cc3);
        return node;
    }
    CC_SAFE_DELETE(node);

    return nullptr;
}

void Car::loadData(cocos2d::Layer* layer, std::string cc1, std::string cc2, std::string cc3)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    auto Tire = Sprite::create(/*"Tires/01/1.png"*/cc1);//a
    Tire->setPosition(Vec2(visibleSize.width / 2, 417));
    Tire->setAnchorPoint(Vec2(0.5, 0.5));
    Tire->setName("cuong123");
    Tire->setScale(0.6);
    layer->addChild(Tire);

    auto car = Sprite::create(cc2);//b
    Tire->addChild(car);
    Rider = Sprite::create(cc3);
    car->setPosition(Vec2(Tire->getContentSize() / 2) + Vec2(0, 20));
    Rider->setPosition(Vec2(Tire->getContentSize() / 2)+ Vec2 (2.5,45));
    car->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    Rider->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    Tire->addChild(Rider);

    

    auto tireAnimation = Animation::create();
    tireAnimation->setDelayPerUnit(0.15f);
    tireAnimation->setLoops(-1);
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/1.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/2.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/3.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/4.png")->getSpriteFrame());

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Car::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    Animate* animate = Animate::create(tireAnimation);
    Tire->runAction(animate);
}

void Car::skill1() {
    auto riderAnimation = Animation::create();
    riderAnimation->setDelayPerUnit(0.15f);
    riderAnimation->setLoops(1);
    riderAnimation->addSpriteFrame(Sprite::create("Riders/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/4.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/0.png")->getSpriteFrame());
    Animate* animate1 = Animate::create(riderAnimation);
    Rider->runAction(animate1);
}

void Car::skill2() {
    auto riderAnimation = Animation::create();
    riderAnimation->setDelayPerUnit(0.15f);
    riderAnimation->setLoops(1);
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/4.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("Riders/cc/0.png")->getSpriteFrame());
    Animate* animate1 = Animate::create(riderAnimation);
    Rider->runAction(animate1);    
}


Car::Car(){}

Car::~Car(){}

