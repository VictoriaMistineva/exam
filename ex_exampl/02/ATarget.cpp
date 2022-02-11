#include "ATarget.hpp"

void ATarget::getHitBySpell(ASpell const &obj) const
{
    std::cout << this->type << " has been " << obj.getEffects() << "!\n";
};