#include "MyLayer.h"

//自定义HelloWorld

//MyLayer *MyLayer::create()
//{
//	MyLayer * pRet = new MyLayer();
//	if(pRet && pRet->init())
//	{
//		pRet->autorelease();
//	}
//	else
//	{
//		delete pRet;
//		pRet = NULL;
//	}
//	return pRet;
//}

bool MyLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite * spr = Sprite::create("role.png");
	spr->setScale(0.5);
	spr->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	addChild(spr);


	return true;
}

Scene * MyLayer::scene(){
	Scene * scene = Scene::create();
	MyLayer *layer = MyLayer::create();
	scene->addChild(layer);
	return scene;

}
