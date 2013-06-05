#include<iostream>
#include<fstream>
using namespace std;
#ifndef GRAPH
#define GRAPH
#define maxn 100
ifstream datastream("D:\\Git\\Datastruct\\test.txt",ios::in);
class EdgeNode
{
	public:
		EdgeNode():to(0),w(0),next(NULL){}
	//private:
		int to;
		int w;
		EdgeNode *next;
};
class VNode
{
	public:
		VNode():from(0),first(NULL){}
	//private:
		int from;
		EdgeNode *first;
};
VNode Graph_link[maxn];
int data[maxn][maxn];
int input()
{
	int n;
	datastream>>n;
	for(int i=0;i<n;i++)
		datastream>>data[i][0]>>data[i][1]>>data[i][2];
	datastream.close();
	return n;
}
void setup(int lenth)
{
	for(int i=0;i<lenth;i++)
	{
		EdgeNode *p=new EdgeNode();
		int x=data[i][0];
		p->to=data[i][1];
		p->w=data[i][2];
		p->next=Graph_link[x].first;
		Graph_link[x].first=p;
	}
}
void show(int n)
{
	for(int i=1;i<n;i++)
	{
		for(EdgeNode *k=Graph_link[i].first;k!=NULL;k=k->next)
			cout<<i<<" "<<k->to<<" "<<k->w<<endl;
	}
}
void BFS(int lenth,int start)
{
	int queue[lenth+5],color[lenth+5],d[lenth+5],pi[lenth+5],beg=0,end=0;
	for(int i=0;i<=lenth;i++)
	{
		color[i]=0;
		d[i]=lenth+1;
		pi[i]=-1;
	}
	color[start]=-1;
	d[start]=0;
	queue[end++]=start;
	while((end-beg)>0)
	{
		int u=queue[beg++];
		for(EdgeNode *k=Graph_link[u].first;k!=NULL;k=k->next)
		{
			int v=k->to;
			if(color[v]==0)
			{
				color[v]=-1;
				d[v]=d[u]+1;
				pi[v]=u;
				queue[end++]=v;
			}	
		}
		color[u]=1;
	}
}
void DFS_Visit(int u,int color[],int &time,int d[],int f[],int pi[])
{
	color[u]=-1;
	time++;
	d[u]=time;
	for(EdgeNode *k=Graph_link[u].first;k!=NULL;k=k->next)
	{
		int v=k->to;
		if(color[v]==0)
		{
			pi[v]=u;
			DFS_Visit(v,color,time,d,f,pi);
		}
	}
	color[u]=1;
	f[u]=(++time);
}
void DFS(int lenth)
{
	int color[lenth+5],pi[lenth+5],d[lenth+5],f[lenth+5];
	for(int i=0;i<=lenth;i++)
	{
		color[i]=0;
		pi[i]=-1;
	}
	int time=0;
	for(int i=1;i<=lenth;i++)
	{
		if(color[i]==0)
			DFS_Visit(i,color,time,d,f,pi);
	}
	for(int i=1;i<=lenth;i++)
	{
		cout<<f[i]<<" "<<d[i]<<endl; 
	}
}
#endif
////////////////////////////////////////////////////////////////////////////////
/*    setup()��Ҫ�ر�ע�⣨data�� graph����������±꣩                       */ 
/*    show()�ڶ���forѭ������Ҫ�ر�ע�� ���߽� �͵������� ��                  */
/*    ͼ���ڽӱ�Ĺ�����̣�                                                  */
/*        1.���ĵ��ж��ߵ����ݵ� data���飬�ĵ���һ�� n��ʾ�� n���ߣ�������   */
/*          ÿ�е�һ������ʼ���ţ��ڶ�������ֹ���� ����������Ȩֵ��       */
/*		  2.�� data����ת���ڽӱ�ʹ�� setup()������                         */
/*    ͼ�Ĺ�����ȱ�����                                                      */ 
/*        ������ BFS������д�ĺ���ԭ����û�з���ֵ�ģ����ǿ��Ը�����Ҫ���أ�  */
/*        �����Ĳ��� lenth�ǽڵ�����start ��Դ�ڵ��ţ�                      */
/*        �����ڲ������� d�����������±�ڵ㵽Դ�ڵ�����·����              */ 
/*        ����pi��¼���Ƿ��ʶ�Ӧ�±�ڵ�ĸ����ڵ���                        */
/*        color�����¼���Ƕ�Ӧ�±�ڵ�ķ���״����0��ʾ��δ���ʣ�-1��ʾ����  */
/*        ���ʣ�����û�з�����ȫ���ӽڵ㣬1��ʾ�Ѿ�������ȫ���ӽڵ�           */
/*        ����queueΪ��ʱ���� 										          */ 
////////////////////////////////////////////////////////////////////////////////