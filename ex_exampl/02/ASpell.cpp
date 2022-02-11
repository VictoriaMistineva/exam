#include "ASpell.hpp"

void    ASpell::launch(ATarget const &obj) const
{
    obj.getHitBySpell(*this);
}