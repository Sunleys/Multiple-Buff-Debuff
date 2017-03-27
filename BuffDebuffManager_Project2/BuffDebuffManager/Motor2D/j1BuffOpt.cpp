#include "j1BuffOpt.h"

j1BuffOpt::j1BuffOpt() : j1Module()
{
	name = "buffdebuff";
}

j1BuffOpt::~j1BuffOpt()
{
}

bool j1BuffOpt::Awake(pugi::xml_node & info)
{
	pugi::xml_document info_buffdebuff;
	pugi::xml_node     bd_node;
	pugi::xml_node     bd_info;

	bool ret = true;

	bd_info = LoadXMLBuffDebuff(info_buffdebuff);

	if (bd_info.empty() == false)
	{
		for (bd_node = info_buffdebuff.child("buff_debuff").child("buffs").child("buff"); bd_node && ret; bd_node = bd_node.next_sibling("buff"))
		{
			Buffs* bd = new Buffs(bd_node.attribute("timer_duration").as_int(), bd_node.attribute("name").as_string(), bd_node.attribute("type").as_string(), bd_node.attribute("attr_to_change").as_string(),bd_node.attribute("operator").as_int() ,bd_node.attribute("value").as_uint());
			buffsList.push_back(bd);
		}
	}

	return ret;
}

bool j1BuffOpt::Start()
{
	return true;
}

bool j1BuffOpt::Update()
{
	return true;
}

bool j1BuffOpt::PreUpdate()
{
	return true;
}

bool j1BuffOpt::CleanUp()
{
	return true;
}

pugi::xml_node j1BuffOpt::LoadXMLBuffDebuff(pugi::xml_document & bd_file) const
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



