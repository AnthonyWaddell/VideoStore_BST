//-----------------------------------------------------------------------------
// File:	main.cpp
// Programmer:	Anthony Waddell, Christopher Salazar
// Description: The main tests all methods in the video library but creating
// a database of customers and inventory of a store. Then it runs the store by
// using the commands from the input files
//-----------------------------------------------------------------------------

#include "originalstore.h"
#include <fstream>
#include <iostream>
#include <string>

int main(void)
{

  // Opens movie file
  std::string moviesFile = "data4movies.txt";
  std::ifstream inputFileMovies(moviesFile.c_str());
  if (!inputFileMovies)
  {
    std::cout << "File could not be opened: " << moviesFile << std::endl;
    return 1;
  }

  // Opens customer file
  std::string customerFile = "data4customers.txt";
  std::ifstream inputFileCustomers(customerFile.c_str());
  if (!inputFileCustomers)
  {
    std::cout << "File could not be opened: " << customerFile << std::endl;
    return 1;
  }

  // Opens command file
  std::string commandFile = "data4commands.txt";
  std::ifstream inputFileCommands(commandFile.c_str());
  if (!inputFileCommands)
  {
    std::cout << "File could not be opened: " << commandFile << std::endl;
    return 1;
  }
  cout << " still need to work on duplicate classics inventory and update inventory on return and borrow and the customer stack history" << endl;

  // Builds and run a particular instance of a store
  IStore* store;
  store = new OriginalStore;
  store->buildStore(inputFileCustomers, inputFileMovies);
  store->runStore(inputFileCommands);

  delete store;
  store = NULL;

  return EXIT_SUCCESS;
}
