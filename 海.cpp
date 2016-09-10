
#include"stack.h"
#include"Maze.h"	
using namespace std;


void test()
{
	Stack<int> s1;
	s1.Push (1);
	s1.Push (2);
	s1.Push (3);
	s1.Push (4);
	s1.Push (5);
	s1.Dislplay ();
	cout<<s1.Empty() <<endl;
	cout<<s1.Top()<<endl;
	s1.Pop ();
	s1.Dislplay ();
}


void MazeTest()
{
	Stack<Pos> s1;
	Pos e ;
	e._row = 1;
	e._col = 0;
 	int maze[N][N];
	InitMaze((int*)maze);
	PrintMaze((int*)maze);
	GetPath(N,N,(int*)maze,s1,e);
	PrintMaze((int*)maze);

}
int main()
{
	//test();
	MazeTest();
	return 0;
}