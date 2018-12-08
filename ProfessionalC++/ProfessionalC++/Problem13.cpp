//#include <iostream>
//#include <deque>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main ()
//{
//	int count;
//	cin >> count;
//
//	bool error = false;
//
//	for (int i = 0; i < count; i++)
//	{
//		string func, numArr, stringToNum;
//		int num;
//		bool reverse = false;
//		deque<int> intDeque;
//
//		cin >> func >> num >> numArr;
//
//		for (int j = 0; j < numArr.size (); j++)
//		{
//			if (numArr.at (j) >= '0' && numArr.at (j) <= '9')
//				stringToNum += numArr.at (j);
//			else
//			{
//				if (numArr.at (j) == ',' || numArr.at (j) == ']')
//					intDeque.push_back (atoi (stringToNum.c_str ()));
//				stringToNum.clear ();
//			}
//		}
//
//		for (int j = 0; j < func.size (); j++)
//		{
//			if (func.at (j) == 'R')
//			{
//				reverse = !reverse;
//				if (num == 0)
//				{
//					error = true;
//					cout << "[]" << endl;
//					break;
//				}
//			}
//			else if (func.at (j) == 'D')
//			{
//				if (intDeque.empty () || num == 0 )
//				{
//					error = true;
//					cout << "error" << endl;
//					break;
//				}
//				else
//				{
//					if (reverse == true)
//						intDeque.pop_back ();
//					else
//						intDeque.pop_front ();
//				}
//			}
//		}
//
//		if (!error)
//		{
//			cout << "[";
//			while (!intDeque.empty ())
//			{
//				if (reverse)
//				{
//					if (intDeque.size () == 1)
//						cout << intDeque.back ();
//					else
//						cout << intDeque.back () << ",";
//					intDeque.pop_back ();
//				}
//				else
//				{
//					if (intDeque.size () == 1)
//						cout << intDeque.front ();
//					else
//						cout << intDeque.front () << ",";
//					intDeque.pop_front ();
//				}
//			}
//			cout << "]" << endl;
//		}
//	}
//}
//
//void One()
//{
//	int count;
//	cin >> count;
//
//	deque<int> intDeque;
//	vector<int> result;
//
//	for (int i = 0; i < count; i++)
//	{
//		string text;
//		cin >> text;
//
//		if (text.compare ("push_front") == 0)
//		{
//			int number;
//			cin >> number;
//			intDeque.push_front (number);
//		}
//		else if (text.compare ("push_back") == 0)
//		{
//			int number;
//			cin >> number;
//			intDeque.push_back (number);
//		}
//		else if (text.compare ("pop_front") == 0)
//		{
//			if (intDeque.empty ())
//			{
//				result.push_back (-1);
//			}
//			else
//			{
//				result.push_back (intDeque.front ());
//				intDeque.pop_front ();
//			}
//		}
//		else if (text.compare ("pop_back") == 0)
//		{
//			if (intDeque.empty ())
//			{
//				result.push_back (-1);
//			}
//			else
//			{
//				result.push_back (intDeque.back ());
//				intDeque.pop_back ();
//			}
//		}
//		else if (text.compare ("size") == 0)
//		{
//			result.push_back (intDeque.size ());
//		}
//		else if (text.compare ("empty") == 0)
//		{
//			if (intDeque.empty ())
//				result.push_back (1);
//			else
//				result.push_back (0);
//		}
//		else if (text.compare ("front") == 0)
//		{
//			if (intDeque.empty ())
//				result.push_back (-1);
//			else
//				result.push_back (intDeque.front ());
//		}
//		else if (text.compare ("back") == 0)
//		{
//			if (intDeque.empty ())
//				result.push_back (-1);
//			else
//				result.push_back (intDeque.back ());
//		}
//	}
//
//	for (auto i : result)
//	{
//		printf ("%d\n", i);
//	}
//}
//
//void Two ()
//{
//	int size, count;
//	deque<int> intDeque;
//
//	cin >> size;
//	cin >> count;
//
//	for (int i = 1; i <= size; i++)
//		intDeque.push_back (i);
//
//	int result = 0;
//	for (int i = 0; i < count; i++)
//	{
//		int num;
//		cin >> num;
//
//		int current = 1;
//		for (auto iter = intDeque.begin (); iter < intDeque.end (); iter++)
//		{
//			if (*iter != num)
//				current++;
//			else
//				break;
//		}
//
//		int left = current - 1;
//		int right = intDeque.size () - current + 1;
//
//		if (left < right)
//		{
//			for (int j = 1; j <= left; j++)
//			{
//				intDeque.push_back (intDeque.front ());
//				intDeque.pop_front ();
//				result++;
//			}
//			intDeque.pop_front ();
//		}
//		else
//		{
//			for (int j = 1; j <= right; j++)
//			{
//				intDeque.push_front (intDeque.back ());
//				intDeque.pop_back ();
//				result++;
//			}
//			intDeque.pop_front ();
//		}
//	}
//	cout << result << endl;
//}