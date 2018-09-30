#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main()
{

}

void one()
{
	int count;
	cin >> count;

	for (int i = 1; i <= count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}


void two()
{
	int num;
	int count = 0;
	cin >> num;

	if (num != 1)
	{
		num -= 1;
		while (num > 0)
		{
			num -= (6 * count);
			count++;
		}

		cout << count;
	}
	else
	{
		cout << num;
	}
}

void three()
{
	int count, num;
	cin >> count;

	int sum = 1;		// 분자, 분모의 합
	while (count > 0)
	{
		count -= sum;
		sum++;
	}

	num = count + sum - 1; // 합 그룹 중 순서 

	int numerator;		// 분자
	int denominator;	// 분모

	if (sum % 2 == 0) // 분자가 큰값으로 시작
	{
		numerator = sum - num;
		denominator = num;
	}
	else
	{
		numerator = num;
		denominator = sum - num;
	}

	cout << numerator << "/" << denominator;
}

void five()
{
	int count;
	cin >> count;
	vector<int> height(count), witdh(count), number(count);

	for (int i = 0; i < count; i++)
	{
		cin >> height[i] >> witdh[i] >> number[i];
	}

	for (int i = 0; i < count; i++)
	{

		int YY, XX;
		YY = number[i] % height[i];
		if (YY == 0)
			YY = height[i];	// 나머지가 0일 경우는 없기 때문
		XX = (number[i] - 1) / height[i] + 1;

		if (XX > 10)
			cout << YY << XX << endl;
		else
			cout << YY << setfill('0') << setw(2) << XX << endl;
	}
}

void six()
{
	int month, day;
	int count = 0;
	cin >> month;
	cin >> day;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 0; i < month - 1; i++)
	{
		count += arr[i];
	}
	count += day;
	count = count % 7;
	switch (count)
	{
	case 1: cout << "MON"; break;
	case 2: cout << "TUE"; break;
	case 3: cout << "WED"; break;
	case 4: cout << "THU"; break;
	case 5: cout << "FRI"; break;
	case 6: cout << "SAT"; break;
	case 0: cout << "SUN"; break;
	}
}

void seven()
{
	int arr[15][14];

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i > 0 && j > 0)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			else
				arr[i][j] = j + j * i + 1;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	int testcase;
	cin >> testcase;

	vector<int>k(testcase), n(testcase);

	for (int i = 0; i < testcase; i++)
	{
		cin >> k[i];
		cin >> n[i];
	}

	for (int i = 0; i < testcase; i++)
	{
		cout << arr[k[i]][n[i] - 1] << endl;
	}
}

void eight()
{
	string num;
	cin >> num;

	int arr[10] = { 0 };

	for (int i = 0; i < num.size(); i++)
	{
		arr[num.at(i) - '0']++;
	}

	arr[6] = (arr[6] + arr[9] + 1) / 2;

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			continue;

		if (arr[i] > max)
			max = arr[i];
	}

	cout << max;
}
