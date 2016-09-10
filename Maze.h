#pragma once

#include"stack.h"
#define N 10
void InitMaze(int *m) //从文件中读取数据到数组Maze中
{
	FILE* fout = fopen("Maze.txt","r");
	for(int i = 0; i < N;i++)
	{
		for(int j = 0; j< N ;)
		{

			char value = fgetc(fout);
			if(value == 32|| value == 10)
				continue;
			m[i*N+j] =  value - '0';
			++j;
		}
	}
}

struct Pos  
{
	int _row;
	int _col;

};

bool CheckPos(int row,int col,Pos p,int *m)//只有当数据为0的时候才考虑上下左右
{
	if((p._row >= 0) &&(p._row < row)&&(p._col >= 0)&&(p._col < col)&&(m[p._row * N+ p._col]==0))
		return true;
	return false;
}

bool Through(int row,int col,Pos next)
{
	if((next._row == row)||(next._col == col))
		return true;
	return false;
}

bool GetPath(int row,int col,int* m,Stack<Pos>& s,Pos enter)
{
	s.Push (enter);
	m[enter._row * N+enter._col ] = 2;
	while(!s.Empty ())
	{
		Pos cur = s.Top ();//cur为最新压入栈中的数据,栈顶的元素就是迷宫目前能走的最后一步
		Pos next = cur;//为进行上下左右路径测试的变量
		next._row = next._row -1;//实际上并没有用到 迷宫中的空间，只是用到了栈中的空间，m[]的作用仅仅是修改值以及进行判断，而next就是其坐标，进行数值改变的坐标，pop()后，next发生改变，从而影响m[]中的数值发生同样的改变。每一次pop'后要在进行上下左右的分析，得到能通过的路径。
		if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._row = next._row +1;

		next._row = next._row +1;         //下
		if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._row = next._row -1;

		next._col = next._col -1;         //左
			if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._col = next._col +1;

		next._col = next._col +1;		 //右
			if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._col = next._col -1;		 

		if(Through(row,col,next))
			return true;
		s.Pop ();                         //当上下左右都无法走的时候
	}
	return false;

}
void PrintMaze(int* m)
{
		for(int i = 0; i < N;i++)
	{
		for(int j = 0; j< N ;j++)
		{
			cout<<m[i*N+j]<<" "; 
		}
		cout<<endl;
	}
		cout<<endl;
}