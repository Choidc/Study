#include "SpreadSheetImpl.h"
SpreadSheetImpl::SpreadSheetImpl(const SpreadSheetApplication& mTheApp, int inWidth, int inHeight)
	: mTheApp(mTheApp), mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth), mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight)
{
	mID = sCounter++;
	mCells = new SpreadSheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadSheetCell[mHeight];
	}
}

SpreadSheetImpl::SpreadSheetImpl(const SpreadSheetImpl& src) : mTheApp(src.mTheApp)
{
	sCounter++;
	copyFrom(src);
}

SpreadSheetImpl& SpreadSheetImpl::operator=(const SpreadSheetImpl& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	for (int i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;

	copyFrom(rhs);
	return *this;
}

void SpreadSheetImpl::copyFrom(const SpreadSheetImpl& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = new SpreadSheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadSheetCell[mHeight];
	}

	for (int i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}


SpreadSheetImpl::~SpreadSheetImpl()
{
	for (int i = 0; i < mWidth; i++) 
	{
		delete[] mCells[i];
	}
	delete[]mCells;
	mCells = nullptr;
}


void SpreadSheetImpl::setCellAt(int x, int y, const SpreadSheetCell& cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight))
	{
		throw std::out_of_range("");
	}
	mCells[x][y] = cell;
}

SpreadSheetCell& SpreadSheetImpl::getCellAt(int x, int y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight))
	{
		throw std::out_of_range("");
	}
	return mCells[x][y];
}
