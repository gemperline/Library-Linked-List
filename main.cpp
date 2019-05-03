// Adam Gemperline
// Section 03

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "book.cpp"
#include "person.cpp"

using namespace std;

Book * findBook(vector<Book *> & b, int id);
Person * findPerson(vector<Person *> & p, int id);



Person * readPersons(vector<Person *> & myCardholders) {

  int cardID;
  bool active;
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

      // create a new person with assigned members
      personPtr = new Person(cardID, active, fName, lName);
      myCardholders.push_back(personPtr);
    }
  }
  inFile.close();
  return personPtr;
}



void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
{
  int bookID;
  int cardID;
  Book * bookPtr;
  Person* personPtr;

  ifstream inFile;
  inFile.open("rentals.txt");

  if(!inFile.is_open())
  {
    cout << "ERROR reading rentals file" << endl;
  }
  else
  {
    while(inFile >> bookID)
    {
      inFile >> cardID;
      bookPtr = findBook(myBooks, bookID);
      personPtr = findPerson(myCardholders, cardID);

      bookPtr->setPersonPtr(personPtr);
    }
    inFile.close();
  }
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
    if(p.at(i)->getID() == id)
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
    cout << endl;
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
  int cardID, bookID;
  Person * personPtr;
  Book * bookPtr;

  cout << "Please enter your card ID: ";
  cin >> cardID;

  // set local pointers to point to person/book found
  personPtr = findPerson(p,cardID);

  if(personPtr != nullptr && personPtr->isActive() == true)
  {
    cout << "Cardholder: " << personPtr->fullName() << endl;

    cout << "Please enter the book ID: ";
    cin >> bookID;

    bookPtr = findBook(b, bookID);

    if(bookPtr != nullptr && bookPtr->getPersonPtr() == nullptr)
    {
        cout << "Title: " << bookPtr->getTitle() << endl;
        cout << "Rental Completed" << endl;
        bookPtr->setPersonPtr(personPtr);
    }
    else if(bookPtr != nullptr && bookPtr->getPersonPtr() != nullptr)
    {
      cout << "Book already checked out" << endl;
    }
    else
    {
      cout << "Book ID not found." << endl;
    }
  }
  else if(personPtr->isActive() == false)
  {
    cout << "Card is inactive" << endl;
  }
  else
  {
    cout << "Card ID not found." << endl;
  }
}



void bookReturn(vector<Book *> &myBooks, vector<Person *> &myCardholders)
{
  int bookID;
  Book * bookPtr;
  Person * personPtr;

  cout << "Please enter the book ID to return: ";
  cin >> bookID;

  bookPtr = findBook(myBooks, bookID);

  if(bookPtr != nullptr  && bookPtr->getPersonPtr() != nullptr)
  {
    personPtr = nullptr;
    bookPtr->setPersonPtr(personPtr);
    cout << "Return completed" << endl;
  }
  else if(bookPtr != nullptr && bookPtr->getPersonPtr() == nullptr)
  {
    cout << "Book is not checked out" << endl;
  }
  else
    cout << "Book ID not found" << endl;
}

void * availableBooks(vector<Book *> & myBooks)
{
  Book * bookPtr;

  for(int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getPersonPtr() == nullptr)
    {
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      cout << "Author: " << myBooks.at(i)->getAuthor() << endl;
      cout << "Category: " << myBooks.at(i)->getTitle() << endl;
      cout << endl;
      bookPtr = myBooks.at(i);
    }
  }
  if(bookPtr->getPersonPtr() != nullptr)
  {
    cout << "No available books" << endl;
  }
}

Book * outstandingRentals(vector<Book *> &myBooks)
{
  Book * bookPtr;

  for(int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getPersonPtr() != nullptr)
    {
      cout << "Book ID: " << myBooks.at(i)->getId() << endl;
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      cout << "Author: " << myBooks.at(i)->getAuthor() << endl;
      cout << "Cardholder: " << myBooks.at(i)->getPersonPtr()->fullName() << endl;
      cout << endl;
      bookPtr = myBooks.at(i);
    }
  }
  if(bookPtr->getPersonPtr() == nullptr)
  {
    cout << "No outstanding rentals" << endl;
  }
}

void outstandingRentalsCardholder(vector<Book *> &myBooks, vector<Person *> &myCardholders)
{
  Book * bookPtr;
  Person * personPtr;
  int cardID;

  cout << "Please enter the card ID: ";
  cin >> cardID;
  personPtr = findPerson(myCardholders, cardID);
  cout << personPtr->fullName() << endl;
  cout << personPtr->getID() << endl;

  for(int i = 0; i < myBooks.size(); i++)
  {
    bookPtr = myBooks.at(i);
    cout << myBooks.at(i)->getPersonPtr()->getID() << endl;
    /*
    if(myBooks.at(i)->personPtr->getId())
    {
      cout << "Book ID: " << myBooks.at(i)->getId() << endl;
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      cout << "Author: " << myBooks.at(i)->getAuthor() << endl;
      cout << endl;
    }*/
  }
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
  vector<Book *> rentalBooks;
  vector<Person *> rentalCardholders;
  int option;

  readBooks(books);
  readPersons(cardholders);
  readRentals(books, cardholders);
  printMenu();

  // Menu loops until exit is selected
  do
  {
    cout << "\nOption: ";
    cin >> option;
    cout << endl;

    switch (option)
    {
      case 1:
        bookCheckout(cardholders, books);
        break;
      case 2:
        bookReturn(books, cardholders);
        break;
      case 3:
        availableBooks(books);
        break;
      case 4:
        outstandingRentals(books);
        break;
      case 5:
        outstandingRentalsCardholder(books, cardholders);
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
