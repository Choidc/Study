#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Factorial (int n)
{
	if (n < 1)
		return 1;

	int result = 1;
	for (int i = n; i >= 1; i--)
	{
		result *= i;
	}
	return result;
}

void One ()
{
	int N, K;
	cin >> N >> K;

	cout << Factorial (N) / (Factorial (K) * Factorial (N - K));
}

void Two ()
{
	int DB[1001][1001];
	int N, K;
	cin >> N >> K;

	for (int row = 1; row <= N; row++)
	{
		for (int col = 0; col <= N; col++)
		{
			if (row == col || col == 0)
			{
				DB[row][col] = 1;
				continue;
			}
			DB[row][col] = (DB[row - 1][col] + DB[row - 1][col - 1]) % 10007;
		}
	}

	cout << DB[N][K];
}

void Four ()
{
	int N;
	cin >> N;
	cout << Factorial (N);
}

void Five ()
{
	int N;
	cin >> N;
	int count2 = 0;
	int count5 = 0;

	for (int i = 1; i <= N; i++)
	{
		int temp = i;
		// 5 25 125 ... div 5 count
		while (temp % 5 == 0)
		{
			temp /= 5;
			count5++;
		}
		// 2 4 8 ... div 2 count
		while (temp % 2 == 0)
		{
			temp /= 2;
			count2++;
		}
	}

	if (count2 < count5)
		cout << count2;
	else
		cout << count5;
}

string Combination (string temp1, string temp2)
{
	long long sum = 0;
	string combination;

	while (!temp1.empty () || !temp2.empty() || sum != 0)
	{
		if (!temp1.empty ())
		{
			sum += temp1.back () - '0';
			temp1.pop_back ();
		}
		if (!temp2.empty ())
		{
			sum += temp2.back () - '0';
			temp2.pop_back ();
		}
		combination.push_back ((sum % 10) + '0');
		sum /= 10;
	}
	reverse (combination.begin (), combination.end ());
	return combination;
}

void Six ()
{
	// long long x
	string DB[101][101];
	int N, K;
	cin >> N >> K;

	for (int row = 1; row <= N; row++)
	{
		for (int col = 0; col <= N; col++)
		{
			if (row == col || col == 0)
			{
				DB[row][col] = "1";
				continue;
			}

			DB[row][col] = Combination (DB[row - 1][col], DB[row - 1][col - 1]);
		}
	}

	cout << DB[N][K];
}

void Seven ()
{
	int N = -1, K = -1;
	vector<string> temp;
	// long long x
	while (N != 0 || K != 0)
	{
		cin >> N >> K;

		string DB[101][101];

		for (int row = 1; row <= N; row++)
		{
			for (int col = 0; col <= N; col++)
			{
				if (row == col || col == 0)
				{
					DB[row][col] = "1";
					continue;
				}

				DB[row][col] = Combination (DB[row - 1][col], DB[row - 1][col - 1]);
			}
		}

		temp.push_back (DB[N][K]);
	}

	for (string i : temp)
	{
		cout << i << endl;
	}

}

int main ()
{
	Seven ();
}
