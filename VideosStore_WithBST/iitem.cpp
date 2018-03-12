//-----------------------------------------------------------------------------
// File:	iitem.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: This is a class of items. This class is a base class for any sort of 
// item that can have a stock in inventory. DVD inherits iitem in order to use
// the stock changes of items.
//-----------------------------------------------------------------------------

#include "iitem.h"

// --------------------------------------------------------------------------
// Function:	IItem::~IItem()
// Title:	Destructor
// Description: Destructor
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IItem::~IItem()
{
}

// --------------------------------------------------------------------------
// Function:	void IItem::changeStock(int alterNumber)
// Title:	change the stock inventory
// Description: change the number of items in inventory
// Parameters:	int alterNumber
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IItem::changeStock(int alterNumber)
{
	m_stock += alterNumber;
}

// --------------------------------------------------------------------------
// Function:	void IItem::setStock(int stock)
// Title:	mutator for stock
// Description: set the initial value of the stock of an item
// Parameters:	int stock
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
void IItem::setStock(int stock)
{
	int empty = 0;
	if (stock >= empty)
	{
		this->m_stock = stock;
	}
}

// --------------------------------------------------------------------------
// Function:	int IItem::getStock()
// Title:	accessor for m_stock
// Description: get the number of stock in inventory
// Parameters:	N/A
// Returns:	void
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
int IItem::getStock()
{
	return m_stock;
}

//ostream & operator<<(ostream & sout, const IItem & i_item)
//{
//	i_item.display(sout);
//	return sout;
//}
