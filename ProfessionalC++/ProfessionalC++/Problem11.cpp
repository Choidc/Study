#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

void one ()
{
	// Memory 1992kb  Time 332ms	== cout
	// Memory 1992kb  Time 4ms		== printf

	int count;
	cin >> count;

	stack<int> intStack;
	vector<int> result;
	// Not work Switch Case...

	for (int i = 0; i < count; i++)
	{
		string text;
		cin >> text;

		if (text.compare ("push") == 0)
		{
			int number;
			cin >> number;
			intStack.push (number);
		}
		else if (text.compare ("pop") == 0)
		{
			if (intStack.empty ())
			{
				result.push_back (-1);
			}
			else
			{
				result.push_back (intStack.top ());
				intStack.pop ();
			}
		}
		else if (text.compare ("size") == 0)
		{
			result.push_back (intStack.size ());
		}
		else if (text.compare ("empty") == 0)
		{
			if (intStack.empty ())
				result.push_back (1);
			else
				result.push_back (0);
		}
		else if (text.compare ("top") == 0)
		{
			if (intStack.empty ())
				result.push_back (-1);
			else
				result.push_back (intStack.top ());
		}
	}

	for (auto i : result)
	{
		printf ("%d\n", i);
	}
}

void two ()
{
	// Strange Example
	// Fucking Example

	int count;
	cin >> count;

	queue<int> intQueue;
	stack<int> intStack;
	vector<string> result;
	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;
		intQueue.push (num);
	}

	int temp = 1;
	while (intQueue.size ())
	{
		int num = intQueue.front ();

		if (intStack.empty () || num > intStack.top ())
		{
			intStack.push (temp++);
			result.push_back ("+");
		}
		else if (num == intStack.top ())
		{
			intQueue.pop ();
			intStack.pop ();
			result.push_back ("-");
		}
		else if (num < intStack.top ())
		{
			result.clear ();
			result.push_back ("No");
			break;
		}
	}

	for (auto i : result)
	{
		printf ("%s\n", i.c_str ());
	}
}

bool CheckStack (string text)
{
	stack<char> charStack;
	for (int i = 0; i < text.length (); i++)
	{
		char c = text.at (i);
		if (c == '(')
			charStack.push (text.at (i));
		else
		{
			if (!charStack.empty ())
				charStack.pop ();
			else
				return false;
		}
	}
	return charStack.empty ();
}

void three ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0); //cin speedUp

	int count;
	cin >> count;
	vector<string> result;
	for (int i = 0; i < count; i++)
	{
		string text;
		cin >> text;

		if (CheckStack (text))
			result.push_back ("YES");
		else
			result.push_back ("NO");
	}

	for (auto i : result)
	{
		printf ("%s\n", i.c_str ());
	}
}


int CalculateStack (string text)
{
	stack<char> charStack;
	int mul = 1;
	int sum = 0;
	int length = text.length ();

	int size1 = 0;
	int size2 = 0;

	for (int i = 0; i < length; i++)
	{
		char c = text.at (i);
		if (c == '(')
		{
			size1++;
			mul *= 2;
			charStack.push (c);
			if (i + 1 < length && text.at (i + 1) == ')')
				sum += mul;
		}
		else if (c == '[')
		{
			size2++;
			mul *= 3;
			charStack.push (c);
			if (i + 1 < length && text.at (i + 1) == ']')
				sum += mul;
		}
		else if (c == ')')
		{
			if (charStack.empty () || charStack.top () != '(')
				return 0;

			size1--;
			if (charStack.top () == '(')
				charStack.pop ();
			mul /= 2;
		}
		else if (c == ']')
		{
			if (charStack.empty () || charStack.top () != '[')
				return 0;

			size2--;
			if (charStack.top () == '[')
				charStack.pop ();
			mul /= 3;
		}
	}

	if (!charStack.empty () || size1 != 0 || size2 != 0)
		return 0;
	return sum;
}

void four()
{
	string text;
	cin >> text;

	cout << CalculateStack (text) << endl;
}

//class Stack
//{
//	private:
//		int arr[10000];
//		int top;
//
//	public :
//		void Init ()
//		{
//			top = 0;
//		}
//			
//		void push (Stack& stack, int num)
//		{
//			stack.arr[++stack.top] = num;
//		}
//
//		int pop (Stack& stack)
//		{
//			return stack.arr[stack.top--];
//		}
//
//		int size (Stack& stack)
//		{
//			return stack.top;
//		}
//
//		int top (Stack& stack)
//		{
//			return stack.arr[stack.top];
//		}
//};
