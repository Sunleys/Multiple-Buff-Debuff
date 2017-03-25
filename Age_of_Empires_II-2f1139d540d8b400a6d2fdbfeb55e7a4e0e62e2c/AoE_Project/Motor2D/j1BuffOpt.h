#ifndef __j1BUFFOPT_H__
#define __j1BUFFOPT_H__

#include "j1Timer.h"
#include "j1Module.h"
#include "j1Player.h"
#include "j1App.h"
#include "p2Log.h"
#include "j1FileSystem.h"

struct Buffs
{
	Buffs(uint timer_duration, std::string buffdebuff_name, std::string type, std::string attr_to_change, int oper, float value) : timer_duration(timer_duration), buffdebuff_name(buffdebuff_name), type(type), attr_to_change(attr_to_change), oper(oper), value(value) {}
	j1Timer timer;
	uint timer_duration;
	std::string buffdebuff_name;
	std::string type;
	std::string attr_to_change;
	int oper;  //operator
	float value;
};

enum Opers
{
	SUM = 0,
	SUBSTRACT,
	MULTIPLY,
	DIVIDE
}; 

class j1BuffOpt : public j1Module
{
public:
	j1BuffOpt();

	// Destructor
	virtual ~j1BuffOpt();

	// Called before render is available
	bool Awake(pugi::xml_node& info);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	bool PreUpdate();
	// Called before quitting
	bool CleanUp();

	pugi::xml_node LoadXMLBuffDebuff(pugi::xml_document& bd_file) const;

	//Utils
	Buffs SearchBuff(std::string buff_name, std::list<Buffs*> buffList);

	bool ApplyBuffs(std::string buff_name, j1Player* target, std::list<Buffs*> buffList);

	bool CheckAppliedBuff(std::list<Buffs*> appliedbuffList);

private:

	std::list<Buffs*> buffsList;
	std::list<Buffs*> appliedbuffList;
	Buffs* buffs;
};

#endif //__j1BUFFOPT_H__