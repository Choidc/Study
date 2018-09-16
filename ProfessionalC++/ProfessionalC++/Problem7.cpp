#include<iostream> 
#include<string>
#include<vector>
using namespace std;

int main()
{
	string text;
	cin >> text;

	int arr['z' - 'a' + 1] = { 0 };
	for (int i = 0; i < text.size(); i++)
	{
		for (int a = 0; a <= 'z' - 'A'; a++)
		{
			if (text[i] - 'A' == a % 26)
			{
				arr[a % 26]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i];
	}
}

void one()
{
	char a;
	cin >> a;

	cout << (int)a << endl;
}

void two()
{
	string text;
	cin >> text;

	for (char a = 'a'; a <= 'z'; a++)
	{
		int count = text.find(a);
		cout << count << " ";
	}
}

void three()
{
	int count;
	cin >> count;

	vector<int> R(count);
	vector<string> S(count);

	for (int i = 0; i < count; i++)
	{
		cin >> R[i];
		cin >> S[i];
	}

	for (int i = 0; i < count; i++)
	{
		for (int s = 0; s < S[i].size(); s++)
		{
			for (int r = 0; r < R[i]; r++)
			{
				cout << S[i][s];
			}
		}
		cout << endl;
	}
	cout << endl;
}

void four()
{

}