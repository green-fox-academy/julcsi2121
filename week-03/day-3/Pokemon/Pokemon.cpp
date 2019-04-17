//
// Created by Varga Júlia on 2019-04-17.
//

#include "Pokemon.h"

Pokemon::Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst)
{
    _name = name;
    _type = type;
    _effectiveAgainst = effectiveAgainst;
}

bool Pokemon::isEffectiveAgainst(Pokemon anotherPokemon)
{
    return _effectiveAgainst == anotherPokemon._type;
}
