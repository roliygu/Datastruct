#! /usr/bin/env python
#coding=utf-8
def input():
    test_data_txt = open('D:\Git\Datastruct\\test.txt','r')
    test_data=test_data_txt.read()
    for i in 


for i in test_data:
    i=i.split(" ")
def zeros(n):
    i=0
    Q=[]
    while i<n:
        Q.append([x*0 for x in range(n)])
        i+=1
    return Q
    

def Create(n,ns):
    L=zeros(n+1)
    for i in ns:
        L[i[0]][i[1]]=i[2]
    return L