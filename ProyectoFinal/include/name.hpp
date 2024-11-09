#ifndef _NAME_H_
#define _NAME_H_

#include <string>
#include <iostream>

class Name {
 private:
  std::string lastF;
  std::string lastM;
  std::string firstName;

  void copy(const Name&);

 public:
  Name();
  Name(const Name&);
  Name(const std::string&, const std::string&, const std::string&);

  std::string getLastF() const;
  std::string getLastM() const;
  std::string getFirstName() const;

  void setLastF(const std::string&);
  void setLastM(const std::string&);
  void setFirstName(const std::string&);

  std::string toString() const;

  Name& operator=(const Name&);

  bool operator==(const Name&) const;
  bool operator!=(const Name&) const;
  bool operator<(const Name&) const;
  bool operator<=(const Name&) const;
  bool operator>(const Name&) const;
  bool operator>=(const Name&) const;

  friend std::ostream& operator<<(std::ostream&, const Name&); 
  friend std::istream& operator>>(std::istream&, Name&);
};
#endif  // _NAME_H_