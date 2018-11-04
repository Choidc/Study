/*
����¿� ���� �˾ƺ���.
C���� printf, scanf�� �Ͽ��µ� �̴� ����ó���� �Ϻ����� �ʰ�, Ŀ���� ������ Ÿ���� �ٷ� �� ����, ��ü������� �Ÿ��� �ִ�.
C++���� ��Ʈ���̶� �Ҹ��� �����ϸ鼭�� ��ü �������� I/O�ý����� �����Ѵ�.

1. ��Ʈ��
cout �� ��� ��Ʈ�� console + out ���� �ֿܼ��� ������ ���� �۾��� �Ѵ�.
cin �� �Է� ��Ʈ�� console + in ���� �ܼ��� �Է� �ҽ��� �Ͽ� �����͸� �д´�. 
cerr ���۰� ���� ��� ��Ʈ������ ���� �ֿܼ� ����. clog ���۸� ���� cerr ��Ʈ���̴�.
�ΰ� ��� std ���ӽ����̽����� ���� �Ǿ� �ִ�.
GUI�� ����ϴ� ���α׷��� �ܼ��� ���� ��찡 ���Ƽ� ������ص� ����ڰ� �� �� ����.
���� cout, cin, cerr, clog �� ����Ͽ� �ֿܼ� ������ �� �ִٰ� �����ϸ� �ȵȴ�.
��Ʈ���� �߿��� ���� ��Ʈ���� �����͸� ���� �� �ƴ϶� ���� ��ġ(�а� ���⸦ �۾��� ��ġ)�� ������.

��Ʈ���� ������ �����͸� �ްų� �����ϴ� ��� ��ü�� ������ �� �ִ�. 
�ܼ� �Է� ��Ʈ���� ��Ÿ�ӿ� �Է��� ���� �� �ְ��Ͽ� ���α׷��� ���ͷ�Ƽ���ϰ� ����� �ְ�, �ܼ� ��� ��Ʈ���� �� ����� ����Ѵ�.
���� ��Ʈ���� ���� �ý��ۿ��� �����͸� �аų�, ���� �ý��ۿ� �����͸� ����Ѵ�.
���ڿ� ��Ʈ���� ���ڿ��� �Ϲ� ��Ʈ�� ó�� ����ϴ� ���̴�.

< ��� >
- ��Ʈ�� ���
ostream ����� ���� �Ǿ� ������ iostream���� �ѹ��� ��Ŭ��� �Ѵ�.
<< �����ڸ� �̿��Ͽ� �⺻ ���� Ÿ���� << �� ����� �� �ִ�.
C��Ÿ���� �̽������� �������� ���������� endl �� �ٶ����ϴ�. - �� �ٲ� �� �ƴ϶� ��� ���۸� �о�� ���ҵ� �Ѵ�. ������ ��� ����ȭ�� �����Ͽ� ���ɿ� �ǿ����� �ش�.
ostream �� �پ��� << �����ڰ� �����ε� �Ǿ� �ִ�.

- ��½�Ʈ�� �޼���
put - << ������ ��� ���ڸ� �޾� ���
write - << ������ ��� ���ڿ��� �޾� ���
flush -  ��� ��Ʈ���� ���۸� ������ �־� ȿ���� ���� ��Ҵٰ� ������ ������ �ѹ��� ���
(����) 1. endl ���� Ư���� ��Ŀ, 2. ��Ʈ�� ��ü�� �������� ����� �Ҹ�, 3. ������ �Է� ��Ʈ������ �Է�, 4. ��Ʈ�� ���۰� ���� á�� ��, 5. ��Ʈ���� ��������� ������ �������� ��� �� ��

- ���� �޽��� ���
good - �������� �������� Ȯ���ϴ� ��� (������ ������, ���� ������ ��������)
bad - true�� �����ϸ� fatal error�� �߻��ߴ�.
fail - true�� �����ϸ� �ֱ� �۾��� �����߰�, ������ �����Ұ�
ios_base::failure exception - what, code �޼��带 ���� ����� �ڵ尪�� ������ �� �ִ�.
clear - ��Ʈ�� ���� ���� ����

- ��� ��Ʈ�� �Ŵ�ǽ������
boolalpha, noboolalpha - ��Ʈ���� bool Ÿ�� ���� ����Ҷ� T/F����(boolalpha) 1/0����(noboolalpha) (����Ʈ�� 1/0)
hex, oct, dec - 16, 8, 10 ���� ����
setprecision - ����� �Ҽ��� ���� �ڸ���
setw - ���� ����� ���� �ڸ��� ũ��
setfill - ���� ����� ���� ������ �ڸ� �� ���� ���� �� �� ������ ä�� ���� ����
showpoint, noshowpoint - ���ڸ� ����� �� �Ҽ����� �Ҽ��� ���ϸ� ǥ��/��ǥ��
put_money - ȭ�� ������
put_time - �ð� ������
quoted - �Է¹��� ���ڿ��� ����ǥ�� �ѷ��μ� ��Ʈ������ ����
*/

