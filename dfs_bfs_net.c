DFS BFS
#include<stdio.h>

#define N 20
#define TRUE 1
#define FALSE 0

int visited[N];        /*���ʱ�־����*/

typedef struct     /*���еĶ���*/
{
    int data[N];
    int front,rear;
}queue;

typedef struct      /*ͼ���ڽӾ���*/
{
    int vexnum,arcnum;
    char vexs[N];
    int arcs[N][N];
}
graph;

void createGraph(graph *g);      /*����һ������ͼ���ڽӾ���*/
void dfs(int i,graph *g);          /*�ӵ�i��������������������*/
void tdfs(graph *g);             /*���������������ͼ*/
void bfs(int k,graph *g);          /*�ӵ�k����������������*/
void tbfs(graph *g);             /*���������������ͼ*/
void init_visit();               /*��ʼ�����ʱ�ʶ����*/

/*����һ������ͼ���ڽӾ���*/
void createGraph(graph *g)
{
    int i,j;
    char v;
    g->vexnum=0;
    g->arcnum=0;
    i=0;
    printf("\n���붥������(��#����)��\n");
    while ((v=getchar())!='#')
    {
        g->vexs[i]=v;            /*���붥����Ϣ*/
        i++;
    }
    g->vexnum=i;             /*������Ŀ*/

    for (i=0;i<g->vexnum;i++)     /*�ڽӾ����ʼ��*/
        for (j=0;j<g->vexnum;j++)
            g->arcs[i][j] = 0;/*��1��-�ڽӾ���Ԫ�س�ʼ��Ϊ0*/

    printf("\n����ߵ���Ϣ(�������,�������)����(-1,-1)������\n");
    scanf("%d,%d",&i,&j);      /*�����(i,j)*/
    while (i!=-1)                 /*����iΪ��1ʱ����*/
    {
        g->arcs[i][j] = 1;    /*��2��-i,j��Ӧ�ߵ���1*/
        g->arcnum++;
        scanf("%d,%d",&i,&j);
    }
}/* createGraph */


/*��3��---�ӵ�i�������������������������������㷨*/
void dfs(int i,graph *g)
{
    int j;
    printf("%c", g->vexs[i]);
    visited[i] = TRUE;
    for (j = 0; j < g->vexnum; j++)
        if (g->arcs[i][j] == 1 && !visited[j])
            dfs(j, g);
}/* dfs */

/*���������������ͼ*/
void tdfs(graph *g)
{
    int i;
    printf("\n�Ӷ���%C��ʼ��������������У�",g->vexs[0]);
    for (i=0;i<g->vexnum;i++)
        if (visited[i] != TRUE)   /*��4��---����δ���ʹ��Ķ�����������������*/
            dfs(i,g);
    printf("\n");
}/*tdfs*/



/*�ӵ�k����������������*/
void bfs(int k,graph *g)
{
    int i,j;

    queue qlist,*q;
    q=&qlist;
    q->rear=0;
    q->front=0;

    printf("%c",g->vexs[k]);                   // �����k
    visited[k]=TRUE;
    q->data[q->rear]=k;
    q->rear=(q->rear+1)%N;

    while (q->rear!=q->front)                  /*�����в�Ϊ�գ���������*/
    {
        i=q->data[q->front];
        q->front=(q->front+1)%N;               // ������ Ԫ��ֵΪ i

        for (j=0;j<g->vexnum;j++)
            if ((g->arcs[i][j]==1)&&(!visited[j]))
            {
                printf("%c",g->vexs[j]);              
                visited[j]=TRUE;
                q->data[q->rear] = j;            /*��5��---�շ��ʹ��Ľ�����*/
                q->rear = (q->rear + 1) % N;     /*��6��---�޸Ķ�βָ��*/
            }
    }
}/*bfs*/

/*���������������ͼ*/
void tbfs(graph *g)
{
    int i;
    printf("\n�Ӷ���%C��ʼ��������������У�",g->vexs[0]);
    for (i=0;i<g->vexnum;i++)
        if (visited[i]!=TRUE)
            bfs(i,g);                        /*�Ӷ���i��ʼ�����������*/
    printf("\n");
}/*tbfs*/


void init_visit()  /*��ʼ�����ʱ�ʶ����*/
{
    int i;
    for (i=0;i<N;i++)
        visited[i]=FALSE;
}

int main()
{
    graph ga;
    int i,j;
    printf("***********ͼ�ڽӾ���洢��ͼ�ı���***********\n");
    printf("\n1-����ͼ�Ļ�����Ϣ��\n");

//1
    createGraph(&ga);

    printf("\n2-����ͼ���ڽӾ���\n");
    for (i=0;i<ga.vexnum;i++)
    {
        for (j=0;j<ga.vexnum;j++)
            printf("%3d",ga.arcs[i][j]);
        printf("\n");
    }
    printf("\n3-ͼ�ı�����\n");

//2
    init_visit(); /*��ʼ����������*/
    tdfs(&ga);    /*�����������ͼ*/

    init_visit();
    tbfs(&ga);    /*�����������ͼ*/

    return 0;
}