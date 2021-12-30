#include "CarAi.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>

#include"network/HttpRequest.h"
#include"network/HttpClient.h"
#include"network/HttpResponse.h"
#include<algorithm>
#include<vector>

#include "../Resources/rapidjson/rapidjson.h"
#include "../Resources/rapidjson/document.h"

using namespace rapidjson;

USING_NS_CC;

CarAi* CarAi::createView(cocos2d::Layer* layer, std::string mai1, std::string mai2, std::string mai3)
{
    auto node = new CarAi;
    if (node)
    {
        node->loadData(layer, mai1, mai2, mai3);
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

struct carai
{
    std::string Tire = "";
    std::string car = "";
    std::string Rider = "";
};

void CarAi::loadData(cocos2d::Layer* layer, std::string mai1, std::string mai2, std::string mai3)
{
    carai demo;
    Document m_document;
    ssize_t size;

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    Tire = Sprite::create(mai1/*"Tires/01/11.png"*/);//a
    auto m = random(60, 355);
    Tire->setPosition(Vec2(m, -100));
    Tire->setAnchorPoint(Vec2(0.5, 0.5));
    layer->addChild(Tire);
    Tire->setScale(0.6);

    auto i1 = random(9, 14);
    auto car = Sprite::create(/*"carai/" + std::to_string(i1) + ".png"*/mai2);
    Tire->addChild(car);
    auto i2 = random(1, 8);
    Rider = Sprite::create(/*"carai/Riders0" + std::to_string(i2) + ".png"*/mai3);
 //   Rider = Sprite::create(str);

    car->setPosition(Vec2(Tire->getContentSize() / 2) + Vec2(0, 20));
    Rider->setPosition(Vec2(Tire->getContentSize() / 2) + Vec2(2.5, 45));
    car->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    Rider->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    Tire->addChild(Rider);
    Tire->setName("aii");

    auto tireAnimation = Animation::create();
    tireAnimation->setDelayPerUnit(0.15f);
    tireAnimation->setLoops(-1);
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/11.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/12.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/13.png")->getSpriteFrame());
    tireAnimation->addSpriteFrame(Sprite::create("Tires/01/14.png")->getSpriteFrame());

    Animate* animate = Animate::create(tireAnimation);
    Tire->runAction(animate);

    int cuong = random(3.0, 8.0);

    this->runAction(Sequence::create(CallFunc::create([=] {
        this->dichuyen(Tire);
        }), DelayTime::create(cuong)
            , CallFunc::create([=] {
            int i = random(1, 2);
            if (i == 2) {
                this->skill1();
            }
            else
            {
                this->skill2();
            }
                }), NULL));

    auto playai = PhysicsBody::createCircle(Tire->getContentSize().width / 2);
    Tire->setTag(5);
    playai->setCollisionBitmask(0x000001);
    playai->setContactTestBitmask(true);
    Tire->setPhysicsBody(playai);
}

void CarAi::dichuyen(Sprite* pri) {
    auto cc = pri->getPosition();
    pri->runAction(MoveTo::create(15.0f, cc + Point(0, 1300)));
}

void CarAi::skill1() {
    auto riderAnimation = Animation::create();
    riderAnimation->setDelayPerUnit(0.15f);
    riderAnimation->setLoops(1);
    riderAnimation->addSpriteFrame(Sprite::create("skillai/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/4.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/0.png")->getSpriteFrame());
    Animate* animate1 = Animate::create(riderAnimation);
    Rider->runAction(animate1);
    auto cc = Tire->getPosition();
    bom = Sprite::create("bom.png");
    bom->setPosition(cc + Point(150,50));
    auto ccc = bom->getPosition();
    this->addChild(bom);
    bomno(bom);
}

void CarAi::bomno(Sprite *a) {
    auto bomanimation = Animation::create();
    bomanimation->setDelayPerUnit(0.15f);
    bomanimation->setLoops(1);
    bomanimation->addSpriteFrame(Sprite::create("no/01/1.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/2.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/3.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/4.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/5.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/6.png")->getSpriteFrame());
    bomanimation->addSpriteFrame(Sprite::create("no/01/7.png")->getSpriteFrame());
    Animate* animate1 = Animate::create(bomanimation);
    a->runAction(animate1);
  //  a->removeFromParent();
}

void CarAi::skill2() {
    auto riderAnimation = Animation::create();
    riderAnimation->setDelayPerUnit(0.15f);
    riderAnimation->setLoops(1);
    riderAnimation->addSpriteFrame(Sprite::create("skillai/1.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/2.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/3.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/4.png")->getSpriteFrame());
    riderAnimation->addSpriteFrame(Sprite::create("skillai/0.png")->getSpriteFrame());
    Animate* animate1 = Animate::create(riderAnimation);
    Rider->runAction(animate1);
    auto cc = Tire->getPosition();
    bom = Sprite::create("bom.png");
    bom->setPosition(cc + Point(-150, -50));
    auto ccc = bom->getPosition();
    this->addChild(bom);
    bomno(bom);
}


CarAi::CarAi() {}

CarAi::~CarAi() {}













/*char* buf = (char*)FileUtils::getInstance()->getFileData("D:/file.json", "r", &size);
std::string content(buf, size);
m_document.Parse(content.c_str());
std::string str = m_document["CARAILV1"][0]["car"].GetString();*/

//loop  m_document["CARAILV1"] => size 
//random (0-size-1)
//m_document["CARAILV1"][id]
//std::string str = m_document["CARAILV1"][id]["car"].GetString();
