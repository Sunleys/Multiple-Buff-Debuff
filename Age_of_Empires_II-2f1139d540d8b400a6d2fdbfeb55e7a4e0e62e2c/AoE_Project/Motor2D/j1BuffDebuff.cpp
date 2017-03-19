#include <sstream> 
#include "p2Log.h"

#include "j1BuffDebuff.h"
#include "j1App.h"
#include "j1FileSystem.h"


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

	pugi::xml_node node_buff; 

	bool ret = true;
	//node_buff = bd_node.child("buff");
	bd->buffdebuff_name = bd_node.child("name").child_value();
	bd->duration = bd_node.attribute("duration").as_float();
	bd->oper = bd_node.attribute("operator").as_string();
	bd->value = bd_node.attribute("value").as_float();
	bd->target = bd_node.attribute("target").as_string();

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
		for (bd_node = info_buffdebuff.child("buff_debuff").child("buff").child("name"); bd_node && ret; bd_node = bd_node.next_sibling("name"))
		{
			Buff* bd = new Buff();

			ret = LoadBuffDebuff(bd_node, bd);
			AddBuffToList(bd); 
			//LOG(" BUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUFF DEBUFF %s %d %c %s %s",bd->buffdebuff_name, bd->duration, bd->oper, bd->target, bd->value);
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


// Called before quitting
bool j1BuffDebuff::CleanUp()
{
	return true; 
}