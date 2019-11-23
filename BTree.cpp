#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<cassert>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//create a node
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

//stack
typedef struct stack_node
{
    BTNode *p[100];
    int top;
}Stack;

//function
void Initial_Stack( Stack *&S )
{
    S = (Stack *)malloc(sizeof( Stack ));
    S->top = -1;
}

void Push_Stack( Stack *&S, BTNode *pt )
{
    if( S->top != 99 )
    {
        S->top++;
        S->p[S->top] = pt;
    }
}

bool Pop_Stack( Stack *&S )
{
    if( S->top != -1 )
    {
        //BTNode c = S->p[S->top];
        S->top--;
        return true;
    }
}

void Display_Stack( Stack *S )
{
    while( S->top != -1 )
    {
        cout << S->p[S->top]->data << "   " << endl;
        S->top--;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


//function
void CreateBtree( BTNode *&B, Stack *&S, const char *str )
{
    BTNode *btn[100];
    int cnt = 0;
    int flag = 1;  //1 -> left, 2 -> right
    int str_status_flag = 1;
    for( int i = 0; str[i] != '\0'; i++)
    {
        if( !((str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97) || str[i] != ',' || str[i] != '(' || str[i] != ')') )
        {
            //cout << "The exp that you input is not a tree !" << endl;
            str_status_flag = 2;
            exit(1);
        }
        //return false;
    }
    //assert( (str_status_flag == 1) && "The exp that you input is not a tree !" );

    for( int i = 0; str[i] != '\0'; i++ )
    {
        if( str[i] == '(' )
        {
            Push_Stack( S, btn[cnt-1] );
            flag = 1;
        }
        if( str[i] == ')' )
        {
            Pop_Stack( S );
        }
        if( str[i] == ',' )
        {
            flag = 2;
        }
        if( (str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97) )
        {
            btn[cnt] = (BTNode *)malloc(sizeof(BTNode));    //allocation memory for every node
            btn[cnt]->data = str[i];     //write data
            btn[cnt]->lchild = nullptr;
            btn[cnt]->rchild = nullptr;
            if( i == 0 )
            {
                B = btn[cnt];
            }
            if( cnt != 0)
            {
                if( flag == 1)
                {
                    S->p[S->top]->lchild = btn[cnt];
                }
                if( flag == 2 )
                {
                    S->p[S->top]->rchild = btn[cnt];
                }
                 
            }
        
            cnt++;
        }
    }
    
}

void Display_BTree( BTNode *B )
{
    if( B != nullptr )
    {
        //cout << B->data;
        Display_BTree( B->lchild );
        cout << B->data;
        Display_BTree( B->rchild );
    }
}

void Display_Btree_as_tree( BTNode *B )
{
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack *S;
    BTNode *B;
    Initial_Stack( S );
    const char *p = "A(B(D(,G)),C(E,F))";
    //const char *p = "a(A(a(d(f";
    
    CreateBtree(B, S, p);
    
    Display_Stack( S );

    Display_BTree( B );

    cout << endl;
    system("pause");
    return 0;
}