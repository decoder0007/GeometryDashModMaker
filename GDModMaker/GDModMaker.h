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
	Adds a sprite to the Menu Layer
	Usage: GDModMaker::MenuLayer::AddSprite(X position, Y position, Name of the sprite)
	X goes from left to right and Y goes from bottom to top.*/
	static void AddSprite(float x, float y, const char* spriteName, CCLayer* self);
}