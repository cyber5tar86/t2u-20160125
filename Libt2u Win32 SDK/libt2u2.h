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
��ʼ��
*/
void		t2u2_init(const char* svraddr,unsigned short svrport,const char* svrkey);

/*
���ûص�����
*/
void		t2u2_set_callback(PT2uCallBack callback);

/*
����P2P�˿ڷ�Χ
min_port:	��С�˿ں�
max_port:	���˿ں�
*/
void		t2u2_set_port_range(unsigned short min_port,unsigned short max_port);

/*
���ӳ��˿�

uuid: Զ���豸UUID

remote_port:	Զ���豸�˿�
local_port:	ӳ�䵽���صĶ˿ڣ�0��ʾʹ������˿�

����ֵ:	
	>0:  ӳ�䵽���صĶ˿�
	-1:  ӳ��ʧ�ܣ��˿ڱ�ռ��
*/

int		t2u2_add_port(const char* uuid,unsigned short remote_port,unsigned short local_port);

int		t2u2_add_port_ex(const char* uuid,const char* remote_ip,unsigned short remote_port,unsigned short local_port);

int		t2u2_add_port_v3(const char* uuid,const char* passwd,const char* remote_ip,unsigned short remote_port,unsigned short local_port);

/*
ɾ��ӳ��˿�
*/
void		t2u2_del_port(unsigned short port);

/*
��ѯ�˿�״̬

����ֵ:
1:		����ͨ
0:		δ��ͨ
-1:		������
-2:		P2P����ʧ�ܣ��ȴ�30����Զ�����
-3:		P2P�����жϣ��ȴ�30����Զ�����
-4:		�Է����ߣ��ȴ�30����Զ�����
-5:		�豸�����룬������֤ʧ��
*/
int		t2u2_port_status(unsigned short port,PT2uNetStat pStat);


/*
��ѯ����ͳ��

port:	Ҫ��ѯ�Ķ˿ںţ�0��ʾͳ��ȫ������
pRate:	�������ݵ����ʽṹָ��

����ֵ:
		0:	�ɹ�
		-1:	�˿ڲ�����
*/
int		t2u2_get_rate(unsigned short port,PT2uNetRate pRate);

int		t2u2_add_udp_port(const char* uuid,unsigned short remote_port,unsigned short local_port);
int		t2u2_add_udp_port_ex(const char* uuid,const char* remote_ip,unsigned short remote_port,unsigned short local_port);
int		t2u2_add_udp_port_v3(const char* uuid,const char* passwd,const char* remote_ip,unsigned short remote_port,unsigned short local_port);
void		t2u2_del_udp_port(unsigned short port);
int		t2u2_udp_port_status(unsigned short port,PT2uNetStat pStat);
int		t2u2_get_udp_rate(unsigned short port,PT2uNetRate pRate);


/*
��ѯ�豸״̬

����ֵ:
		1:	�豸����
		0:	�豸������
		-1:	��ѯʧ��
*/
int		t2u2_query(const char* uuid);


/*
��ѯ�豸״̬�͸��Ӳ���

buff:			�����豸�����Ļ����ַ
buffsize:		�����С��������1024�ֽ�
ipaddr:		�����豸����IP�Ļ����ַ
ipsize:		�����С

����ֵ:
		1:	�豸����
		0:	�豸������
		-1:	��ѯʧ��
*/
int		t2u2_query_ex(const char * uuid,char* buff,int buffsize,char* ipaddr,int ipsize);


/*
�������ֱ����������豸
����������ı���ʽ�����ÿ��һ����¼����ʽΪ: uuid=xxxx,ip=x.x.x.x

buff:			�������Ļ����ַ
buffsize:		�����С

����ֵ :  
		>=0		���ֵ��豸��
		-1		ʧ��
*/
int		t2u2_search(char* buff,int buffsize);

/*
ͨ���������ز�ѯ�Է�����������DVR�豸
��ѯ������ı���ʽ�����ÿ��һ����¼��
��ʽΪ: ���Ҵ���|DVR���к�|ͨ����|IP|�˿�

����
uuid:		�������ص�UUID
outbuff:		����ı�����Ļ���
buffsize:		�����С

����ֵ:
		1:		��ѯ�ɹ�����DVR �豸
		0:		��ѯ�ɹ��������豸
		-1:		����ʧ��
		-2:		��ѯʧ��
		-3:		��ѯ��ʱ���Է�����Ӧ
*/
int		t2u2_search_dvr(const char* uuid,char* outbuff,int buffsize);

/*
��ѯ״̬

����ֵ:
1:		����������ӣ�״̬����
0:		δ���ӷ�����
-1:		SDKδ��ʼ��
-2:		��Կ��Ч
*/
int		t2u2_status();

/*
�˳����ͷ���Դ
*/
void		t2u2_exit();

#ifdef __cplusplus
}
#endif

#endif


