K,N = map(int, raw_input().split())
L = []
for i in range(K):
    L.append(input())

left,right = 1,2147483647

while(left <= right):
    mid = (right + left) / 2
    cnt = 0
    for val in L:
        if(val >= mid and  N > cnt ):
            cnt += val/mid

    if(cnt >= N):
        left = mid + 1
    else:
        right = mid - 1

print left-1
