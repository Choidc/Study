#include "SpreadSheet.h"

SpreadSheet::SpreadSheet(const SpreadSheetApplication& theApp, int inWidth, int inHeight)
{
	mImpl = std::make_unique<SpreadSheetImpl>(theApp, inWidth, inHeight);
}

SpreadSheet::SpreadSheet(const SpreadSheetApplication& theApp)
{
	mImpl = std::make_unique<SpreadSheetImpl>(theApp);
}

SpreadSheet::SpreadSheet(const SpreadSheet& src)
{
	mImpl = std::make_unique<SpreadSheetImpl>(*src.mImpl);
}

SpreadSheet::~SpreadSheet()
{

}

SpreadSheet& SpreadSheet::operator= (const SpreadSheet& rhs)
{
	*mImpl = *rhs.mImpl;
	return *this;
}

void SpreadSheet::setCellAt(int x, int y, const SpreadSheetCell& inCell)
{
	mImpl->setCellAt(x, y, inCell);
}

SpreadSheetCell& SpreadSheet::getCellAt(int x, int y)
{
	return mImpl->getCellAt(x, y);
}

int SpreadSheet::getID() const
{
	return mImpl->getID();
}