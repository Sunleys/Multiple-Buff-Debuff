#include "j1Player.h"
#include "j1FileSystem.h"
#include "j1App.h"
#include "p2Log.h"
#include "j1BuffOpt.h"
#include "j1Input.h"
#include "SDL/include/SDL.h"

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
				ret = LoadPlayers(bd_node);
				//unitList.push_back(unit);
		}
	}

	return ret;
}

bool j1Player::Start()
{

	//life
	str_life = (UI_String*)App->gui->GenerateUI_Element(STRING);
	str_life->Activate();
	str_life->SetString(" ");
	str_life->GenerateTexture();
	str_life->ChangeString("Life: %i", life);

	//strength
	str_attack = (UI_String*)App->gui->GenerateUI_Element(STRING);
	str_attack->Activate();
	str_attack->SetString(" ");
	str_attack->GenerateTexture();
	str_attack->ChangeString("Strength: %i", attack);

	//agility
	str_agility = (UI_String*)App->gui->GenerateUI_Element(STRING);
	str_agility->Activate();
	str_agility->SetString(" ");
	str_agility->GenerateTexture();
	str_agility->ChangeString("Agility: %i", agility);

	//defense
	str_defense = (UI_String*)App->gui->GenerateUI_Element(STRING);
	str_defense->Activate();
	str_defense->SetString(" ");
	str_defense->GenerateTexture();
	str_defense->ChangeString("Defense: %i", defense);


	return true;
}

bool j1Player::Update(float dt)
{
	//Buffs 
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		App->buffdebuff->ApplyBuffs("increase_strength", this);
		str_attack->ChangeString("Strength: %i", attack);
	}

	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		App->buffdebuff->ApplyBuffs("increase_life", this);
		str_life->ChangeString("Life: %i", life);
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		App->buffdebuff->ApplyBuffs("increase_agility", this);
		str_agility->ChangeString("Agility: %i", agility);
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
	{
		App->buffdebuff->ApplyBuffs("increase_defense", this);
		str_defense->ChangeString("Defense: %i", defense);
	}


	//Debuffs
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		if(App->buffdebuff->SearchBuff("decrease_life")->buff_active == false)
		{
			App->buffdebuff->ApplyBuffs("decrease_life", this);
			str_life->ChangeString("Life: %i", life);
		}
	}


	/*
	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		App->buffdebuff->ApplyBuffs("mult_life", this);
		str_life->ChangeString("Life: %i", life);
	}
	*/

	if (App->buffdebuff->CheckAppliedBuff())
	{
		str_life->ChangeString("Life: %i", life);
		str_attack->ChangeString("Strength: %i", attack);
		str_agility->ChangeString("Agility: %i", agility);
		str_defense->ChangeString("Defense: %i", defense);
	}

	str_life->DrawAt(50, 100);
	str_attack->DrawAt(50, 200);
	str_agility->DrawAt(50, 300);
	str_defense->DrawAt(50, 400);

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


bool j1Player::LoadPlayers(pugi::xml_node& node)
{
	bool ret = false;

	pugi::xml_node node_units;
	ret = true;
	id = node.attribute("id").as_string();
	life = node.attribute("life").as_uint();
	agility = node.attribute("agility").as_uint();
	defense = node.attribute("defense").as_uint();
	attack = node.attribute("attack").as_uint();


	return ret;
}




