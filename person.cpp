#include "person.h"

Person::Person(int cardNo, bool act, string fName, string lName) {
    cardID = cardNo;
    active = act;
    firstName = fName;
    lastName = lName;
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

int Person::getID() {
    return cardID;
}

void Person::setActive(bool act) {
  active = act;
}

bool Person::isActive() {
  if(active)
    return true;
  else
    return false;
}

string Person::fullName() {
    return firstName + " " + lastName;
}
