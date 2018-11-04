/*
입출력에 대해 알아보자.
C에선 printf, scanf로 하였는데 이는 에러처리가 완벽하지 않고, 커스텀 데이터 타입을 다룰 수 없고, 객체지향과는 거리가 멀다.
C++에선 스트림이라 불리는 유연하면서도 객체 지향적인 I/O시스템을 제공한다.

1. 스트림
cout 은 출력 스트림 console + out 으로 콘솔에서 데이터 쓰기 작업을 한다.
cin 은 입력 스트림 console + in 으로 콘솔을 입력 소스로 하여 데이터를 읽는다. 
cerr 버퍼가 없는 출력 스트림으로 에러 콘솔에 쓴다. clog 버퍼를 가진 cerr 스트림이다.
두개 모두 std 네임스페이스에서 정의 되어 있다.
GUI를 사용하는 프로그램은 콘솔이 없는 경우가 많아서 출력을해도 사용자가 볼 수 없다.
따라서 cout, cin, cerr, clog 를 사용하여 콘솔에 접근할 수 있다고 가정하면 안된다.
스트림의 중요한 점은 스트림이 데이터를 가질 뿐 아니라 현재 위치(읽고 쓰기를 작업할 위치)도 가진다.

스트림의 개념은 데이터를 받거나 생성하는 모든 객체에 적용할 수 있다. 
콘솔 입력 스트림은 런타임에 입력을 받을 수 있게하여 프로그램을 인터랙티브하게 만들어 주고, 콘솔 출력 스트림은 그 결과를 출력한다.
파일 스트림은 파일 시스템에서 데이터를 읽거나, 파일 시스템에 데이터를 기록한다.
문자열 스트림은 문자열을 일반 스트림 처럼 사용하는 것이다.

< 출력 >
- 스트림 출력
ostream 헤더에 정의 되어 있지만 iostream으로 한번에 인클루드 한다.
<< 연산자를 이용하여 기본 내장 타입을 << 로 출력할 수 있다.
C스타일의 이스케이프 시퀀스도 지원하지만 endl 이 바람직하다. - 줄 바꿈 뿐 아니라 출력 버퍼를 밀어내는 역할도 한다. 하지만 출력 동기화를 유발하여 성능에 악영향을 준다.
ostream 에 다양한 << 연산자가 오버로딩 되어 있다.

- 출력스트림 메서드
put - << 연산자 대신 문자를 받아 출력
write - << 연산자 대신 문자열을 받아 출력
flush -  출력 스트림은 버퍼를 가지고 있어 효율을 위해 모았다가 조건이 맞으면 한번에 출력
(조건) 1. endl 같은 특별한 마커, 2. 스트림 객체가 스코프를 벗어나서 소멸, 3. 연관된 입력 스트림에서 입력, 4. 스트림 버퍼가 가득 찼을 때, 5. 스트림에 명시적으로 데이터 내보내기 명령 할 때

- 에러 메시지 출력
good - 정상적인 상태인지 확인하는 방법 (에러가 없는지, 정상 동작이 가능한지)
bad - true를 리턴하면 fatal error가 발생했다.
fail - true를 리턴하면 최근 작업이 실패했고, 다음도 실패할것
ios_base::failure exception - what, code 메서드를 통해 설명과 코드값을 가져올 수 있다.
clear - 스트림 에러 상태 리셋

- 출력 스트림 매니퓰레이터
boolalpha, noboolalpha - 스트림이 bool 타임 값을 출력할때 T/F일지(boolalpha) 1/0일지(noboolalpha) (디폴트는 1/0)
hex, oct, dec - 16, 8, 10 진수 포맷
setprecision - 출력할 소수점 이하 자릿수
setw - 숫자 출력을 위한 자릿수 크기
setfill - 숫자 출력을 위해 지정된 자리 수 보다 작을 때 빈 공간을 채울 문자 지정
showpoint, noshowpoint - 숫자를 출력할 때 소수점과 소수점 이하를 표시/안표시
put_money - 화폐 포맷팅
put_time - 시간 포맷팅
quoted - 입력받은 물자열을 따옴표로 둘러싸서 스트림으로 보냄
*/

