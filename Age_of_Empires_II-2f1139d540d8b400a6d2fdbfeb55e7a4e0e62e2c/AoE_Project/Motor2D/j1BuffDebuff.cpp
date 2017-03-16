#include <iostream>		
#include <sstream> 
#include "p2Log.h"

#include "j1BuffDebuff.h"
#include "j1App.h"
#include "j1FileSystem.h"


j1BuffDebuff::j1BuffDebuff() : j1BuffDebuff()
{
	name = "buffdebuff"; 
}

j1BuffDebuff::~j1BuffDebuff()
{}

pugi::xml_node j1BuffDebuff::LoadBuffDebuff(pugi::xml_document& bd_file) const
{
	pugi::xml_node ret;

	char* buf;
	int size = App->fs->Load("buff_debuff.xml", &buf);
	pugi::xml_parse_result result = bd_file.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL)
		LOG("Could not load map xml file buff_debuff.xml. pugi error: %s", result.description());
	else
		ret = bd_file.child("buff_debuff");

	return ret;
}



bool j1BuffDebuff::Awake(pugi::xml_node& info)
{
	pugi::xml_document info_buffdebuff;
	pugi::xml_node     bd_node;
	pugi::xml_node     bd_info;

	bool ret = false;

	bd_node = LoadBuffDebuff(info_buffdebuff); 

	//Load App config data
	
	if (bd_node.empty() == false)
	{
		// self-config
		ret = true;
		bd_info = bd_node.child("buff");
		buffdebuff_name = bd_info.child("name").child_value(); 
		duration = bd_info.attribute("duration").as_float(); 
		oper = bd_info.attribute("operator").as_string();
		value = bd_info.attribute("value").as_float(); 
		target = bd_info.attribute("target").as_string(); 
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


// Called before quitting
bool j1BuffDebuff::CleanUp()
{
	return true; 
}