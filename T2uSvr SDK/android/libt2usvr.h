/***************************************************************************
 *   Copyright (C) 2013 by Yexr   *
 *   yexr@vveye.com   *
 ***************************************************************************/
#ifndef _LIB_T2U_SVR_H_
#define _LIB_T2U_SVR_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*
��ʼ��������P2P����
svraddr		��������ַ������
svrport		�������˿�
svrkey		��������Կ
uuid			����UUID
threadnum	�߳���

����ֵ:
0			�ɹ�
-1			ʧ��
*/
int	t2u_svr_init(const char* svraddr,unsigned short svrport,const char* svrkey,const char* uuid,int threadnum);


/*
��������
(������������룬�ͻ��˱���ƾ��ȷ��������ܽ���P2Pͨ��)

passwd		�����ַ���

����ֵ:
0			�ɹ�
-1			ʧ��
*/
int	t2u_svr_set_passwd(const char* passwd);


/*
�����Զ��帽�Ӳ���

param		�Զ�����������豸�ͺţ�ͨ����Ϣ��UPNP�˿�״̬��
len			�������ȣ���󲻳���1024�ֽ�

����ֵ:
0:			�ɹ�
-1:			ʧ��

*/
int	t2u_svr_set_param(const char* param,int len);


/*
����P2P�˿ڷ�Χ

min_port:			��С�˿ں�
max_port:			���˿ں�
*/
void t2u_svr_set_port_range(unsigned short min_port,unsigned short max_port);

/*
�������P2Pͨ����(����TCP������)

num:		1-100

����ֵ:
0:				�ɹ�
-1:				ʧ��
*/
int	t2u_svr_set_maxconn(unsigned short num);

/*
�޶�Ŀ��˿�
port:		0:   ���޶�
			>0: �޶�Ŀ��˿�

����ֵ:
0:				�ɹ�
-1:				ʧ��
*/
int	t2u_svr_set_destport(unsigned short port);

/*
�ر�P2P����
*/
void	t2u_svr_exit();

/*
��ѯ״̬

����ֵ:
1:		��ע�ᵽ��������״̬����
0:		��δע�ᵽ������
-1:		SDKδ��ʼ��
-2:		��������Կ��Ч
-3:		��UUID������ע��
*/
int	t2u_svr_status();

/*
��ѯP2P����

outbuff			���ս���Ļ����ַ
				(�������Ϊ�ַ�����ÿ��һ�����ӣ���ʽΪ: ip:port|������|�������д���)
buffsize			���ս���Ļ����С


����ֵ:

int	��ǰP2P������

*/
int	t2u_svr_conn_stats(char* outbuff,int buffsize);


/*
��ѯ��ǰTCP�ͻ�������
outbuff			���ս���Ļ����ַ(�������Ϊ�ַ�����ÿ��һ������)
buffsize			���ս���Ļ����С

����ֵ
int		��ǰTCP������
*/
int	t2u_svr_dump_client(char* outbuff,int buffsize);

#ifdef __cplusplus
}
#endif

#endif


