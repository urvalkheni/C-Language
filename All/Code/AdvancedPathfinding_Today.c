#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXR 50
#define MAXC 50

int R,C;
int grid[MAXR][MAXC];
int dr[4]={-1,1,0,0}; int dc[4]={0,0,-1,1};

typedef struct Node{int r,c; int dist;} Node;

int valid(int r,int c){ return r>=0 && r<R && c>=0 && c<C && grid[r][c]==0; }

/* BFS shortest path on unweighted grid */
int bfs(int sr,int sc,int tr,int tc){ int vis[MAXR][MAXC]={0}; Node q[2500]; int qs=0, qe=0; q[qe++] = (Node){sr,sc,0}; vis[sr][sc]=1; while(qs<qe){ Node cur=q[qs++]; if(cur.r==tr && cur.c==tc) return cur.dist; for(int k=0;k<4;k++){ int nr=cur.r+dr[k], nc=cur.c+dc[k]; if(valid(nr,nc) && !vis[nr][nc]){ vis[nr][nc]=1; q[qe++] = (Node){nr,nc,cur.dist+1}; } } } return -1; }

int main(){ printf("Enter R C (<=50):"); if(scanf("%d %d", &R,&C)!=2) return 0; printf("Enter grid (0 free,1 obstacle) rows of %d values:\n", C); for(int i=0;i<R;i++) for(int j=0;j<C;j++) scanf("%d", &grid[i][j]); int sr,sc,tr,tc; printf("start r c: "); scanf("%d %d", &sr,&sc); printf("target r c: "); scanf("%d %d", &tr,&tc); int d = bfs(sr,sc,tr,tc); if(d==-1) printf("No path\n"); else printf("Shortest steps: %d\n", d); return 0; }
