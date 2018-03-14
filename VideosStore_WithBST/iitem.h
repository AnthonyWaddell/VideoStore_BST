// ---------------------------- iitem.h --------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - An item interface.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef IITEM_
#define IITEM_

#include <ostream> // For ostream
using namespace std;

class IItem
{
public:
  // ---------------------------- ~IItem --------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~IItem();

  // ---------------------------- display -------------------------------------
  // Displays item information.
  // Preconditions: None.
  // Postconditions: outStream contains item information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display() const = 0;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains item information.
  // Parameter: genDisplayString - A string that will contain the item's
  // information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(std::string& genDisplayString) = 0;

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an item so all of this items fields are the same as
  // the parameters items fields.
  // Preconditions: None.
  // Postconditions: This item contains the same fields as the parameter item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr) = 0;

  // ---------------------------- operator== ----------------------------------
  // Compares if two items are the same.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if item is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr) = 0;

  // ---------------------------- changeStock ---------------------------------
  // Changes the quantity of the item by a certain amount.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: alterNumber - A number to alter the stock by. Can be plus or
  // negative number.
  // --------------------------------------------------------------------------
  void changeStock(int alterNumber);

  // ---------------------------- setStock ------------------------------------
  // Sets the stock to a certain quantity of items.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: stock - the amount of the item.
  // --------------------------------------------------------------------------
  void setStock(int stock);

  // ---------------------------- getStock ------------------------------------
  // Gets the stock of the item.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns the quantity of the item.
  // --------------------------------------------------------------------------
  int getStock();

protected:

  int m_stock; // The amount of the item
};


#endif // !IITEM_

