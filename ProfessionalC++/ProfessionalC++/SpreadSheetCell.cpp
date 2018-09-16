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
	setValue(initialValue);
}

SpreadSheetCell::SpreadSheetCell(const string& initialValue)
{
	setString(initialValue);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src) : mValue(src.mValue), mString(src.mString)
{
}

void SpreadSheetCell::setValue(double inValue)
{
	mValue = inValue;
	mString = doubleToString(mValue);
 }

double SpreadSheetCell::getValue() const
{
	return mValue;
}

void SpreadSheetCell::setString(const string& inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const string& SpreadSheetCell::getString() const
{
	return mString;
}

string SpreadSheetCell::doubleToString(double inValue) const
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadSheetCell::stringToDouble(const string& inString) const
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof())
		return 0;
	
	return temp;
}