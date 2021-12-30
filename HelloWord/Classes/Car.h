#pragma once
#include<cocos2d.h>
#include "cocos2d/cocos/editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"

class Car :public cocos2d::Layer, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(Car);
	static Car* createView(cocos2d::Layer* layer, std::string cc1, std::string cc2, std::string cc3);
	void loadData(cocos2d::Layer* layer, std::string cc1, std::string cc2, std::string cc3);
	Car();
	~Car();
	void LoadImageShip(int type);
	void skill1();
	void skill2();
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* _car;
	cocos2d::Sprite* Rider;

};
