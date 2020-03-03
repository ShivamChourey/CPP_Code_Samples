#pragma once
#ifndef POKEDEX
#define POKEDEX

#include <string>
#include <vector>

using namespace std;

namespace PokeDex
{
	enum POKETYPE
	{
		GRASS_POKEMON,
		FIRE_POKEMON,
		WATER_POKEMON,
		ELECTRIC_POKEMON,
		ROCK_POKEMON,
		POISON_POKEMON,
		PSYCHIC_POKEMON,
		NORMAL_POKEMON
	};

	class Pokemon
	{
		string m_name;
		POKETYPE m_type;

	public:

		Pokemon()
		{
			this->m_name.clear();
			this->m_type = POKETYPE::NORMAL_POKEMON;
		}

		Pokemon(string& name, POKETYPE type) :m_name(name), m_type(type) {}

		string getName()
		{
			return this->m_name;
		}

		string getType();
		void printDetails();

		virtual void printAttacks() {};
		virtual void printDefense() {};
		virtual void printStrongAgainst() {};
		virtual void printVulnerability() {};
		
	};

	class GrassPokemon :public Pokemon
	{
		string m_grassAttack;
		string m_grassDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		GrassPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_grassAttack(attack), m_grassDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};

	class FirePokemon :public Pokemon
	{
		string m_fireAttack;
		string m_fireDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		FirePokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_fireAttack(attack), m_fireDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};

	class ElectricPokemon :public Pokemon
	{
		string m_electricAttack;
		string m_electricDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		ElectricPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_electricAttack(attack), m_electricDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};
}


#endif