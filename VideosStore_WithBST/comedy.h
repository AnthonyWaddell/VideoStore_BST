// ---------------------------- comedy.h -------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A comedy DVD.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: Comedy DVDs
// are sorted by Title, then Year it released.
// ---------------------------------------------------------------------------

#ifndef COMEDY_
#define COMEDY_

#include "dvd.h"
using namespace std;

class Comedy : public DVD
{
public:
  // ---------------------------- ~Comedy -------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Comedy();

  // ---------------------------- display -------------------------------------
  // Displays comedy DVD information.
  // Preconditions: None.
  // Postconditions: outStream contains comedy DVD information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display() const;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains comedy DVD information.
  // Parameter: genDisplayString - A string that will contain the comedy DVD's
  // information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(string& genDisplayString);

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an comedy DVD so all of this comedy DVD fields are the
  // same as the parameters items fields.
  // Preconditions: itemPtr is a type of comedy DVD.
  // Postconditions: This comedy DVD contains the same fields as the parameter 
  // item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr);

  // ---------------------------- buildDVD ------------------------------------
  // Builds a comedy DVD by setting all of the comedy DVDs data members from an
  // input file that contains a line of information about a particular comedy
  // DVD.
  // Preconditions: genre is a valid movie genre and inputFileInventory is
  // formatted properly.
  // Postconditions: This comedy DVD is built and contains all its proper 
  // information.
  // Parameter: genre - An genre of this particular DVD.
  // inputFileInventory - a file that contains the inventory and one line
  // that has a comedy DVDs information.
  // --------------------------------------------------------------------------
  virtual void buildDVD(char genre, std::ifstream& inputFileInventory);

  // ---------------------------- operator== ----------------------------------
  // Compares if two comedy DVDs are the same.
  // Preconditions: itemPtr is a type of comedy DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if comedy DVD is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr);

  // ---------------------------- operator< -----------------------------------
  // Compares one DVD object is less than the other
  // Preconditions: itemPtr is a type of comedy DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this is less than itemPtr, false if not
  // --------------------------------------------------------------------------
  virtual bool operator<(IItem* itemPtr);

  // ---------------------------- operator> -----------------------------------
  // Compares one DVD object is greater than the other
  // Preconditions: itemPtr is a type of comedy DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this is greater than itemPtr, false if not
  // --------------------------------------------------------------------------
  virtual bool operator>(IItem* itemPtr);

private:

};

#endif // !COMEDY_
