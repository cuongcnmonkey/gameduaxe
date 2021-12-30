#pragma once
#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__
#define SCROLLING_BACKGROUND_SPEED 0.005
#include "Car.h"
#include "Obstacle.h"
#include "Prize.h"
#include <vector>
#include "cocos2d.h"
#include "CarAi.h"
#include "NumberOfPlays.h"
USING_NS_CC;

class GameMap : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(float input, std::string string1, std::string string2, std::string string3);//1
	virtual bool init(float input, std::string string1, std::string string2, std::string string3);

	static GameMap* create(float input, std::string string1, std::string string2, std::string string3);
	void update(float dt);
	void start();
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void creatObs(std::string cc);
	void creatNof(GameMap* layer);
	void creatCarai(GameMap* layer, std::string mai1, std::string mai2, std::string mai3);
	void creatPri(GameMap* layer);
	void gameOver(Ref* a);
	void showProgressTimer();
	void gameWin(Ref *a);
	bool onContactBegin(const PhysicsContact& contact);
	float time;
	
private:
	float speedGame;
	std::string cc1;
	std::string cc2;
	std::string cc3;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* background1;
	cocos2d::Sprite* background2;
	cocos2d::Sprite* background3;
	cocos2d::Sprite* background4;
	cocos2d::Sprite* background5;
	cocos2d::Sprite* background6;
	cocos2d::Sprite* background7;
	ProgressTimer* progressTimer;
	int tien = 0;
	int mangchoi = 2;

	

	Car* car;
	Sprite* _car;
	Sprite* __car;
	Obstacle* obs;
	Sprite* _obs;
	Prize* pri;
	Sprite* _pri;
	NumberOfPlays* nof;
	Sprite* _nof;
	CarAi* ai;
	Sprite* _ai;
	GameMap* layer1;
	GameMap* layer2;
	GameMap* layer3;
};

#endif // __HELLOWORLD_SCENE_H__
