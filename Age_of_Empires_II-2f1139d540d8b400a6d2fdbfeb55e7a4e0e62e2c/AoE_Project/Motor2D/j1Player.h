#ifndef _J1_PLAYER_H_
#define _J1_PLAYER_H_

#include "j1Module.h"
#include "j1BuffDebuff.h"

struct Info_players
{
	std::string id;
	uint life;
	int defense;
	int agility;
	int attack;
};

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
	bool Update();
	
	bool PreUpdate();

	bool PostUpdate();

	// Called before quitting
	bool CleanUp();
	
	pugi::xml_node LoadXMLPlayers(pugi::xml_document& player_doc);
	bool ModifyAttributes(std::list<Info_players*>list_player, float value);
	bool AddPlayers(Info_players* player);
	bool LoadPlayers(pugi::xml_node& node, Info_players* unit);
	
	std::list<Info_players*> playerList;
	

private: 

	pugi::xml_node p_node;
	Info_players* info_players;
};




#endif // _J1_PLAYER_H_
