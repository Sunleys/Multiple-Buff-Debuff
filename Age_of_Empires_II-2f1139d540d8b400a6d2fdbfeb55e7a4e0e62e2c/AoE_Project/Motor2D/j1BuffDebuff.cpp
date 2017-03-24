#include <sstream> 
#include <time.h>
#include "p2Log.h"
#include "j1Input.h"
#include "j1BuffDebuff.h"
#include "j1App.h"
#include "j1FileSystem.h"
#include "j1Player.h"
#include "SDL/include/SDL.h"

j1BuffDebuff::j1BuffDebuff() : j1Module()
{
	name = "buffdebuff";

}

j1BuffDebuff::~j1BuffDebuff()
{}

pugi::xml_node j1BuffDebuff::LoadXMLBuffDebuff(pugi::xml_document& bd_file) const
{
	pugi::xml_node ret;

	char* buf;
	int size = App->fs->Load("buff_debuff.xml", &buf);
	pugi::xml_parse_result result = bd_file.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL)
		LOG("Could not load xml file buff_debuff.xml. pugi error: %s", result.description());
	else
		ret = bd_file.child("buff_debuff");

	return ret;
}


bool j1BuffDebuff::LoadBuffDebuff(pugi::xml_node & bd_node, Buff * bd)
{
	bool ret = false;

	if (bd_node && bd)
	{
		pugi::xml_node node_buff;

		ret = true;
		
		bd->type = bd_node.parent().attribute("id").as_string();
		bd->buffdebuff_name = bd_node.child_value();
		bd->timer_duration = bd_node.attribute("timer_duration").as_uint();
		bd->oper = bd_node.attribute("operator").as_int();
		bd->value = bd_node.attribute("value").as_float();
		bd->target = bd_node.attribute("target").as_string();
		bd->attr_to_change = bd_node.attribute("attr_to_change").as_string();
	}
	return ret;
}

bool j1BuffDebuff::AddBuffToList(Buff* bd)
{
	buffList.push_back(bd);

	return true;
}

bool j1BuffDebuff::Awake(pugi::xml_node& info)
{
	pugi::xml_document info_buffdebuff;
	pugi::xml_node     bd_node;
	pugi::xml_node     bd_info;

	bool ret = true;

	bd_info = LoadXMLBuffDebuff(info_buffdebuff);

	//Load App config data

	if (bd_info.empty() == false)
	{
		// self-config
		for (bd_node = info_buffdebuff.child("buff_debuff").child("buff").child("type"); bd_node && ret; bd_node = bd_node.next_sibling("type"))
		{
			for (pugi::xml_node node = bd_node.child("name"); node && ret; node = node.next_sibling("name"))
			{
				Buff* bd = new Buff();

				ret = LoadBuffDebuff(node, bd);
				AddBuffToList(bd);
				//LOG(" BUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUFF DEBUFF %s %d %c %s %s",bd->buffdebuff_name, bd->duration, bd->oper, bd->target, bd->value);
			}
		}
	}

	return ret;
}

// Called before the first frame
bool j1BuffDebuff::Start()
{
	return true;
}

// Called each loop iteration
bool j1BuffDebuff::Update()
{
	return true;
}

bool j1BuffDebuff::PreUpdate()
{
	CheckAppliedBuff(appliedBuffList);

	return true;
}

// Called before quitting
bool j1BuffDebuff::CleanUp()
{
	return true; 
}

bool j1BuffDebuff::CheckTypeBuffDebuff(std::string type, std::string name_buff, std::string id_player)
{
	std::list<Buff*>::iterator item = buffList.begin();
	while (item != buffList.end())
	{
		if ((*item)->type == type && (*item)->buffdebuff_name == name_buff)
		{
			if (type == "attribute")
			{
				ApplyBuffAttributes((*item)->buffdebuff_name, id_player);
			}
			else if (type == "item")
			{
				ApplyBuffItems((*item)->buffdebuff_name);
			}
			else
			{
				LOG("ANY TYPE BUFF DEBUFF :')");
			}
			item++;
		}
		else
		{
			item++;
			LOG("It doesn't work! =( "); 
		}
	}

	return true; 
}


bool j1BuffDebuff::ApplyBuffAttributes(std::string buff_name, std::string id_players)
{
	
	std::list<Buff*>::iterator item = buffList.begin();
	while (item != buffList.end())
	{
		std::list<Info_players*>::iterator it_player = App->player->playerList.begin();
		while (it_player != App->player->playerList.end())
		{
			if ((*item)->buffdebuff_name == buff_name)
			{
				switch ((*item)->oper)
				{
				case(sum) :

					if ((*item)->target == "enemy")
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}

					}
					else
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life += (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
					}

						  break;

				case(substract) :

					if ((*item)->target == "enemy")
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}

					}
					else
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life -= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
					}

								break;

				case(multiply) :

					if ((*item)->target == "enemy")
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
					}
					else
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life *= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
					}

							   break;

				case(divide) :

					if ((*item)->target == "enemy")
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}

					}
					else
					{
						if ((*item)->attr_to_change == "defense" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->defense;
							(*it_player)->defense /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "attack" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->attack;
							(*it_player)->attack /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "agility" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->agility;
							(*it_player)->agility /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
						else if ((*item)->attr_to_change == "life" && (*it_player)->id == id_players)
						{
							float original_value = (*it_player)->life;
							(*it_player)->life /= (*item)->value;
							AppliedBuff app_buff((*item)->timer_duration, (*item)->attr_to_change, id_players, original_value);
							appliedBuffList.push_back(&app_buff);
							app_buff.timer.Start();
						}
					}

							 break;

				default:


					break;
				}
			}
			it_player++;
		}
		
		item++;
	}

	return true; 
}

bool j1BuffDebuff::CheckAppliedBuff(std::list<AppliedBuff*> appliedbuffList)
{
	
	std::list<AppliedBuff*>::iterator item = appliedBuffList.begin();
	while (item != appliedBuffList.end())
	{
		if ((*item)->timer_duration < (*item)->timer.Read())
		{
			std::list<Info_players*>::iterator it_player = App->player->playerList.begin();
			while (it_player != App->player->playerList.end())
			{
				if ((*it_player)->id == (*item)->id_player_buffed)
				{
					if ((*item)->attr_to_change == "defense" && (*it_player)->defense)
					{
						(*it_player)->defense = (*item)->original_value; 
						appliedBuffList.erase(item); 
					}
					else if ((*item)->attr_to_change == "attack" && (*it_player)->attack)
					{
						(*it_player)->attack = (*item)->original_value;
						appliedBuffList.erase(item);
					}
					else if ((*item)->attr_to_change == "agility" && (*it_player)->agility)
					{
						(*it_player)->agility = (*item)->original_value;
						appliedBuffList.erase(item);
					}
					else if ((*item)->attr_to_change == "life" && (*it_player)->life)
					{
						(*it_player)->life = (*item)->original_value;
						appliedBuffList.erase(item);
					}
					it_player++;
				}
			}
		}
		item++;
	}

	return true; 
}


bool j1BuffDebuff::ApplyBuffItems(std::string buff_name)
{


	return true; 
}

