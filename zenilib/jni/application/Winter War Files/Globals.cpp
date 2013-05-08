
#include "Globals.h"

#include "Structure.h"
#include "Player.h"
#include "Team.h"

#include "Utility.h"

void Game_Parameter::increment()
{
	current_value += unit_increment;

	if (current_value > max)
		current_value = max;
}

void Game_Parameter::decrement()
{
	current_value -= unit_increment;

	if (current_value < min)
		current_value = min;
}

void Game_Parameter::reset()
{
	current_value = default_value;
}

Parameter_List parameters;

Parameter_List::Parameter_List()
{
	list.push_back(Game_Parameter("Snowman Health", Struct_Integrity[SNOWMAN], 1000, 10, 10));
	list.push_back(Game_Parameter("Fort Health", Struct_Integrity[FORT], 1000, 10, 10));
	list.push_back(Game_Parameter("Snow_Factory Health", Struct_Integrity[SNOW_FACTORY], 1000, 10, 10));
	list.push_back(Game_Parameter("Healing_Pool Health", Struct_Integrity[HEALING_POOL], 1000, 10, 10));

	list.push_back(Game_Parameter("Snowman Cost", Build_Cost[SNOWMAN], 10000, 100, 10));
	list.push_back(Game_Parameter("Fort Cost", Build_Cost[FORT], 10000, 100, 10));
	list.push_back(Game_Parameter("Snow_Factory Cost", Build_Cost[SNOW_FACTORY], 10000, 100, 10));
	list.push_back(Game_Parameter("Healing_Pool Cost", Build_Cost[HEALING_POOL], 10000, 100, 10));
	
	list.push_back(Game_Parameter("Player Health", Max_Player_Health, 10000, 10, 1));
	list.push_back(Game_Parameter("Respawn Time", Respawn_Time, 10000, 1, 0));

	list.push_back(Game_Parameter("Max Snow Scoopable", Max_Snow_Amount, 10000, 10, 10));
	list.push_back(Game_Parameter("Scoop Rate per Second", snow_absorbtion_rate, 10000, 10, 10));
	
	list.push_back(Game_Parameter("Biggest Snowball Packed", max_snowball_size, 200, 5, 20));
	list.push_back(Game_Parameter("Packing Rate per Second", packing_rate, 600, 5, 0));
	
	list.push_back(Game_Parameter("Structure Recharge Seconds", Building_Recharge_Time, 10, 1, 0.5));

	list.push_back(Game_Parameter("Max Resouces", Max_Resources, 1000000, 1000, 0));
	list.push_back(Game_Parameter("Starting Resources", starting_resources, 1000000, 500, 0));

	list.push_back(Game_Parameter("Soft Snow Intake", soft_snow_intake, 500, 10, 0));
	list.push_back(Game_Parameter("Hard Snow Intake", hard_snow_intake, 500, 10, 0));
	list.push_back(Game_Parameter("Ice Intake", ice_intake, 500, 10, 0));

	list.push_back(Game_Parameter("Snow Factory Intake per Second", snow_factory_intake, 500, 10, 0));

}

void Parameter_List::reset_all()
{
	for (int i = 0 ; i < size() ; i++)
		at(i).reset();
}

Game_Parameter &Parameter_List::find(const Zeni::String &name_)
{	
	return list.at(0);
}