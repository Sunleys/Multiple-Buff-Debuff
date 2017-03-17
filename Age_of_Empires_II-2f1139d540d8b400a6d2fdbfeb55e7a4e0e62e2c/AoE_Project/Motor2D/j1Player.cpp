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
	return false;
}

bool j1Player::Start()
{
	return false;
}

bool j1Player::Update()
{
	return false;
}

bool j1Player::PreUpdate()
{
	return false;
}

bool j1Player::PostUpdate()
{
	return false;
}

bool j1Player::CleanUp()
{
	return false;
}
