/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CC_APPLICATION_IOS_H__
#define __CC_APPLICATION_IOS_H__

#include "base/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include "2d/platform/CCCommon.h"
#include "2d/platform/CCApplicationProtocol.h"

NS_CC_BEGIN

class Rect;

class CC_DLL Application : public ApplicationProtocol
{
public:
    /**
     * @js ctor
     */
    Application();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~Application();
        
    /**
    @brief    运行消息循环
    */
    int run();
        
    /**
    @brief    获取当前应用程序实例.
    @return 返回当前应用程序实例指针.
    */
    static Application* getInstance();
    
    /** @deprecated 用getInstance()代替 */
    CC_DEPRECATED_ATTRIBUTE static Application* sharedApplication();
    
    /**
     @brief   Director调用来限制FPS.
     @param interval    当前帧和下一帧的时间间隔，以秒为单位
     */
    virtual void setAnimationInterval(double interval);

    /**
    @brief 获取当前语言配置
    @return 返回当前语言配置
    */
    virtual LanguageType getCurrentLanguage();
    
    /**
     @brief 获取当前语言的iso 639-1的代码
     @return 返回当前语言的iso 639-1的代码
     */
    virtual const char * getCurrentLanguageCode();
    
    /**
     @brief 获取目标平台
     */
    virtual Platform getTargetPlatform();

	/**
	@brief  这个函数在应用程序的屏幕尺寸改变的时候被调用
	@param 新的宽度
	@param 新的高度
	*/
	virtual void applicationScreenSizeChanged(int newWidth, int newHeight);

protected:
    static Application * sm_pSharedApplication;
};

NS_CC_END

#endif // CC_PLATFORM_IOS

#endif    // end of __CC_APPLICATION_IOS_H__
