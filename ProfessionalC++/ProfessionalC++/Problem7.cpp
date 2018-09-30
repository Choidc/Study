//#include<iostream> 
//#include<string>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//
//}
//
//
//void one()
//{
//	char a;
//	cin >> a;
//
//	cout << (int)a << endl;
//}
//
//void two()
//{
//	string text;
//	cin >> text;
//
//	for (char a = 'a'; a <= 'z'; a++)
//	{
//		int count = text.find(a);
//		cout << count << " ";
//	}
//}
//
//void three()
//{
//	int count;
//	cin >> count;
//
//	vector<int> R(count);
//	vector<string> S(count);
//
//	for (int i = 0; i < count; i++)
//	{
//		cin >> R[i];
//		cin >> S[i];
//	}
//
//	for (int i = 0; i < count; i++)
//	{
//		for (int s = 0; s < S[i].size(); s++)
//		{
//			for (int r = 0; r < R[i]; r++)
//			{
//				cout << S[i][s];
//			}
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void four()
//{
//	// 오류 남 수정해야됌
//
//	string text;
//	cin >> text;
//
//	int arr['z' - 'a' + 1] = { 0 };
//	for (int i = 0; i < text.size(); i++)
//	{
//		for (int a = 0; a <= 'z' - 'A'; a++)
//		{
//			if (text[i] - 'A' == a % 26)
//			{
//				arr[a % 26]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < 26; i++) {
//		cout << arr[i];
//	}
//}
//
//void five()
//{
//	int num;
//	cin >> num;
//
//	int count = 0;
//	cin.ignore();
//	for (int i = 0; i < num; i++)
//	{
//		string text;
//		getline(cin, text);
//
//		bool arr[26] = { false };
//		bool flag = false;
//		arr[text[0] - 'a'] = 1;
//		for (int j = 1; j < text.size(); j++)
//		{
//			int cur = text.at(j) - 'a';
//			int prv = text.at(j - 1) - 'a';
//			if (arr[cur] && cur != prv)
//				flag = true;
//			arr[cur] = true;
//		}
//		if (flag == false)
//			count++;
//	}
//
//	cout << count;
//}
//
//int Convert(int);
//
//void seven()
//{
//	int num1, num2;
//
//	cin >> num1 >> num2;
//
//	int new1 = Convert(num1);
//	int new2 = Convert(num2);
//
//	if (new1 > new2)
//		cout << new1;
//	else
//		cout << new2;
//}
//
//int Convert(int num)
//{
//	int num0, num10, num100;
//	num0 = num % 10;
//	num10 = num % 100 - num0;
//	num100 = num % 1000 - num10;
//
//	return num0 * 100 + num10 + num100 / 100;
//}
