//#include <iostream>
//using namespace std;
//
//int zero = 0;
//int one = 0;
//
//// timeOver ==> O(N^2);
//int Fibonacci_Recursive (int num)
//{
//	if (num == 0)
//		return num;
//	else if (num == 1)
//		return num;
//	else
//		return Fibonacci_Recursive (num - 1) + Fibonacci_Recursive (num - 2);
//}
//
//// Ok ==> O(N)
//int Fibonacci_Recursive2 (int num, int before, int next)
//{
//	if (num == 0)
//		return 0;
//	else if (num == 1)
//		return next;
//	else
//		return Fibonacci_Recursive2 (num - 1, next, before + next);
//}
//
//// int -> long long
//long long Fibonacci_Recursive3 (int num, long long before, long long next)
//{
//	if (num == 0)
//	{
//		zero++;
//		return 0;
//	}
//	else if (num == 1)
//	{
//		one++;
//		return next;
//	}
//	else
//		return Fibonacci_Recursive3 (num - 1, next, before + next);
//}
//
//int main ()
//{
//	int num;
//	cin >> num;
//	cout << Fibonacci_Recursive3(num, 0, 1) << ", Zero : " << zero << ", One : " << one << endl;
//}