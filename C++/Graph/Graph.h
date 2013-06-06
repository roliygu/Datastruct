#include<iostream>
#include<fstream>
using namespace std;
#ifndef GRAPH
#define GRAPH
#define maxn 100
ifstream datastream("D:\\Git\\Datastruct\\Graph_test.txt",ios::in);
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
void DFS_Visit(int u,int color[],int &time,int d[],int f[],int pi[],int id[])
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
			id[v]=id[u];
			DFS_Visit(v,color,time,d,f,pi,id);
		}
	}
	color[u]=1;
	f[u]=(++time);
}
void DFS(int lenth)
{
	int color[lenth+5],pi[lenth+5],d[lenth+5],f[lenth+5],id[lenth+5];
	for(int i=0;i<=lenth;i++)
	{
		color[i]=0;
		pi[i]=-1;
		id[i]=i;
	}
	int time=0;
	for(int i=1;i<=lenth;i++)
	{
		if(color[i]==0)
			DFS_Visit(i,color,time,d,f,pi,id);
	}
	for(int i=1;i<=7;i++)
	cout<<id[i]<<" "; 
}
#endif
////////////////////////////////////////////////////////////////////////////////
/*    setup()需要特别注意（data和 graph两个数组的下标）                       */ 
/*    show()第二层for循环的需要特别注意 （边界 和递增条件 ）                  */
/*    图的邻接表的构造过程：                                                  */
/*        1.从文档中读边的数据到 data数组，文档第一行 n表示有 n条边，接下来   */
/*          每行第一个是起始点标号，第二个是终止点标号 ，第三个是权值；       */
/*		  2.把 data数组转成邻接表，使用 setup()函数；                         */
/*    图的广度优先遍历：                                                      */ 
/*        函数是 BFS，这里写的函数原型是没有返回值的，但是可以根据需要返回；  */
/*        函数的参数 lenth是边数，start 是源节点标号；                        */
/*        函数内部有数组 d，用来保存下标节点到源节点的最短路径，              */ 
/*        数组pi记录的是访问对应下标节点的父辈节点标号                        */
/*        color数组记录的是对应下标节点的访问状况，0表示还未访问，-1表示正在  */
/*        访问，但是没有访问完全部子节点，1表示已经访问完全部子节点           */
/*        队列queue为临时变量 												  */ 
/*    图的深度优先遍历：													  */
/*		  函数是 DFS和 DFS_VISIT											  */
/*        需要注意的是 d，f两个数组和变量 time								  */
/*        time纪录的是访问时间点，顶点 u 在 d[u]之前是白色，d[u]和 f[u]之间   */ 
/*        是灰色，f[u]之后是黑色； 	 										  */
/*        新加了一个 id数组，id数组值相同表示连通，注意，连通性只针对无向图   */
/*        这点一定要注意！！！ id数组也只在无向图条件下才有意义！！！         */ 
/*    还有一个重要，需要注意的，这里是用边数来代替节点数，也就是说，当一个    */
/*    图有很多节点但是边很少的时候会出现一些 Bug。这里忽视这一点的原因是读数  */
/*    据就是按边来读的，这样的数据信息不会给出单点的情况                      */ 
////////////////////////////////////////////////////////////////////////////////