#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StudentManager.h"
#include <string.h>

int main(int argc, char* argv[])
{
	//�����б�
	List list = { 0 };
	//�ڴ�����
	memset(&list, 0, sizeof(List));
	
	while (true)
	{
		switch (menu())
		{
		case Quit:
			printf("Quit\n");
			clearList(&list);
			return 0;
		case Entry:
			entryStudent(&list);
			break;
		case Print:
			printStudent(&list);
			break;
		case Save:
			//saveStudent(&list);
			saveStudentHuman(&list);
			break;
		case Read:
			// ��ȡ֮ǰ����б���ֹ�ظ�����
			clearList(&list);
			//readStudent(&list);
			readStudentHuman(&list);
			break;
		case Statistics:
			break;
		case Find:
			break;
		case Alter:
			break;
		case Remove:
			break;
		default:
			break;
		}
		system("pause");
		// �ó�����ͣһ��
		system("cls"); // ����
	}
	
	
}