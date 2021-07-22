#pragma once
#include <cocos2d.h>
#include "gd.h"

using namespace cocos2d;

/*
This is simply for hooking and should not be used
*/
namespace Hooks {
	inline bool(__thiscall* MenuLayerInit)(CCLayer* self);
}

namespace GDModMaker {
	void HookMenuLayer();
	bool __fastcall MenuLayerCode(CCLayer* self);

	/*
	Creates and adds a sprite to a layer
	Usage: GDModMaker::CreateSpriteToLayer(X position, Y position, Name of the sprite, self (yes just type self))
	X goes from left to right and Y goes from bottom to top.
	Note: Once added it cannot be modified. Please see GDModMaker::CreateSprite*/
	
	void CreateSpriteToLayer(float x, float y, const char* spriteName, CCLayer* self);

	/*
	Creates a sprite
	Usage: GDModMaker::CreateSprite(X position, Y position, Name of the sprite)
	X goes from left to right and Y goes from bottom to top.
	Note: This function will return the sprite so to add it to a layer
	you must do:
		spriteName = GDModMaker::CreateSprite(X position, Y position, Name of the sprite);
		self -> addChild(spriteName);
	See GDModMaker::CreateSpriteToLayer to automatically add it to the layer although
	you will not be able to modify it using this method.*/

	CCSprite* CreateSprite(float x, float y, const char* spriteName);

	/*
	Fades in the given object at the given speed
	speed - 1 will fade in in a second
	*/
	void FadeInObject(CCNode* Object, int speed);
}