#ifndef __PACIENTE_H__
#define __PACIENTE_H__

#include<string>
#include"name.hpp"

class Paciente{
    protected:
    std::string nss;
    std::string code;
    Name name;

    public:
    Paciente();
    Paciente(const Paciente&);
    std::string getNss();
    std::string getCode();
    Name getName();

    void setNss(const std::string&);
    void setCode(const std::string&);
    void setName(const Name&);

    std::string toString() const;
    Paciente& operator=(const Paciente&);

    bool operator==(const Paciente&) const;
    bool operator!=(const Paciente&) const;
    bool operator<(const Paciente&) const;
    bool operator<=(const Paciente&) const;
    bool operator>(const Paciente&) const;
    bool operator>=(const Paciente&) const;

    friend std::ostream& operator<<(std::ostream&, const Paciente&);
    friend std::istream& operator>>(std::istream&, Paciente&);
};

#endif // __PACIENTE_H__
