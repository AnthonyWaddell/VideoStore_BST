// ---------------------------- drama.h --------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A drama DVD.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: Drama DVDs
// are sorted by Director, then Title.
// ---------------------------------------------------------------------------

#ifndef DRAMA_
#define DRAMA_

#include "dvd.h"
using namespace std;

class Drama : public DVD
{
public:
  // ---------------------------- ~Drama --------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Drama();

  // ---------------------------- display -------------------------------------
  // Displays drama DVD information.
  // Preconditions: None.
  // Postconditions: outStream contains drama DVD information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display() const;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains drama DVD information.
  // Parameter: genDisplayString - A string that will contain the drama DVD's
  // information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(string& genDisplayString);

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an drama DVD so all of this drama DVD fields are the 
  // same as the parameters items fields.
  // Preconditions: itemPtr is a type of drama DVD.
  // Postconditions: This drama DVD contains the same fields as the parameter 
  // item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr);

  // ---------------------------- buildDVD ------------------------------------
  // Builds a drama DVD by setting all of the drama DVDs data members from an 
  // input file that contains a line of information about a particular drama
  // DVD.
  // Preconditions: genre is a valid movie genre and inputFileInventory is
  // formatted properly.
  // Postconditions: This drama DVD is built and contains all its proper 
  // information.
  // Parameter: genre - An genre of this particular DVD.
  // inputFileInventory - a file that contains the inventory and one line
  // that has a drama DVDs information.
  // --------------------------------------------------------------------------
  virtual void buildDVD(char genre, ifstream& inputFileInventory);

  // ---------------------------- operator== ----------------------------------
  // Compares if two drama DVDs are the same.
  // Preconditions: itemPtr is a type of drama DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if drama DVD is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr);

  // ---------------------------- operator< -----------------------------------
  // Compares two drama dvds to see if this is less than what it is being
  // compared against
  // Preconditions: itemPtr is a type of drama DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this drama dvd is less than what it is being
  // compared against, false if not
  // --------------------------------------------------------------------------
  virtual bool operator<(IItem* itemPtr);

  // ---------------------------- operator> -----------------------------------
  // Compares two drama dvds to see if this is greater than what it is being
  // compared against
  // Preconditions: itemPtr is a type of drama DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this drama dvd is greater than what it is being
  // compared against, false if not
  // --------------------------------------------------------------------------
  virtual bool operator>(IItem* itemPtr);

private:

};

#endif // !DRAMA_

