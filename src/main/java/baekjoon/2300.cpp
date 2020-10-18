#include <stdio.h>
 
int map[19][19];
int dir[4][2] = { {1,0},{1,1},{0,1},{-1,1} };
 
bool is_in_range(int y, int x) {
    return (y >= 0 && x >= 0 && y < 19 && x < 19);
}
 
int getMap(int y, int x) {
    if (y < 0 || x < 0 || y >= 19 || x >= 19)
        return 0;
    return map[y][x];
}
 
int main() {
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            scanf("%d", &map[i][j]);
 
    int ans_y = -1, ans_x = -1, ans_c = -1;
 
    for (int d = 0; d < 4; ++d) {
        for (int x = 0; x < 19; ++x) {
            for (int y = 0; y < 19; ++y) {
                if (map[y][x] == 0)
                    continue;
 
                if (getMap(y - dir[d][0], x - dir[d][1]) == map[y][x])
                    continue;
 
                int yy = y, xx = x, cnt = 0;
                while (1) {
                    yy += dir[d][0];
                    xx += dir[d][1];
 
                    if (!is_in_range(yy, xx))
                        break;
 
                    if (map[yy][xx] != map[y][x])
                        break;
 
                    cnt++;
                }
                if (cnt == 4) {
                    ans_y = y;
                    ans_x = x;
                    ans_c = map[y][x];
                }
            }
        }
    }
 
    if (ans_c == -1) {
        printf("0");
        return 0;
    }
 
    printf("%d\n%d %d", ans_c, ans_y + 1, ans_x + 1);
    return 0;
}
