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

	class WaterPokemon :public Pokemon
	{
		string m_waterAttack;
		string m_waterDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		WaterPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_waterAttack(attack), m_waterDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};

	class PoisonPokemon :public Pokemon
	{
		string m_poisonAttack;
		string m_poisonDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		PoisonPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_poisonAttack(attack), m_poisonDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};

	class RockPokemon :public Pokemon
	{
		string m_rockAttack;
		string m_rockDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		RockPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_rockAttack(attack), m_rockDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};

	class NormalPokemon :public Pokemon
	{
		string m_normalAttack;
		string m_normalDefense;

		vector<POKETYPE> m_vulnerability;
		vector<POKETYPE> m_strongAgainst;

	public:

		NormalPokemon(string& name, POKETYPE type, string& attack, string& defense) :Pokemon(name, type), m_normalAttack(attack), m_normalDefense(defense)
		{

		}

		void printStrongAgainst(void);
		void printVulnerability(void);
		void printAttacks();
		void printDefense();
	};
}


#endif