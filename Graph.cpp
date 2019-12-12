#include<iostream>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<vector>
using namespace std;

#define INF 1000
#define MAX_V 15
#define MAX_Y 15
#define MAX_E 15

vector<int> vec[100];
vector<int> vec_two[100];
int path_count = 0;
int path_count_two = 0;

int have_flag[15];
int have_count = 0;


typedef struct Snode
{
    int index;
    int weight;
    struct Snode *pNext; //struct Snode *pNext = (struct Snode *) malloc(sizeof(struct Snode));
}SideNode;

typedef struct Hnode
{
    int ifo;
    SideNode *pHead;
}HeadNode;

typedef struct Hparray
{
    int V_count;
    int E_count;
    HeadNode *Hp_Array[MAX_V];
}HpArray;

void Initial_Graph( Hparray *& hparray, HeadNode *hnp[] )
{
    hparray = (HpArray *) malloc ( sizeof ( HpArray ) );
    //包含头节点数组的初始化
    //HeadNode * head_node = (HeadNode *) malloc (sizeof( HeadNode ));
    //头节点指针域全部赋上空指针
    //将指针数组赋上
    for(int i = 0; i < MAX_V; i++ )
    {
        hnp[i] = ( HeadNode* ) malloc ( sizeof( HeadNode ) );
        hparray->Hp_Array[i] = hnp[i];
    }
    for( int i = 0; i < MAX_V; i++ )
    {
        hparray->Hp_Array[i]->pHead = nullptr;
    }
}

void Create_Graph( Hparray *& hparray, int dgraph[MAX_V][MAX_Y], int n, int e )
{
    // for( int i = 0; i < 5; i++ )
    // {
    //     for(int j = 0; j < 5; j++ )
    //     {
    //         cout << dgraph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    SideNode *p_prior = nullptr;
    SideNode *p_head = nullptr;
    int create_flag = 0;
    for( int i = 0; i < n; i++ )
    {
        // HeadNode pl;
        // hparray->Hp_Array[1] = &pl;
        create_flag = 0;
        for( int j = 0; j < n; j++ )
        {
            if( dgraph[i][j] != 0 && dgraph[i][j] != INF )
            {
                create_flag++;
                //如果邻接矩阵的某个位置不是0也不是无穷大，这为这一个节点创建边节点
                SideNode *p = (SideNode *) malloc ( sizeof ( SideNode ));
                p->index = j;
                //p->pNext = nullptr;
                p->weight = dgraph[i][j];
                //然后将头节点数组里的头节点的数据域起名，指针域赋上
                hparray->Hp_Array[i]->ifo = i;
                // 尾插, 第一次创建
                // if( create_flag == 1 )
                // {
                //     //cout << i << " :" << endl;
                //     hparray->Hp_Array[i]->pHead = p;
                //     p_head = p;
                // }
                //cout << "debug : " << hparray->Hp_Array[i]->pHead->weight;
                // 让这个指针始终标识该边链表
                //p_head = hparray->Hp_Array[i]->pHead;
                // 后续
                // while( hparray->Hp_Array[i]->pHead->pNext != nullptr )
                // {
                //     //cout << "hellow rold"<<endl;
                //     hparray->Hp_Array[i]->pHead = hparray->Hp_Array[i]->pHead->pNext;
                // }
                //p_prior = p;
                //hparray->Hp_Array[i]->pHead->pNext = p; // 新节点
                
                p->pNext = hparray->Hp_Array[i]->pHead;
                hparray->Hp_Array[i]->pHead = p;
                
                //hparray->Hp_Array[i]->pHead = p_head; //重新标识边界点的首部
            }
        }
    }
    hparray->V_count = n;
    hparray->E_count = e;
}

// 深度优先遍历

 int visited[MAX_V] = { 0 };
 int visit_node[MAX_V] = { 0 };
void DFS( HpArray *& G, int v, int result, int k)
{   //k++;

    int w;
    //int i;
    SideNode *p;
     visited[v] = 1;
     visit_node[k] = v;
    k++;
    if( v == result  && k >= 0 )
    {
        cout << "第 " << path_count << " 条路径 : ";
        for( int i = 0; i < k; i++)
        {
            cout << visit_node[i] << " ";
            vec[path_count].push_back(visit_node[i]);
        }
        cout << endl;
        path_count++;
        //return ;
    }
    //cout << v << " ";
    

    p = G->Hp_Array[v]->pHead;
    while( p != nullptr )
    {
        if( visited[p->index] == 0 )
        {
            DFS( G, p->index, result, k );
        }
        p = p->pNext;
    }
    visited[v] = 0;
}

void D_DFS( HpArray *& G, int v, int result, int k )
{
    for( int i = 0; i < 15; i++ )
    {
        visited[i] = { 0 };
        visit_node[i] = { 0 };
    }


    DFS( G, v, result, k);

}

// 输出
void Display_Graph( Hparray * p )
{
    if( p->Hp_Array[0]->pHead == nullptr )
    {
        cout << "debug"<< endl;
    }
    else
    {
        cout << "else"<<endl;
    }
    cout << "ifo "<<" index[wight] -> "<<endl;
    //cout << "debug : " << p->V_count<<endl;
    for( int i = 0; i < p->V_count; i++ )
    {
        SideNode *p_head = p->Hp_Array[i]->pHead;
        
        if( p_head == nullptr ) //后判断为0，则每一个sidenode遍历完后肯定为nullptr
        {
            cout << "Array["<<i<<"] : -> ";
        }

        if( p_head != nullptr )
        {
            cout << "Array["<<i<<"] : ";
            while( p_head != nullptr )
            {
                cout << p_head->index<<"["<<p_head->weight<<"] -> ";
                p_head = p_head->pNext;
            }
            //cout << " / " << endl;
        }
        cout << " / " << endl;
    }
}

