#ifndef _J1_PLAYER_H_
#define _J1_PLAYER_H_

#include "j1Module.h"
#include "j1BuffDebuff.h"
#include "UI_Text_Box.h"

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
	int GetPlayerDefense()const { return defense; }
	int GetPlayerAgility()const { return agility; }
	int GetPlayerAttack()const { return attack; }
	//Setters
	void SetPlayerLife(uint life) { this->life = life; }
	void SetPlayerDefense(int defense) { this->defense = defense; }
	void SetPlayerAgility(uint agility) { this->agility = agility; }
	void SetPlayerAttack(uint attack) { this->attack = attack; }

	//Utils
	pugi::xml_node LoadXMLPlayers(pugi::xml_document& player_doc);
	bool LoadPlayers(pugi::xml_node& node, j1Player* unit);
	
	std::list<j1Player*> unitList;
	
private: 
	std::string id;
	uint life;
	int defense;
	int agility;
	int attack;

	pugi::xml_node p_node;
	UI_Text_Box* txt;

};




#endif // _J1_PLAYER_H_
