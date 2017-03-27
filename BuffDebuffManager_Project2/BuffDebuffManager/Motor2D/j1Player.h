#ifndef _J1_PLAYER_H_
#define _J1_PLAYER_H_

#include "j1Module.h"
#include "j1BuffDebuff.h"
#include "UI_String.h"

class j1Player : public j1Module
{
public:
	j1Player();

	// Destructor
	virtual ~j1Player();

	// Called before render is available
	bool Awake(pugi::xml_node& info);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update(float dt);
	
	bool PreUpdate();

	bool PostUpdate();

	// Called before quitting
	bool CleanUp();
	
	//Getters
	std::string GetPlayerId()const { return id; }
	uint GetPlayerLife()const { return life; }
	uint GetPlayerDefense()const { return defense; }
	uint GetPlayerAgility()const { return agility; }
	uint GetPlayerAttack()const { return attack; }
	//Setters
	void SetPlayerLife(uint life) { this->life = life; }
	void SetPlayerDefense(uint defense) { this->defense = defense; }
	void SetPlayerAgility(uint agility) { this->agility = agility; }
	void SetPlayerAttack(uint attack) { this->attack = attack; }

	//Utils
	pugi::xml_node LoadXMLPlayers(pugi::xml_document& player_doc);
	bool LoadPlayers(pugi::xml_node& node);
	
	
private: 
	std::string id;
	uint life;
	uint defense;
	uint agility;
	uint attack;

	pugi::xml_node p_node;
	UI_String*	str_life;
	UI_String*	str_attack;
	UI_String*	str_agility;
	UI_String*	str_defense;
};




#endif // _J1_PLAYER_H_
