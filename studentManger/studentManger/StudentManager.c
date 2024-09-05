#include "StudentManager.h"
#include<stdio.h>
#include<malloc.h>

//�����ڵ�

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
	printf("*	��ӭʹ��ѧ������ϵͳV1.0	*\n");
	printf("*****************************************\n");
	printf("*		��ѡ����		*\n");
	printf("*****************************************\n");
	printf("*		1.¼��ѧ����Ϣ		*\n");
	printf("*		2.��ӡѧ����Ϣ		*\n");
	printf("*		3.����ѧ����Ϣ		*\n");
	printf("*		4.��ȡѧ����Ϣ		*\n");
	printf("*		5.ͳ��ѧ����Ϣ		*\n");
	printf("*		6.����ѧ����Ϣ		*\n");
	printf("*		7.�޸�ѧ����Ϣ		*\n");
	printf("*		8.ɾ��ѧ����Ϣ		*\n");
	printf("*		0.�˳�ϵͳ		*\n");
	printf("*****************************************\n");
	printf("select>");
	int select = -1;
	scanf_s("%d", &select);
	return select;
}

//���������������ظ�����
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
	//�����ڵ�
	Node* node = CreateNode();

	//����ѧ��
	printf("����ѧ��ѧ��>");
	scanf("%llu", &node->stu.number);
	printf("����ѧ������>");
	scanf("%s", &node->stu.name);
	printf("����ѧ�����ĳɼ�>");
	scanf("%f", &node->stu.chinese);
	printf("����ѧ����ѧ�ɼ�>");
	scanf("%f", &node->stu.math);
	printf("����ѧ��Ӣ��ɼ�>");
	scanf("%f", &node->stu.english);

	node->next = list->front;
	list->front = node;
	list->size++;
}

//void printStudent(List* list)
//{
//	printf("********************************************\n");
//	printf("*          ��ӭʹ��ѧ������ϵͳV1.0        *\n");
//	printf("********************************************\n");
//	printf("*  ѧ��  *  ����  *  ����  *  ��ѧ  *  Ӣ��*\n");
//	printf("********************************************\n");
//
	//��������
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
	printf("*          ��ӭʹ��ѧ������ϵͳV1.0        *\n");
	printf("********************************************\n");
	printf("*  ѧ��  *  ����  *  ����  *  ��ѧ  *  Ӣ��*\n");
	printf("********************************************\n");

	// ��������
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
	//���ļ�
	FILE* fp = fopen("students.data", "wb");
	if (!fp) {
		perror("file open failed");
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(Student), 1, fp);
		curNode = curNode->next;
	}
	//�ر��ļ�
	fclose(fp);
}

void saveStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fprintf(fp, "%llu\t%s\t%.1f\t%.1f\t%.lf\n",curNode->stu.number,curNode->stu.name,curNode->stu.chinese,curNode->stu.math,curNode->stu.english);
		curNode = curNode->next;
	}
	//�ر��ļ�
	fclose(fp);
}

void readStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//��ȡѧ����Ϣ
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
		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//�ر��ļ�
	fclose(fp);

}

/*
void readStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//��ȡѧ����Ϣ
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
		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}
	
	//�ر��ļ�
	fclose(fp);
}
*/


//���ǽ�ʹ�� fscanf() ���滻�����õ� feof() ��顣���ǻ�ȷ��ÿ�γɹ���ȡһ��ʱ�����ݸ�ʽ����ȫƥ���
void readStudentHuman(List* list)
{
	// ���ļ�
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	// ��ʼ������
	unsigned long long number;
	char name[50];  // �������ֵ���󳤶�Ϊ50
	float chinese, math, english;

	// ��ȡѧ����Ϣ
	while (fscanf(fp, "%llu\t%s\t%f\t%f\t%f\n", &number, name, &chinese, &math, &english) == 5)
	{
		// �����µĽڵ㲢�������
		Node* node = CreateNode();
		if (!node)
		{
			perror("Memory allocation failed");
			break;
		}

		// ����ȡ�����ݴ���ڵ�
		node->stu.number = number;
		strcpy(node->stu.name, name);
		node->stu.chinese = chinese;
		node->stu.math = math;
		node->stu.english = english;

		// ��������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	// �ر��ļ�
	fclose(fp);
}
