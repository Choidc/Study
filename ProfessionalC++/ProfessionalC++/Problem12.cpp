//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//
//void One ()
//{
//	int count;
//	cin >> count;
//
//	queue<int> intQueue;
//	vector<int> result;
//
//	for (int i = 0; i < count; i++)
//	{
//		string text;
//		cin >> text;
//
//		if (text.compare ("push") == 0)
//		{
//			int number;
//			cin >> number;
//			intQueue.push (number);
//		}
//		else if (text.compare ("pop") == 0)
//		{
//			if (intQueue.empty ())
//			{
//				result.push_back (-1);
//			}
//			else
//			{
//				result.push_back (intQueue.front ());
//				intQueue.pop ();
//			}
//		}
//		else if (text.compare ("size") == 0)
//		{
//			result.push_back (intQueue.size ());
//		}
//		else if (text.compare ("empty") == 0)
//		{
//			if (intQueue.empty ())
//				result.push_back (1);
//			else
//				result.push_back (0);
//		}
//		else if (text.compare ("front") == 0)
//		{
//			if (intQueue.empty ())
//				result.push_back (-1);
//			else
//				result.push_back (intQueue.front ());
//		}
//		else if (text.compare ("back") == 0)
//		{
//			if (intQueue.empty ())
//				result.push_back (-1);
//			else
//				result.push_back (intQueue.back ());
//		}
//	}
//
//	for (auto i : result)
//	{
//		printf ("%d\n", i);
//	}
//}
//
//
//void Three ()
//{
//	int test;
//	cin >> test;
//
//	vector<int> result;
//	for (int i = 0; i < test; i++)
//	{
//		queue<pair<int, int>> intQueue;
//		priority_queue<int> intpQueue;
//
//		int N; int M;
//
//		cin >> N >> M;
//		for (int i = 0; i < N; i++)
//		{
//			int input;
//			cin >> input;
//			intQueue.push ({i, input});
//			intpQueue.push (input);
//		}
//
//		int count = 0;
//		while (!intQueue.empty ())
//		{
//			auto value = intQueue.front ();
//			if (intpQueue.top () == value.second)
//			{
//				intpQueue.pop ();
//				count++;
//				if (value.first == M)
//				{
//					result.push_back (count);
//					break;
//				}
//			}
//			else
//			{
//				intQueue.push (value);
//			}
//			intQueue.pop ();
//		}
//	}
//
//	for (auto i : result)
//	{
//		printf ("%d\n", i);
//	}
//}
//
//void FourFive ()
//{
//	int N, M;
//	cin >> N >> M;
//
//	queue<int> intQueue;
//	vector<int> result;
//
//	for (int i = 1; i <= N; i++)
//	{
//		intQueue.push (i);
//	}
//
//	while (!intQueue.empty ())
//	{
//		for (int i = 0; i < M - 1; i++)
//		{
//			intQueue.push (intQueue.front ());
//			intQueue.pop ();
//		}
//		result.push_back (intQueue.front ());
//		intQueue.pop ();
//	}
//
//	cout << "<";
//	for (int i = 0; i < result.size (); i++)
//	{
//		if (i == result.size () - 1)
//			cout << result.at (i);
//		else
//			cout << result.at (i) << ", ";
//	}
//	cout << ">";
//}