#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StudentManager.h"
#include <string.h>

int main(int argc, char* argv[])
{
	//创建列表
	List list = { 0 };
	//内存设置
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
			// 读取之前清空列表，防止重复加载
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
		// 让程序暂停一下
		system("cls"); // 清屏
	}
	
	
}