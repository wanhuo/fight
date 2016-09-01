#ifndef __Screen_h__
#define __Screen_h__
#include "cocos2d.h"

USING_NS_CC;



/**
* ÆÁÄ»²ÎÊý
* Author
*	Dennis
*/

class Screen
{
	static CCRect getVisibleRect();

    static CCPoint left();
    static CCPoint right();
    static CCPoint top();
    static CCPoint bottom();
    static CCPoint center();
    static CCPoint leftTop();
    static CCPoint rightTop();
    static CCPoint leftBottom();
    static CCPoint rightBottom();
private:
    static void lazyInit();
    static CCRect s_visibleRect;
};

#endif