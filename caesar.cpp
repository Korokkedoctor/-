#include <iostream>//���������������
#include <fstream> //�ļ�������� fin fout
#include <cstdlib>//��������ɣ��ڴ���� 
using namespace std;
const char c[27]={'d','j','k','z','u','x','c','m','l','i','w','b','v','n','o','p','q','a','r','s','g','h','f','t','y','e',' '};
void encryption(ifstream& fin, ofstream& fout);//��&���������� 
void decryption(ifstream& fin, ofstream& fout);
int main()
{
	ifstream fin;//��ȡ�����ļ�������,���ڶ�ȡ���ݣ������ķ�ʽ
	//��ȡ 
	ofstream fout;//��ȡ����ļ��������������
	//���ܺ������
	//ifstream��ofstrean��fsteam�����ĳ�ֱ������� 
	ifstream enc;
	ofstream dec;
	fin.open("file1_1.in");//
	if(fin.fail()) //fail��������������ļ���״̬������һ��bool���͵�ֵ
	{
		cout <<"File open error!(Input)"<< endl;
		exit(1);//exit(n),����n��0��ʾ�����쳣��ֹ���������쳣���� 
	} 
	fout.open("file1_1.text");
	if(fout.fail())
	{
		cout <<"File open error!(output)"<< endl;
	}
	encryption(fin,fout);
	fin.close();
	fout.close();
	
	enc.open("file1_1.text");
	if(enc.fail())
	{
		cout <<"File open error!(encryp)"<< endl;
	}
	dec.open("file1_1.dec");
	if(dec.fail())
	{
		cout <<"File open error!(decryp)"<< endl;
	}
	
	decryption(enc,dec);
	
	enc.close();
	dec.close();
	return 0; 
}
void encryption(ifstream& fin,ofstream& fout)
{
	char next;
	char ch;
	int i;
	while(fin.get(next))//ʹ��get��ȡ������������next
	{
		if(next>='a'&&next<='z')
		{
			i = next-'a';
			ch=c[i];
			fout<<ch;
		} 
		else
		{
			fout<<' '; 
		}
	 } 
 } 
 void decryption(ifstream& enc,ofstream& dec)
 {
 	char ch;
 	char chout;
 	while(enc.get(ch))
 	{
 		for(int i = 0;i<=26;i++)
 		{
 			if(ch==c[i])
 			{
 				if(i == 26)
 				{
 					dec<<' ';	
				}
				else
				{
					chout=char('a'+i);
					dec<<chout;	
				} 
 				
			}
		}
	}
 }
 

