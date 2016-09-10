#pragma once

#include"stack.h"
#define N 10
void InitMaze(int *m) //���ļ��ж�ȡ���ݵ�����Maze��
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

bool CheckPos(int row,int col,Pos p,int *m)//ֻ�е�����Ϊ0��ʱ��ſ�����������
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
		Pos cur = s.Top ();//curΪ����ѹ��ջ�е�����,ջ����Ԫ�ؾ����Թ�Ŀǰ���ߵ����һ��
		Pos next = cur;//Ϊ������������·�����Եı���
		next._row = next._row -1;//ʵ���ϲ�û���õ� �Թ��еĿռ䣬ֻ���õ���ջ�еĿռ䣬m[]�����ý������޸�ֵ�Լ������жϣ���next���������꣬������ֵ�ı�����꣬pop()��next�����ı䣬�Ӷ�Ӱ��m[]�е���ֵ����ͬ���ĸı䡣ÿһ��pop'��Ҫ�ڽ����������ҵķ������õ���ͨ����·����
		if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._row = next._row +1;

		next._row = next._row +1;         //��
		if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._row = next._row -1;

		next._col = next._col -1;         //��
			if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._col = next._col +1;

		next._col = next._col +1;		 //��
			if(CheckPos(row,col,next,m))
		{
			s.Push (next);
			m[next._row *N+next._col ]=2;
			continue;
		}
		next._col = next._col -1;		 

		if(Through(row,col,next))
			return true;
		s.Pop ();                         //���������Ҷ��޷��ߵ�ʱ��
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