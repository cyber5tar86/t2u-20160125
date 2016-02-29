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
		
		//-------------��ʼ��------------------------
		T2u.Init("122.225.102.4", (char)8000, "");
		
		//---------���������豸-------------------------
		byte[] result = new byte[1500];
		int num = T2u.Search(result);
		String tmp;
		Log.d("T2u","T2u.Search:"+num);
		if (num>0)
		{
			tmp = new String(result);
			Log.d("T2u",tmp);
		}

		//----------------�ȴ�����---------------------
		while(T2u.Status()==0)
		{
			SystemClock.sleep(1000);
			Log.d("T2u","T2u.Status="+T2u.Status());
		}
			
		Log.d("T2u","T2u.status -> "+T2u.Status());

		//-------------------�����˿�ӳ��--------------------
		if (T2u.Status()==1)
		{
			int ret;
			//---------------��ѯ�豸�Ƿ�����-----------------
			ret = T2u.Query("6CE873D2435C");
			Log.d("T2u","T2u.Query 6CE873D2435C -> "+ret);
			if (ret>0)
			{
				//--------------����ӳ��˿�-----------------
				port = T2u.AddPortEx("6CE873D2435C", "192.168.1.67" ,(char)8000, (char)8000);
				Log.d("T2u","T2u.add_port -> port:"+port);
			}
		}
		
		setContentView(R.layout.main);
	}

	protected void onDestroy()
	{
		Log.d("T2u","onDestroy");
		
		//�رն˿�
		if (port>0)
			T2u.DelPort((char)port);
		
		//�ͷ���Դ
		T2u.Exit();
		super.onDestroy();
	}
}
