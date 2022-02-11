#pragma once

#include "ASpell.hpp"
#include <iostream>

// #include "Warlock.hpp"

using namespace std;


class ASpell;

class ATarget
{
    private:

    string  type;

    public:

    ATarget() {};
    ATarget(string const &type) {this->type = type;};
    ATarget(ATarget const &obj) {*this = obj;};

    ATarget &operator = (ATarget const &obj) {this->type = obj.type; return (*this);};

    virtual ~ATarget() {};

    string  const &getType() const {return (this->type);};

    void    getHitBySpell(ASpell const &obj) const;

    virtual ATarget  *clone () const = 0;
};