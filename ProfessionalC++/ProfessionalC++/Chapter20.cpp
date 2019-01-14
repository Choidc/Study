

// iterator : http://tcpschool.com/cpp/cpp_iterator_etc
// iterator_traits : https://en.cppreference.com/w/cpp/iterator/iterator_traits
// allocator : http://celdee.tistory.com/639

#include "hash_map.h"
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;
using namespace ProCpp;

class MoveableClass
{
	public:
	MoveableClass ()
	{
		cout << "Default constructor" << endl;
	}
	MoveableClass (const MoveableClass& /* src */)
	{
		cout << "Copy constructor" << endl;
	}
	MoveableClass (MoveableClass&& /* src */) noexcept
	{
		cout << "Move constructor" << endl;
	}
	MoveableClass& operator=(const MoveableClass& /* rhs */)
	{
		cout << "Copy assignment operator" << endl;
		return *this;
	}
	MoveableClass& operator=(MoveableClass&& /* rhs */) noexcept
	{
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all (InputIterator first, InputIterator last, OutputIterator dest, Predicate pred)
{
	while (first != last)
	{
		if (pred (*first))
		{
			*dest = first;
			++dest;
		}
		++first;
	}
	return dest;

}

using std::vector;
using std::cout;
using std::endl;

template <typename IteratorType>
void iteratorTraitsTest (IteratorType it)
{
	typename std::iterator_traits<IteratorType>::value_type temp;
	temp = *it;
	//auto temp = *it;
	cout << temp << endl;
}


int main ()
{
	//vector<MoveableClass> vecSource;
	//MoveableClass mc;
	//vecSource.push_back (mc);
	//vecSource.push_back (mc);
	//cout << "----" << endl;

	//// Copy the elements from vecSource to vecOne
	//vector<MoveableClass> vecOne (cbegin (vecSource), cend (vecSource));
	//cout << "----" << endl;

	//// Move the elements from vecSource to vecTwo
	//vector<MoveableClass> vecTwo (make_move_iterator (begin (vecSource)),
	//							  make_move_iterator (end (vecSource)));
	//cout << "----" << endl;
	
	//--------------------

	//vector<int> vec{3, 4, 5, 4, 5, 6, 5, 8};
	//vector<vector<int>::iterator> matches;
	//find_all (begin (vec), end (vec), back_inserter (matches), [](int i) { return i == 5; });

	//cout << "Found " << matches.size () << " matching elements: " << endl;

	//for (auto it : matches)
	//{
	//	cout << *it << " at position " << (it - cbegin (vec)) << endl;;
	//}
	//cout << endl;

	//----------------------

	//vector<int> v{5};
	//iteratorTraitsTest (cbegin (v));

	//--------------------
	hash_map<int, int> myHash;
	myHash.insert (make_pair (4, 40));
	myHash.insert (make_pair (6, 60));

	// x will have type hash_map<int, int>::value_type*
	auto x = myHash.find (4);
	if (x != nullptr)
	{
		cout << "4 maps to " << x->second << endl;
	}
	else
	{
		cout << "cannot find 4 in map" << endl;
	}

	myHash.erase (4);

	auto x2 = myHash.find (4);
	if (x2 != nullptr)
	{
		cout << "4 maps to " << x2->second << endl;
	}
	else
	{
		cout << "cannot find 4 in map" << endl;
	}

	myHash[4] = 35;
	myHash[4] = 60;

	auto x3 = myHash.find (4);
	if (x3 != nullptr)
	{
		cout << "4 maps to " << x3->second << endl;
	}
	else
	{
		cout << "cannot find 4 in map" << endl;
	}


	hash_map<int, int> myHash2;
	myHash2 = myHash;
	hash_map<int, int> myHash3 (myHash2);

	return 0;
}