/*
< 입력 >
- 스트림 입력
일반 데이터 및 구조화된 데이터까지 입력 받을 수 있다.
>> 연산자 - 공백문자를 구분자로하여 입력값들을 토큰화(구분화) 한다.

- 입력 메서드
get - 스트림으로부터 로우 데이터를 얻을 수있도록 한다. 문자를 하나씩 리턴 / 동시에 리턴 하는 여러 버전이 제공된다.
unget - 이미 읽어들인 문자 하나를 스트림에 되돌려 놓는다.
putback - 읽어들인 문자 하나를 꺼내오는거 (스트림에 되돌려 놓는거) 에 추가로 파라미터로 지정이 가능
peek - get을 읽을때 꺼내오지 않고 미리 확인이 됌
getline - 한 줄 단위로 문자열 데이터를 읽는다. 문자열 끝 데이터는 가져오지 않는다 eol

- 에러처리 방법
good(), bad(), fail() 메서드로 상태검사, eof() 메서드는 스트림의 끝에 도달할 경우 true

- 입력 스트림 매니퓰레이터
boolalpha, noboolalpha - 문자열 false는 bool false로, 나머지는 true (boolalpha) 문자 0 인 경우 (noboolalpha)
hex, oct, dec - 16 8 10 진수
skipws, noskipws - skipws 입력 문자열을 토큰활 할때 공백 생략, noskipws는 공백 포함 ws = white space
ws - 현재 위치로 부터 연이은 공백문자 생략
get_money - 화폐금액으로 읽음
get_time - 시간으로 읽음
quoted - 따옴표로 둘러싸인 문자열을 입력 받음 

- 문자열 스트림
문자열 스트림을 사용하면 string 객체를 스트림 개념에 적용
ostringstream, istringstream = sstream 으로 정의
+= 연산자를 이용하는 것보다 문자열 스트림을 이용하는게 더 효율적

- 파일 스트림
파일은 읽고 쓰는 작업에 현재 위치가 존재하여 스트림 화 하기에 적절하다
ofstream, ifstream = fstream 에 정의
ios_base::app = 파일을 연 다음 쓰기 작업이 시작되기 전에 스트림의 위치를 파일 제일 끝으로 옮김
ios_base::ate = 파일을 열자마다 스트림의 위치를 파일의 제일 끝으로 옮김
ios_base::binary = 바이너리 모드로 데이터 입출력을 한다.
ios_base::in = 입력 모드로 파일을 연다.
ios_base::out = 출력 모드로 파일을 연다.
ios_base::trunc = 파일을 열고 기존데이터를 삭제한다.

seek() - 입출력 스트림을 임의 위치로 옮길 수 있다. seekg()는 입력스트림에서, seekp()는 출력스트림에서..
두개가 따로 존재하는 이유는 입출력이 동시에 이뤄지면 각각 다른 스트림을 가지고 있어야 하기 때문.

ios_base::streampos = 스트림의 위치
ios_base::streamoff = 스트림의 오프셋
ios_base::beg = 스트림의 시작위치
ios_base::end = 스트림의 마지막위치
ios_base::cur = 스트림의 현재위치

tie() - 스트림 연관 시키기

양방향 IO


*/


#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void rawWrite (const char* data, int dataSize)
{
	cout.write (data, dataSize);
}

void rawPutChar (const char* data, int charIndex)
{
	cout.put (data[charIndex]);
}

/*
string readName(istream& inStream)
{
	string name;
	while (!inStream.fail()) {
		int next = inStream.get();
		if (next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next);// Append character.
	}
	return name;
}
*/

string readName (istream& inStream)
{
	string name;
	char next;
	while (inStream.get (next))
	{
		name += next;
	}

	return name;
}

void getReservationData ()
{
	string guestName;
	int partySize = 0;

	char ch;
	cin >> noskipws;

	//while (cin >> ch)
	//{
	//	if (isdigit (ch))
	//	{
	//		cin.unget ();
	//		if (cin.fail ())
	//			cout << "unget() failed" << endl;
	//		break;
	//	}
	//	guestName += ch;
	//}

	while (true)
	{
		// 'peek' at next character
		ch = static_cast<char>(cin.peek ());
		if (!cin.good ())
			break;
		if (isdigit (ch))
			break;
		
		cin >> ch;
		guestName += ch;
	}
	cin >> partySize;

	cout << "Thank you '" << guestName
		<< "', party of " << partySize << endl;
	if (partySize > 10)
	{
		cout << "An extra gratuity will apply." << endl;
	}
}

