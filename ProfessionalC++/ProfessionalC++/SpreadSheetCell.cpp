// 7¿Â
#include "SpreadSheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

SpreadSheetCell::SpreadSheetCell()
{
	mValue = 0;
}

SpreadSheetCell::SpreadSheetCell(double initialValue)
{
	set(initialValue);
}

SpreadSheetCell::SpreadSheetCell(const string& initialValue)
{
	set(initialValue);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src) : mValue(src.mValue), mString(src.mString)
{
}

void SpreadSheetCell::set(double inValue)
{
	mValue = inValue;
	mString = doubleToString(mValue);
 }

void SpreadSheetCell::set(const string& inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const string& SpreadSheetCell::getString() const
{
	mNumAccesses++;
	return mString;
}

string SpreadSheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadSheetCell::stringToDouble(const string& inString)
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof())
		return 0;
	
	return temp;
}

SpreadSheetCell SpreadSheetCell::add(const SpreadSheetCell& cell) const
{
	SpreadSheetCell newCell;
	newCell.set(mValue + cell.mValue);
	return newCell;
}

SpreadSheetCell SpreadSheetCell::operator+(const SpreadSheetCell& cell) const
{
	SpreadSheetCell newCell;
	newCell.set(mValue + cell.mValue);
	return newCell;
}

SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	SpreadSheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue);
	return newCell;
}

SpreadSheetCell SpreadSheetCell::operator+(double rhs) const
{
	return SpreadSheetCell(mValue + rhs);
}