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

	// overloaded operators ���ز�����
	char& operator[] (int offset);
	char operator[] (int offest) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);
	friend std::ostream& operator<<
		(std::ostream& stream, String& newString);
	//friend:
	//friend �ؼ��ֱ����ú����� String �����Ԫ��������Ԫ�������Է��ʸ����˽�г�Ա�ͱ�����Ա��������ķ�װ�������������ͨ�������˽�����ݲ��ܱ�����ĺ���ֱ�ӷ��ʣ�����Ԫ�������ԡ�

	//	std::ostream& operator<<:
	//����һ�����ص� << �����������֧�����������

	//	std::ostream & ��ʾ�ú�������һ�����ã�������ָ������������� std::cout����
	//	operator<< ����������أ�������ͨ�� << ������� String ������������С�
	//	std::ostream & stream :
	//	stream ��һ��������������á����������κ�������������׼����� std::cout ���ļ������ std::ofstream��

	//	String & newString :
	//	����һ�� String ���������ã��ö���������ϣ��������Զ�����ʵ����ͨ�����ô��ݿ��Ա������Ŀ�����
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
		string[i] = rhs[i];// �浽char* string���ָ��ָ���String�������顣
	string[len] = '\0';
	// std::cout << "\tStruct(String&) constructor\n";
	// constructorCount++;
}

// destructor, fress allocated memory
String::~String()
{
	delete[] string;	// delete[]������һ�������ͷŶ�̬����������ڴ�Ĳ������������ڵ�������� delete
	len = 0;
	// std::cout << "\tString destructor\n";
}

// ��Ϣ�ı��溯�� 
String& String::operator=(const String &rhs)
{
	// �жϵ�ǰ��Ϣ�����ݺͱ���������Ƿ�һ�£�һ��ֱ�ӷ��أ���һ���������Ϣ���£��ٷ���
	if (this == &rhs)	
		return *this;	//this����ָ�룬ָ��main��������õ�String::operator=���������this����rhs�����ã�����һ����ַ�ıȽϣ�
						//����һ��thisָ��Ľ����ã�Ҳ���Ƿ���rhsʵ��
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
//	if (offset < 0)  // ��鸺����
//		return string[0];  // ���ص�һ���ַ�
//	else if (offset >= len)  // ����Ƿ񳬳���Ч��Χ
//		return string[len - 1];  // �������һ���ַ�
//	else
//		return string[offset];  // ���ض�Ӧ���������ַ�
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
	// ���캯���������ĸ�����:SERVICE ������ö�ٱ�����ʣ�����������ַ���ָ�루����������˽�б�����
	// pAddress(String, String);
	// pAddress();
	// pAddress(const pAddress&);
	~pAddress(){}
	// Ĭ�Ϲ�������
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
		const pDate& newCreationData); // ���캯�����ĸ���������̬��pAddress(��ַ)��ָ�룬���ͷ������շ�����Ϣ������

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
		PostMaster, "james@ekzemplo.com", "James"); // ���õ�ַ�ࣨ���ͷ�������������: �������ͣ����ͷ����䣬������
	pAddress recipient(
		PostMaster, "sharon@ekzemplo.com", "Sharon");// ���õ�ַ�ࣨ���շ�������������: �������ͣ����ͷ����䣬������
	PostMasterMessage postMasterMessage(
		sender, recipient, "Greetings", 0
	);// ������õ��ʼ��������͵��ʼ���Ϣ
	std::cout << "Message review... \n";
	std::cout << "From:\t\t"
		<< postMasterMessage.getSender() << "\n";
	std::cout << "To:\t\t"
		<< postMasterMessage.getRecipient() << "\n";
	std::cout << "Subject:\t"
		<< postMasterMessage.getSubject() << "\n";
	return 0;
}
