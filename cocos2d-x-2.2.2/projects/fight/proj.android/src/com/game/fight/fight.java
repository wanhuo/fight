/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

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
package com.game.fight;



import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

public class fight extends Cocos2dxActivity{
	
	static String TAG = "fight";
	static int payIndex[] = { 8/* 购买技能“八稚女” */, 9/* 购买技能“八酒杯 */,
		23/* 购买技能“紧急躲避” */, 10/* 死亡复活 */, 25/* 金币礼包（小） */, 26/* 金币礼包（中） */,
		27/* 金币礼包（大） */, 16/* 超级大礼包 */, 15 /* 怒气大礼包 */,32 ,31,19
    };
	 static String []mes = {"成功升级属性点","金币不足","成功升级属性点","金币不足",//3
	             "成功升级属性点","金币不足","成功获得怒气包","金币不足",//7    
	             "成功获得八稚女技能","成功八酒杯技能","获得死亡复活礼包","成功获得怒气包",//11      8，9，10 计费点
	             "成功获得金币礼包（小）","成功获得金币礼包（中）","成功获得金币礼包（大）","成功获得怒气大礼包",//15  ，15 计费点
	             "成功获得超级大礼包","死亡复活只能购买一次","死亡复活礼包已经使用","激活成功",//19    //16计费点           19硬计费点 mm平台不要
	             "领取超值大礼包成功","领取金币大礼包成功","领取技能大礼包成功","成功获得紧急躲避技能","成功获得受身技能", // 24
	             "领取1888金币礼包成功","领取5888金币礼包成功","领取18888金币礼包成功","您已经拥有紧急躲避和受身技能了",//28    25，26，27 计费点
	             "成功获得紧急躲避技能","成功获得受身技能"//花费金币购买
      };
	  int goodsIndex;
	  private static Context context; 
	  static fight king;
	  private static Toast mToast;
	  static int msgAdd;
	  static int isMusicOn;
	  private void exitGame() 
	  {

	  }
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
		king = this;
		context = fight.this;
	}
    @Override
	 protected void onStart() 
	 {
		// TODO Auto-generated method stub
		super.onStart();
		isMusicOn = 1;
		//musicIsOn(isMusicOn);
	 }
    
    public void openUrl(String url)
    {
         if(context==null)
              return ;
          System.out.println("invoking open url:" + url);
          Intent it = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
          it.setClassName("com.android.browser", "com.android.browser.BrowserActivity");
          context.startActivity(it);
          System.out.println("invoke open url ok");
          return ;
    }
    public static fight getActivity()
    { 
	    	return king;
    }
    
    static Handler handler = new Handler()
	 {
	  	   public void handleMessage(Message msg)
	  	   {
	  	       new AlertDialog.Builder(king.getContext()).setTitle("是否退出游戏") 
	  		    .setPositiveButton("确认", new DialogInterface.OnClickListener() { 
	  		        @Override 
	  		        public void onClick(DialogInterface dialog, int which) { 
	  		        	king.exit();
	  		        } 
	  		    }) 
	  		    .setNegativeButton("取消", new DialogInterface.OnClickListener() { 
	  		        @Override 
	  		        public void onClick(DialogInterface dialog, int which) { 
	  		        } 
	  		    }).show();
	  		}
	 };
	   
	 @Override
	 protected void onDestroy() 
	 {
			super.onDestroy();
			System.exit(0);
	 }
	  	
	  public static void showDialogs(int s)
	  {
			Message msg = new Message();
			handler.sendMessage(msg);
	  }

     public static void addXueTong(int s)
    {
    	Log.d(TAG, "addXueTong-->>s="+s );
		Message msg = new Message();
		msg.what = s;
		XueTonghandler.sendMessage(msg);
    }

	    
	 
     public  void exit()
	 {
		   finish();
	 }
	  static int m_mapIndex; 
	   public static void recordCurrentIndex(int mapIndex)
	   {
//		   if (m_mapIndex <= mapIndex) 
//		   {
//			     return;
//		   }else
//		   {
//			   m_mapIndex = mapIndex;
//		   }
//		   System.out.print(mapIndex);
//		   
//		   
//		   Log.e("sys", Integer.toString(mapIndex));
			Message msg = new Message();
			msg.what = mapIndex;
		    m_hander.sendMessage(msg);
	   }
	    
	   
	  static Handler m_hander = new Handler()
	  {
		  public void handleMessage(Message msg)
		  {
			  Toast.makeText(king, "asdasdasd", Toast.LENGTH_SHORT);
		  }
	  };
	   
	    public int findKey(int key)
	    {
	    	int toFind = 0;
	    	for (int i = 0; i < payIndex.length; i++) 
	    	{
			      if(key == payIndex[i])	
			      {
			    	  toFind = i;
			    	  break;
			      }
			}
	    	return toFind;
	    }
	  
	  
	    static Handler XueTonghandler = new Handler()
	    {
	       public void handleMessage(Message msg)
	       {
	    	      int find = king.findKey(msg.what);
	    	      
	    	      Log.d(TAG, "XueTonghandler-handleMessage-->>find="+find );
	    		  if(msg.what == 8 || msg.what == 9||msg.what == 10||msg.what == 25||msg.what == 26||msg.what ==27||msg.what == 15||msg.what == 16||msg.what == 23||msg.what == 31 || msg.what == 32 || msg.what == 19 )
	    		  {
	    			   king.goodsIndex = find;
	    			   //  kingBuyGoods(Goods.GOODSNAME[find]);
	    			   //Log.d(king.goodsIndex+"", king.goodsIndex+"" );
	    			   Log.d(TAG, "XueTonghandler-handleMessage-->>king.goodsIndex="+king.goodsIndex );
	    			   try {
//	    				 //硬计费点,激活游戏,1元,试玩三分钟后弹出 
//			    			EgamePay.pay(king, Goods.GOODSCODE[find], new EgamePayListener() {
//			    	   			@Override
//				    			public void paySuccess(String alias)
//			    	   			{ 
//			    	   				Toast.makeText(king, "道具("+ alias + ")支付成功。",Toast.LENGTH_LONG).show(); 
//			    	   				backAction( payIndex[king.goodsIndex]);
//			  	    			  
//			    	   			}
//				    			@Override
//				    			public void payFailed(String alias, int errorInt) 
//				    			{ 
//				    				Toast.makeText(king, "道具("+ alias + ")支付失败:" + errorInt,
//				    			    Toast.LENGTH_LONG).show(); 
//				    				backAction(100);
//				    			}
//				    			public void payCancel(String alias)
//				    			{ 
//				    				Toast.makeText(king, "道具("+ alias + ")支付操作被取消。",
//				    				Toast.LENGTH_LONG).show();
//				    				backAction(100);
//				    			}
//				    		});
					   } catch (Exception e) {
						// TODO: handle exception
					   }
		    			
	    			   Log.d(TAG, "XueTonghandler-handleMessage-->>payIndex[king.goodsIndex]="+payIndex[king.goodsIndex]);
	    			  backAction( payIndex[king.goodsIndex]);
	    			  
	    		  }
	    		  else
	    		  {
	    			  
		    		  if (mToast == null) 
		    		  {
		    			  Log.d(TAG, "XueTonghandler-handleMessage-->>mToast1");
		                  mToast = Toast.makeText(king, mes[msg.what], Toast.LENGTH_SHORT);
		              } 
		    		  else 
		              {
		            	  Log.d(TAG, "XueTonghandler-handleMessage-->>mToast2");
		                  mToast.setText(mes[msg.what]);
		              }
		              mToast.show();
		              Log.d(TAG, "XueTonghandler-handleMessage-->>mToast3");
		              backAction(msg.what);
				  }
	    	
	    	}
	    };

	    public static void kingBuyGoods(String name)//游戏调用此方法购买物品，
	    {
	    	//System.out.println("passed code is:" + name);
	    	int index = CommonDatas.m_good.getIndexByName(name);
	    	//System.out.println("code index is:" + index);
	    	String payCode = CommonDatas.m_good.getGoodsCodeByIndex(index);
	    	//System.out.println("need buy goods code:"+ payCode);
	    	king.goodsIndex = index;
	    	payCode = payCode.substring(payCode.length() - 3);
	      
	    }
	    
	    public static native void backAction(final int key);
	    public static native int getMapIndex();
	    
    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// fight should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

    static {
        System.loadLibrary("cocos2dcpp");
    }  
  
}
