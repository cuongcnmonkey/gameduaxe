#include "Obstacle.h"
#include"GameScene.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>
USING_NS_CC;

Obstacle* Obstacle::createView(cocos2d::Layer* layer, std::string cc)
{
    auto node = new Obstacle;
    if (node)
    {
        node->loadData (layer, cc);
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

void Obstacle::loadData(cocos2d::Layer* layer, std::string cc)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
 //   int i = random(1,6);//Obstacle/" + std::to_string(i) + ".png"
    auto obs = Sprite::create(cc);
    obs->setScale(0.7);
    int j = random(100, 320);
    obs->setPosition(j, 900);
    obs->setName("cuong");
    layer->addChild(obs);
    this->runAction(Sequence::create(CallFunc::create([=] {
        }), DelayTime::create(0.15f)
            , CallFunc::create([=] {
            this->dichuyen(obs);
                }), NULL));

    auto playObs = PhysicsBody::createCircle(obs->getContentSize().width / 2);
    obs->setTag(2);
    playObs->setCollisionBitmask(0x000001);
    playObs->setContactTestBitmask(true);
    obs->setPhysicsBody(playObs);
}

void Obstacle::dichuyen(Sprite* obs) {
    auto cc = obs->getPosition();
    obs->runAction(MoveTo::create(7.0f, cc + Point(0, -1300)));
}

Obstacle::Obstacle(){}

Obstacle::~Obstacle(){}
