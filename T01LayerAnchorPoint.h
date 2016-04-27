#ifndef __T01LayerAnchorPoint_H__	//如果没有被定义
#define __T01LayerAnchorPoint_H__	//则重新定义

#include "cocos2d.h"
USING_NS_CC;   //#define USING_NS_CC  using namespace cocos2d

			   /*
			   备注：需要把头文件T01LayerAnchorPoint.h注册到AppDelegate.cpp

			   示例
			   #include "T01LayerAnchorPoint.h"

			   bool AppDelegate::applicationDidFinishLaunching() {
			   auto scene = T01LayerAnchorPoint::scene(); 添加这一句
			   }


			   */

class T01LayerAnchorPoint :public Layer
{
public:

	static T01LayerAnchorPoint *create();	//预定义create函数
	bool init();							//预定义初始化函数

	static Scene *scene();					//预定义场景

	void myDraw();							//绘制
	void mySchedule(float dt);				//定时器
	Sprite * spr;


};

#endif //__T01LayerAnchorPoint_H__
