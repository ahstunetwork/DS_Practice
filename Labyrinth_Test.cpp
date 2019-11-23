#include<iostream>
#include<windows.h>
using namespace std;
#define LENGTH 10
#define WIDTH 10
#define BEGIN_X 1
#define BEGIN_Y 1
#define END_X 8
#define END_Y 8

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   bulid a data model
class Node      
{
    public:
        Node()
        {
            status = 0;         //
        }
        //Node(int i, int j, int m = 0 ) : x{i}, y{j}, status{m} {}
        int x;                  // x position
        int y;                  // y position
        int status;             // status, 0 indicate the pass
        int dire;               // direction
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//   bulid stack
typedef struct stack
{
    Node data[100];
    int data_p;
}Stack;

void Initial_Stack(Stack *&S)
{
    S = new Stack;
    S->data_p = -1;
}

void Push_Stack( Stack *&S, int x, int y, Node Map[][WIDTH] )
{
    Map[x][y].status = 1;
    if( S->data_p != 100 )
    {
        S->data_p = S->data_p + 1;
        S->data[S->data_p].x = x;
        S->data[S->data_p].y = y;
        S->data[S->data_p].status = 1;
    }
}

void delete_stack( Stack *&S )
{
    //Map[S->data[S->data_p].x][S->data[S->data_p].y].status = 0;     //set postion status to 0
    S->data_p = S->data_p - 1;
}

bool Find_position(Stack *S, Node Map[][WIDTH])
{
    int x = S->data[S->data_p].x;
    int y = S->data[S->data_p].y;
    if( Map[x-1][y].status == 0 )     //if left is passage, use Push_Stack() function
    {
        Push_Stack(S, x-1, y, Map );
        return true;
    }
    if( Map[x][y-1].status == 0 )     //if up is passage, use Push_Stack() function
    {
        Push_Stack(S, x, y-1, Map );
        return true;
    }
    if( Map[x+1][y].status == 0 )     //if right is passage, use Push_Stack() function
    {
        Push_Stack(S, x+1, y, Map );
        return true;
    }
    if( Map[x][y+1].status == 0 )     //if down is passage, use Push_Stack() function
    {
        Push_Stack(S, x, y+1, Map );
        return true;
    }

    delete_stack( S );    //Have no result after four judgement, pop stack once
    return false;
}

void Display_Labyrinth(Node Map[][WIDTH])
{
    cout << "The shape of the labyrinth is : " << endl;
    for(int i = 0; i < LENGTH; i++)    //row
    {
        for(int j = 0; j < WIDTH; j++)    //column
        {
            cout << Map[j][i].status <<" ";
        }
        cout << endl;
    }
}





void Display_Stack(Stack *S)
{
    for( int i = 0; i <= S->data_p; i++ )
    {
        cout << "The no." << i << " data in stack is : ( x = " << S->data[i].x
                                << ", y = " << S->data[i].y << ", status = " << S->data[i].status <<" )" << endl;
    }
}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    system("cls");
    Stack *S;
    Initial_Stack(S);

    bool FIND_RESULT_FLAG = false;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //    build a map
    Node map[LENGTH][WIDTH];
    for( int i = 0; i < WIDTH; i++ )    //fill this border
    {
        map[i][0].status = 1;  // top line
        map[i][WIDTH - 1].status = 1;  // bottom line
        map[0][i].status = 1;  // left line
        map[LENGTH - 1][i].status = 1;  // right line
    }
    {     //fill the detail
        map[4][1].status = 1;
        map[2][2].status = 1;
        map[4][3].status = 1;
        map[1][4].status = 1;
        map[3][3].status = 1;
        map[1][3].status = 1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////
    //      begin position and end position
    Push_Stack(S, BEGIN_X, BEGIN_Y, map);     // begin
    map[END_X][END_Y].status = 0;         // end
    //////////////////////////////////////////////////////////////////////////////////////////////////
    Display_Labyrinth(map);
    // while(S->data_p != -1 )
    // {
    //     Find_position( S, map );
    // }
    //for(int i = 0; i < 14; i++)
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // use function to find the passage
    while( S->data_p != -1 )
    {
        bool find_result = Find_position( S, map );
        system("cls");
        Display_Labyrinth(map);
        Sleep(1000);
        if( S->data[S->data_p].x == END_X && S->data[S->data_p].y == END_Y)
        {
            FIND_RESULT_FLAG = true;
            break;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    if( FIND_RESULT_FLAG )
    {
        cout << "Find passage successful !"<< endl;
        Display_Stack(S);
    }
    else
    {
        cout << "Find passage failure !" << endl;
    }
    
    



    
    //Display_Stack(S);

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // for( int i = 0; i < 10; i++ )
    // {
    //     Push_Stack(S, i);
    // }
    // cout << "There have " << S->data_p << " number(s) in the stack " << endl;
    // for( int i = 0; i < 20; i++ )
    // {
    //     cout << "The no. " << i <<" data is : " << Pop_stack(S) << endl;
    // }

    system("pause");
    return 0;
}