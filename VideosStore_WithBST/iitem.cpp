#include "iitem.h"

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
IItem::~IItem()
{
}

// --------------------------------------------------------------------------
// change stock of item for borrow/return and duplicate DVD's (classics)
// --------------------------------------------------------------------------
void IItem::changeStock(int alterNumber)
{
	m_stock += alterNumber;
}

// --------------------------------------------------------------------------
// mutator for m_stock
// --------------------------------------------------------------------------
void IItem::setStock(int stock)
{
	int empty = 0;
	if (stock >= empty)
	{
		m_stock = stock;
	}
}

// --------------------------------------------------------------------------
// accessor for m_stock
// --------------------------------------------------------------------------
int IItem::getStock()
{
	return m_stock;
}

ostream & operator<<(ostream & sout, const IItem & i_item)
{
	i_item.display(sout);
	return sout;
}
