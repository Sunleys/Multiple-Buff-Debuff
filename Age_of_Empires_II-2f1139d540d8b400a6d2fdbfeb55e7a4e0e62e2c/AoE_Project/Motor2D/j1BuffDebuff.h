#ifndef __j1BUFFDEBUFF_H__
#define __j1BUFFDEBUFF_H__

#include "j1Timer.h"
#include "j1Module.h"

struct Buff
{
	uint timer_duration;
	std::string buffdebuff_name;
	std::string type; 
	std::string attr_to_change;
	int oper;  //operator
	float value;
	std::string target;
};

struct AppliedBuff
{
	j1Timer timer;
	uint timer_duration;
	std::string attr_to_change;
	std::string id_player_buffed;
	float original_value;
};
enum Operators
{
	sum = 0,  
	substract, 
	multiply, 
	divide
};


class j1BuffDebuff : public j1Module
{
	public:
		j1BuffDebuff();

		// Destructor
		virtual ~j1BuffDebuff();

		// Called before render is available
		bool Awake(pugi::xml_node& info);

		// Called before the first frame
		bool Start();

		// Called each loop iteration
		bool Update(); 
		//bool PreUpdate();
		//bool PostUpdate();

		// Called before quitting
		bool CleanUp();
	
		pugi::xml_node LoadXMLBuffDebuff(pugi::xml_document& bd_file) const;

		//Utils
		bool AddBuffToList(Buff* bd);

		bool LoadBuffDebuff(pugi::xml_node& bd_node, Buff* bd);

		bool CheckTypeBuffDebuff(std::string type, std::string name_buff, std::string id_player); 

		bool ApplyBuffAttributes(std::string buff_name, std::string id_players);
		bool ApplyBuffItems(std::string buff_name);
		bool ApplyBuffTerrain(std::string buff_name);

		bool CreateAppliedBuff(j1Timer timer, uint timer_duration, std::string attr_to_change, std::string id_player_buffed, float original_value);
	
	private: 
		
		std::list<Buff*> buffList;
		std::list<AppliedBuff*> appliedBuffList;
		Buff* buff_debuff;
		AppliedBuff* app_buff;
		j1Timer timer;
}; 











































#endif // __j1BUFFDEBUFF_H__