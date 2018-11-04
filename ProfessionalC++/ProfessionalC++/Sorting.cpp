//#include<iostream>
//#include<vector>
//using namespace std;
//
//void BubbleSorting (vector<int>& sort)
//{
//	for (int i = 0; i < sort.size(); i++)
//	{
//		for (int j = 0; j < sort.size() - 1 - i; j++)
//		{
//			int temp;
//			if (sort[j] > sort[j + 1])
//			{
//				temp = sort[j + 1];
//				sort[j + 1] = sort[j];
//				sort[j] = temp;
//			}
//		}
//	}
//}
//
//void SelectionSorting (vector<int>& sort)
//{
//	for (int i = 0; i < sort.size () - 1; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < sort.size (); j++)
//		{
//			if (sort[j] < sort[max])
//				max = j;
//		}
//		int temp;
//		temp = sort[i];
//		sort[i] = sort[max];
//		sort[max] = temp;
//	}
//}
//
//void InsertionSorting (vector<int>& sort)
//{
//	for (int i = 1; i < sort.size (); i++)
//	{
//		int insert = sort[i];
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (sort[j] > insert)
//			{
//				sort[j + 1] = sort[j];
//				sort[j] = insert;
//			}
//			else
//				break;
//		}
//	}
//}
//
//void MergeSorting (vector<int>& sort, int left, int mid, int right)
//{
//	vector<int> temp(right + 1);
//
//	int low = left;
//	int high = mid + 1;
//	int current = left;
//
//	while (low <= mid && high <= right)
//	{
//		if (sort[low] <= sort[high])
//			temp[current] = sort[low++];
//		else
//			temp[current] = sort[high++];
//
//		current++;
//	}
//
//	if (low > mid)
//		for (int i = high; i <= right; i++, current++)
//			temp[current] = sort[i];
//	else
//		for (int i = low; i <= mid; i++, current++)
//			temp[current] = sort[i];
//
//	for (int i = left; i <= right; i++)
//		sort[i] = temp[i];
//}
//
//void Merge (vector<int>& sort, int left, int right)
//{
//	if (left < right)
//	{
//		int mid = (left + right) / 2;
//
//		//Divide
//		Merge (sort, left, mid);
//		Merge (sort, mid + 1, right);
//
//		//Combine
//		MergeSorting (sort, left, mid, right);
//	}
//
//
//}
//
//int Partition (vector<int>& sort, int left, int right)
//{
//	int pivot = sort[left];
//
//
//	int low = left + 1;
//	int high = right;
//
//	while (low <= high)
//	{
//		while (pivot > sort[low])
//			low++;
//
//		while (pivot < sort[high])
//			high--;
//
//		if (low <= high)
//		{
//			int temp = sort[low];
//			sort[low] = sort[high];
//			sort[high] = temp;
//		}
//	}
//	
//	int temp = sort[left];
//	sort[left] = sort[high];
//	sort[high] = temp;
//
//	return high;
//}
//
//void QuickSorting (vector<int>& sort, int left, int right)
//{
//	if (left <= right)
//	{
//		int pivot = Partition (sort, left, right);
//		QuickSorting (sort, left, pivot - 1);
//		QuickSorting (sort, pivot + 1, right);
//	}
//}
//
//int main ()
//{
//	int count, input;
//	cin >> count;
//
//	vector<int> sort;
//	for (int i = 0; i < count; i++)
//	{
//		cin >> input;
//		sort.push_back (input);
//	}
//
//	QuickSorting (sort, 0, sort.size () - 1);
//	for (int i = 0; i < sort.size (); i++)
//	{
//		cout << sort[i] << endl;
//	}
//}