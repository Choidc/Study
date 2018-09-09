#include "ProfessionalC++.h"
#include <iostream>
#include <string>
using namespace std;

//class A {
//public :
//	void string()
//	{
//		cout << "AA" << endl;
//	}
//};
//
//class B {
//public:
//	void string()
//	{
//		cout << "BB" << endl;
//	}
//};
//
//class C : public A, public B
//{
//public:
//	void showString()
//	{
//		string();
//		string()
//	}
//};
// http://www.ikpil.com/538


int main()
{
	stringLowLiteral();
}

// http://norux.me/7 
// strcpy_s 문제 해결법

char* copyString(const char* str)
{
	char* result = new char[strlen(str)];
	strcpy(result, str);
	return result;
}

void stringSize()
{
	char text1[] = "Abcdef";
	size_t s1 = sizeof(text1);
	size_t s2 = strlen(text1);

	const char* text2 = "Abcdef";
	size_t s3 = sizeof(text2);


	size_t s4 = strlen(text1);
}

void stringLiteral()
{
	//https://msdn.microsoft.com/ko-kr/library/69ze775t(v=vs.120).aspx

	char arr[] = "hello";
	arr[1] = 'a';
	cout << arr << endl;
}

void stringLowLiteral()
{
	string r;
	string str = R"(Hello "World"!)";
	cout << str << endl;
	string str2 = R"(Line 1
					Line2 with \t)";
	cout << str2 << endl;
	string str3 = R"-(My Name)" is CDC)-";
	cout << str3 << endl;
	cin >> r;
}

/*
3장

주석 잘 달아라
코드는 적당히 분할하여라
네이밍 센스를 발휘하여라
참조형 https://boycoding.tistory.com/207
협업 관련 포멧팅을 맞춰라

4장

C++ 의 디자인원칙
1. 추상화 - 내부 구현과 외부 인터페이스를 깨끗하게 분리
 버전이 오르면 내부는 조금씩 변할 수 잇찌만 인터페이스를 통해 신경안쓰도록 함
2. 재사용 
 매번 밑단부터 구현하는건 아주 비효율적이다. 함수, 클래스, 라이브러리, 외부프레임워크 등을 이용

 5장

 객체지향
 클래스, 컴포넌트, 프로퍼티, 행동

is a - 상속관계
has a - 포함관계
http://pacs.tistory.com/entry/C-%EC%83%81%EC%86%8D-%EC%84%B8%EB%B2%88%EC%A7%B8-%EC%83%81%EC%86%8D%EC%9D%98-%EC%A1%B0%EA%B1%B4-is-a-%EC%99%80-has-a-%EA%B4%80%EA%B3%84

일반 상속
http://wnsgp.tistory.com/66


*/



// 데코레이터패턴 http://bowie.egloos.com/v/1348409