void Dijkstra( int map[][MAX_V], int v )
{
    
}

int main()
{
    HpArray *HPA;
    HeadNode *hnp[MAX_V];
    Initial_Graph( HPA, hnp );

    int data_map[15][15] = {
        { 0, 1, 1, 1, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
        { 1, 0, INF, INF, INF, INF, 1,INF,1,INF,INF,INF,INF,INF,INF},
        { 1, INF,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
        { 1, INF,INF,0,INF,INF,1,INF,INF,INF,INF,INF,INF,INF,INF},
        { 1, INF,INF,INF,0,INF,INF,1,INF,INF,INF,INF,INF,INF,INF},
        { INF, INF,INF,INF,INF,0,INF,INF,1,1,INF,INF,INF,INF,INF},
        { INF, 1,INF,INF,INF,INF,0,1,INF,1,INF,INF,INF,INF,INF},
        { INF, INF,INF,INF,1,INF,1,0,INF,INF,1,1,INF,INF,INF},
        { INF, 1,INF,INF,INF,1,INF,INF,0,INF,INF,INF,1,INF,INF},
        { INF, INF,INF,INF,INF,1,1,INF,INF,0,1,INF,1,INF,INF},
        { INF, INF,INF,INF,INF,INF,INF,1,INF,1,0,INF,INF,1,INF},
        { INF, INF,INF,INF,INF,INF,INF,1,INF,INF,INF,0,INF,1,INF},
        { INF, INF,INF,INF,INF,INF,INF,INF,1,1,INF,INF,0,INF,1},
        { INF, INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,INF,0,1},
        { INF, INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,0},
    };

    // for( int i = 0; i < MAX_V; i++ )
    // {
    //     for(int j = 0; j < MAX_V; j++ )
    //     {
    //         cout << setw(7) << setiosflags( ios::left ) << data_map[i][j]; 
    //     }
    //     cout << endl;
    // }

    // Create_Graph( HPA, data_map, MAX_V, MAX_E );

    // Display_Graph( HPA );

    //int node_begin, node_end;
    int node_not[15];
    //cout << "输入开始和结束顶点 : ";
    //cin >> node_begin >>  node_end;

    int must_count = 0;

    int first = 0;
    int result = 14;
    cout << "输入开始点和终点, 空格隔开 : ";
    cin >> first >> result;
    int must_pass[15];
    cout << "输入必经点, 空格隔开, 以 -1 表示结束 : ";
    int pass;
    cin >> pass;
    while( pass != -1 )
    {
        must_pass[must_count] = pass;
        must_count++;
        cin >> pass;
    }



    int count_this = 0;
    //cout <<"debug" <<must_count;
    cout << "输入必避点, 空格隔开, 以 -1 表示结束 : ";
    int i_this;
    cin >> i_this;
    while( i_this != -1 )
    {
        node_not[count_this] = i_this;
        count_this++;
        cin>>i_this;
    }


    for(int j = 0; j < count_this; j++)
    {
        cout << node_not[j]<<endl;
    }

    //for(int i = 0; i < 15; i++ )    //外层遍历15
    //{
        for(int j = 0; j < count_this; j++)   //内层检验该次是否擦除   每个必避点
        {
            //cout << node_not[j]<<endl;
            //if( i == node_not[j] );   //如果相等，则说明第 i 个点需要排除
            //{
                for(int k = 0; k < 15; k++ )
                {
                    data_map[node_not[j]][k] = INF;
                    data_map[k][node_not[j]] = INF;
                }
            //}
            data_map[node_not[j]][node_not[j]] = 0;
        }
    //}



    Initial_Graph(HPA, hnp );
    Create_Graph( HPA, data_map, 15, 15 );

    for( int i = 0; i < MAX_V; i++ )
    {
        for(int j = 0; j < MAX_V; j++ )
        {
            cout << setw(7) << setiosflags( ios::left ) << data_map[i][j]; 
        }
        cout << endl;
    }




    Display_Graph( HPA );

    // cout <<HPA->Hp_Array[0]->pHead->weight; 
    // if( HPA->Hp_Array[0]->pHead->pNext == nullptr )
    // {
    //     cout << "All right" << endl;
    // }

    cout << endl;
    cout << "The diaplay of DFS() is : ";
    //深度优先遍历求通路
    int count = 0;

    cout << "图的所有通路为 :  " <<endl;
    D_DFS( HPA, first, result, count );
    cout << endl; 

    cout << "其中符合条件的通路为 : ";

    //cout << path_count<< endl;

    //cout <<"vdvdvdfvdfv"<< vec[2][7]<<endl;
    for (int i = 0; i < path_count; i++ )   //循环所有的向量
    {
        have_count = 0;
        for( auto w : vec[i] )    //对于每一个向量
        {
            for( int j = 0; j < must_count; j++ )   //循环必经点,进行比对
            {
                if( w == must_pass[j] )
                {
                    have_count++;
                }
            }
        }

        if( have_count  == must_count )
        {
            vec_two[path_count_two] = vec[i];
            path_count_two++;
        }
        //cout << " path_count_two = " << path_count_two << endl;
    }
    cout << endl;
    if( path_count_two == 0 )
    {
        cout << "无通路!" << endl;
    }
    else
    {
        for( int i = 0; i < path_count_two; i++ )
        {
            cout << "第 " << i << " 条路径 : ";
            for( auto w : vec_two[i] )
            {
                cout << w << " ";
            }
            cout << endl;
        }   
    }
 
    system("pause");
    return 0;
}