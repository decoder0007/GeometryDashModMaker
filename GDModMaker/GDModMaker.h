#pragma once
#include <cocos2d.h>
#include "gd.h"

using namespace cocos2d;

extern float x;
extern float y;
extern const char* filename;

namespace GDModMaker {
	inline bool(__thiscall* MenuLayerInit)(CCLayer* self);
	bool __fastcall MenuLayerInitHook(CCLayer* self);
	void HookMenuLayer();

	/*
	Adds a sprite to the layer
	Usage: GDModMaker::MenuLayer::AddSprite(X position, Y position, Name of the sprite, self (yes just type self))
	X goes from left to right and Y goes from bottom to top.*/
	void AddSprite(float x, float y, const char* spriteName, CCLayer* self);

	/*
	Fades out the given object at the given speed
	speed - 100 will fade out in a second
	*/
	void FadeOutObject(CCNode* Object, int speed);
}