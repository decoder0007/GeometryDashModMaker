#include "GDModMaker.h"
#include "MinHook.h"
#include <cocos2d.h>
#include "gd.h"
#include <Windows.h>

using namespace cocos2d;

void GDModMaker::FadeInObject(CCNode* object, int speed) {
	object->runAction(CCSequence::create(CCShow::create(), CCFadeIn::create(1.0), NULL));
}

void GDModMaker::CreateSpriteToLayer(float x, float y, const char* spriteName, CCLayer* self) {
	CCSprite* sprite = CCSprite::createWithSpriteFrameName(spriteName);
	sprite->setPositionX(x);
	sprite->setPositionY(y);
	self->addChild(sprite);
}

CCSprite* GDModMaker::CreateSprite(float x, float y, const char* spriteName) {
	CCSprite* sprite = CCSprite::createWithSpriteFrameName(spriteName);
	sprite->setPositionX(x);
	sprite->setPositionY(y);
	return sprite;
}

void GDModMaker::HookMenuLayer() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));
	MH_CreateHook(
		(PVOID)(base + 0x1907b0),
		GDModMaker::MenuLayerCode,
		(LPVOID*)&Hooks::MenuLayerInit);
}