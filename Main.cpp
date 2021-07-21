#include "Main.h"
#include "GDModMaker.h"
#include "gd.h"
#include <cocos2d.h>
#include "achievement_nodes/AchievementBar.h"
#include "achievement_nodes/AchievementNotifier.h"

using namespace cocos2d;

bool __fastcall GDModMaker::MenuLayerInitHook(CCLayer* self) {
	#pragma region DO NOT DELETE
	if (!MenuLayerInit(self)) {
		return false;
	}

	auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();
#pragma endregion

	//Your code goes here
	GDModMaker::AddSprite(100, 100, "difficulty_10_btn2_001.png", self);
	GDModMaker::AddSprite(150, 150, "difficulty_10_btn2_001.png", self);
	GDModMaker::AddSprite(27, 300, "difficulty_10_btn2_001.png", self);

	auto welcomeMessage = gd::AchievementBar::create("Welcome", "Thank you for using GDModMaker", "GJ_editBtn_001.png", 1);
	welcomeMessage->setZOrder(1000);
	welcomeMessage->setPositionX(winSize.width / 2);
	welcomeMessage->setPositionY(winSize.height / 2);

	self->addChild(welcomeMessage);

	return true;
}

void RunMod() {
	//Your Code Goes Here

	GDModMaker::HookMenuLayer();
}