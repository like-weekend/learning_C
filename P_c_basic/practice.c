#include<stdio.h>
#include<string.h>

#define N 10

char arr[N] = {0}; //用于记录当前屏幕上的字符
char copy_board[N] = {0}; //用于记录剪切板字符
char choose_board[N] = {0};//用于记录选择板字符
int choose_flag = 0;

int func_c()
{
    /*
    1. 先清空剪切板
    2. 将选择字符存入剪切板
    3. 不清空选择标志
    */
    if(choose_flag == 0) return 0;
    memset(copy_board, 0, N*sizeof(char));
    for(int i = 0; choose_board[i] != 0; i++) 
        copy_board[i] = choose_board[i];
    return 0;
}

int func_x()
{
    /*
    1. 先清空剪切板
    2. 将选择字符存入剪切板
    3. 清空选择标志，屏幕前字符和选择伴
    */
    if(choose_flag == 0) return 0;
    memset(copy_board, 0, N*sizeof(char));
    for(int i = 0; choose_board[i] != 0; i++) 
        copy_board[i] = choose_board[i];
    choose_flag = 0;
    memset(arr, 0, N*sizeof(char));
    memset(choose_board, 0, N*sizeof(char));
    return 0;
}

void func_v()
{
    int i = 0;
    if(choose_flag == 0)
    {
        while(1)
        {
            if(arr[i] == 0) 
            {
                for(int j = 0; copy_board[j] != 0; j++) 
                    arr[i++] = copy_board[j];
                break;
            }
            i++;
        }
    }
    else
    {
        memset(arr, 0, N*sizeof(char));
        for(int i = 0; copy_board[i] != 0; i++) 
            arr[i] = copy_board[i];
        choose_flag = 0;
        memset(choose_board, 0, N*sizeof(char));
    }
    
}

void func_a()
{
    choose_flag = 0;
    memset(choose_board, 0, N*sizeof(char));
    for(int i = 0; arr[i] != 0; i++)
    {
        choose_board[i] = arr[i];
        choose_flag = 1;
    }
}


int main()
{
    int act;
    int j = 0 ;
    while(scanf("%d", &act) != EOF )
    {
        if(act != 1)
        {
            switch (act)
            {
                case 2:
                    func_c();   //复制
                    break;
                case 3:
                    func_x();   //剪切
                    break;
                case 4:
                    func_v();   //粘贴
                    break;
                case 5:
                    func_a();   //全选
                    break;
            }
        }
        else 
        {
            //act = 1,屏幕多加一个a
            if(choose_flag == 1)
            {
                memset(arr, 0, N*sizeof(char));
                memset(choose_board, 0, N*sizeof(char));
                choose_flag = 0;
            }
             
            j = 0;
            while(1)
            {
                if(arr[j] == 0) 
                {
                    arr[j] = 'a';
                    break;
                }
                j++;
            }
        }
    }
    int num = 0;
    for(int i = 0; arr[i] != 0; i++)
    {
        num++;
    }
    printf("%d", num);
    return 0;
}