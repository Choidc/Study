#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void one ()
{
	int count, input;
	cin >> count;

	vector<int> sort;
	for (int i = 0; i < count; i++)
	{
		cin >> input;
		sort.push_back (input);
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			int temp;
			if (sort[j] > sort[j + 1])
			{
				temp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << sort[i] << endl;
	}
}

void two ()
{
	int n, a;
	vector <int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back (a);
	}

	sort (v.begin (), v.end ());

	for (int i = 0; i < n; i++)
		printf ("%d\n", v[i]);
}

void twotwo () // time over
{
	int count, *arr;
	cin >> count;
	arr = new int[count];

	for (int i = 0; i < count; i++)
		cin >> arr[i];

	sort (arr, arr + count);
	for (int i = 0; i < count; i++)
		cout << arr[i] << endl;
}

void five()
{
	int size;
	string text;
	vector <char> arr;

	cin >> text;
	size = text.size ();

	for (int i = 0; i < size; i++)
		arr.push_back (text[i]);

	sort (arr.begin (), arr.end (), greater<char> ());

	for (int i = 0; i < size; i++)
		cout << arr[i];
}

bool compare (string left, string right)
{
	if (left.length () == right.length ()) // size check
	{
		for (int i = 0; i < left.length (); i++)
		{
			if (left.at (i) != right.at (i)) // order check
				return left.at (i) < right.at (i);
		}
	}
	else
		return left.length () < right.length ();
}

void six () // time over
{
	int count;
	cin >> count;

	vector<string> word;

	for (int i = 0; i < count; i++)
	{
		string temp;
		cin >> temp;
		if (find (word.begin (), word.end (), temp) == word.end ())
			word.push_back (temp);
	}

	sort (word.begin (), word.end (), compare);
	for (int i = 0; i < word.size (); i++)
	{
		cout << word[i] << endl;
	}
}