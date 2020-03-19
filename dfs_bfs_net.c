DFS BFS
#include<stdio.h>

#define N 20
#define TRUE 1
#define FALSE 0

int visited[N];        /*访问标志数组*/

typedef struct     /*队列的定义*/
{
    int data[N];
    int front,rear;
}queue;

typedef struct      /*图的邻接矩阵*/
{
    int vexnum,arcnum;
    char vexs[N];
    int arcs[N][N];
}
graph;

void createGraph(graph *g);      /*建立一个无向图的邻接矩阵*/
void dfs(int i,graph *g);          /*从第i个顶点出发深度优先搜索*/
void tdfs(graph *g);             /*深度优先搜索整个图*/
void bfs(int k,graph *g);          /*从第k个顶点广度优先搜索*/
void tbfs(graph *g);             /*广度优先搜索整个图*/
void init_visit();               /*初始化访问标识数组*/

/*建立一个无向图的邻接矩阵*/
void createGraph(graph *g)
{
    int i,j;
    char v;
    g->vexnum=0;
    g->arcnum=0;
    i=0;
    printf("\n输入顶点序列(以#结束)：\n");
    while ((v=getchar())!='#')
    {
        g->vexs[i]=v;            /*读入顶点信息*/
        i++;
    }
    g->vexnum=i;             /*顶点数目*/

    for (i=0;i<g->vexnum;i++)     /*邻接矩阵初始化*/
        for (j=0;j<g->vexnum;j++)
            g->arcs[i][j] = 0;/*（1）-邻接矩阵元素初始化为0*/

    printf("\n输入边的信息(顶点序号,顶点序号)，以(-1,-1)结束：\n");
    scanf("%d,%d",&i,&j);      /*读入边(i,j)*/
    while (i!=-1)                 /*读入i为－1时结束*/
    {
        g->arcs[i][j] = 1;    /*（2）-i,j对应边等于1*/
        g->arcnum++;
        scanf("%d,%d",&i,&j);
    }
}/* createGraph */


/*（3）---从第i个顶点出发深度优先搜索，补充完整算法*/
void dfs(int i,graph *g)
{
    int j;
    printf("%c", g->vexs[i]);
    visited[i] = TRUE;
    for (j = 0; j < g->vexnum; j++)
        if (g->arcs[i][j] == 1 && !visited[j])
            dfs(j, g);
}/* dfs */

/*深度优先搜索整个图*/
void tdfs(graph *g)
{
    int i;
    printf("\n从顶点%C开始深度优先搜索序列：",g->vexs[0]);
    for (i=0;i<g->vexnum;i++)
        if (visited[i] != TRUE)   /*（4）---对尚未访问过的顶点进行深度优先搜索*/
            dfs(i,g);
    printf("\n");
}/*tdfs*/



/*从第k个顶点广度优先搜索*/
void bfs(int k,graph *g)
{
    int i,j;

    queue qlist,*q;
    q=&qlist;
    q->rear=0;
    q->front=0;

    printf("%c",g->vexs[k]);                   // 入队列k
    visited[k]=TRUE;
    q->data[q->rear]=k;
    q->rear=(q->rear+1)%N;

    while (q->rear!=q->front)                  /*当队列不为空，进行搜索*/
    {
        i=q->data[q->front];
        q->front=(q->front+1)%N;               // 出队列 元素值为 i

        for (j=0;j<g->vexnum;j++)
            if ((g->arcs[i][j]==1)&&(!visited[j]))
            {
                printf("%c",g->vexs[j]);              
                visited[j]=TRUE;
                q->data[q->rear] = j;            /*（5）---刚访问过的结点入队*/
                q->rear = (q->rear + 1) % N;     /*（6）---修改队尾指针*/
            }
    }
}/*bfs*/

/*广度优先搜索整个图*/
void tbfs(graph *g)
{
    int i;
    printf("\n从顶点%C开始广度优先搜索序列：",g->vexs[0]);
    for (i=0;i<g->vexnum;i++)
        if (visited[i]!=TRUE)
            bfs(i,g);                        /*从顶点i开始广度优先搜索*/
    printf("\n");
}/*tbfs*/


void init_visit()  /*初始化访问标识数组*/
{
    int i;
    for (i=0;i<N;i++)
        visited[i]=FALSE;
}

int main()
{
    graph ga;
    int i,j;
    printf("***********图邻接矩阵存储和图的遍历***********\n");
    printf("\n1-输入图的基本信息：\n");

//1
    createGraph(&ga);

    printf("\n2-无向图的邻接矩阵：\n");
    for (i=0;i<ga.vexnum;i++)
    {
        for (j=0;j<ga.vexnum;j++)
            printf("%3d",ga.arcs[i][j]);
        printf("\n");
    }
    printf("\n3-图的遍历：\n");

//2
    init_visit(); /*初始化访问数组*/
    tdfs(&ga);    /*深度优先搜索图*/

    init_visit();
    tbfs(&ga);    /*广度优先搜索图*/

    return 0;
}