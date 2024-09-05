#include "StudentManager.h"
#include<stdio.h>
#include<malloc.h>

//创建节点

static Node* CreateNode()
{
	Node* node = malloc(sizeof(Node));
	if (!node)
	{
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

int menu()
{
	printf("*****************************************\n");
	printf("*	欢迎使用学生管理系统V1.0	*\n");
	printf("*****************************************\n");
	printf("*		请选择功能		*\n");
	printf("*****************************************\n");
	printf("*		1.录入学生信息		*\n");
	printf("*		2.打印学生信息		*\n");
	printf("*		3.保存学生信息		*\n");
	printf("*		4.读取学生信息		*\n");
	printf("*		5.统计学生信息		*\n");
	printf("*		6.查找学生信息		*\n");
	printf("*		7.修改学生信息		*\n");
	printf("*		8.删除学生信息		*\n");
	printf("*		0.退出系统		*\n");
	printf("*****************************************\n");
	printf("select>");
	int select = -1;
	scanf_s("%d", &select);
	return select;
}

//清链函数，避免重复插入
void clearList(List* list)
{
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		Node* nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	}
	list->front = NULL;
	list->size = 0;
}

void entryStudent(List* list)
{
	//创建节点
	Node* node = CreateNode();

	//输入学生
	printf("输入学生学号>");
	scanf("%llu", &node->stu.number);
	printf("输入学生姓名>");
	scanf("%s", &node->stu.name);
	printf("输入学生语文成绩>");
	scanf("%f", &node->stu.chinese);
	printf("输入学生数学成绩>");
	scanf("%f", &node->stu.math);
	printf("输入学生英语成绩>");
	scanf("%f", &node->stu.english);

	node->next = list->front;
	list->front = node;
	list->size++;
}

//void printStudent(List* list)
//{
//	printf("********************************************\n");
//	printf("*          欢迎使用学生管理系统V1.0        *\n");
//	printf("********************************************\n");
//	printf("*  学号  *  姓名  *  语文  *  数学  *  英语*\n");
//	printf("********************************************\n");
//
	//遍历链表
//	Node* curNode = list->front;
//	while (curNode != NULL)
//	{
//		printf("*	%llu**%s**%.lf**%.1f**%.1f	*\n",curNode->stu.number,curNode->stu.name,curNode->stu.chinese,curNode->stu.math,curNode->stu.english);
//		curNode = curNode->next;
//	}
//}
void printStudent(List* list)
{
	printf("********************************************\n");
	printf("*          欢迎使用学生管理系统V1.0        *\n");
	printf("********************************************\n");
	printf("*  学号  *  姓名  *  语文  *  数学  *  英语*\n");
	printf("********************************************\n");

	// 遍历链表
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		printf("*   %llu  **  %s  **  %.1f  **  %.1f  **  %.1f  *\n",
			curNode->stu.number, curNode->stu.name,
			curNode->stu.chinese, curNode->stu.math, curNode->stu.english);
		curNode = curNode->next;
	}

	printf("********************************************\n");
}


void saveStudent(List* list)
{
	//打开文件
	FILE* fp = fopen("students.data", "wb");
	if (!fp) {
		perror("file open failed");
	}

	//写入学生信息
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(Student), 1, fp);
		curNode = curNode->next;
	}
	//关闭文件
	fclose(fp);
}

void saveStudentHuman(List* list)
{
	//打开文件
	FILE* fp = fopen("students.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//写入学生信息
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fprintf(fp, "%llu\t%s\t%.1f\t%.1f\t%.lf\n",curNode->stu.number,curNode->stu.name,curNode->stu.chinese,curNode->stu.math,curNode->stu.english);
		curNode = curNode->next;
	}
	//关闭文件
	fclose(fp);
}

void readStudent(List* list)
{
	//打开文件
	FILE* fp = fopen("students.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//读取学生信息
	while (!feof(fp))
	{
		Node* node = CreateNode();
		if (!node)
		{
			break;
		}
		size_t len= fread(&node->stu, sizeof(Student), 1, fp);
		if (len == 0)
		{
			free(node);
			break;
		}
		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//关闭文件
	fclose(fp);

}

/*
void readStudentHuman(List* list)
{
	//打开文件
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//读取学生信息
	while (!feof(fp))
	{
		Node* node = CreateNode();
		if (!node)
		{
			break;
		}
		if(5 != fscanf(fp, "%llu\t%s\t%.1f\t%.1f\t%.1f\n",&node->stu.number,node->stu.name,&node->stu.chinese,&node->stu.math,&node->stu.english))
		{
			free(node);
			break;
		}
		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}
	
	//关闭文件
	fclose(fp);
}
*/


//我们将使用 fscanf() 并替换不适用的 feof() 检查。我们还确保每次成功读取一行时，数据格式是完全匹配的
void readStudentHuman(List* list)
{
	// 打开文件
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	// 初始化变量
	unsigned long long number;
	char name[50];  // 假设名字的最大长度为50
	float chinese, math, english;

	// 读取学生信息
	while (fscanf(fp, "%llu\t%s\t%f\t%f\t%f\n", &number, name, &chinese, &math, &english) == 5)
	{
		// 创建新的节点并填充数据
		Node* node = CreateNode();
		if (!node)
		{
			perror("Memory allocation failed");
			break;
		}

		// 将读取的数据存入节点
		node->stu.number = number;
		strcpy(node->stu.name, name);
		node->stu.chinese = chinese;
		node->stu.math = math;
		node->stu.english = english;

		// 插入链表
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	// 关闭文件
	fclose(fp);
}
