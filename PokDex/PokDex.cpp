// PokDex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "include/Pokedex.h"

using namespace PokeDex;

// Generic Pokemon function
string Pokemon::getType()
{
    switch (this->m_type)
    {
    case GRASS_POKEMON:
    {
        return string("Grass");
    }
    break;
    case FIRE_POKEMON:
    {
        return string("Fire");
    }
    break;
    case WATER_POKEMON:
    {
        return string("Water");
    }
    break;
    case ELECTRIC_POKEMON:
    {
        return string("Electric");
    }
    break;
    case ROCK_POKEMON:
    {
        return string("Rock");
    }
    break;
    case POISON_POKEMON:
    {
        return string("Poison");
    }
    break;
    case PSYCHIC_POKEMON:
    {
        return string("Psychic");
    }
    break;
    default:
    {
        return string("Normal");
    }
    }
}


void Pokemon::printDetails()
{
    cout << "\n Name: "<<this->getName();
    cout << "\n Type: " << this->getType();
    this->printAttacks();
    this->printDefense();
    this->printStrongAgainst();
    this->printVulnerability();

    cout << "\n \n \n";

}

// Grass Pokemon functions
void GrassPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Normal";
}

void GrassPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Electric, Water, Fire";
}

void PokeDex::GrassPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_grassAttack;
}

void PokeDex::GrassPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_grassDefense;
}

// Fire Pokemon functions
void FirePokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Normal, Grass, Electric";
}

void FirePokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Water, Rock";
}

void PokeDex::FirePokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_fireAttack;
}

void PokeDex::FirePokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_fireDefense;
}

// Electric Pokemon functions
void ElectricPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Normal, Grass, Water, Poison";
}

void ElectricPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Fire, Rock";
}

void ElectricPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_electricAttack;
}

void ElectricPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_electricDefense;
}

int main()
{
    string Pokename;
    int Poketype;
    std::cout << " Welcome to PokeDex!\n"<<"\n Enter the Pokemon name and type: ";
    cin >> Pokename;
    cin >> Poketype;

    switch (Poketype)
    {
	case POKETYPE::ELECTRIC_POKEMON:
	{
		string attack = "Thunderbolt";
		string defense = "Dodge";
		ElectricPokemon electricPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
		electricPokemon.printDetails();
	}
	break;
    case POKETYPE::FIRE_POKEMON:
    {
        string attack = "FireBall";
        string defense = "Steady";
        FirePokemon firePokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
        firePokemon.printDetails();
    }
    break;
    case POKETYPE::GRASS_POKEMON:
    {
        string attack = "Tackle";
        string defense = "Dodge";
        GrassPokemon grassPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
        grassPokemon.printDetails();
    }
    break;
    case POKETYPE::WATER_POKEMON:
    {

    }
    break;
    case POKETYPE::POISON_POKEMON:
    {

    }
    break;
    case POKETYPE::ROCK_POKEMON:
    {

    }
    break;
    default:
    {

    }
    }
}

