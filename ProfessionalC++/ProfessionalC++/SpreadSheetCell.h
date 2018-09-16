#pragma once
#include <string>
class SpreadSheetCell
{
	public:
		SpreadSheetCell();
		SpreadSheetCell(double initialValue);
		SpreadSheetCell(const std::string& initialValue);
		SpreadSheetCell(const SpreadSheetCell& src);
		SpreadSheetCell& operator=(const SpreadSheetCell& rhs);
		void setValue(double inValue);
		double getValue() const;
		void setString(const std::string& isString);
		const std::string& getString() const;
	private:
		std::string doubleToString(double inValue) const;
		double stringToDouble(const std::string& inString) const;
		double mValue;
		std::string mString;
};