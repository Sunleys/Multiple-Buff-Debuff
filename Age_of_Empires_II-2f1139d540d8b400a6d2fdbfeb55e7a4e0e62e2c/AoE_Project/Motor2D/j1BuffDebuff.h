#ifndef __j1BUFFDEBUFF_H__
#define __j1BUFFDEBUFF_H__

#include "j1Module.h"

struct Buff
{
	std::string buffdebuff_name;
	float duration;
	std::string oper;  //operator
	float value;
	std::string target;
};


struct 
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

	private: 
		
		pugi::xml_document	buff_file;
		std::list<Buff*> buffList;
		Buff* buff_debuff;

}; 











































#endif // __j1BUFFDEBUFF_H__