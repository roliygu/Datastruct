#include<iostream>
using namespace std;
#ifndef HASHTABLE
#define HASHTABLE
#include<fstream>
#define maxn 1000
ifstream Hash_datastream("D:\\Git\\Datastruct\\Hash_test.txt",ios::in);
int Hash_data[maxn],prime_number[maxn+100],prime_total=0;
bool prime_is(int k)
{
	for(int i=0;i<prime_total;i++)
		if(k%prime_number[i]==0)
			return false;
	return true;
}
void prime_create(int n)
{
	for(int i=2;i<=n;i++)
		if(prime_is(i))
			prime_number[prime_total++]=i;
	prime_number[prime_total]=n+1;
}
int setup()
{
	int i=0;
	while(!Hash_datastream.eof())
		Hash_datastream>>Hash_data[i++];
	prime_create(i-1);
	return i-1;
}
class Node
{
	public:
		Node():data(0),next(NULL){}
	//private:
		int data;
		Node *next;
};
class Hash_table
{
	public:
		Hash_table():lenth(0){}
		void len(int number);
		void insert(int key);
		int div_tranlate(int key);
		bool have_key(int ex_key);
		void show();
	//private:
		Node Hash[maxn];
		int lenth;
};
bool Hash_table::have_key(int ex_key)
{
	int t=0;
	int ex_afterkey=div_tranlate(ex_key);
	for(Node *k=Hash[ex_afterkey].next;k!=NULL;k=(k->next))
		if(k->data==ex_key)
		{
			t=1;
			break;
		}
	return t;
}
void Hash_table::len(int number)
{
	number/=3;
	int L=0;
	for(int i=1;(i++)&&(L<number);i++)
		L=prime_number[i];
	this->lenth=L;
}
int Hash_table::div_tranlate(int key)
{
	return key%(this->lenth);
}
void Hash_table::insert(int key)
{
	int after_key=div_tranlate(key);
	Node *p=new Node();
	p->data=key;
	p->next=Hash[after_key].next;
	Hash[after_key].next=p;
}
void Hash_table::show()
{
	for(int i=0;i<lenth;i++)
	{
		cout<<i<<" ";
		for(Node *k=Hash[i].next;k!=NULL;k=(k->next))
			cout<<k->data<<" ";
		cout<<endl;
	}
}
#endif
////////////////////////////////////////////////////////////////////////////////
/*    ���ļ���Ҫע����ǣ����� insert֮ǰ��Ҫ�ȵ���setup��������ȡ���� , ��   */
/*    ���صĲ�������Ҳ���õ����� ���磬�����������ǵ��� Hashtable����� len   */
/*    ���ϲ�����׼������������Ҫע����� �������������� setup �����Ҳ����  */
/*    ˵�����������setup���ĵ��������ݣ������Լ���ȡ���ݵĻ���һ��Ҫע�⽫   */
/*    primer_number����ˢ���ˣ����� 										  */
/*    ����˵����															  */
/*			��ϣ�������õĳ�����ϣ����������Ҳûʲô˵���ġ�                  */ 
////////////////////////////////////////////////////////////////////////////////