class Muffin
{
	public:
	const string& getDescription () const;
	void setDescription (const string& inDesc);

	int getSize () const;
	void setSize (int inSize);

	bool getHasChocolateChips () const;
	void setHasChocolateChips (bool inChips);

	void output ();

	private:
	string mDesc;
	int mSize;
	bool mHasChocolateChips;
};

const string& Muffin::getDescription () const
{
	return mDesc;
}
void Muffin::setDescription (const string& inDesc)
{
	mDesc = inDesc;
}
int Muffin::getSize () const
{
	return mSize;
}
void Muffin::setSize (int inSize)
{
	mSize = inSize;
}
bool Muffin::getHasChocolateChips () const
{
	return mHasChocolateChips;
}
void Muffin::setHasChocolateChips (bool inChips)
{
	mHasChocolateChips = inChips;
}

void Muffin::output ()
{
	printf ("%s, Size is %d, %s\n", getDescription ().c_str (), getSize (),
		(getHasChocolateChips () ? "has chips" : "no chips"));
}

Muffin createMuffin (istringstream& inStream)
{
	Muffin muffin;

	string description;
	int size;
	bool hasChips;

	inStream >> description >> size >> boolalpha >> hasChips;
	muffin.setSize (size);
	muffin.setDescription (description);
	muffin.setHasChocolateChips (hasChips);

	return muffin;
}

bool changeNumberForID (const string& inFileName, int inID,
						const string& inNewNumber)
{
	fstream ioData (inFileName.c_str ());
	if (!ioData)
	{
		cerr << "Error while opening file " << inFileName << endl;
		return false;
	}

	// 파일 마지막까지 루프
	while (ioData.good ())
	{
		int id;
		string number;

		// ID를 읽는다.
		ioData >> id;

		if (id == inID)
		{
			// 현재의 읽기 위치로 쓰기 위치를 이동시킨다.
			ioData.seekp (ioData.tellg ());
			// 공백 문자 하나와 새로운 전화번호를 출력한다.
			ioData << " " << inNewNumber;
			break;
		}

		// 현재 위치에서 전화번호를 읽어서 스트림을 다음 레코드로 ㅇ ㅣ동
		ioData >> number;
	}
	return true;
}

