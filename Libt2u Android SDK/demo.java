package com.example.demo;

import android.os.Bundle;
import android.os.SystemClock;
import android.app.Activity;
import android.util.Log;
import com.vveye.T2u;

public class Main extends Activity {

	private int port;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		Log.d("T2u","Demo for T2u!");
		
		//-------------初始化------------------------
		T2u.Init("122.225.102.4", (char)8000, "");
		
		//---------搜索本地设备-------------------------
		byte[] result = new byte[1500];
		int num = T2u.Search(result);
		String tmp;
		Log.d("T2u","T2u.Search:"+num);
		if (num>0)
		{
			tmp = new String(result);
			Log.d("T2u",tmp);
		}

		//----------------等待上线---------------------
		while(T2u.Status()==0)
		{
			SystemClock.sleep(1000);
			Log.d("T2u","T2u.Status="+T2u.Status());
		}
			
		Log.d("T2u","T2u.status -> "+T2u.Status());

		//-------------------建立端口映射--------------------
		if (T2u.Status()==1)
		{
			int ret;
			//---------------查询设备是否在线-----------------
			ret = T2u.Query("6CE873D2435C");
			Log.d("T2u","T2u.Query 6CE873D2435C -> "+ret);
			if (ret>0)
			{
				//--------------创建映射端口-----------------
				port = T2u.AddPortEx("6CE873D2435C", "192.168.1.67" ,(char)8000, (char)8000);
				Log.d("T2u","T2u.add_port -> port:"+port);
			}
		}
		
		setContentView(R.layout.main);
	}

	protected void onDestroy()
	{
		Log.d("T2u","onDestroy");
		
		//关闭端口
		if (port>0)
			T2u.DelPort((char)port);
		
		//释放资源
		T2u.Exit();
		super.onDestroy();
	}
}
