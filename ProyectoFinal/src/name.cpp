#include "../include/name.hpp"

using namespace std;

Name::Name() {
  lastF = "";
  lastM = "";
  firstName = "";
}

Name::Name(const Name& other) { this->copy(other); }
Name::Name(const string& f, const string& m, const string& n) {
  lastF = f;
  lastM = m;
  firstName = n;
}

string Name::getLastF() const { return lastF; }
string Name::getLastM() const { return lastM; }
string Name::getFirstName() const { return firstName; }

void Name::setLastF(const string& f) { lastF = f; }
void Name::setLastM(const string& m) { lastM = m; }
void Name::setFirstName(const string& n) { firstName = n; }

string Name::toString() const {
  return lastF + " " + lastM + ", " + firstName;
}
Name& Name::operator=(const Name& other) {
  this->copy(other);
  return *this;
}

bool Name::operator==(const Name& n) const {return toString() == n.toString();}
bool Name::operator<(const Name& n) const { return toString() < n.toString(); }
bool Name::operator!=(const Name& n) const { return !(*this == n); }
bool Name::operator<=(const Name& n) const { return *this < n or *this == n; }
bool Name::operator>(const Name& n) const { return !(*this <= n); }
bool Name::operator>=(const Name& n) const { return !(*this < n); }

void Name::copy(const Name& other) {
  lastF = other.lastF;
  lastM = other.lastM;
  firstName = other.firstName;
}
istream& operator>>(istream& is, Name& n) { //flujo

  getline(is, n.lastF);
  getline(is, n.lastM);
  getline(is, n.firstName);
  return is;
}
ostream &operator<<(ostream& os, const Name& n) {
  os << n.lastF << endl;
  os << n.lastM << endl;
  os << n.firstName;
  return os;
}
