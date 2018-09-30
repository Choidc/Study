#pragma once
#include <string>
class SpreadSheetCell
{
	public:
		SpreadSheetCell();
		SpreadSheetCell(double initialValue);
		explicit SpreadSheetCell(const std::string& initialValue);
		SpreadSheetCell(const SpreadSheetCell& src);
		SpreadSheetCell& operator=(const SpreadSheetCell& rhs);
		void set(double inValue);
		void set(const std::string& isString);
		double getValue() const { mNumAccesses++; return mValue; }
		const std::string& getString() const { mNumAccesses++; return mString; }

		SpreadSheetCell add(const SpreadSheetCell& cell) const;\

		SpreadSheetCell operator+(const SpreadSheetCell& cell) const;
		SpreadSheetCell operator+(double rhs) const;
		friend SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);

	private:
		static std::string doubleToString(double inValue);
		static double stringToDouble(const std::string& inString);
		double mValue;
		std::string mString;
		mutable int mNumAccesses = 0;
};