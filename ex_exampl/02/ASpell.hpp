#pragma once

#include "ATarget.hpp"
#include <iostream>

// #include "Warlock.hpp"

using namespace std;


class ATarget;

class ASpell
{
    private:

    string  name;
    string  effects;

    public:

    ASpell() {};
    ASpell(string const &name, string const &effects) {this->name = name; this->effects = effects;};
    ASpell(ASpell const &obj) {*this = obj;};
    ASpell &operator = (ASpell const &obj) {this->name = obj.name; this->effects = obj.effects; return (*this);};
    virtual ~ASpell() {};

    string  const &getName() const {return (this->name);};
    string  const &getEffects() const {return (this->effects);};

    void    launch(ATarget const &obj) const;
    
    virtual ASpell  *clone () const = 0;
};