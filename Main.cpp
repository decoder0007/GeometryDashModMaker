#include "Main.h"
#include "GDModMaker.h"

bool __fastcall GDModMaker::MenuLayerInitHook(CCLayer* self) {
	#pragma region DO NOT DELETE
	if (!MenuLayerInit(self)) {
		return false;
	}
#pragma endregion

	//Your code goes here
	GDModMaker::AddSprite(100, 100, "difficulty_10_btn2_001.png", self);
	GDModMaker::AddSprite(150, 150, "difficulty_10_btn2_001.png", self);
	GDModMaker::AddSprite(27, 300, "difficulty_10_btn2_001.png", self);

	return true;
}

void RunMod() {
	//Your Code Goes Here
	GDModMaker::HookMenuLayer();
}