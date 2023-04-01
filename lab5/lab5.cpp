#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class DynamicString {
private:
	char* data;
	size_t length;
public:
    DynamicString();
    DynamicString(const char* str);
    DynamicString(const DynamicString& other);
    ~DynamicString();

    void setData(const char* str);

    size_t getLength();
    char* getData();

    DynamicString& operator = (const DynamicString& other);
    DynamicString operator + (const DynamicString& other);
    bool operator == (const DynamicString& other);
    bool operator != (const DynamicString& other);
    bool operator <= (const DynamicString& other);
    bool operator >= (const DynamicString& other);
};
DynamicString::DynamicString() {
    data = nullptr;
    length = 0;
}
DynamicString::DynamicString(const char* str) {
    if (strlen(str) > 254) {
        cerr << "����������� ������� ����������� � 254." << endl;
        data = nullptr;
        length = 0;
        return;
    }
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}
DynamicString::DynamicString(const DynamicString& other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
    data[length] = '\0';
}
DynamicString::~DynamicString() {
    delete[] data;
}


size_t DynamicString::getLength() {
    return length;
}
char* DynamicString::getData() {
    return data;
}

void DynamicString::setData(const char* str) {
    if (strlen(str) > 254) {
        cerr << "����������� ������� ����������� � 254." << endl;
        return;
    }
    delete[] data;
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}

DynamicString& DynamicString::operator = (const DynamicString &other) {
    length = other.length;

    if (data != nullptr) {
        delete[]data;
    }

    data = new char[other.length+1];
    strcpy(data, other.data);

    return *this;
}
DynamicString DynamicString::operator + (const DynamicString& other) {
    DynamicString temp;
    temp.length = strlen(data) + strlen(other.data);
    temp.data = new char[temp.length + 1];
    strcpy(temp.data, this->data);
    strcat(temp.data, other.data);
    temp.data[temp.length] = '\0';
    return temp;
}

bool DynamicString::operator == (const DynamicString& other) {
    int res = strcmp(data, other.data);
    return length == other.length && res == 0;
}
bool DynamicString::operator != (const DynamicString& other) {
    int res = strcmp(data, other.data);
    return !(this->length == other.length && res == 0);
}
bool DynamicString::operator <= (const DynamicString& other) {
    return length <= other.length;
}
bool DynamicString::operator >= (const DynamicString& other) {
    return length >= other.length;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DynamicString text("������ ����� ��� ���� ��������.");
    cout << "�� ����: " << text.getData() << endl;
    cout << "�������: " << text.getLength() << endl;

    cout << "==========================" << endl;

    text.setData("�, � ����� �����!");
    cout << "ϳ��� ����: " << text.getData() << endl;
    cout << "�������: " << text.getLength() << endl;

    cout << "==========================" << endl;

    DynamicString text1("�������� ����� 1.");
    cout << "Text1: " << text1.getData() << endl;
    DynamicString text2("�������� ����� 2.");
    cout << "Text2: " << text2.getData() << endl;
    cout << "==========================" << endl;


    DynamicString sumResult;
    sumResult = text1 + text2;
    cout << "������������ �����: " << endl<< sumResult.getData() << endl;
    cout << "==================================" << endl;

    cout << "��������� �����:" << endl;
    bool result = text1 == text2;
    cout <<"�������� == : " << result << endl;
    result = text1 != text2;
    cout << "�������� != : " << result << endl;
    result = text1 >= text2;
    cout << "�������� >= : " << result << endl;
    result = text1 <= text2;
    cout << "�������� <= : " << result << endl;


    cout << "==================================" << endl;
    cout << "��������� ������ � text2 � text1: " << endl << text1.getData() << endl;
    text1 = text2;
    cout << "==================================" << endl;

    return 0;
}
