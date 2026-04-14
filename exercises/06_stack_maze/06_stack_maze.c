#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};
int visit[MAX_ROW][MAX_COL]={0};
int path[MAX_ROW*MAX_COL*2];
int done=0;
void dfs(int layer,int cur_col, int cur_row,int cur_path[MAX_ROW*MAX_COL*2])
{
	if(done)
	return;
	if(cur_col<0 || cur_col>=MAX_COL || cur_row<0 || cur_row>=MAX_ROW)
	return;
	if(maze[cur_row][cur_col]==1 || visit[cur_row][cur_col]==1)
	return;

	visit[cur_row][cur_col]=1;

	path[layer*2]=cur_row;
	path[layer*2+1]=cur_col;

	if(cur_col==MAX_COL-1 && cur_row==MAX_ROW-1)
	{
		done=1;
		
		
		for(int i=layer;i>0;i--)
		{
			printf("(%d, %d)→\n",path[i*2],path[i*2+1]);
		}
		printf("(0, 0)");
		printf("\n");
		return;
	}
	dfs(layer+1,cur_col-1,cur_row,cur_path);
	dfs(layer+1,cur_col,cur_row-1,cur_path);
	dfs(layer+1,cur_col+1,cur_row,cur_path);
	dfs(layer+1,cur_col,cur_row+1,cur_path);
	visit[cur_row][cur_col]=0;
	
}
int main(void)
{
	// TODO: 在这里添加你的代码
    
	// (0, 0) (4, 4)
	for(int i=0;i<MAX_ROW*MAX_COL*2;i++)
	path[i]=-1;
	dfs(0,0,0,path);
	return 0;
}