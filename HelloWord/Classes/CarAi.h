#pragma once
#include<cocos2d.h>
#include "cocos2d/cocos/editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"
class CarAi :public cocos2d::Layer, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(CarAi);
	static CarAi* createView(cocos2d::Layer* layer, std::string mai1, std::string mai2, std::string mai3);
	void loadData(cocos2d::Layer* layer, std::string mai1, std::string mai2, std::string mai3);
	void dichuyen(cocos2d::Sprite* obs);
	void skill1();
	void skill2();
	void bomno(cocos2d::Sprite* p);
	CarAi();
	~CarAi();
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* Rider;
	cocos2d::Sprite* bom;
	cocos2d::Sprite* Tire;
};
