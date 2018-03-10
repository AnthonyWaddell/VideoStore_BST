// ---------------------------- classical.h ----------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A classical DVD.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: Classical 
// DVDs are sorted by Release date, then Major actor.
// ---------------------------------------------------------------------------

#ifndef CLASSICAL_
#define CLASSICAL_

#include "dvd.h"
using namespace std;

class Classical : public DVD
{
public:
  // ---------------------------- ~Classical ----------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Classical();

  // ---------------------------- display -------------------------------------
  // Displays classical DVD information.
  // Preconditions: None.
  // Postconditions: outStream contains classical DVD information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display(ostream& outStream) const;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains classical DVD information.
  // Parameter: genDisplayString - A string that will contain the classical 
  // DVD's information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(std::string& genDisplayString);

  //// ---------------------------- displaySearchKey ----------------------------
  //// Displays the search key information of the classical DVD.
  //// Preconditions: None.
  //// Postconditions: outStream contains classical DVD search key information.
  //// Parameter: outStream - A out stream for the display.
  //// --------------------------------------------------------------------------
  //virtual void displaySearchKey(std::ostream& outStream);

  //// ---------------------------- genSearchKey --------------------------------
  //// Generates an classical DVD that only contains its search key information.
  //// Preconditions: None.
  //// Postconditions: This classical DVD has its search key information updated.
  //// ifStream will be at the end of its line.
  //// Parameter: inputFile - A file the contains the search key of the classical 
  //// DVD.
  //// --------------------------------------------------------------------------
  //virtual void genSearchKey(std::ifstream& inputFile);

  //// ---------------------------- compareSearchKey ----------------------------
  //// Detects if classical DVD is the same purely based of its search key 
  //// information.
  //// Preconditions: itemPtr is a type of classical DVD.
  //// Postconditions: None.
  //// Parameter: itemPtr - Item to compare against to see if it is the same
  //// item based of a search key information.
  //// Return: Returns true if item is same as item with search key information.
  //// --------------------------------------------------------------------------
  //virtual bool compareSearchKey(IItem* iitemPtr);

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an classical DVD so all of this classical DVD fields 
  // are the same as the parameters items fields.
  // Preconditions: itemPtr is a type of classical DVD.
  // Postconditions: This classical DVD contains the same fields as the
  // parameter item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr);

  // ---------------------------- buildDVD ------------------------------------
  // Builds a classical DVD by setting all of the classical DVDs data members 
  // from an input file that contains a line of information about a particular 
  // classical DVD.
  // Preconditions: genre is a valid movie genre and inputFileInventory is
  // formatted properly.
  // Postconditions: This classical DVD is built and contains all its proper 
  // information.
  // Parameter: genre - An genre of this particular DVD.
  // inputFileInventory - a file that contains the inventory and one line
  // that has a classical DVDs information.
  // --------------------------------------------------------------------------
  virtual void buildDVD(char genre, ifstream& inputFileInventory);

  // ---------------------------- operator== ----------------------------------
  // Compares if two classical DVDs are equivalent, Regardless if major actor
  // is different.
  // Preconditions: itemPtr is a type of classical DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if classical DVD is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr);

  // ---------------------------- operator< -----------------------------------
  // Compares two classical dvds to see if this is less than what it is being
  // compared against
  // Preconditions: itemPtr is a type of classical DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this classical dvd is less than what it is being
  // compared against, false if not
  // --------------------------------------------------------------------------
  virtual bool operator<(IItem* itemPtr);

  // ---------------------------- operator< -----------------------------------
  // Compares two classical dvds to see if this is greater than what it is 
  // being compared against
  // Preconditions: itemPtr is a type of classical DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if this classical dvd is greater than what it is
  // being compared against, false if not
  // --------------------------------------------------------------------------
  virtual bool operator>(IItem* itemPtr);

  // ---------------------------- getMonthReleased ----------------------------
  // Gets the month the classical DVD was released.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns month classical DVD was released.
  // --------------------------------------------------------------------------
  int getMonthReleased();

  // ---------------------------- getMajorActorFirstName ----------------------
  // Gets the major actor first name.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns major actor first name of classical DVD.
  // --------------------------------------------------------------------------
  string getMajorActorFirstName();

  // ---------------------------- getMajorActorLastName ----------------------
  // Gets the major actor last name.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns major actor last name of classical DVD.
  // --------------------------------------------------------------------------
  string getMajorActorLastName();

  // ---------------------------- setMonthReleased ----------------------------
  // Sets the month released of the classical DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: month - Month the classical DVD was released.
  // --------------------------------------------------------------------------
  void setMonthReleased(int month);

  // ---------------------------- setMajorActorFirstName ----------------------
  // Sets the major actors first name of the classical DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: firstName - First name of major actor of the classical DVD.
  // --------------------------------------------------------------------------
  void setMajorActorFirstName(string firstName);

  // ---------------------------- setMajorActorLastName -----------------------
  // Sets the major actors last name of the classical DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: lastName - Last name of major actor of the classical DVD.
  // --------------------------------------------------------------------------
  void setMajorActorLastName(string lastName);

private:

  int m_monthReleased;               // Month classical dvd was released
  string m_majorActorFirstName; // Major actor's first name
  string m_majorActorLastName;  // Major actor's last name
};

#endif // !CLASSICAL_

