/***************************************************************************
 *   Copyright (C) 2014 by Yexr   *
 *   yexr@vveye.com   *
 ***************************************************************************/
#ifndef _LIB_T2U2_H_
#define _LIB_T2U2_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*
初始化
*/
void		t2u2_init(const char* svraddr,unsigned short svrport,const char* svrkey);

/*
设置回调函数
*/
void		t2u2_set_callback(PT2uCallBack callback);

/*
设置P2P端口范围
min_port:	最小端口号
max_port:	最大端口号
*/
void		t2u2_set_port_range(unsigned short min_port,unsigned short max_port);

/*
添加映射端口

uuid: 远端设备UUID

remote_port:	远端设备端口
local_port:	映射到本地的端口，0表示使用随机端口

返回值:	
	>0:  映射到本地的端口
	-1:  映射失败，端口被占用
*/

int		t2u2_add_port(const char* uuid,unsigned short remote_port,unsigned short local_port);

int		t2u2_add_port_ex(const char* uuid,const char* remote_ip,unsigned short remote_port,unsigned short local_port);

int		t2u2_add_port_v3(const char* uuid,const char* passwd,const char* remote_ip,unsigned short remote_port,unsigned short local_port);

/*
删除映射端口
*/
void		t2u2_del_port(unsigned short port);

/*
查询端口状态

返回值:
1:		已连通
0:		未连通
-1:		不存在
-2:		P2P连接失败，等待30秒后自动重连
-3:		P2P连接中断，等待30秒后自动重连
-4:		对方离线，等待30秒后自动重连
-5:		设备有密码，密码认证失败
*/
int		t2u2_port_status(unsigned short port,PT2uNetStat pStat);


/*
查询速率统计

port:	要查询的端口号，0表示统计全局速率
pRate:	保存数据的速率结构指针

返回值:
		0:	成功
		-1:	端口不存在
*/
int		t2u2_get_rate(unsigned short port,PT2uNetRate pRate);

int		t2u2_add_udp_port(const char* uuid,unsigned short remote_port,unsigned short local_port);
int		t2u2_add_udp_port_ex(const char* uuid,const char* remote_ip,unsigned short remote_port,unsigned short local_port);
int		t2u2_add_udp_port_v3(const char* uuid,const char* passwd,const char* remote_ip,unsigned short remote_port,unsigned short local_port);
void		t2u2_del_udp_port(unsigned short port);
int		t2u2_udp_port_status(unsigned short port,PT2uNetStat pStat);
int		t2u2_get_udp_rate(unsigned short port,PT2uNetRate pRate);


/*
查询设备状态

返回值:
		1:	设备在线
		0:	设备不在线
		-1:	查询失败
*/
int		t2u2_query(const char* uuid);


/*
查询设备状态和附加参数

buff:			保存设备参数的缓存地址
buffsize:		缓存大小，不超过1024字节
ipaddr:		保存设备公网IP的缓存地址
ipsize:		缓存大小

返回值:
		1:	设备在线
		0:	设备不在线
		-1:	查询失败
*/
int		t2u2_query_ex(const char * uuid,char* buff,int buffsize,char* ipaddr,int ipsize);


/*
搜索发现本地内网的设备
搜索结果以文本方式输出，每行一条记录，格式为: uuid=xxxx,ip=x.x.x.x

buff:			输出结果的缓存地址
buffsize:		缓存大小

返回值 :  
		>=0		发现的设备数
		-1		失败
*/
int		t2u2_search(char* buff,int buffsize);

/*
通过代理网关查询对方所在内网的DVR设备
查询结果以文本方式输出，每行一条记录，
格式为: 厂家代码|DVR序列号|通道数|IP|端口

参数
uuid:		代理网关的UUID
outbuff:		输出文本结果的缓存
buffsize:		缓存大小

返回值:
		1:		查询成功，有DVR 设备
		0:		查询成功，但无设备
		-1:		连接失败
		-2:		查询失败
		-3:		查询超时，对方无响应
*/
int		t2u2_search_dvr(const char* uuid,char* outbuff,int buffsize);

/*
查询状态

返回值:
1:		与服务器连接，状态正常
0:		未连接服务器
-1:		SDK未初始化
-2:		密钥无效
*/
int		t2u2_status();

/*
退出并释放资源
*/
void		t2u2_exit();

#ifdef __cplusplus
}
#endif

#endif


