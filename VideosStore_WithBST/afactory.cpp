//-----------------------------------------------------------------------------
// File:	aFactory.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: This is a design pattern of a factory that creates objects of actions
// that the store does based on the command file. It uses a switch statement by reading
// the char of the comand file which creates the correct object action
//-----------------------------------------------------------------------------

#include "afactory.h"
#include <iostream>
using namespace std;

// --------------------------------------------------------------------------
// Function:	AFactory::~AFactory()
// Title:	Destructor
// Description: Destructor of the AFactory class
// Parameters:	N/A
// Returns:	N/A
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
AFactory::~AFactory()
{
}

// --------------------------------------------------------------------------
// Function:	IAction * AFactory::createAction(char actionType)
// Title:	create an action class
// Description: The method creates an action class based on the command switch staement
//		and if the command is not valid, it will provide an invalid print statement
// Parameters:	char actionType
// Returns:	action type 
// History Log: 03/14/18 AW Completed Function
// --------------------------------------------------------------------------
IAction * AFactory::createAction(char actionType)
{
	IAction *m_action = NULL;
	actionType = toupper(actionType);
	switch (actionType)
	{
	case 'B':
		m_action = new Borrow();
		break;
	case 'R':
		m_action = new Return();
		break;
	case 'H':
		m_action = new History();
		break;
	case 'I':
		m_action = new Inventory();
		break;
	default:
		cout << "Invalid Action: " << actionType << endl;
		break;
	}
	return m_action;
}
