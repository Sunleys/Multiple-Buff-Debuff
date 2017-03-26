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
			Buffs* bd = new Buffs(bd_node.attribute("timer_duration").as_int(), bd_node.attribute("name").as_string(), bd_node.attribute("type").as_string(), bd_node.attribute("attr_to_change").as_string(),bd_node.attribute("operator").as_int() ,bd_node.attribute("value").as_float());
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



bool j1BuffOpt::ApplyBuffs(std::string buff_name, j1Player* target, std::list<Buffs*> buffsList_toSearch)
{
	Buffs* buff_to_apply = SearchBuff(buff_name, buffsList_toSearch);

		switch (buff_to_apply->oper)
		{
		case SUM:

			if (buff_to_apply->attr_to_change == "life")
			{
				int original_value = target->GetPlayerLife();
				target->SetPlayerLife(buff_to_apply->value + original_value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "strength")
			{
				int original_value = target->GetPlayerAttack();
				target->SetPlayerAttack(buff_to_apply->value + original_value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "agility")
			{
				int original_value = target->GetPlayerAgility();
				target->SetPlayerAgility(buff_to_apply->value + original_value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "defense")
			{
				int original_value = target->GetPlayerDefense();
				target->SetPlayerDefense(buff_to_apply->value + original_value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}

			break;

		case SUBSTRACT:

			if (buff_to_apply->attr_to_change == "life")
			{
				int original_value = target->GetPlayerLife();
				target->SetPlayerLife(original_value - buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "strength")
			{
				int original_value = target->GetPlayerAttack();
				target->SetPlayerAttack(original_value - buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "agility")
			{
				int original_value = target->GetPlayerAgility();
				target->SetPlayerAgility(original_value - buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "defense")
			{
				int original_value = target->GetPlayerDefense();
				target->SetPlayerDefense(original_value - buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			break;

		case MULTIPLY:
			if (buff_to_apply->attr_to_change == "life")
			{
				int original_value = target->GetPlayerLife();
				target->SetPlayerLife(original_value * buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "strength")
			{
				int original_value = target->GetPlayerAttack();
				target->SetPlayerAttack(original_value * buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "agility")
			{
				int original_value = target->GetPlayerAgility();
				target->SetPlayerAgility(original_value * buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "defense")
			{
				int original_value = target->GetPlayerDefense();
				target->SetPlayerDefense(original_value * buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}

			break;

		case DIVIDE:
			if (buff_to_apply->attr_to_change == "life")
			{
				int original_value = target->GetPlayerLife();
				target->SetPlayerLife(original_value / buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "strength")
			{
				int original_value = target->GetPlayerAttack();
				target->SetPlayerAttack(original_value / buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "agility")
			{
				int original_value = target->GetPlayerAgility();
				target->SetPlayerAgility(original_value / buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}
			else if (buff_to_apply->attr_to_change == "defense")
			{
				int original_value = target->GetPlayerDefense();
				target->SetPlayerDefense(original_value / buff_to_apply->value);
				buff_to_apply->value = original_value;
				appliedbuffList.push_back(buff_to_apply);
				buff_to_apply->timer.Start();
			}

			break;

		default: LOG("applybuff doesnt work correctly"); return false;
		}
	
	return true;
}

Buffs* SearchBuff(std::string buff_name, std::list<Buffs*> buffList)
{
	
	std::list<Buffs*>::iterator item = buffList.begin();
	while (item != buffList.end())
	{
		if ((*item)->buffdebuff_name == buff_name)
		{
			Buffs* ret = new Buffs((*item)->timer_duration,(*item)->buffdebuff_name,(*item)->type, (*item)->attr_to_change,(*item)->oper, (*item)->value);
			return ret;
		}
		item++;
	}
	LOG("Error searching buff to apply");
}

bool j1BuffOpt::CheckAppliedBuff(std::list<Buffs*> appliedbuffList)
{
	return true;
}