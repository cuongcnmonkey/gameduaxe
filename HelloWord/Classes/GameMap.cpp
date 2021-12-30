#include "GameMap.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Car.h"
#include "Definitions.h"
#include "GameOver.h"
#include "NumberOfPlays.h"
#include "Prize.h"
#include "../Resources/rapidjson/rapidjson.h"
#include "../Resources/rapidjson/document.h"
#include <time.h>
#include <random>

using namespace rapidjson;

USING_NS_CC;

static int s_currentLevel = 0;

Scene* GameMap::createScene(float input, std::string string1, std::string string2, std::string string3)//1
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vect(0.0f, 0.0f));
    auto layer = GameMap::create(input, string1, string2, string3);//2

    scene->addChild(layer);

    return scene;
}


GameMap* GameMap::create(float input, std::string string1, std::string string2, std::string string3)//2
{
    
    GameMap* pRet = new(std::nothrow) GameMap();
    if (pRet && pRet->init(input, string1, string2, string3))//3
    {
        pRet->autorelease();
        //pRet->setSpeed(0.05);
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}
bool GameMap::init(float input, std::string string1, std::string string2, std::string string3)//3
{
    if (!Layer::init())
    {
        return false;
    }
    speedGame = input;
    cc1 = string1;
    cc2 = string2;
    cc3 = string3;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    background1 = Sprite::create("01.png");
    background1->setAnchorPoint(Vec2(0, 0));
    background1->setPosition(Vec2(origin.x, origin.y));

    background2 = Sprite::create("02.png");
    background2->setAnchorPoint(Vec2(0, 0));
    background2->setPosition(Vec2(origin.x, origin.y + background2->getContentSize().height));

    background3 = Sprite::create("left.png");
    background3->setAnchorPoint(Vec2(0, 0));
    background3->setPosition(Point(0, 0));

    background4 = Sprite::create("left.png");
    background4->setAnchorPoint(Vec2(0, 0));
    background4->setPosition(Point(0, 0));

    background5 = Sprite::create("tien.png");
    background5->setScale(0.7);
    background5->setPosition(Point(70, 710));

    background6 = Sprite::create("mang.png");
    background6->setScale(1);
    background6->setPosition(Point(30, 675));

    background7 = Sprite::create("mang.png");
    background7->setScale(1);
    background7->setPosition(Point(60, 675));

    auto rightBody = PhysicsBody::createBox(background3->getContentSize());
    rightBody->setDynamic(false);
    rightBody->setCollisionBitmask(1);
    rightBody->setContactTestBitmask(true);
    background3->setPhysicsBody(rightBody);
    background3->setPosition(Point(visibleSize.width - background3->getContentSize().width + origin.x, 0));

    auto ltBody = PhysicsBody::createBox(background4->getContentSize());
    ltBody->setDynamic(false);
    ltBody->setCollisionBitmask(1);
    ltBody->setContactTestBitmask(true);
    background4->setPhysicsBody(ltBody);
    background4->setPosition(Point(visibleSize.width - background4->getContentSize().width + origin.x - 405, 0));

    // add the sprite as a child to this layer
    this->addChild(background1, 0);
    this->addChild(background2, 0);
    this->addChild(background3, 0);
    this->addChild(background4, 0);
    this->addChild(background5, 0);
    if (mangchoi == 2) {
        this->addChild(background6, 0);
        this->addChild(background7, 0);
    }



    car = Car::createView(this, cc1, cc2, cc3);
    _car = utils::findChild<Sprite*>(this, "cuong123");
    /*obs = Obstacle::createView(this);
    _obs = utils::findChild<Sprite*>(this, "cuong");*/
    pri = Prize::createView(this);
    _pri = utils::findChild<Sprite*>(this, "prize1");
    nof = NumberOfPlays::createView(this);
    _nof = utils::findChild<Sprite*>(this, "noff");
    /*ai = CarAi::createView(this, );
    _ai = utils::findChild<Sprite*>(this, "aii");*/

    car->setPosition(100, 100);

    //Tạo 1 bộ khung body vật lý dạng hình tròn
    auto playCar = PhysicsBody::createCircle(_car->getContentSize().width / 2.5);
    //Đặt cờ = 1, để kiểm tra đối tượng khi va chạm sau này
    _car->setTag(1);
    //Lệnh này ko hiểu lắm nhưng thực sự ko thể thiếu, bỏ đi sẽ ko có gì xuất hiện khi va chạm
    playCar->setCollisionBitmask(0x000001);
    playCar->setContactTestBitmask(true);
    //Đặt bộ khung vật lý vào nhân vật
    _car->setPhysicsBody(playCar);

    this->addChild(car);

    layer1 = new GameMap();
    this->addChild(layer1);

    layer2 = new GameMap();
    this->addChild(layer2);

    layer3 = new GameMap();
    this->addChild(layer3);

    Document m_document;
    ssize_t size;
    char* buf = (char*)FileUtils::getInstance()->getFileData("D:/file.json", "r", &size);
    std::string content(buf, size);
    m_document.Parse(content.c_str());

    auto levelConfig = m_document["levels"].GetArray();
    auto obss = levelConfig[s_currentLevel]["obs"].GetArray()[1].GetString();
    auto t = levelConfig[s_currentLevel]["time"].GetArray()[0].GetFloat();
    time = t;
    creatObs(obss);
    creatPri(layer1);
    creatNof(layer2);

    auto mai1 = levelConfig[s_currentLevel]["cars"].GetArray()[0].GetString();
    auto mai2 = levelConfig[s_currentLevel]["cars"].GetArray()[1].GetString();
    auto mai3 = levelConfig[s_currentLevel]["cars"].GetArray()[2].GetString();

    creatCarai(layer3, mai1, mai2, mai3);

    this->runAction(Sequence::create(CallFunc::create([=] {
        start();
        }), DelayTime::create(1.0f)
            , CallFunc::create([=] {
            this->scheduleUpdate();
                }), NULL));

    showProgressTimer();

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameMap::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //Tạo đối tượng lắng nghe va chạm nếu xảy ra
    auto contactListener = EventListenerPhysicsContact::create();
    //Khi có va chạm sẽ gọi hàm onContactBegin để xử lý va chạm đó, chú ý dòng CC_CALLBACK_1, nhiều tại liệu là CC_CALLBACK_2 sẽ báo lỗi ko chạy
    contactListener->onContactBegin = CC_CALLBACK_1(GameMap::onContactBegin, this);
    //Bộ truyền tải kết nối với đối tượng bắt va chạm
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    /*auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
    edgeBody->setCollisionBitmask(0x000001);
    edgeBody->setContactTestBitmask(true);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);*/

    return true;
}

int random(int start, int last)
{
    int iRet;
    srand(time(NULL));
    iRet = (rand() % (last - start + 1)) + start;
    return iRet;
}

void GameMap::showProgressTimer()
{
    auto screenSize = Director::getInstance()->getVisibleSize();
    auto board1 = getBoundingBox();

    progressTimer = ProgressTimer::create(Sprite::create("ProgressCircle.png"));
    progressTimer->setType(ProgressTimer::Type::RADIAL);
    progressTimer->setMidpoint(Vec2(0.5f, 0.5f));
    progressTimer->setReverseDirection(true);
    progressTimer->setPercentage(100);
    progressTimer->setScale((screenSize.height - board1.getMaxY()) / 1.5f / progressTimer->getContentSize().width);
    progressTimer->setPosition(350, 670);
    progressTimer->setScale(0.2);
    this->addChild(progressTimer);
    auto time = ProgressFromTo::create(TIMEGAME, 100, 0);


    //call den func sau action
    progressTimer->runAction(Sequence::create(time, CallFunc::create([=]() {
        gameWin(this);
        }), NULL));
}


void GameMap::gameWin(Ref *a) {
    s_currentLevel++;
    if (s_currentLevel <= 2) {
        auto scene = GameMap::createScene(0.005, cc1, cc2, cc3);
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }
    else
    {
        auto scene = GameOver::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }
    
 //   auto scene = GameMap::createScene(0.005, cc1, cc2, cc3);
//    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


bool GameMap::onContactBegin(const PhysicsContact& contact)
{
    //Lấy đối tượng va chạm thứ nhất, ép kiểu con trỏ Sprite*
    auto car = (Sprite*)contact.getShapeA()->getBody()->getNode();
    //Lấy giá trị cờ để xét xem đối tượng nào ( đạn, quái, hay nhân vật)
    int tag = car->getTag();

    //Lấy đối tượng va chạm thứ hai, ép kiểu con trỏ Sprite*
    auto obs = (Sprite*)contact.getShapeB()->getBody()->getNode();
    //Lấy giá trị cờ để xét xem đối tượng nào ( đạn, quái, hay nhân vật)
    int tag1 = obs->getTag();

    auto pri = (Sprite*)contact.getShapeB()->getBody()->getNode();
    int tag2 = pri->getTag();

    auto nop = (Sprite*)contact.getShapeB()->getBody()->getNode();
    int tag3 = nop->getTag();

    auto body = (Sprite*)contact.getShapeA()->getBody()->getNode();
    int tag4 = body->getTag();

    auto ai = (Sprite*)contact.getShapeB()->getBody()->getNode();
    int tag5 = body->getTag();
    // Nếu va chạm xảy ra giữa quái và nhân vật thì NV lăn ra chết , rồi GameOver, rồi tính điểm
    if ((tag == 1 & tag1 == 2) || (tag == 2 & tag1 == 1))
    {
        // Xử lý GameOver
        // Tính điểm 
        mangchoi--;

        if (mangchoi == 1) {
            car->removeFromParent();
            background7->removeFromParent();
        }
        if (mangchoi == 0) {
            auto cc = _car->getPosition();
            auto start1 = Sprite::create("no/02/1.png");
            start1->setPosition(cc);
            this->addChild(start1);

            auto characterAnimation = Animation::create();
            characterAnimation->setDelayPerUnit(0.15f);
            characterAnimation->setLoops(1);
            characterAnimation->addSpriteFrame(Sprite::create("no/02/1.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/2.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/3.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/4.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/5.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/6.png")->getSpriteFrame());
            characterAnimation->addSpriteFrame(Sprite::create("no/02/7.png")->getSpriteFrame());
            Animate* animate = Animate::create(characterAnimation);
            start1->runAction(animate);

            auto start2 = Sprite::create("no/01/1.png");
            start2->setPosition(cc);
            this->addChild(start2);
            auto characterAnimation1 = Animation::create();
            characterAnimation1->setDelayPerUnit(0.15f);
            characterAnimation1->setLoops(1);
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/1.png")->getSpriteFrame());
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/2.png")->getSpriteFrame());
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/3.png")->getSpriteFrame());
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/4.png")->getSpriteFrame());
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/5.png")->getSpriteFrame());
            characterAnimation1->addSpriteFrame(Sprite::create("no/01/6.png")->getSpriteFrame());
            Animate* animate1 = Animate::create(characterAnimation1);
            start2->runAction(animate1);

            obs->removeFromParent();
            car->removeFromParent();
            gameOver(this);
            background6->removeFromParent();
        }
    }
    if ((tag == 1 & tag2 == 3) || (tag == 3 & tag2 == 1))
    {
        
        tien = tien + 1000;
        auto label = Label::createWithTTF(std::to_string(tien), "fonts/Marker Felt.ttf", 30);
        label->setColor(Color3B::GREEN);
        label->setPosition(Point(80, 706));
        label->setName("_tien");
        this->getChildByName("_tien");
        if (this->getChildByName("_tien") != NULL) removeChild(this->getChildByName("_tien"));
        this->addChild(label, 1);
        CCLOG("%d", "a");
        car->removeFromParent();
    }
    if ((tag == 1 & tag3 == 4) || (tag == 4 & tag3 == 1))
    {
        mangchoi++;
        CCLOG("%d", mangchoi);
        car->removeFromParent();
    }
    

    return true;
}

void GameMap::gameOver(Ref* a) {
    auto scene = GameOver::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameMap::creatObs(std::string cc) {
    this->schedule([=](float) {
        Obstacle* obs = Obstacle::createView(this, cc);
        this->addChild(obs);
        auto cc = obs->getPosition();
        }, 2.0f, CC_REPEAT_FOREVER, 2.0f, "aaaaaaaaa");
}

void GameMap::creatPri(GameMap* layer) {
    layer->schedule([=](float) {
        Prize* pri = Prize::createView(layer);
        layer->addChild(pri);
        auto cc = pri->getPosition();
        }, 7.0f, CC_REPEAT_FOREVER, 2.0f, "aaaaaaaaa");
}

void GameMap::creatNof(GameMap* layer) {
    layer->schedule([=](float) {
        NumberOfPlays* nop = NumberOfPlays::createView(layer);
        layer->addChild(nop);
        auto cc = nop->getPosition();
        }, 30.0f, CC_REPEAT_FOREVER, 2.0f, "aaaaaaaaa");
}

void GameMap::creatCarai(GameMap* layer, std::string mai1, std::string mai2, std::string mai3) {
    layer->schedule([=](float) {
        CarAi* ai = CarAi::createView(layer, mai1, mai2, mai3);
        layer->addChild(ai);
        auto cc = ai->getPosition();
        }, 7.0f, CC_REPEAT_FOREVER, 2.0f, "aaaaaaaaa");
}

void GameMap::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

    if (keyCode == EventKeyboard::KeyCode::KEY_A) {
        auto cc = _car->getPosition();
        _car->runAction(MoveTo::create(0.1f, cc + Point(-30, 0)));

    }
    if (keyCode == EventKeyboard::KeyCode::KEY_D) {
        auto cc = _car->getPosition();
        _car->runAction(MoveTo::create(0.1f, cc + Point(30, 0)));
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_S) {
        auto cc = _car->getPosition();
        _car->runAction(MoveTo::create(0.1f, cc + Point(0, -30)));
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_W) {
        auto cc = _car->getPosition();
        _car->runAction(MoveTo::create(0.1f, cc + Point(0, 30)));
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_Q)
    {
        car->skill1();
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_E)
    {
        car->skill2();
    }
}


void GameMap::update(float dt)
{
    background1->setPositionY(background1->getPositionY() - (time * visibleSize.height));
    background2->setPositionY(background2->getPositionY() - (time * visibleSize.height));

    if (background1->getPositionY() <= -background1->getContentSize().height)
    {
        background1->setPositionY(background2->getPositionY() + background2->getContentSize().height);
    }

    if (background2->getPositionY() <= -background2->getContentSize().height)
    {
        background2->setPositionY(background1->getPositionY() + background1->getContentSize().height);
    }
}

void GameMap::start() {
    auto start1 = Sprite::create("Start/Start.png");
    start1->setPosition(Point(417/2,729/2));
    this->addChild(start1);

    auto characterAnimation = Animation::create();
    characterAnimation->setDelayPerUnit(0.3f);

    characterAnimation->setLoops(1);
    characterAnimation->addSpriteFrame(Sprite::create("Start/Start.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("Start/Start2.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("Start/Start1.png")->getSpriteFrame());
    Animate* animate = Animate::create(characterAnimation);

    this->runAction(Sequence::create(CallFunc::create([=] {
        start1->runAction(animate);
        }), DelayTime::create(1.0f)
            , CallFunc::create([=] {
            this->removeChild(start1);
                }), NULL));
}