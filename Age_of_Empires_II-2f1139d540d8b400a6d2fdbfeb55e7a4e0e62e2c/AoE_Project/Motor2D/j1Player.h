#ifndef _J1_PLAYER_H_
#define _J1_PLAYER_H_

#include "j1Module.h"
#include "j1BuffDebuff.h"

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

private: 
	uint life;
	int defense;
	int agility;
	int attack;

};




#endif // _J1_PLAYER_H_
