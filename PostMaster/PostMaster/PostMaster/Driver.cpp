#include <iostream>
#include <string.h>

typedef unsigned long pDate;

enum SERVICE { PostMaster, Interchange,
	Gmail, Hotmail, AOL, Internet };

class String {
public:
	// constructors
	String();
	String(const char* const);
	String(const String&);
	~String();

	// overloaded operators 重载操作符
	char& operator[] (int offset);
	char operator[] (int offest) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);
	friend std::ostream& operator<<
		(std::ostream& stream, String& newString);
	//friend:
	//friend 关键字表明该函数是 String 类的友元函数。友元函数可以访问该类的私有成员和保护成员，这在类的封装中是例外情况。通常，类的私有数据不能被类外的函数直接访问，但友元函数可以。

	//	std::ostream& operator<<:
	//这是一个重载的 << 运算符，用于支持输出操作。

	//	std::ostream & 表示该函数返回一个引用，该引用指向输出流对象（如 std::cout）。
	//	operator<< 是运算符重载，它允许通过 << 运算符将 String 对象输出到流中。
	//	std::ostream & stream :
	//	stream 是一个对输出流的引用。它可以是任何输出流对象，如标准输出流 std::cout 或文件输出流 std::ofstream。

	//	String & newString :
	//	这是一个 String 类对象的引用，该对象是我们希望输出的自定义类实例。通过引用传递可以避免对象的拷贝。
	//	General accessors
	int getLen() const { return len; }
	const char* getString() const { return string; }
	// static int constructorCount;

private:
	String(int);	// private constructor
	char* string;
	int len;
};

// default constructor creates string of 0 bytes
String::String()
{
	string = new char[1];
	string[0] = '\n';
	len = 0;
	// std::cout << "\tDefault string constructor\n";
	// constructorCount++;
}

// private (helper) constructor, use only by
// class functions for creating a new string of
// required size. Null filled.
String::String(int newLen)
{
	string = new char[newLen + 1];
	int i;
	for (i = 0; i <= newLen; i++)
		string[i] = '\0';
	len = newLen;
	// std::cout << "\tString(int) constructor\n";
	// constructorCount++
}

// Converts a character array to a String
String::String(const char* const cString)
{
	len = strlen(cString);
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = cString[i];
	string[len] = '\0';
	// std::cout << "\tString(char*) constructor\n";
	// constructorCount++;
}

// copy constructor
String::String(const String &rhs)
{
	len = rhs.getLen();
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = rhs[i];// 存到char* string这个指针指向的String类型数组。
	string[len] = '\0';
	// std::cout << "\tStruct(String&) constructor\n";
	// constructorCount++;
}

// destructor, fress allocated memory
String::~String()
{
	delete[] string;	// delete[]：这是一个用于释放动态分配的数组内存的操作符，区别于单个对象的 delete
	len = 0;
	// std::cout << "\tString destructor\n";
}

// 信息的保存函数 
String& String::operator=(const String &rhs)
{
	// 判断当前信息的数据和保存的数据是否一致，一致直接返回，不一致则进行信息更新，再返回
	if (this == &rhs)	
		return *this;	//this类型指针，指向main函数里调用的String::operator=函数，如果this等于rhs的引用（进行一个地址的比较）
						//返回一个this指针的接引用，也就是返回rhs实例
	delete[] string;
	len = rhs.getLen();
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = rhs[i];
	string[len] = '\0';
	return *this;
	// std::cout << "\tString operator=\n";
}

//non constant offset operator, returns
// reference to character so it can be changed
char& String::operator[] (int offset)
{
	if (offset > len)
		return string[len - 1];
	else
		return string[offset];
}

//char& String::operator[] (int offset)
//{
//	if (offset < 0)  // 检查负索引
//		return string[0];  // 返回第一个字符
//	else if (offset >= len)  // 检查是否超出有效范围
//		return string[len - 1];  // 返回最后一个字符
//	else
//		return string[offset];  // 返回对应索引处的字符
//}

