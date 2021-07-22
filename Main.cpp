#include "Main.h"
#include "GDModMaker.h"
#include "gd.h"
#include <cocos2d.h>
#include <thread>

using namespace cocos2d;

bool __fastcall GDModMaker::MenuLayerCode(CCLayer* self) {
	#pragma region DO NOT DELETE
	if (!MenuLayerInit(self)) {
		return false;
	}

	if (Started) gd::AchievementNotifier::sharedState()->notifyAchievement("Welcome", "This mod was made with GDModMaker", "GJ_editBtn_001.png", 1);
	Started = false;
	auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();
#pragma endregion

	//Your code goes here
	GDModMaker::CreateSpriteToLayer(100, 100, "difficulty_10_btn2_001.png", self);
	GDModMaker::CreateSpriteToLayer(150, 150, "difficulty_10_btn2_001.png", self);
	GDModMaker::CreateSpriteToLayer(27, 300, "difficulty_10_btn2_001.png", self);

	

	return true;
}

void RunMod() {
	//Your Code Goes Here

	GDModMaker::HookMenuLayer();
}