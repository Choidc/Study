#pragma once
#include "SpreadSheetCell.h"
#include <memory>

class SpreadSheetImpl;
class SpreadSheetApplication;
class SpreadSheet
{
	public:
		SpreadSheet(const SpreadSheetApplication& theApp, int inWidth, int inHeight);
		SpreadSheet(const SpreadSheetApplication& theApp);
		SpreadSheet(const SpreadSheet& src);
		~SpreadSheet();
		SpreadSheet& operator=(const SpreadSheet& rhs);
		void setCellAt(int x, int y, const SpreadSheetCell& inCell);
		SpreadSheetCell& getCellAt(int x, int y);
		int getID() const;
	private:
		std::unique_ptr<SpreadSheetImpl> mImpl;
};