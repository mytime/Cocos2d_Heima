#include "cocos2d.h"
USING_NS_CC; //    #define USING_NS_CC  using namespace cocos2d



class MyLayer:public Layer
{
public:
	CREATE_FUNC(MyLayer);
	//static MyLayer *create();

	static Scene * scene();

	bool init();
	
};

