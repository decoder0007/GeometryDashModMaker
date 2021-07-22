#include "Main.h"
#include "GDModMaker.h"
#include "gd.h"
#include <cocos2d.h>
#include <thread>

using namespace cocos2d;

void test(gd::AchievementBar* ach) {
	Sleep(5000);
	ach->setVisible(true);
	Sleep(2000);
	for (int x = 0; x < 101; x = x + 1) {
		ach->setOpacity(100 - x);
		Sleep(10);
	}
	ach->setVisible(false);
	ach->setOpacity(100);
}

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

	gd::AchievementNotifier::sharedState()->notifyAchievement("Welcome", "This mod was made with GDModMaker", "GJ_editBtn_001.png", 1);

	return true;
}

void RunMod() {
	//Your Code Goes Here

	GDModMaker::HookMenuLayer();
}