#ifndef __SANGUINEA_H__
#define __SANGUINEA_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Sanguinea {
 public:
  enum Tipo { BASICA, MEDIA, FULL };

  Sanguinea();
  Sanguinea(Tipo tipo);
  Sanguinea(const Sanguinea&);

  Tipo getTipo() const;
  std::vector<std::string> getElementos() const;

  void mostrar() const;
  std::string toString() const;

  Sanguinea& operator=(const Sanguinea&);
  bool operator==(const Sanguinea&) const;
  bool operator!=(const Sanguinea&) const;
  bool operator<(const Sanguinea&) const;
  bool operator<=(const Sanguinea&) const;
  bool operator>(const Sanguinea&) const;
  bool operator>=(const Sanguinea&) const;

  friend std::ostream& operator<<(std::ostream&, const Sanguinea&);
  friend std::istream& operator>>(std::istream&, Sanguinea&);

 private:
  Tipo tipo;                           
  std::vector<std::string> elementos;  

  // Mapa estático que almacena los elementos de cada tipo de química sanguínea
  static const std::map<Tipo, std::vector<std::string>> elementosxTipo;

  void inicializar();
};

#endif  // __SANGUINEA_H__