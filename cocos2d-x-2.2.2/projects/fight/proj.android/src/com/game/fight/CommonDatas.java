package com.game.fight;

import android.test.IsolatedContext;

/**
 * 整个应用中涉及到的各种数据定义
 * @author mac
 *
 */
public class CommonDatas {
	public static Goods m_good = new Goods(); 
}

class Goods{
	/**========private========**/
	private static final int LEN = 13;
	
	private Boolean canRepeat = false; 
	/*商品计费点代码,商品名称依次为：八稚女  八酒杯    紧急躲避   死亡复活   金币礼包小   金币礼包中  金币礼包大  超级大礼包   怒气大礼包   */
	public static final String GOODSCODE[] = {"158365","158366","158367","158368","158369",
		"158370","158371","158372","158373","5009927","5009928","5011457",""};
	
	public static final String GOODSNAME[] = {"bazhinv","bajiubei","jinjiduobi","siwangfuhuo","libaoxiao","libaozhong","libaoda",
		"chaoji","nuqi","zaixian","yincang","jihuo"};	
	
	
//	public static final String GOODSCODE[] = {"006036006001","006036006002","006036006003","006036006004","006036006005",
//		"006036006006","006036006007","006036006008","006036006009","006036006010","006036006011","006036006012","006036006013"};
//	
//	public static final String GOODSNAME[] = {"5reconsist","5delete","10reconsist","10delete","5reconvery","SuperPackage","VIP1",
//		"VIP2","VIP3","VIP4","VIP5","OpenRecord","OpenAllModes"};	
	
	public int getIndexByName(String name)
	{
		int index = -1;
		for(int i = 0;i < LEN;i ++)
		{
			if(name.equals(GOODSNAME[i]))
			{
				index = i;
				break;
			}
		}
		canRepeat = index >= 0 && index < 5 ? true : false;
		return index;
	}
	
	public String getGoodsCodeByName(String name)
	{
		String code = "";
		int index = getIndexByName(name);
		if(index < 0)
			return code;
		else 
			code = GOODSCODE[index];
		return code;
	}
	
	public String getGoodsCodeByIndex(int index)
	{
		String code = "";
		if(index >= 0 && index < LEN)
			code = GOODSCODE[index];
		canRepeat = index >= 0 && index < 5 ? true : false;
		return code;
	}
	
	public Boolean canCurrentGoodsRepeatBuy()
	{
		return canRepeat;
	}
}