/*
< �Է� >
- ��Ʈ�� �Է�
�Ϲ� ������ �� ����ȭ�� �����ͱ��� �Է� ���� �� �ִ�.
>> ������ - ���鹮�ڸ� �����ڷ��Ͽ� �Է°����� ��ūȭ(����ȭ) �Ѵ�.

- �Է� �޼���
get - ��Ʈ�����κ��� �ο� �����͸� ���� ���ֵ��� �Ѵ�. ���ڸ� �ϳ��� ���� / ���ÿ� ���� �ϴ� ���� ������ �����ȴ�.
unget - �̹� �о���� ���� �ϳ��� ��Ʈ���� �ǵ��� ���´�.
putback - �о���� ���� �ϳ��� �������°� (��Ʈ���� �ǵ��� ���°�) �� �߰��� �Ķ���ͷ� ������ ����
peek - get�� ������ �������� �ʰ� �̸� Ȯ���� ��
getline - �� �� ������ ���ڿ� �����͸� �д´�. ���ڿ� �� �����ʹ� �������� �ʴ´� eol

- ����ó�� ���
good(), bad(), fail() �޼���� ���°˻�, eof() �޼���� ��Ʈ���� ���� ������ ��� true

- �Է� ��Ʈ�� �Ŵ�ǽ������
boolalpha, noboolalpha - ���ڿ� false�� bool false��, �������� true (boolalpha) ���� 0 �� ��� (noboolalpha)
hex, oct, dec - 16 8 10 ����
skipws, noskipws - skipws �Է� ���ڿ��� ��ūȰ �Ҷ� ���� ����, noskipws�� ���� ���� ws = white space
ws - ���� ��ġ�� ���� ������ ���鹮�� ����
get_money - ȭ��ݾ����� ����
get_time - �ð����� ����
quoted - ����ǥ�� �ѷ����� ���ڿ��� �Է� ���� 

- ���ڿ� ��Ʈ��
���ڿ� ��Ʈ���� ����ϸ� string ��ü�� ��Ʈ�� ���信 ����
ostringstream, istringstream = sstream ���� ����
+= �����ڸ� �̿��ϴ� �ͺ��� ���ڿ� ��Ʈ���� �̿��ϴ°� �� ȿ����

- ���� ��Ʈ��
������ �а� ���� �۾��� ���� ��ġ�� �����Ͽ� ��Ʈ�� ȭ �ϱ⿡ �����ϴ�
ofstream, ifstream = fstream �� ����
ios_base::app = ������ �� ���� ���� �۾��� ���۵Ǳ� ���� ��Ʈ���� ��ġ�� ���� ���� ������ �ű�
ios_base::ate = ������ ���ڸ��� ��Ʈ���� ��ġ�� ������ ���� ������ �ű�
ios_base::binary = ���̳ʸ� ���� ������ ������� �Ѵ�.
ios_base::in = �Է� ���� ������ ����.
ios_base::out = ��� ���� ������ ����.
ios_base::trunc = ������ ���� ���������͸� �����Ѵ�.

seek() - ����� ��Ʈ���� ���� ��ġ�� �ű� �� �ִ�. seekg()�� �Է½�Ʈ������, seekp()�� ��½�Ʈ������..
�ΰ��� ���� �����ϴ� ������ ������� ���ÿ� �̷����� ���� �ٸ� ��Ʈ���� ������ �־�� �ϱ� ����.

ios_base::streampos = ��Ʈ���� ��ġ
ios_base::streamoff = ��Ʈ���� ������
ios_base::beg = ��Ʈ���� ������ġ
ios_base::end = ��Ʈ���� ��������ġ
ios_base::cur = ��Ʈ���� ������ġ

tie() - ��Ʈ�� ���� ��Ű��

����� IO


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

	// ���� ���������� ����
	while (ioData.good ())
	{
		int id;
		string number;

		// ID�� �д´�.
		ioData >> id;

		if (id == inID)
		{
			// ������ �б� ��ġ�� ���� ��ġ�� �̵���Ų��.
			ioData.seekp (ioData.tellg ());
			// ���� ���� �ϳ��� ���ο� ��ȭ��ȣ�� ����Ѵ�.
			ioData << " " << inNewNumber;
			break;
		}

		// ���� ��ġ���� ��ȭ��ȣ�� �о ��Ʈ���� ���� ���ڵ�� �� �ӵ�
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

	//// �� Ÿ��
	//bool myBool = true;
	//cout << "This is the default: " << myBool << endl;
	//cout << "This should be true: " << boolalpha << myBool << endl;
	//cout << "This should be 1: " << noboolalpha << myBool << endl;

	//// 6���� ������ ����
	//int i = 123;
	//printf ("This should be '   123': %6d\n", i);
	//cout << "This should be '   123': " << setw (6) << i << endl;

	//// 6���� ���� �� �� ������ 0���� ä��
	//printf ("This should be '000123': %06d\n", i);
	//cout << "This should be '000123': " << setfill ('0') << setw (6) << i << endl;

	//// *�� ä��
	//cout << "This should be '***123': " << setfill ('*') << setw (6) << i << endl;
	//// ��ĭä��� �� ���� ����
	//cout << setfill (' ');

	//// �Ҽ��� ��
	//cout.precision (5);
	//cout << "This should be '1.2346': " << 1.23456789 << endl;

	//// �ε� �Ҽ��� ��
	//double dbl = 1.452;
	//double dbl2 = 5;
	//cout << "This should be ' 5': " << setw (2) << noshowpoint << dbl2 << endl;
	//cout << "This should be @@1.452: " << setw (7) << setfill ('@') << dbl << endl;
	//
	//cout << setfill (' ');

	//// ����(����)�� �°� ���� ������
	//// ������ ��ü
	//cout.imbue (locale (""));
	//cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;

	//// ȭ��������
	//cout << "This should be a money amount of 120000, "
	//	<< "formatted according to your location: "
	//	<< put_money ("120000") << endl;

	//// �ð���¥ ������

	//time_t t_t = time (nullptr);
	//tm t;
	//localtime_s (&t, &t_t);
	//cout << "This should be the current date and time formatted according to your location: "
	//	<< put_time (&t, "%c") << endl;

	//// C++14: ����ǥ�� �ѷ����� ���ڿ�
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
	//		cin.clear (); // ���� ���� Ŭ����
	//		string badToken;
	//		cin >> badToken; // �߸��� �����͸� ����
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

	//// 1. ���Ͽ� 12345 ���
	//fout << "12345";

	//// 2. ��Ʈ���� ��ġ�� 5���� üũ
	//ios_base::streampos curPos = fout.tellp ();
	//if (5 == curPos)
	//{
	//	cout << "Test passed: Currently at position 5" << endl;
	//}
	//else
	//{
	//	cout << "Test failed: Not at position 5" << endl;
	//}

	//// 3. ������ġ���� ��½�Ʈ�� ��ġ�� 2�ű�
	//fout.seekp (2, ios_base::beg);

	//// 4. ��ġ 2�� 0�� ����ϰ� ��Ʈ�� ����
	//fout << 0;
	//fout.close ();

	//// 5. out������ �Է½�Ʈ������ ����
	//ifstream fin ("test.out");
	//if (!fin)
	//{
	//	cerr << "Error opening test.out for reading" << endl;
	//	return 1;
	//}

	//// 6. ù° ��ū�� int ������ ������
	//int testVal;
	//fin >> testVal;

	//// 7. �� üũ
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
	// input ouput ������Ű��
	inFile.tie (&outFile);
	
	outFile << "Hello there!";
	
	string nextToken;
	inFile >> nextToken;

	changeNumberForID ("data.txt", 263, "415-555-454");

	return 0;
#pragma endregion

}
