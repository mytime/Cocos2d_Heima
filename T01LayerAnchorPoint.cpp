#include "T01LayerAnchorPoint.h"

/*
锚点
*/

/*实现头文件里scene()方法*/
Scene *T01LayerAnchorPoint::scene()
{
	//创建场景
	Scene *scene = Scene::create();

	//创建层
	T01LayerAnchorPoint *layer = T01LayerAnchorPoint::create();

	//添加到场景
	scene->addChild(layer);

	return scene;
}


/*实现头文件里create()方法*/
T01LayerAnchorPoint *T01LayerAnchorPoint::create()
{
	T01LayerAnchorPoint *pRet = new T01LayerAnchorPoint();
	if (pRet && pRet->init())
	{
		pRet->autorelease(); //添加到内存托管
	}
	else
	{
		delete pRet;
		pRet = NULL;
	}
	return pRet;
}

/*实现头文件里init()方法*/
bool T01LayerAnchorPoint::init()
{
	//初始化一个层
	Layer::init();

	//可视范围
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//创建精灵
	spr = Sprite::create("anchor3.png");

	//锚点(精灵左下角位置在屏幕中心位置)
	//spr->setAnchorPoint(ccp(0, 0));
	//忽略锚点
	spr->ignoreAnchorPointForPosition(true);

	//精灵放置位置
	spr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

	//定时器,每2秒转动30度
	schedule(schedule_selector(T01LayerAnchorPoint::mySchedule), 2);

	//添加到层
	addChild(spr);


	return true;
}

void T01LayerAnchorPoint::draw2()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// R G B 透明度
	ccDrawColor4B(255, 0, 0, 255);

	//绘制水平线，arg1:绘制起点，arg2:绘制终点
	ccDrawLine(Vec2(0, visibleSize.height / 2), Vec2(visibleSize.width, visibleSize.height / 2));

	//垂直线
	ccDrawLine(Vec2(visibleSize.width / 2, 0), Vec2(visibleSize.width / 2, visibleSize.height));

}

void T01LayerAnchorPoint::mySchedule(float dt){
	static float ro = 0;
	ro += 30;
	spr->setRotation(ro);
}
