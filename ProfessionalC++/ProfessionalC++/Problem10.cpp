//#include <iostream>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//bool eratosthenes (int n)
//{
//	if (n < 2)
//		return false;
//
//	int i;
//	for (i = 2; i * i <= n; i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	if (i * i > n)
//		return true;
//}
//
//vector<int> goldbach (int num)
//{
//	vector<int> temp (0);
//
//	if (num % 2 != 0)
//		return temp;
//
//	int mid = num / 2;
//	int low, high;
//	for (int low = high = mid; low <= mid; low--, high++)
//	{
//		if (eratosthenes(low) && eratosthenes(high))
//		{
//			temp.push_back (low);
//			temp.push_back (high);
//			return temp;
//		}
//	}
//}
//
//int main ()
//{
//	int count, num;
//	cin >> count;
//	vector<int> numList;
//	for (int i = 0; i < count; i++)
//	{
//		cin >> num;
//		numList.push_back (num);
//	}
//
//	for (int i = 0; i < numList.size (); i++)
//	{
//		auto list = goldbach (numList.at (i));
//		for (auto i : list)
//			cout << i << " ";
//		cout << endl;
//	}
//}
//
//
//bool primeNumber (unsigned int num)
//{
//	if (num < 2)
//		return false;
//
//	for (int i = 2; i < num; i++)
//	{
//		if (num % i == 0)
//			return false;
//	}
//	return true;
//}
//
//void one ()
//{
//	int count, num;
//	vector<int> number;
//
//	cin >> count;
//	for (int i = 0; i < count; i++)
//	{
//		cin >> num;
//		number.push_back (num);
//	}
//
//	vector<int> primeNumberList;
//	for (int i = 0; i < number.size (); i++)
//	{
//		if (primeNumber (number.at (i)))
//			primeNumberList.push_back (number.at (i));
//	}
//
//	cout << primeNumberList.size ();
//}
//
//void two ()
//{
//	int min, max;
//	cin >> min;
//	cin >> max;
//
//	vector<int> primeNumberList;
//	for (int i = min; i <= max; i++)
//	{
//		if (primeNumber (i))
//			primeNumberList.push_back (i);
//	}
//
//	int sum = 0;
//	int last = -1;
//	for (int i = 0; i < primeNumberList.size (); i++)
//	{
//		sum += primeNumberList.at (i);
//		last = primeNumberList.at (0);
//	}
//
//	if (sum != 0)
//		cout << sum << endl << last;
//	else
//		cout << last;
//}
//
//// https://namu.wiki/w/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98%20%EC%B2%B4
//
//void three_timeOver ()
//{
//	int min, max;
//
//	cin >> min >> max;
//
//	bool num[1000001];
//	for (int i = 2; i <= max; i++)
//	{
//		num[i] = true;
//	}
//
//	num[0] = false;
//	num[1] = false;
//
//	for (int i = 2; i*i <= max; i++)
//	{
//		if (num[i] == true)
//			for (int j = i * i; j <= max; j += i)
//				num[j] = false;
//	}
//
//	for (int i = min; i <= max; i++)
//	{
//		if (num[i] == true)
//			cout << i << endl;
//	}
//}
//
//void three ()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = m; i <= n; i++)
//	{
//		if (eratosthenes (i) == 1)
//			printf ("%d\n", i);
//	}
//}
//
//void four ()
//{
//	int count;
//	cin >> count;
//	vector<int> arr;
//	while (count > 0)
//	{
//		int total = 0;
//		for (int i = count + 1; i <= count * 2; i++)
//		{
//			if (eratosthenes (i) == 1)
//				total++;
//		}
//		arr.push_back (total);
//		cin >> count;
//	}
//
//	for (int i = 0; i < arr.size (); i++)
//	{
//		cout << arr.at (i) << endl;
//	}
//}