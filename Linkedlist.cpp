#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;


int people_num = 0;


typedef struct employee
{
    int no;
    string name;
    int depno;
    int salary;

    struct employee *pnext;
}Emp;

void Initial_list( Emp *&L )
{   
    L = new Emp;
    L->pnext = nullptr;
}

void Create_List( Emp *& L )
{
    Emp *Root = L;
    fstream fs( "f1.dat", ios::in );

    string NO;
    string DEPNO;
    string NAME;
    string SALARY;

    while( !fs.eof() )
    {
        if( !fs )
        {
            cout << "Create() 打开文件错误 " << endl;
            return ;
        }
        else
        {
            Emp *node;
            node = new Emp;

            fs >> NO;
            fs >> NAME;
            fs >> DEPNO;
            fs >> SALARY;

            node->no = atoi( NO.c_str() );
            node->name =  NAME;
            node->depno = atoi( DEPNO.c_str() );
            node->salary = atoi( SALARY.c_str() );

            while( L->pnext != nullptr )
            {
                L = L->pnext;
            }
            L->pnext = node;
            node->pnext = nullptr;
            people_num++;

            //L  = Root;
        
        }
    }
    L = Root;
    fs.close();
    

}

void Add_List( Emp *& L, int no, string name, int depno, int salary )
{
    Emp *Root = L;
    Emp *node;
    node = new Emp;

    node->no = no;
    node->name = name;
    node->depno = depno;
    node->salary = salary;

    //fstream fs("f1.dat", ios::out );
    //fs << no << "\t" << name << "\t" << depno << "\t" << salary << endl;
    
    while( L->pnext != nullptr )
    {
        L = L->pnext;
    }
    L->pnext =  node;
    node->pnext = nullptr;
    people_num++;
    L = Root;
}

void Sort_no( Emp *& L )
{
        cout << "Sort in no :  " << endl;
    Emp *Root = L;
    //L = L->pnext;

    for( int i = 0; i < people_num; i++ )
    {
        //L = L->pnext;        
        while( L->pnext->pnext != nullptr )     //如果有下一个
        {
            if( L->pnext->no > L->pnext->pnext->no )   //当前和下一个的编号进行比较
            {
                Emp *pt_one;  //保存当前
                Emp *pt_two;  //保存下一个的后续
                pt_one = L->pnext;
                pt_two = L->pnext->pnext->pnext;

                L->pnext = L->pnext->pnext;
                L->pnext->pnext = pt_one;

                L->pnext->pnext->pnext = pt_two;  
            }
            L = L->pnext;
        }
        L = Root;     
    }
}

void Sort_depno( Emp *& L )
{
    Emp *Root = L;
    //L = L->pnext;

    for( int i = 0; i < people_num; i++ )
    {
        //L = L->pnext;        
        while( L->pnext->pnext != nullptr )     //如果有下一个
        {
            if( L->pnext->depno > L->pnext->pnext->depno )   //当前和下一个的编号进行比较
            {
                Emp *pt_one;  //保存当前
                Emp *pt_two;  //保存下一个的后续
                pt_one = L->pnext;
                pt_two = L->pnext->pnext->pnext;

                L->pnext = L->pnext->pnext;
                L->pnext->pnext = pt_one;

                L->pnext->pnext->pnext = pt_two;  
            }
            L = L->pnext;
        }
        L = Root;     
    }
}

void Sort_salary( Emp *& L )
{

    Emp *Root = L;
    //L = L->pnext;

    for( int i = 0; i < people_num; i++ )
    {
        //L = L->pnext;        
        while( L->pnext->pnext != nullptr )     //如果有下一个
        {
            if( L->pnext->salary > L->pnext->pnext->salary )   //当前和下一个的编号进行比较
            {
                Emp *pt_one;  //保存当前
                Emp *pt_two;  //保存下一个的后续
                pt_one = L->pnext;
                pt_two = L->pnext->pnext->pnext;

                L->pnext = L->pnext->pnext;
                L->pnext->pnext = pt_one;

                L->pnext->pnext->pnext = pt_two;  
            }
            L = L->pnext;
        }
        L = Root;     
    }
}

void Delete_no( Emp *& L, int no )
{
    Emp *Root = L;
    while( L->pnext != nullptr )
    {
        if( L->pnext->no == no )
        {
            L->pnext = L->pnext->pnext;
            people_num--;
        }
        L = L->pnext;
    }
    L = Root;
}

void Delete_file( Emp *& L )
{

}

void Storage_file( Emp * L )
{
    fstream fs("f1.dat", ios::out | ios::in );
    
    while( L->pnext != nullptr )
    {
        fs << L->pnext->no << "\t" << L->pnext->name << "\t" << L->pnext->depno << "\t" << L->pnext->salary << endl;
        L = L->pnext;
    }
    fs.close();

}

void Dispaly_List( Emp *L )
{
    int count = 0;
    if( L != nullptr )
    {
        L = L->pnext;
        while( L != nullptr )
        {
            cout << "第 " << count + 1 <<" 个员工 : " << "编号 " << L->no <<" 姓名 " << L->name << " 部门号 " << L->depno <<" 工资数 " << L->salary << endl;
            L = L->pnext;
            count++;
        }
    }
}


int main()
{
    Emp *L;

    Initial_list( L );
    //Create_List( L );

     Add_List( L, 2, "zhangsan", 15, 8000 );
     Add_List( L, 1, "zhangsan",13, 7000 );
     Add_List( L, 3, "zhangsan", 16, 5000 );
     Add_List( L, 5, "zhangsan", 12, 6000 );

    Dispaly_List( L );

    Sort_no( L );
    Dispaly_List( L );

    Sort_depno( L );
    cout << "Sort in depno : " << endl;
    Dispaly_List( L );

    Sort_salary( L );
    cout << "Sort in salary : " << endl;
    Dispaly_List( L );

    Delete_no( L, 4 );
    cout << "After delete, the ifo is : " << endl;
    Dispaly_List( L );

    Storage_file( L );

    
    fstream fs( "f1.dat", ios::out | ios::in );
    if( !fs )
    {
        cout << "main() 打开文件错误 " << endl;
    }
    fs.close();
    cout << endl;
    
    system("pause");
    return 0;

    //矿工 黑暗王子 蝙蝠 暗夜女巫 雪人 闪电法师 雪球 火球
}