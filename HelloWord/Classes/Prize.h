#pragma once
#include<cocos2d.h>
#include "cocos2d/cocos/editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"
class Prize :public cocos2d::Layer, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(Prize);
	static Prize* createView(cocos2d::Layer* layer);
	void loadData(cocos2d::Layer* layer);
	void dichuyen(cocos2d::Sprite* obs);
	Prize();
	~Prize();
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
