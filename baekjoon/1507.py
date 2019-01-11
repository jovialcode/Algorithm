# -*- coding: utf8 -*-
import sys

N = input()
road = []
chk = []

for i in range(N):
    road.append(map(int,raw_input().split()))
    chk.append([True]*N)

#입력정리
for k in range(N):
    for i in range(N):
        for j in range(N):
            #더 작은 경우는 문제의 정의에 어긋남
            if (road[i][j] > (road[i][k] + road[k][j])):
                print '-1'
                sys.exit(0)

            if( i == j or j == k or i == k):
                 continue
            #동일한 노드 i,j 는 나감

            if(road[i][j] == (road[i][k] + road[k][j])):
                chk[i][j] = False

ans = 0
for i in range(N):
    j = i
    while(j<N):
        if(chk[i][j]):
            ans += road[i][j]
        j+=1

print ans