int main (int argc, char* argv[])
{
	
#pragma region Output
	//const char* test = "hello";
	//rawPutChar (test, 1);
	//rawWrite (test, strlen (test));

	//cout << endl;
	//if (cout.good ())
	//	cout << "All good" << endl;

	//cout.flush ();
	//if (cout.fail ())
	//	cerr << "Unable to flush to standard out" << endl;

	//cout.exceptions (ios::failbit | ios::badbit | ios::eofbit);
	//try
	//{
	//	cout << "Hello World." << endl;
	//}
	//catch (const ios_base::failure& ex)
	//{
	//	cerr << "Caught exception: " << ex.what ()
	//		<< ", error code = " << ex.code () << endl;
	//}

	//// 불 타입
	//bool myBool = true;
	//cout << "This is the default: " << myBool << endl;
	//cout << "This should be true: " << boolalpha << myBool << endl;
	//cout << "This should be 1: " << noboolalpha << myBool << endl;

	//// 6개의 공간을 만듦
	//int i = 123;
	//printf ("This should be '   123': %6d\n", i);
	//cout << "This should be '   123': " << setw (6) << i << endl;

	//// 6개에 공간 중 빈 공간을 0으로 채움
	//printf ("This should be '000123': %06d\n", i);
	//cout << "This should be '000123': " << setfill ('0') << setw (6) << i << endl;

	//// *로 채움
	//cout << "This should be '***123': " << setfill ('*') << setw (6) << i << endl;
	//// 빈칸채우기 용 문자 리셋
	//cout << setfill (' ');

	//// 소수점 값
	//cout.precision (5);
	//cout << "This should be '1.2346': " << 1.23456789 << endl;

	//// 부동 소수점 값
	//double dbl = 1.452;
	//double dbl2 = 5;
	//cout << "This should be ' 5': " << setw (2) << noshowpoint << dbl2 << endl;
	//cout << "This should be @@1.452: " << setw (7) << setfill ('@') << dbl << endl;
	//
	//cout << setfill (' ');

	//// 지역(국가)에 맞게 숫자 포맷팅
	//// 로케일 객체
	//cout.imbue (locale (""));
	//cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;

	//// 화폐포맷팅
	//cout << "This should be a money amount of 120000, "
	//	<< "formatted according to your location: "
	//	<< put_money ("120000") << endl;

	//// 시간날짜 포맷팅

	//time_t t_t = time (nullptr);
	//tm t;
	//localtime_s (&t, &t_t);
	//cout << "This should be the current date and time formatted according to your location: "
	//	<< put_time (&t, "%c") << endl;

	//// C++14: 따옴표로 둘러쌓인 문자열
	//cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
	//	<< quoted ("Quoted string with \"embedded quotes\".") << endl;
#pragma endregion

#pragma region Input
	//string theName = readName (cin);
	//cout << "The name is \"" << theName << "\"" << endl;

	// get & unget
	//getReservationData ();
	
	//string mystring;
	//getline (cin, mystring);
	///////
	//cout << "Enter numbers on separate lines to add. "
	//	<< "Use Control+D to finish (Control+Z in Windows)." << endl;
	//int sum = 0;


	//if (!cin.good ())
	//{
	//	cerr << "Standard input is in a bad state!" << endl;
	//	return 1;
	//}

	//int number;
	//while (!cin.bad ())
	//{
	//	cin >> number;
	//	if (cin.good ())
	//	{
	//		sum += number;
	//	}
	//	else if (cin.eof ())
	//	{
	//		break;
	//	}
	//	else if (cin.fail ())
	//	{
	//		cin.clear (); // 에러 상태 클리어
	//		string badToken;
	//		cin >> badToken; // 잘못된 데이터를 꺼냄
	//		cerr << "WARNING: Bad input encountered: " << badToken << endl;
	//	}
	//}
	//cout << "The sum is " << sum << endl;

	///////
	//cout << "First, let's create a muffin in code and output it." << endl;

	//Muffin m;
	//m.setDescription ("Giant_Blueberry_Muffin");
	//m.setSize (42);
	//m.setHasChocolateChips (false);

	//m.output ();

	//cout << "Now we'll create a muffin from a string stream" << endl;

	//istringstream instream ("My_Muffin 2 true");
	//Muffin m2 = createMuffin (instream);

	//m2.output ();

#pragma endregion

#pragma region FileIO
	//ofstream outFile ("test.txt", ios_base::trunc);
	//if (!outFile.good ())
	//{
	//	cerr << "Error while opening output file!" << endl;
	//	return -1;
	//}
	//outFile << "There were " << argc << " arguments to this program." << endl;
	//outFile << "They are: " << endl;
	//for (int i = 0; i < argc; i++)
	//{
	//	outFile << argv[i] << endl;
	//}

	//ofstream fout ("test.out");
	//if (!fout)
	//{
	//	cerr << "Error opening test.out for writing" << endl;
	//	return 1;
	//}

	//// 1. 파일에 12345 출력
	//fout << "12345";

	//// 2. 스트림의 위치가 5인지 체크
	//ios_base::streampos curPos = fout.tellp ();
	//if (5 == curPos)
	//{
	//	cout << "Test passed: Currently at position 5" << endl;
	//}
	//else
	//{
	//	cout << "Test failed: Not at position 5" << endl;
	//}

	//// 3. 시작위치에서 출력스트림 위치를 2옮김
	//fout.seekp (2, ios_base::beg);

	//// 4. 위치 2에 0을 출력하고 스트림 닫음
	//fout << 0;
	//fout.close ();

	//// 5. out파일을 입력스트림으로 연다
	//ifstream fin ("test.out");
	//if (!fin)
	//{
	//	cerr << "Error opening test.out for reading" << endl;
	//	return 1;
	//}

	//// 6. 첫째 토큰을 int 값으로 가져옮
	//int testVal;
	//fin >> testVal;

	//// 7. 값 체크
	//const int expected = 12045;
	//if (testVal == expected)
	//{
	//	cout << "Test passed: Value is " << expected << endl;
	//}
	//else
	//{
	//	cout << "Test failed: Value is not " << expected
	//		<< "(it was " << testVal << ")" << endl;
	//}

	ifstream inFile ("input.txt");  
	ofstream outFile ("output.txt");
	// input ouput 연관시키기
	inFile.tie (&outFile);
	
	outFile << "Hello there!";
	
	string nextToken;
	inFile >> nextToken;

	changeNumberForID ("data.txt", 263, "415-555-454");

	return 0;
#pragma endregion

}
