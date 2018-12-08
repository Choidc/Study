#include <iostream>
#include <vector>
#include "RoundRobin.h"

using namespace std;

void fixedSizeVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();

	for (auto i = 0; i < doubleVector.size (); i++)
	{
		cout << "EnterScore " << i + 1 << " : ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max)
		{
			max = doubleVector[i];
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
}

void dynamicSizeVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();

	for (auto i = 1; true; i++)
	{
		double temp;
		cout << "EnterScore " << i << " (-1 to Step) : ";
		cin >> temp;
		if (temp == -1)
			break;

		doubleVector.push_back (temp);
		if (temp > max)
			max = temp;
	}

	max /= 100.0;
	for (auto& element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
}

void deepVector ()
{
	vector<int> intVector; // size = 0 type = int // defaultVector
	vector<int> intVector2 (10, 100); // size = 10, initialize = 100;
	vector<string> stringVector (10, "hello");
	vector<int> intVector3 ({1, 2, 3, 4, 5, 6});
	intVector3.assign (3, 123);
	intVector3.swap (intVector2);
	for (auto& i : intVector3)     
	{
		cout << i << endl;
	}
}

void compareVector ()
{
	vector<int> vectorOne (10);
	vector<int> vectorTwo (10);

	if (vectorOne == vectorTwo)	
		cout << "equal!" << endl;
	else
		cout << "not equal!" << endl;

	vectorOne[3] = 50;

	if (vectorOne < vectorTwo)
		cout << "vectorOne is less than vectorTwo" << endl;
	else
		cout << "vectorOne is not less than vectorTwo" << endl;
}

void iteratorVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();

	for (auto i = 1; true; i++)
	{
		double temp;
		cout << "EnterScore " << i << " (-1 to Step) : ";
		cin >> temp;
		if (temp == -1)
			break;

		doubleVector.push_back (temp);
		if (temp > max)
			max = temp;
	}

	max /= 100.0;
	
	//for (vector<double>::iterator iter = begin (doubleVector); iter != end (doubleVector); ++iter)
	for(auto iter = doubleVector.begin(); iter != doubleVector.end(); ++iter)
	{
		*iter /= max;
		cout << *iter << " ";
	}
}

void iteratorVector2 ()
{
	vector<string> stringVector (10, "hello");
	for (auto& str : stringVector)
		str.append (" there");
}

class Element
{
	public:
	Element (int i, const string& str) : mI (i), mStr (str)
	{}

	private:
	int mI;
	string mStr;
};

void MovePushback()
{
	vector<Element> vec;

	Element myElement (12, "Twelve");
	vec.push_back (myElement);

	vec.push_back (move (myElement));
	vec.push_back (Element (12, "Twelve"));
	vec.push_back ({12, "Twelve"});
}

void RoundRobin ()
{

}
 
int main ()
{
	// https://comcxx11.github.io/com/stl-container/
	//fixedSizeVector ();
	//dynamicSizeVector ();
	//deepVector ();
	//compareVector ();
	//iteratorVector ();
	//iteratorVector2 ();
	//MovePushback ();
	// List Method : http://www.cplusplus.com/reference/list/list/

}
