// Adam Gemperline
// Section 03

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "book.cpp"
#include "person.cpp"

using namespace std;

/* You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
    return;
}

int readPersons(vector<Person *> & myCardholders) {
    return 0;
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
    return;
}

void openCard(vector<Person *> & myCardholders, int nextID) {
    return;
}

Book * searchBook(vector<Book *> myBooks, int id) {
    return nullptr;
}
*/

void readBooks(vector<Book *> & myBooks)
{
  string input;
  int bookID;
  string title;
  string author;
  string category;

  Book * bookPtr;

  ifstream inFile;
  inFile.open("books.txt");

  if(!inFile.is_open())
  {
    cout << "ERROR opening file" << endl;
  }
  else
  {
    while(inFile >> bookID)
    {
      inFile >> title >> author >> category;
      cout << "ID: " << bookID << endl;
      cout << "Title: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "Category: " << category << endl;

      bookPtr = new Book(bookID, title, author, category);

      myBooks.push_back(bookPtr);

    }
  }
}

void printMenu()
{
  // LIBRARY RENTAL MENU
    cout << "----------------------------------------------------------" << endl;
    cout << "Welcome to the rental portal. Please choose from the menu." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "\nPlease enter a choice: ";
}


void bookCheckout()
{
  int cardID, bookID;

  cout << "Please enter the card ID: ";
  cin >> cardID;
  cout << "Please enter the book ID: ";
  cin >> bookID;

}


void bookReturn()
{

}

Book * availableBooks(vector<Book *> & myBooks)
{

}

Book * outstandingRentals()
{

}

void outstandingRentalsCardholder()
{

}

void newCard()
{

}

void closeCard()
{

}



int main()
{
  vector<Book *> books;
  vector<Person *> cardHolders;
  int option;
  readBooks(books);

  printMenu();
  cin >> option;

  // Menu loops until exit is selected
  do
  {
    switch (option)
    {
      case 1:
        bookCheckout();
        break;
      case 2:
        bookReturn();
        break;
      case 3:
        availableBooks(books);
        break;
      case 4:
        outstandingRentals();
        break;
      case 5:
        outstandingRentalsCardholder();
        break;
      case 6:
        newCard();
        break;
      case 7:
        closeCard();
        break;
      case 8:
        break;
    }
    cout << endl;
  } while (option != 8);



  return 0;
}
