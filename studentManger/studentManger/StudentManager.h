#pragma once

/*
*学生信息结构 
*/
typedef struct Student
{
	unsigned long long number; //学号
	char name[32];			   //姓名
	float chinese;			   //语文
	float math;				   //数学
	float english;			   //英语
}Student;

/*
* 节点 Node
*/
typedef struct Node
{
	Student stu;			//学生
	struct Node* next;		//指向下一个节点的指针
}Node;

/*
* 链表结构
* 
*/

typedef struct List
{
	Node* front;			//指向第一个节点
	int size;				//当前节点数量
}List;


/*
* 菜单功能
*/

typedef enum MenuOptions
{
	Quit, //退出系统
	Entry, //录入学生
	Print, //打印信息
	Save, //保存信息
	Read, //读取信息
	Statistics, //统计信息
	Find, //查找学生
	Alter, //修改信息
	Remove, //删除学生
}MenuOptions;

/*
打印菜单，并提供用户选择

*/

int menu();

/**
* 学生录入
*/
void entryStudent(List* list);

/**
* 学生信息打印
*/

void printStudent(List* list);

/**
* 保存学生信息,以二进制方式保存
*/

void saveStudent(List* list);

/**
* 保存学生信息，以我们能看懂的形式
*/
void saveStudentHuman(List* list);


/**
* 读取学生信息,二进制
*/
void readStudent(List* list);

/**
* 读取学生信息,以我们读得懂的形式
*/
void readStudentHuman(List* list);


/**
*清链函数
*/
void clearList(List* list);
