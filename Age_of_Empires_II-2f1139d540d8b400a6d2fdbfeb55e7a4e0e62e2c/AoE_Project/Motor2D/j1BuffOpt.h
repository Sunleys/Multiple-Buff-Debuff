#ifndef __j1BUFFOPT_H__
#define __j1BUFFOPT_H__

#include "j1Timer.h"
#include "j1Module.h"

struct Buff
{
	j1Timer timer;
	uint timer_duration;
	std::string buffdebuff_name;
	std::string type;
	std::string attr_to_change;
	int oper;  //operator
	float value;
	std::string cast;
};

enum Operators
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
	bool LoadBuffDebuff(pugi::xml_node& bd_node, Buff* bd);

	//bool ApplyBuff(std::string buff_name, j1PlayerOpt id_players);

	bool CheckAppliedBuff(std::list<Buff*> appliedbuffList);

private:

	std::list<Buff*> buffsList;
	std::list<Buff*> appliedbuffList;
	Buff* buff_debuff;
};

#endif //__j1BUFFOPT_H__