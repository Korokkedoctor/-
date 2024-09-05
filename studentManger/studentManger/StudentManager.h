#pragma once

/*
*ѧ����Ϣ�ṹ 
*/
typedef struct Student
{
	unsigned long long number; //ѧ��
	char name[32];			   //����
	float chinese;			   //����
	float math;				   //��ѧ
	float english;			   //Ӣ��
}Student;

/*
* �ڵ� Node
*/
typedef struct Node
{
	Student stu;			//ѧ��
	struct Node* next;		//ָ����һ���ڵ��ָ��
}Node;

/*
* ����ṹ
* 
*/

typedef struct List
{
	Node* front;			//ָ���һ���ڵ�
	int size;				//��ǰ�ڵ�����
}List;


/*
* �˵�����
*/

typedef enum MenuOptions
{
	Quit, //�˳�ϵͳ
	Entry, //¼��ѧ��
	Print, //��ӡ��Ϣ
	Save, //������Ϣ
	Read, //��ȡ��Ϣ
	Statistics, //ͳ����Ϣ
	Find, //����ѧ��
	Alter, //�޸���Ϣ
	Remove, //ɾ��ѧ��
}MenuOptions;

/*
��ӡ�˵������ṩ�û�ѡ��

*/

int menu();

/**
* ѧ��¼��
*/
void entryStudent(List* list);

/**
* ѧ����Ϣ��ӡ
*/

void printStudent(List* list);

/**
* ����ѧ����Ϣ,�Զ����Ʒ�ʽ����
*/

void saveStudent(List* list);

/**
* ����ѧ����Ϣ���������ܿ�������ʽ
*/
void saveStudentHuman(List* list);


/**
* ��ȡѧ����Ϣ,������
*/
void readStudent(List* list);

/**
* ��ȡѧ����Ϣ,�����Ƕ��ö�����ʽ
*/
void readStudentHuman(List* list);


/**
*��������
*/
void clearList(List* list);
