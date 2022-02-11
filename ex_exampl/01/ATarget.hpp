#pragma once

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:

        std::string type;
    
    public:
        ATarget() {};
        ATarget(std::string const &type) { this->type = type;};
        ATarget(ATarget const &other) { *this = other;};

        ATarget &operator=(ATarget const &other) {this->type = other.type; return (*this);};
        
        virtual ~ATarget() {};

        std::string const &getType() const {return (this->type);};

        void getHitBySpell(ASpell const &aspell_ref) const;

        virtual ATarget *clone() const = 0;
};
