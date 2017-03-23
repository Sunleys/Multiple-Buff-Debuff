#include "j1Player.h"
#include "j1FileSystem.h"
#include "j1App.h"
#include "p2Log.h"

j1Player::j1Player() : j1Module()
{
	name = "player";
}

j1Player::~j1Player()
{
}

bool j1Player::Awake(pugi::xml_node& info)
{
	pugi::xml_document info_players;
	pugi::xml_node     bd_node;
	pugi::xml_node     bd_info;

	bool ret = true;

	bd_info = LoadXMLPlayers(info_players);

	//Load App config data

	if (bd_info.empty() == false)
	{
		// self-config
		for (bd_node = info_players.child("players").child("player"); bd_node && ret; bd_node = bd_node.next_sibling("player"))
		{
				j1Player* unit = new j1Player();
				ret = LoadPlayers(bd_node, unit);
				AddPlayers(unit);
				//LOG(" BUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUFF DEBUFF %s %d %c %s %s",bd->buffdebuff_name, bd->duration, bd->oper, bd->target, bd->value);
		}
	}

	return ret;
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

pugi::xml_node j1Player::LoadXMLPlayers(pugi::xml_document& player_doc)
{
	pugi::xml_node ret;

	char* buf;
	int size = App->fs->Load("player.xml", &buf);
	pugi::xml_parse_result result = player_doc.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL)
		LOG("Could not load xml file player.xml. pugi error: %s", result.description());
	else
		ret = player_doc.child("players");

	return ret;
}


bool j1Player::ModifyAttributes(float value)
{


	return true; 
}

bool j1Player::AddPlayers(j1Player* player)
{
	if (player)
	{
		this->playerList.push_back(player);
		return true;
	}
	return false;
}

bool j1Player::LoadPlayers(pugi::xml_node& node, j1Player* unit)
{
	bool ret = false;

	if (node && unit)
	{
		pugi::xml_node node_units;

		ret = true;

		unit->id = node.child("player").attribute("id").as_string();
		unit->life = node.child("player").attribute("life").as_uint();
		unit->agility = node.child("player").attribute("agility").as_uint();
		unit->defense = node.child("player").attribute("defense").as_uint();
		unit->attack = node.child("player").attribute("attack").as_uint();

	}
	return ret;
}

pugi::xml_node j1Player::GetConfigPlayer() const
{
	return p_node; 
}


