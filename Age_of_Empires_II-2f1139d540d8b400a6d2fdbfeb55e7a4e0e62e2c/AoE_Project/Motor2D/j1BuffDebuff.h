#ifndef __j1BUFFDEBUFF_H__
#define __j1BUFFDEBUFF_H__

#include "j1Module.h"


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
	
		pugi::xml_node LoadBuffDebuff(pugi::xml_document& bd_file) const;

	private: 
		std::string buffdebuff_name; 
		float duration; 
		std::string oper;  //operator
		float value; 
		std::string target; 


}; 











































#endif // __j1BUFFDEBUFF_H__