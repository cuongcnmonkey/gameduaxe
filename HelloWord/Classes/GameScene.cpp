#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameMap.h"


//#include "../Resources/rapidjson/rapidjson.h"
//#include "../Resources/rapidjson/document.h"
//using namespace rapidjson;
USING_NS_CC;
//static double speedgame = 0.005f;
Scene* GameScene::createScene()
{
    auto scene = Scene::create();

    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

   /* Document m_document;
    ssize_t size;

    char* buf = (char*)FileUtils::getInstance()->getFileData("D:/file.json", "r", &size);
    std::string content(buf, size);

    m_document.Parse(content.c_str());

    std::string str = m_document["CARAI"][0]["Rider"].GetString();

    auto label = Label::createWithTTF(str, "fonts/Marker Felt.ttf", 100);
    label->setColor(Color3B::RED);
    label->setPosition(Point(100, 100));
    this->addChild(label, 1);*/

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto mainMenu = CSLoader::getInstance()->createNode("csb/gameScene.csb");
    this->addChild(mainMenu);

    auto button = mainMenu->getChildByName<ui::Button*>("Button_1");
    button->setPressedActionEnabled(true);
    button->addClickEventListener([=](Ref*){
        for (int i = 1; i < 7; i++) {
            if (utils::findChild(this, "banhxe" + std::to_string(i))->isVisible() == true) {
                banhxe = i;
            }
        }
        for (int j = 2; j < 8; j++) {
            if (utils::findChild(this, "tire" + std::to_string(j))->isVisible() == true) {
                tire = j;
            }
        }
        for (int k = 1; k < 3; k++) {
            if (utils::findChild(this, "mu" + std::to_string(k))->isVisible() == true) {
                rider = k;
            }
        }


        Director::getInstance()->replaceScene(GameMap::createScene(0.005, "Tires/02/" + std::to_string(banhxe)+ ".png", "tire/" + std::to_string(tire) + ".png", "tire/mu" + std::to_string(rider) + ".png"));//1 khai bao
    });

    //chọn tire
    auto buttonTire1 = mainMenu->getChildByName<ui::Button*>("Button_4");
    buttonTire1->setPressedActionEnabled(true);
    buttonTire1->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(true);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        utils::findChild(this, "mu")->setVisible(false);
        utils::findChild(this, "vukhi")->setVisible(false);


        });

    auto buttonTire2 = utils::findChild<ui::Button*>(this,"Button_10");
    buttonTire2->setPressedActionEnabled(true);
    buttonTire2->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_8")->setVisible(true);
        utils::findChild(this, "Image_6")->setVisible(false);
        });

    auto buttonTire3 = utils::findChild<ui::Button*>(this, "Button_16");
    buttonTire3->setPressedActionEnabled(true);
    buttonTire3->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(true);
        utils::findChild(this, "Image_8")->setVisible(false);
        });

    auto buttonTire4 = utils::findChild<ui::Button*>(this, "Button_17");
    buttonTire4->setPressedActionEnabled(true);
    buttonTire4->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_10")->setVisible(true);
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        });

    auto buttonTire5 = utils::findChild<ui::Button*>(this, "Button_22");
    buttonTire5->setPressedActionEnabled(true);
    buttonTire5->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_8")->setVisible(true);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "Image_6")->setVisible(false);
        });

    auto Tire2 = utils::findChild<ui::Button*>(this, "Button_9");
    Tire2->setPressedActionEnabled(true);
    Tire2->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(true);
        utils::findChild(this, "tire3")->setVisible(false);
        utils::findChild(this, "tire4")->setVisible(false);
        utils::findChild(this, "tire5")->setVisible(false);
        utils::findChild(this, "tire6")->setVisible(false);
        utils::findChild(this, "tire7")->setVisible(false);
        });
    
    auto Tire3 = utils::findChild<ui::Button*>(this, "Button_8");
    Tire3->setPressedActionEnabled(true);
    Tire3->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(false);
        utils::findChild(this, "tire3")->setVisible(true);
        utils::findChild(this, "tire4")->setVisible(false);
        utils::findChild(this, "tire5")->setVisible(false);
        utils::findChild(this, "tire6")->setVisible(false);
        utils::findChild(this, "tire7")->setVisible(false);
        });

    auto Tire4 = utils::findChild<ui::Button*>(this, "Button_13");
    Tire4->setPressedActionEnabled(true);
    Tire4->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(false);
        utils::findChild(this, "tire3")->setVisible(false);
        utils::findChild(this, "tire4")->setVisible(true);
        utils::findChild(this, "tire5")->setVisible(false);
        utils::findChild(this, "tire6")->setVisible(false);
        utils::findChild(this, "tire7")->setVisible(false);
        });

    auto Tire5 = utils::findChild<ui::Button*>(this, "Button_14");
    Tire5->setPressedActionEnabled(true);
    Tire5->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(false);
        utils::findChild(this, "tire3")->setVisible(false);
        utils::findChild(this, "tire4")->setVisible(false);
        utils::findChild(this, "tire5")->setVisible(true);
        utils::findChild(this, "tire6")->setVisible(false);
        utils::findChild(this, "tire7")->setVisible(false);
        });

    auto Tire6 = utils::findChild<ui::Button*>(this, "Button_23");
    Tire6->setPressedActionEnabled(true);
    Tire6->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(false);
        utils::findChild(this, "tire3")->setVisible(false);
        utils::findChild(this, "tire4")->setVisible(false);
        utils::findChild(this, "tire5")->setVisible(false);
        utils::findChild(this, "tire6")->setVisible(true);
        utils::findChild(this, "tire7")->setVisible(false);
        });

    auto Tire7 = utils::findChild<ui::Button*>(this, "Button_24");
    Tire7->setPressedActionEnabled(true);
    Tire7->addClickEventListener([=](Ref*) {
        utils::findChild(this, "tire2")->setVisible(false);
        utils::findChild(this, "tire3")->setVisible(false);
        utils::findChild(this, "tire4")->setVisible(false);
        utils::findChild(this, "tire5")->setVisible(false);
        utils::findChild(this, "tire6")->setVisible(false);
        utils::findChild(this, "tire7")->setVisible(true);
        });
    
    //chọn bánh xe
    auto banhxe = utils::findChild<ui::Button*>(this, "Button_3");
    banhxe->setPressedActionEnabled(true);
    banhxe->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(true);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        utils::findChild(this, "mu")->setVisible(false);
        utils::findChild(this, "vukhi")->setVisible(false);
        });

    auto banhxe1 = utils::findChild<ui::Button*>(this, "Button_19");
    banhxe1->setPressedActionEnabled(true);
    banhxe1->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(true);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        });

    auto banhxe2 = utils::findChild<ui::Button*>(this, "Button_20");
    banhxe2->setPressedActionEnabled(true);
    banhxe2->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(true);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        });

    auto banhxe3 = utils::findChild<ui::Button*>(this, "Button_26");
    banhxe3->setPressedActionEnabled(true);
    banhxe3->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(true);
        });

    auto banhxe4 = utils::findChild<ui::Button*>(this, "Button_27");
    banhxe4->setPressedActionEnabled(true);
    banhxe4->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(true);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        });

    auto banhxe5 = utils::findChild<ui::Button*>(this, "Button_15");
    banhxe5->setPressedActionEnabled(true);
    banhxe5->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(true);
        utils::findChild(this, "banhxe2")->setVisible(false);
        utils::findChild(this, "banhxe3")->setVisible(false);
        utils::findChild(this, "banhxe4")->setVisible(false);
        utils::findChild(this, "banhxe5")->setVisible(false);
        utils::findChild(this, "banhxe6")->setVisible(false);
        });

    auto banhxe6 = utils::findChild<ui::Button*>(this, "Button_18");
    banhxe6->setPressedActionEnabled(true);
    banhxe6->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(false);
        utils::findChild(this, "banhxe2")->setVisible(true);
        utils::findChild(this, "banhxe3")->setVisible(false);
        utils::findChild(this, "banhxe4")->setVisible(false);
        utils::findChild(this, "banhxe5")->setVisible(false);
        utils::findChild(this, "banhxe6")->setVisible(false);
        });

    auto banhxe7 = utils::findChild<ui::Button*>(this, "Button_21");
    banhxe7->setPressedActionEnabled(true);
    banhxe7->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(false);
        utils::findChild(this, "banhxe2")->setVisible(false);
        utils::findChild(this, "banhxe3")->setVisible(true);
        utils::findChild(this, "banhxe4")->setVisible(false);
        utils::findChild(this, "banhxe5")->setVisible(false);
        utils::findChild(this, "banhxe6")->setVisible(false);
        });

    auto banhxe8 = utils::findChild<ui::Button*>(this, "Button_25");
    banhxe8->setPressedActionEnabled(true);
    banhxe8->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(false);
        utils::findChild(this, "banhxe2")->setVisible(false);
        utils::findChild(this, "banhxe3")->setVisible(false);
        utils::findChild(this, "banhxe4")->setVisible(true);
        utils::findChild(this, "banhxe5")->setVisible(false);
        utils::findChild(this, "banhxe6")->setVisible(false);
        });

    auto banhxe9 = utils::findChild<ui::Button*>(this, "Button_28");
    banhxe9->setPressedActionEnabled(true);
    banhxe9->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(false);
        utils::findChild(this, "banhxe2")->setVisible(false);
        utils::findChild(this, "banhxe3")->setVisible(false);
        utils::findChild(this, "banhxe4")->setVisible(false);
        utils::findChild(this, "banhxe5")->setVisible(true);
        utils::findChild(this, "banhxe6")->setVisible(false);
        });

    auto banhxe10 = utils::findChild<ui::Button*>(this, "Button_29");
    banhxe10->setPressedActionEnabled(true);
    banhxe10->addClickEventListener([=](Ref*) {
        utils::findChild(this, "banhxe1")->setVisible(false);
        utils::findChild(this, "banhxe2")->setVisible(false);
        utils::findChild(this, "banhxe3")->setVisible(false);
        utils::findChild(this, "banhxe4")->setVisible(false);
        utils::findChild(this, "banhxe5")->setVisible(false);
        utils::findChild(this, "banhxe6")->setVisible(true);
        });

    //chọn mũ
    auto mu = utils::findChild<ui::Button*>(this, "Button_5");
    mu->setPressedActionEnabled(true);
    mu->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        utils::findChild(this, "mu")->setVisible(true);
        utils::findChild(this, "vukhi")->setVisible(false);
        });

    auto mu1 = utils::findChild<ui::Button*>(this, "Button_30");
    mu1->setPressedActionEnabled(true);
    mu1->addClickEventListener([=](Ref*) {
        utils::findChild(this, "mu1")->setVisible(true);
        utils::findChild(this, "mu2")->setVisible(false);
        utils::findChild(this, "vukhi1")->setVisible(false);
        utils::findChild(this, "vukhi2")->setVisible(false);
        utils::findChild(this, "vukhi3")->setVisible(false);
        utils::findChild(this, "vukhi4")->setVisible(false);
        });

    auto mu2 = utils::findChild<ui::Button*>(this, "Button_31");
    mu2->setPressedActionEnabled(true);
    mu2->addClickEventListener([=](Ref*) {
        utils::findChild(this, "mu2")->setVisible(true);
        utils::findChild(this, "mu1")->setVisible(false);
        utils::findChild(this, "vukhi1")->setVisible(false);
        utils::findChild(this, "vukhi2")->setVisible(false);
        utils::findChild(this, "vukhi3")->setVisible(false);
        utils::findChild(this, "vukhi4")->setVisible(false);
        });

    //chọn vukhi
    auto vukhi = utils::findChild<ui::Button*>(this, "Button_6");
    vukhi->setPressedActionEnabled(true);
    vukhi->addClickEventListener([=](Ref*) {
        utils::findChild(this, "Image_6")->setVisible(false);
        utils::findChild(this, "Image_8")->setVisible(false);
        utils::findChild(this, "Image_10")->setVisible(false);
        utils::findChild(this, "imgbanhxe1")->setVisible(false);
        utils::findChild(this, "imgbanhxe2")->setVisible(false);
        utils::findChild(this, "imgbanhxe3")->setVisible(false);
        utils::findChild(this, "mu")->setVisible(false);
        utils::findChild(this, "vukhi")->setVisible(true);
        });

    auto vukhi1 = utils::findChild<ui::Button*>(this, "Button_32");
    vukhi1->setPressedActionEnabled(true);
    vukhi1->addClickEventListener([=](Ref*) {
        if (utils::findChild(this, "mu1")->isVisible() == true) {
            utils::findChild(this, "vukhi1")->setVisible(true);
            utils::findChild(this, "vukhi2")->setVisible(false);
            utils::findChild(this, "vukhi3")->setVisible(false);
            utils::findChild(this, "vukhi4")->setVisible(false);
        }
        else {
            utils::findChild(this, "vukhi1")->setVisible(false);
            utils::findChild(this, "vukhi2")->setVisible(false);
            utils::findChild(this, "vukhi3")->setVisible(true);
            utils::findChild(this, "vukhi4")->setVisible(false);
        }
        });

    auto vukhi2 = utils::findChild<ui::Button*>(this, "Button_33");
    vukhi2->setPressedActionEnabled(true);
    vukhi2->addClickEventListener([=](Ref*) {
        if (utils::findChild(this, "mu1")->isVisible() == true) {
            utils::findChild(this, "vukhi1")->setVisible(false);
            utils::findChild(this, "vukhi2")->setVisible(true);
            utils::findChild(this, "vukhi3")->setVisible(false);
            utils::findChild(this, "vukhi4")->setVisible(false);
        }
        else {
            utils::findChild(this, "vukhi1")->setVisible(false);
            utils::findChild(this, "vukhi2")->setVisible(false);
            utils::findChild(this, "vukhi3")->setVisible(false);
            utils::findChild(this, "vukhi4")->setVisible(true);
        }
        });

    return true;
}

