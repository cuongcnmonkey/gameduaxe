#include "NumberOfPlays.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>
USING_NS_CC;

NumberOfPlays* NumberOfPlays::createView(cocos2d::Layer* layer)
{
    auto node = new NumberOfPlays;
    if (node)
    {
        node->loadData(layer);
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

void NumberOfPlays::loadData(cocos2d::Layer* layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    auto prize1 = Sprite::create("items/01/1.png");
    auto prize1Animation = Animation::create();
    prize1Animation->setDelayPerUnit(0.15f);
    prize1Animation->setLoops(-1);
    prize1Animation->addSpriteFrame(Sprite::create("items/01/1.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/01/2.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/01/3.png")->getSpriteFrame());
    prize1Animation->addSpriteFrame(Sprite::create("items/01/4.png")->getSpriteFrame());
    Animate* animate = Animate::create(prize1Animation);
    prize1->runAction(animate);
    layer->addChild(prize1);

    prize1->setScale(1);
    int j = random(100, 320);
    prize1->setPosition(j, 900);
    prize1->setName("noff");

    this->runAction(Sequence::create(CallFunc::create([=] {
        }), DelayTime::create(15.0f)
            , CallFunc::create([=] {
            this->dichuyen(prize1);
                }), NULL));
    auto playPrize = PhysicsBody::createCircle(prize1->getContentSize().width / 2);
    prize1->setTag(4);
    playPrize->setCollisionBitmask(0x000001);
    playPrize->setContactTestBitmask(true);
    prize1->setPhysicsBody(playPrize);
}

void NumberOfPlays::dichuyen(Sprite* pri) {
    auto cc = pri->getPosition();
    pri->runAction(MoveTo::create(7.0f, cc + Point(0, -1300)));
}

NumberOfPlays::NumberOfPlays() {}

NumberOfPlays::~NumberOfPlays() {}
