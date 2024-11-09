#include "../include/fecha.hpp"
#include <stdexcept>
using namespace std;

void Fecha::copy(const Fecha &d) {
  year = d.year;
  month = d.month;
  day = d.day;
}

Fecha::Fecha() {
  chrono::system_clock::time_point today(chrono::system_clock::now());
  time_t tt(chrono::system_clock::to_time_t(today));
  struct tm *timeinfo = localtime(&tt);

  if (timeinfo) {
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
  } else {
    throw runtime_error("Error obteniendo la fecha actual.");
  }
}

Fecha::Fecha(const Fecha &d) { this->copy(d); }

Fecha::Fecha(const int &d, const int &m, const int &y) : day(d), month(m), year(y) {
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
    throw invalid_argument("Fecha inválida");
  }
}

int Fecha::getDay() const { return day; }
int Fecha::getMonth() const { return month; }
int Fecha::getYear() const { return year; }

void Fecha::setDay(const int &d) {
  if (d > 0 && d <= 31) day = d;
  else throw invalid_argument("Día inválido");
}

void Fecha::setMonth(const int &m) {
  if (m > 0 && m <= 12) month = m;
  else throw invalid_argument("Mes inválido");
}

void Fecha::setYear(const int &y) {
  if (y >= 0) year = y;
  else throw invalid_argument("Año inválido");
}

std::string Fecha::toString() const {
  return (day < 10 ? "0" : "") + to_string(day) + "/" +
         (month < 10 ? "0" : "") + to_string(month) + "/" +
         to_string(year);
}

int Fecha::toInt() const {
  return year * 10000 + month * 100 + day;
}

Fecha &Fecha::operator=(const Fecha &d) {
  if (this != &d) {
    this->copy(d);
  }
  return *this;
}

bool Fecha::operator==(const Fecha &d) const { return toInt() == d.toInt(); }
bool Fecha::operator!=(const Fecha &d) const { return !(*this == d); }
bool Fecha::operator<(const Fecha &d) const { return toInt() < d.toInt(); }
bool Fecha::operator<=(const Fecha &d) const { return !(*this > d); }
bool Fecha::operator>(const Fecha &d) const { return toInt() > d.toInt(); }
bool Fecha::operator>=(const Fecha &d) const { return !(*this < d); }

istream &operator>>(istream &is, Fecha &d) {
  char separator;
  if (!(is >> d.day >> separator >> d.month >> separator >> d.year) ||
      d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year < 0) {
    is.setstate(ios::failbit);
    throw invalid_argument("Entrada de fecha inválida");
  }
  return is;
}

ostream &operator<<(ostream &os, const Fecha &d) {
  os << (d.day < 10 ? "0" : "") << d.day << "/"
     << (d.month < 10 ? "0" : "") << d.month << "/"
     << d.year;
  return os;
}