bool j1BuffOpt::ApplyBuffs(std::string buff_name, j1Player * target)
{
	Buffs* buff_to_apply = SearchBuff(buff_name);
	if (buff_to_apply->buff_active == false)
	{
		switch (buff_to_apply->oper)
		{
		case SUM:
			if (buff_to_apply->attr_to_change.compare("life") == 0)
			{
				target->SetPlayerLife(target->GetPlayerLife() + buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);

			}

			else if (buff_to_apply->attr_to_change.compare("strength") == 0)
			{
				target->SetPlayerAttack(target->GetPlayerAttack() + buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("agility") == 0)
			{
				target->SetPlayerAgility(target->GetPlayerAgility() + buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("defense") == 0)
			{
				target->SetPlayerDefense(target->GetPlayerDefense() + buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}
			break;

		case SUBSTRACT:
			if (buff_to_apply->attr_to_change.compare("life") == 0)
			{
				target->SetPlayerLife(target->GetPlayerLife() - buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("strength") == 0)
			{
				target->SetPlayerAttack(target->GetPlayerAttack() - buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("agility") == 0)
			{
				target->SetPlayerAgility(target->GetPlayerAgility() - buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("defense") == 0)
			{
				target->SetPlayerDefense(target->GetPlayerDefense() - buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}
			break;

		case MULTIPLY:

			if (buff_to_apply->attr_to_change.compare("life") == 0)
			{
				target->SetPlayerLife(target->GetPlayerLife() * buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("strength") == 0)
			{
				target->SetPlayerAttack(target->GetPlayerAttack() * buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("agility") == 0)
			{
				target->SetPlayerAgility(target->GetPlayerAgility() * buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("defense") == 0)
			{
				target->SetPlayerDefense(target->GetPlayerDefense() * buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}
			break;

		case DIVIDE:
			if (buff_to_apply->attr_to_change.compare("life") == 0)
			{
				target->SetPlayerLife(target->GetPlayerLife() / buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("strength") == 0)
			{
				target->SetPlayerAttack(target->GetPlayerAttack() / buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("agility") == 0)
			{
				target->SetPlayerAgility(target->GetPlayerAgility() / buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			else if (buff_to_apply->attr_to_change.compare("defense") == 0)
			{
				target->SetPlayerDefense(target->GetPlayerDefense() / buff_to_apply->value);
				buff_to_apply->timer.Start();
				buff_to_apply->buff_active = true;
				buff_to_apply->target = target;
				appliedbuffList.push_back(buff_to_apply);
			}

			break;

		default: LOG("applybuff doesnt work correctly"); return false;
		}
	}	

	return true;
}

Buffs* j1BuffOpt::SearchBuff(std::string buff_name)
{
	
	std::list<Buffs*>::iterator item = buffsList.begin();
	while (item != buffsList.end())
	{
		if ((*item)->buffdebuff_name == buff_name)
		{
			return item._Ptr->_Myval; 
		}
		item++;
	}
	LOG("Error searching buff to apply");
}

bool j1BuffOpt::CheckAppliedBuff()
{
	std::list<Buffs*>::iterator item = appliedbuffList.begin();

	while (item != appliedbuffList.end())
	{
		if (item._Ptr->_Myval->timer_duration < item._Ptr->_Myval->timer.ReadSec() && item._Ptr->_Myval->buff_active == true)
		{
			if (item._Ptr->_Myval->attr_to_change.compare("life") == 0)
			{
				switch (item._Ptr->_Myval->oper)
				{
				case SUM:
					item._Ptr->_Myval->target->SetPlayerLife(item._Ptr->_Myval->target->GetPlayerLife() - item._Ptr->_Myval->value);
					break;

				case SUBSTRACT:
					item._Ptr->_Myval->target->SetPlayerLife(item._Ptr->_Myval->target->GetPlayerLife() + item._Ptr->_Myval->value);
					break;

				case MULTIPLY:
					item._Ptr->_Myval->target->SetPlayerLife(item._Ptr->_Myval->target->GetPlayerLife() / item._Ptr->_Myval->value);
					break;

				case DIVIDE:
					item._Ptr->_Myval->target->SetPlayerLife(item._Ptr->_Myval->target->GetPlayerLife() * item._Ptr->_Myval->value);
					break;

				default:
					LOG("ERROR buff_life end");
					break;
				}
				item._Ptr->_Myval->buff_active = false;
				appliedbuffList.remove(item._Ptr->_Myval);
			}
			else if (item._Ptr->_Myval->attr_to_change.compare("strength") == 0)
			{
				switch (item._Ptr->_Myval->oper)
				{
				case SUM:
					item._Ptr->_Myval->target->SetPlayerAttack(item._Ptr->_Myval->target->GetPlayerAttack() - item._Ptr->_Myval->value);
					break;

				case SUBSTRACT:
					item._Ptr->_Myval->target->SetPlayerAttack(item._Ptr->_Myval->target->GetPlayerAttack() + item._Ptr->_Myval->value);
					break;

				case MULTIPLY:
					item._Ptr->_Myval->target->SetPlayerAttack(item._Ptr->_Myval->target->GetPlayerAttack() / item._Ptr->_Myval->value);
					break;

				case DIVIDE:
					item._Ptr->_Myval->target->SetPlayerAttack(item._Ptr->_Myval->target->GetPlayerAttack() * item._Ptr->_Myval->value);
					break;

				default:
					LOG("ERROR buff_attack end");
					break;
				}	
				item._Ptr->_Myval->buff_active = false;
				appliedbuffList.remove(item._Ptr->_Myval);
			}
			else if (item._Ptr->_Myval->attr_to_change.compare("agility") == 0)
			{
				switch (item._Ptr->_Myval->oper)
				{
				case SUM:
					item._Ptr->_Myval->target->SetPlayerAgility(item._Ptr->_Myval->target->GetPlayerAgility() - item._Ptr->_Myval->value);
					break;

				case SUBSTRACT:
					item._Ptr->_Myval->target->SetPlayerAgility(item._Ptr->_Myval->target->GetPlayerAgility() + item._Ptr->_Myval->value);
					break;

				case MULTIPLY:
					item._Ptr->_Myval->target->SetPlayerAgility(item._Ptr->_Myval->target->GetPlayerAgility() / item._Ptr->_Myval->value);
					break;

				case DIVIDE:
					item._Ptr->_Myval->target->SetPlayerAgility(item._Ptr->_Myval->target->GetPlayerAgility() * item._Ptr->_Myval->value);
					break;

				default:
					LOG("ERROR buff_agility end");
					break;
				}	
				item._Ptr->_Myval->buff_active = false;
				appliedbuffList.remove(item._Ptr->_Myval);
			}
			else if (item._Ptr->_Myval->attr_to_change.compare("defense") == 0)
			{
				switch (item._Ptr->_Myval->oper)
				{
				case SUM:
					item._Ptr->_Myval->target->SetPlayerDefense(item._Ptr->_Myval->target->GetPlayerDefense() - item._Ptr->_Myval->value);
					break;

				case SUBSTRACT:
					item._Ptr->_Myval->target->SetPlayerDefense(item._Ptr->_Myval->target->GetPlayerDefense() + item._Ptr->_Myval->value);
					break;

				case MULTIPLY:
					item._Ptr->_Myval->target->SetPlayerDefense(item._Ptr->_Myval->target->GetPlayerDefense() / item._Ptr->_Myval->value);
					break;

				case DIVIDE:
					item._Ptr->_Myval->target->SetPlayerDefense(item._Ptr->_Myval->target->GetPlayerDefense() * item._Ptr->_Myval->value);
					break;

				default:
					LOG("ERROR buff_defense end");
					break;
				}	
				item._Ptr->_Myval->buff_active = false;
				appliedbuffList.remove(item._Ptr->_Myval);
			}
			return true;
		}
		item++;
	}
			
	return false;
}
