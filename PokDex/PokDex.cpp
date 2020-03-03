// PokDex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "include/Pokedex.h"

using namespace std;
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

void GrassPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_grassAttack;
}

void GrassPokemon::printDefense()
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

void FirePokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_fireAttack;
}

void FirePokemon::printDefense()
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

// Water Pokemon functions
void WaterPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Fire, Rock, Grass";
}

void WaterPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Electric, Poison ";
}

void WaterPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_waterAttack;
}

void WaterPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_waterDefense;
}

// Poison Pokemon functions
void PoisonPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Normal, Grass";
}

void PoisonPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Fire, Electric";
}

void PoisonPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_poisonAttack;
}

void PoisonPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_poisonDefense;
}

// Rock Pokemon functions
void RockPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: Electric, Grass, Fire, Normal";
}

void RockPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Water";
}

void RockPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_rockAttack;
}

void RockPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_rockDefense;
}

// Normal Pokemon functions
void NormalPokemon::printStrongAgainst()
{
    cout << "\n Strong Against: None";
}

void NormalPokemon::printVulnerability()
{
    cout << "\n Vulnerable Against: Fire, Poison, Electric, Rock";
}

void NormalPokemon::printAttacks()
{
    cout << " \n Main Attack: " << this->m_normalAttack;
}

void NormalPokemon::printDefense()
{
    cout << "\n Main Defense: " << this->m_normalDefense;
}

int main()
{
    string Pokename;
    int Poketype;

    bool loop = true;

    cout << " Welcome to PokeDex!";

    do
    {
        cout << "\n Enter name and type of Pokemon to learn more about the Pokemon";
        cout << "\n Refer to the following list for type of Pokemon";
        cout << "\n  Pokemon     Type \n   Grass        0  \n   Fire         1  \n   Water        2   \n   Electric     3 \n   Rock         4 \n   Poison       5 \n   Psychic      6  \n   Normal       7";
        cout << "\n Name : "; cin >> Pokename;
        cout << "\n Type : "; cin >> Poketype;

        if (Poketype < 0 || Poketype > 7)
        {
            cout << "\n Incorrect type entered (must be from 0 to 7). \n Please refer to the type list and try again. \n Exiting.";
            continue;
        }

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
            string attack = "Water Gun";
            string defense = "Dodge";
            WaterPokemon waterPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
            waterPokemon.printDetails();
        }
        break;
        case POKETYPE::POISON_POKEMON:
        {
            string attack = "Poison Gas";
            string defense = "Dodge";
            PoisonPokemon poisonPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
            poisonPokemon.printDetails();
        }
        break;
        case POKETYPE::ROCK_POKEMON:
        {
            string attack = "Earthquake";
            string defense = "Endure";
            RockPokemon rockPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
            rockPokemon.printDetails();
        }
        break;
        default:
        {
            string attack = "Tackle";
            string defense = "Dodge";
            NormalPokemon normalPokemon(Pokename, static_cast <POKETYPE> (Poketype), attack, defense);
            normalPokemon.printDetails();
        }
        }

        string input;
        cout << "\n To try again: enter Y / y  \n To exit : enter N / n \n";
        cin >> input;

        if (!input.compare("Y") || !input.compare("y"))
        {
            loop = true;
        }
        else
        {
            loop = false;
        }
    } while (loop);

    return 0;
}

