#ifndef _FECHA_H_
#define _FECHA_H_

#include <chrono>
#include <iostream>
#include <string>

class Fecha {
 private:
  int day;
  int month;
  int year;

  void copy(const Fecha &);

 public:
  Fecha();
  Fecha(const Fecha &);
  Fecha(const int &, const int &, const int &); 

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  void setDay(const int &d);
  void setMonth(const int &m);
  void setYear(const int &y);

  std::string toString() const;
  int toInt() const;

  Fecha &operator=(const Fecha &);

  bool operator==(const Fecha &) const;
  bool operator!=(const Fecha &) const;
  bool operator<(const Fecha &) const;
  bool operator<=(const Fecha &) const;
  bool operator>(const Fecha &) const;
  bool operator>=(const Fecha &) const;

  friend std::ostream &operator<<(std::ostream &, const Fecha &); 
  friend std::istream &operator>>(std::istream &, Fecha &); 
};

#endif  // _FECHA_H_
