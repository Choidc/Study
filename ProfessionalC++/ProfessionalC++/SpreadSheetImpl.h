#pragma once
#include "SpreadSheetCell.h"
class SpreadSheetApplication;
class SpreadSheetImpl
{
	public:

		SpreadSheetImpl(const SpreadSheetApplication& theApp, int inWitdh = kMaxWidth, int inHeight = kMaxHeight);
		SpreadSheetImpl(const SpreadSheetImpl& src);
		~SpreadSheetImpl();
		SpreadSheetImpl& operator=(const SpreadSheetImpl& rhs);
		void setCellAt(int x, int y, const SpreadSheetCell& cell);
		SpreadSheetCell& getCellAt(int x, int y);
		int getID() const;

		static const int kMaxHeight = 100;
		static const int kMaxWidth = 100;
	private:
		bool inRange(int val, int upper);
		void copyFrom(const SpreadSheetImpl& src);
		int mWidth, mHeight;
		int mID;
		SpreadSheetCell** mCells;
		const SpreadSheetApplication& mTheApp;
		static int sCounter;

};
