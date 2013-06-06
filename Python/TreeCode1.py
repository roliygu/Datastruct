#! /usr/bin/env python
#coding=utf-8
class Node:
    def creat(self,value):
        self.data=value
        self.left=Node()
        self.left.data=None
        self.right=Node()
        self.right.data=None
        
pro="ABDGLHEICFJK"                                                            
mid="GLDHBEIACJFK"
low1=0
low2=0
high1=11
high2=11
P=Node()
def proAndmid(low1,high1,low2,high2,pro,mid,P):                                #根据先序和中序生成树
    if high1<low1:
        return 0
    P.creat(pro[low1])
    i= mid.find(pro[low1])
    if i != low2 :
        proAndmid(low1+1,low1+i-low2,low2,i-1,pro,mid,P.left)  
    if i!= high2:
        proAndmid(low1+i-low2+1,high1,i+1,high2,pro,mid,P.right)

proAndmid(0,11,0,11,pro,mid,P)

def Pro(P):                                                                    #先序遍历
    if P.data is None:
        return 0
    print(P.data)
    Pro(P.left)
    Pro(P.right)
    
def Count(P):
    if P.data is None:
        return 0
    else:
        return Count(P.left)+Count(P.right)+1

def G(P):                                                                      #广度遍历
    t=Count(P)-1                                                               #i是计数器，当i等于Count-1，就说明结点都入队列了
    i=0                                                                        #当某节点的右儿子进队列之后，j才加1，额，也许下次看到此代码不明白怎么回事，就画一个队列模拟一下
    j=0
    L=[P]
    while i!=t:
        K=L[j]
        if K.left.data is not None:
            L.append(K.left)
            i+=1
        if K.right.data is not None:
            L.append(K.right)
            i+=1
            j+=1
        else:
            j+=1
    return L

'''for i in L:
    print i.data'''