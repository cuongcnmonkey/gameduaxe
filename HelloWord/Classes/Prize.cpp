#include "Prize.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>
USING_NS_CC;

Prize* Prize::createView(cocos2d::Layer* layer)
{
    auto node = new Prize;
    if (node)
    {
        node->loadData(layer);
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

void Prize::loadData(cocos2d::Layer* layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    auto prize1 = Sprite::create("items/03/1.png");
    auto prize1Animation = Animation::create();
    prize1Animation->setDelayPerUnit(0.15f);
    prize1Animation->setLoops(-1);
    prize1Animation->addSpriteFrame(Sprite::create("items/03/1.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/03/2.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/03/3.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/03/4.png")->getSpriteFrame());
    Animate* animate = Animate::create(prize1Animation);
    prize1->runAction(animate);
    layer->addChild(prize1);

    prize1->setScale(1);
    int j = random(100, 320);
    prize1->setPosition(j, 900);
    auto cc = prize1->getPosition();
    prize1->setName("prize1");

    auto _prize1 = Sprite::create("items/BlankTemp/2.png");
    auto _prize1Animation = Animation::create();
    _prize1Animation->setDelayPerUnit(0.15f);
    _prize1Animation->setLoops(-1);
    _prize1Animation->addSpriteFrame(Sprite::create("items/BlankTemp/2.png")->getSpriteFrame());
    _prize1Animation->addSpriteFrame(Sprite::create("items/BlankTemp/3.png")->getSpriteFrame());
    _prize1Animation->addSpriteFrame(Sprite::create("items/BlankTemp/4.png")->getSpriteFrame());
    _prize1Animation->addSpriteFrame(Sprite::create("items/BlankTemp/1.png")->getSpriteFrame());
    Animate* _animate = Animate::create(_prize1Animation);
    _prize1->runAction(_animate);
    _prize1->setPosition(cc);
    layer->addChild(_prize1);

    this->runAction(Sequence::create(CallFunc::create([=] {
        }), DelayTime::create(3.0f)
            , CallFunc::create([=] {
            this->dichuyen(prize1);
                }), NULL));
    auto playPrize = PhysicsBody::createCircle(prize1->getContentSize().width / 2);
    prize1->setTag(3);
    playPrize->setCollisionBitmask(0x000001);
    playPrize->setContactTestBitmask(true);
    prize1->setPhysicsBody(playPrize);
}

void Prize::dichuyen(Sprite* pri) {
    auto cc = pri->getPosition();
    pri->runAction(MoveTo::create(7.0f, cc + Point(0, -1300)));
}

Prize::Prize() {}

Prize::~Prize() {}
