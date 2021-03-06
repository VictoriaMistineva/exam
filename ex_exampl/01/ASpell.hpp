#pragma once

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
    
        std::string name;
        std::string effects;

    public:
        ASpell() {};
        ASpell(std::string const &name, std::string const &effects){this->name = name; this->effects = effects;};
        ASpell(ASpell const &other) { *this = other;};
        ASpell &operator=(ASpell const &other) 
        {
            this->name = other.name;
            this->effects = other.effects;
            return (*this);
        };

        virtual ~ASpell() {};

        std::string const &getName() const { return (this->name);};
        std::string const &getEffects() const { return (this->effects);};

        void launch(ATarget const &atarget_ref) const;

        virtual ASpell *clone() const = 0;
};
