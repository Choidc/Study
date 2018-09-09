#include<iostream>
using namespace std;

int main()
{
	int arr[5];
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		if (arr[i] < 40)
		{
			arr[i] = 40;
		}
		total += arr[i];
	}
	
	cout << total / 5 << endl;
}


//http://www.cplusplus.com/reference/string/string/

// Problem 6_1
//int main()
//{
//	string text;
//	int count = 1;
//	getline(cin, text);
//
//	if (text.length() > 1000000)
//		return 0;
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		if (text.at(i) == ' ')
//			count++;
//	}
//
//	if (text.at(0) == ' ')
//		count--;
//
//	if (text.at(text.length() - 1) == ' ')
//		count--;
//
//	cout << count << endl;
//}

// Problem 6_2
//int main()
//{
//	unsigned int a, b, c;
//	int arr[10] = { 0, };
//
//	cin >> a >> b >> c;
//
//	int total = a * b * c;
//	while (total != 0)
//	{
//		int mod = total % 10;
//		arr[mod]++;
//		total /= 10;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << endl;
//	}
//}

// Problem6_3
//int main()
//{
//	int count;
//	cin >> count;
//	cin.ignore();
//	vector<string> text(count);
//	for (string& string : text)
//	{
//		getline(cin, string);
//	}
//
//	int totalscore = 0;
//	int score = 0;
//	for (string& string : text)
//	{
//		for (int i = 0; i < string.length(); i++)
//		{
//			if (string.at(i) == 'O')
//			{
//				score++;
//				totalscore += score;
//			}
//			else if (string.at(i) == 'X')
//			{
//				score = 0;
//			}
//		}
//		cout << totalscore << endl;
//		totalscore = 0;
//		score = 0;
//	}
//}

// Problem 6_4
//int main()
//{
//	int arr[8];
//	for (int i = 0; i < 8; i++)
//		cin >> arr[i];
//
//	if (arr[0] == 1)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (arr[i] + 1 != arr[i + 1])
//			{
//				cout << "mixed" << endl;
//				return 0;
//			}
//		}
//		cout << "ascending" << endl;
//		return 0;
//	}
//	else if (arr[0] == 8)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (arr[i] - 1 != arr[i + 1])
//			{
//				cout << "mixed" << endl;
//				return 0;
//			}
//		}
//		cout << "descending" << endl;
//		return 0;
//	}
//	else
//	{
//		cout << "mixed" << endl;
//		return 0;
//	}
//}


// Problem 6_5
//int main()
//{
//	int arr[5];
//	int total = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> arr[i];
//		if (arr[i] < 40)
//		{
//			arr[i] = 40;
//		}
//		total += arr[i];
//	}
//	
//	cout << total / 5 << endl;
//}
