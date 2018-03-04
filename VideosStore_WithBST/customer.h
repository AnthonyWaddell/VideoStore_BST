// ---------------------------- customer.h -----------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Makes a person with an ID, dvd history, and their own inventory.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef CUSTOMER_
#define CUSTOMER_

#include "iperson.h"
#include <string.h>
#include <stack> // For stack

using namespace std;

class Customer : public IPerson
{
public:
  // ---------------------------- Customer ------------------------------------
  // A constructor for an Customer, storing name, ID, and hash key. Hash key
  // is the customers ID. Also, LinkedList inventory m_inventoryLLPtr is 
  // allocated.
  // Preconditions: A valid unique ID.
  // Postconditions: Customer has a name, ID, and hash key.
  // Parameter: id - ID of customer.
  // firstName - first name of customer.
  // lastName - last name of customer.
  // --------------------------------------------------------------------------
  Customer(string firstName, string lastName, int id);

  // ---------------------------- ~Customer -----------------------------------
  // Deconstructor that deallocated LinkedList inventory of customer.
  // Preconditions: None.
  // Postconditions: Customers inventory is deallocated..
  // --------------------------------------------------------------------------
  virtual ~Customer();

  // ---------------------------- getDVDHistory -------------------------------
  // Gets the stack containing customers borrow and return history. History in
  // order of most recent to oldest.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns a stack containing history from most recent to oldest of
  // borrows and returns.
  // --------------------------------------------------------------------------
  stack<string> getDVDHistory();

  //// ---------------------------- getInventoryLLPtr ---------------------------
  //// Gets the Linked List inventory of customer that is in sorted order.
  //// Preconditions: None.
  //// Postconditions: None.
  //// Return: Returns a pointer to a Linked List that contains the customer's
  //// inventory in sorted order.
  //// --------------------------------------------------------------------------
  //LinkedList* getInventoryLLPtr();

  // ---------------------------- setHistory ----------------------------------
  // Pushes a borrow or return information into m_dvdHistory which is the stack
  // of strings that contains customers history.
  // Preconditions: None.
  // Postconditions: m_dvdHistory contains newly added history line that is
  // a borrow or a return with the information.
  // --------------------------------------------------------------------------
  void setHistory(string historyLine);

private:
  int m_id;                             // Unique ID of customer
  stack<string> m_dvdHistory;			// The history of borrow and returns
						                // history from most recent to oldest
  /*LinkedList* m_inventoryLLPtr; */        // Customer's inventory of DVDs
};

#endif // !CUSTOMER_

