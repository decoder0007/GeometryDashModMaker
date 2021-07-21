#include "GDModMaker.h"
#include "MinHook.h"
#include <cocos2d.h>
#include "gd.h"
#include <Windows.h>

using namespace cocos2d;

void GDModMaker::MenuLayer::AddSprite(float paramX, float paramY, const char* paramSpriteName, CCLayer* self) {
	CCSprite* sprite = CCSprite::createWithSpriteFrameName(filename);
	sprite->setPositionX(x);
	sprite->setPositionY(y);

	self->addChild(sprite);
}

void GDModMaker::HookMenuLayer() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));
	MH_CreateHook((PVOID)(base + 0x1907b0), GDModMaker::MenuLayerInitHook, (LPVOID*)&MenuLayerInit);
}