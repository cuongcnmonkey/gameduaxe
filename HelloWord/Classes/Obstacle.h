#pragma once
#include<cocos2d.h>
#include "cocos2d/cocos/editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"
class Obstacle :public cocos2d::Layer, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(Obstacle);
	static Obstacle* createView(cocos2d::Layer* layer, std::string cc);
	void loadData(cocos2d::Layer* layer, std::string cc);
	void dichuyen(cocos2d::Sprite* obs);
	Obstacle();
	~Obstacle();
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
