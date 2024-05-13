#include <iostream>//输入输出，流对象
#include <fstream> //文件输出输入 fin fout
#include <cstdlib>//随机数生成，内存管理 
using namespace std;
const char c[27]={'d','j','k','z','u','x','c','m','l','i','w','b','v','n','o','p','q','a','r','s','g','h','f','t','y','e',' '};
void encryption(ifstream& fin, ofstream& fout);//“&”——引用 
int main()
{
	ifstream fin;//读取输入文件流对象,用于读取数据，以流的方式
	//读取 
	ofstream fout;//读取输出文件流对象，用于输出
	//加密后的数据
	//ifstream和ofstrean是fsteam定义的某种变量类型 
	
	fin.open("file1_1.in");//
	if(fin.fail()) //fail函数常用来检查文件流状态，返回一个bool类型的值
	{
		cout <<"File open error!(Input)"<< endl;
		exit(1);//exit(n),参数n非0表示程序异常终止，常用于异常捕获 
	} 
	fout.open("file1_1.text");
	if(fout.fail())
	{
		cout <<"File open error!(output)"<< endl;
	} 
	encryption(fin,fout);
	fin.close();
	fout.close();
	return 0; 
}
void encryption(ifstream& fin,ofstream& fout)
{
	char next;
	char ch;
	int i;
	while(fin.get(next))//使用get读取流，传给变量next
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
 
 

