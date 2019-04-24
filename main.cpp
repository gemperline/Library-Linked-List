// Adam Gemperline
// Section 03

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "book.cpp"
#include "person.cpp"

using namespace std;




Person * readPersons(vector<Person *> & myCardholders) {

  string cardID;
  string active;
  string fName;
  string lName;
  string fullName;
  Person * personPtr;

  ifstream inFile;
  inFile.open("persons.txt");

  if(!inFile.is_open())
  {
    cout << "ERROR opening file ..." << endl;
  }
  else
  {
    cout << "Reading cardholders into vector ..." << endl;

    while(inFile >> cardID)
    {
      inFile >> active >> fName >> lName;

      fullName = fName + " " + lName;

      // parse strings to types
      int cID = stoi(cardID);
      bool act = stoi(active);

      // create a new person with assigned members
      personPtr = new Person(cID, act, fName, lName);
      myCardholders.push_back(personPtr);
    }
  }
  inFile.close();
  return personPtr;
}




void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
    return;
}

void openCard(vector<Person *> & myCardholders, int nextID) {
    return;
}




Book * readBooks(vector<Book *> & myBooks)
{
  string line;
  string bookID;
  string title;
  string author;
  string category;
  Book * bookPtr;

  ifstream inFile;
  inFile.open("books.txt");

  if(!inFile.is_open())
  {
    cout << "ERROR opening file ..." << endl;
  }
  else
  {
    cout << "Reading books into vector ..." << endl;

    while(!inFile.eof())
    {
      getline(inFile, bookID);
      getline(inFile, title);
      getline(inFile, author);
      getline(inFile, category);
      getline(inFile, line);
/*
      cout << "ID: " << bookID << endl;
      cout << "Title: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "Category: " << category << endl;
      cout << endl;
*/
      // parse string to int
      int bID = stoi(bookID);
      // create a new book with assigned members
      bookPtr = new Book(bID, title, author, category);
      myBooks.push_back(bookPtr);

    }
  }
  inFile.close();
  return bookPtr;
}



Person * findPerson(vector<Person *> & p, int id)
{
  for(int i = 0; i < p.size(); i++)
  {
    if(p.at(i)->getId() == id)
      return p.at(i);
  }
  // if person not found, return nullptr
  return nullptr;
}



Book * findBook(vector<Book *> & b, int id)
{
  for(int i = 0; i < b.size(); i++)
  {
    if(b.at(i)->getId() == id)
      return b.at(i);
  }
  // if book not found, return nullptr
  return nullptr;
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


void bookCheckout(vector<Person *> & p, vector<Book *> & b)
{
  // create local ptrs and set equal to calling search function
  int cardID, bookID;
  Person * pPtr =; // 
  cout << "Please enter your card ID: ";
  cin >> cardID;

  if(findPerson(p,cardID) != nullptr)
  {
    cout << "Cardholder: " << p->fullName() << endl;

    cout << "Please enter the book ID: ";
    cin >> bookID;

    if(findBook(b, bookID) != nullptr)
    {

      cout << "Title: " << b->getTitle() << endl;
    }
    else
    {
      cout << "Book not found." << endl;
    }
  }
  else
  {
    cout << "ID not found." << endl;
  }
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
  vector<Person *> cardholders;
  int option;

  readBooks(books);
  readPersons(cardholders);
  printMenu();

  // Menu loops until exit is selected
  do
  {
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
      case 1:
        bookCheckout(cardholders, books);
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