// constant offset operator for use
// on const objects (see copy Constructor!)
char String::operator[](int offset) const 
{
	if (offset > len)
		return string[len - 1];
	else
		return string[offset];
}

// creates a new string by adding current
// string to rhs
String String::operator+(const String& rhs)
{
	int totalLen = len + rhs.getLen();
	String temp(totalLen);
	int i, j;
	for (i = 0; i < len; i++)
		temp[i] = string[i];
	for (j = 0; j < rhs.getLen(); j++, i++)
		temp[i] = rhs[j];
	return temp;
}

// int String::ConstructorCount = 0;

std::ostream& operator<<(std::ostream& stream,
	String& newString)
{
	stream << newString.getString();
	return stream;
}

class pAddress
{
public:
	pAddress(SERVICE newService,const String& newAddress,const String& newDisplay):
		service(newService),
		addressString(newAddress),
		displayString(newDisplay)
	{ }
	// 构造函数，传入四个参数:SERVICE 声明的枚举变量，剩下两个常量字符串指针（该类声明的私有变量）
	// pAddress(String, String);
	// pAddress();
	// pAddress(const pAddress&);
	~pAddress(){}
	// 默认构析函数
	friend std::ostream& operator<<(
		std::ostream& stream, pAddress& address);
	String& getDisplayString()
	{
		return displayString;
	}
private:
	 SERVICE service;
	String addressString;
	String displayString;
};

std::ostream& operator<<
(std::ostream& stream, pAddress& address)
{
	stream << address.getDisplayString();
	return stream;
}

class PostMasterMessage
{
public:
	//	PostMasterMessage();

	PostMasterMessage(const pAddress& newSender,
		const pAddress& newRecipient,
		const String& newSubject,
		const pDate& newCreationData); // 构造函数，四个参数：常态的pAddress(地址)类指针，发送方，接收方，信息，日期

	~PostMasterMessage(){}

	void Edit(); // invokes editor on this message

	pAddress& getSender() { return sender; }
	pAddress& getRecipient() { return recipient; }
	String& getSubject() { return subject; }
	// void setSender(pAddress& );
	// other member accessors

	// operator functions here, including operator equals
	// and conversion routines to turn PostMaster message
	// into messages of other formats.

private:
	pAddress sender;
	pAddress recipient;
	String subject;
	pDate creationDate;
	pDate lastModDate;
	pDate receiptDate;
	pDate firstReadDate;
	pDate lastReadDate;
};

PostMasterMessage::PostMasterMessage(
	const pAddress& newSender,
	const pAddress& newRecipient,
	const String& newSubject,
	const pDate& newCreationDate):
	sender(newSender),
	recipient(newRecipient),
	subject(newSubject),
	creationDate(newCreationDate),
	lastModDate(newCreationDate),
	firstReadDate(0),
	lastReadDate(0)
{
	std::cout << "Postmaster message created. \n";
}

void PostMasterMessage::Edit()
{
	std::cout << "Postmaster message edit function called\n";
}

int main()
{
	pAddress sender(
		PostMaster, "james@ekzemplo.com", "James"); // 调用地址类（发送方），三个参数: 服务类型，发送方邮箱，发件人
	pAddress recipient(
		PostMaster, "sharon@ekzemplo.com", "Sharon");// 调用地址类（接收方），三个参数: 服务类型，发送方邮箱，发件人
	PostMasterMessage postMasterMessage(
		sender, recipient, "Greetings", 0
	);// 上面调用的邮件服务类型的邮件信息
	std::cout << "Message review... \n";
	std::cout << "From:\t\t"
		<< postMasterMessage.getSender() << "\n";
	std::cout << "To:\t\t"
		<< postMasterMessage.getRecipient() << "\n";
	std::cout << "Subject:\t"
		<< postMasterMessage.getSubject() << "\n";
	return 0;
}
