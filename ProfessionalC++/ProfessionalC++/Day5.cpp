#include <iostream>
#include <vector>
#include <memory>

#include"Super.h"
#include"Sub.h"
#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"

using namespace std;

int main()
{
	Super* superPointer = new Sub();
	superPointer->someMethod ();

	Super mySuper;
	mySuper.someMethod ();

	Sub mySub;
	mySub.someMethod ();

	Super& ref = mySub;
	ref.someMethod ();

	//Sub& ref = mySuper; // Error;
	//ref.someMethod ();
	
	mySub.someOtherMethod ();
	//ref.someOtherMethod (); // Error

	Super assignedObject = mySub;
	assignedObject.someMethod (); // assigenment
	// Subclass Characteristic Delete

	///// Polymorphism Test /////
	vector<unique_ptr<SpreadsheetCell>> cellArray;

	cellArray.push_back (make_unique<StringSpreadsheetCell> ());
	cellArray.push_back (make_unique<StringSpreadsheetCell> ());
	cellArray.push_back (make_unique<DoubleSpreadsheetCell> ());

	cellArray[0]->set ("hello");
	cellArray[1]->set ("10");
	cellArray[2]->set ("18");

	cout << "Vector values are [" << cellArray[0]->getString () << "," <<
		cellArray[1]->getString () << "," <<
		cellArray[2]->getString () << "]" << endl;

	//DoubleSpreadsheetCell myDbl;
	//myDbl.set (8.4);
	//StringSpreadsheetCell result = myDbl + myDbl;
	//cout << endl << result.getString () << endl;

}


// Virtual Keyword : http://genesis8.tistory.com/105 
// OOP 5 SOLID : https://ko.wikipedia.org/wiki/%EB%A6%AC%EC%8A%A4%EC%BD%94%ED%94%84_%EC%B9%98%ED%99%98_%EC%9B%90%EC%B9%99
// liskov subsitution principle : http://2dubbing.tistory.com/25

