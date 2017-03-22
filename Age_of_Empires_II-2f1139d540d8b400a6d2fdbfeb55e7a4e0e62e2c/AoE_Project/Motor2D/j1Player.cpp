#include "j1Player.h"

j1Player::j1Player() : j1Module()
{
	name = "player";
}

j1Player::~j1Player()
{
}

bool j1Player::Awake(pugi::xml_node & info)
{
	return true;
}

bool j1Player::Start()
{
	return true;
}

bool j1Player::Update()
{
	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}

bool j1Player::PostUpdate()
{
	return true;
}

bool j1Player::CleanUp()
{
	return true;
}

pugi::xml_node j1Player::LoadXMLPlayers(pugi::xml_node& bd_node, Buff* bd)
{
	/*
	pugi::xml_document info_players;
	pugi::xml_node     bd_node;
	pugi::xml_node     bd_info;

	bool ret = true;

	bd_info = LoadXMLPlayers(info_players);

	//Load App config data

	if (bd_info.empty() == false)
	{
		// self-config
		for (bd_node = info_players.child("buff_debuff").child("buff").child("type"); bd_node && ret; bd_node = bd_node.next_sibling("type"))
		{
			for (pugi::xml_node node = bd_node.child("name"); node && ret; node = node.next_sibling("name"))
			{
				Buff* bd = new Buff();

				ret = LoadXMLPlayers(node, bd);
				AddBuffToList(bd);
				//LOG(" BUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUFF DEBUFF %s %d %c %s %s",bd->buffdebuff_name, bd->duration, bd->oper, bd->target, bd->value);
			}
		}
	}

	return ret;
	*/
}


bool j1Player::ModifyAttributes(float value)
{


	return true; 
}