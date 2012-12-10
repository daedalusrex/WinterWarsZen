#include "Structure.h"
#include "Snowball.h"
#include "Team.h"
#include "Tile.h"
#include "Player.h"

#include "Game_Model.h"
#include "Effect.h"

using namespace Zeni;

const int Structure::structure_ID_c = 3;

// NOTHING, SNOWMAN, FORT, SNOW_FACTORY, HEALING_POOL
const int Build_Cost[5] = { 0, 300, 100, 200, 400 };

const float Struct_Integrity[5] = {1, 50, 150, 20, 100};

Structure::Structure(Team *team, Tile* tile_,
				const Zeni::Point3f &position_,	 float radius) :
	Seen_Object(position_ + Point3f(0, 0, 60), Vector3f(1.4,1.4,1.4)*radius),
	owner(team), Health(1), Status(PRESENT_MODE), 
	Connected_to_Team(true), hex(tile_), opened(false),
	default_position(position_), default_size(Vector3f(1,1,1)*radius), default_radius(radius)
{
	Present_Clock.start();
}

void Structure::save_position()
{
//	position_
}

Structure::~Structure(void)
{
}

void Structure::receive_hit(float damage)	{

	Health -= damage;
	if(Health < 0)
		Status = DESTROYED;
}

void Structure::update(const float &time)
{
	//Structures don't move, so their body doen't need to be changed.
	//Collidable::update(time);
	if(Status == DESTROYED)	{
		perform_destruction_effects();
		hex->destroy_structure();
		owner->remove_tile(hex);
	}
	

	if(Isolation_Clock.seconds() > 15)	{
		Status = DESTROYED;
	}

	if (Present_Clock.seconds() > 3 && !opened)
		{
		opened = true; 
		Status = UNWRAP_MODE;
		}

	if (Status == UNWRAP_MODE)
	{
		Game_Model::get().add_effect(new Effect("bluepresent_unwrapped", center, size, 50));
	}

}

void Structure::begin_isolation()	{
	Connected_to_Team = false;
	Isolation_Clock.start();
}

void Structure::reintegrate()	{
	Connected_to_Team = true;
	Isolation_Clock.stop();
	Isolation_Clock.reset();
}

void Structure::perform_destruction_effects()	{
	
}

void Structure::handle_player_collision(Player *P)	{
	//Should be overwritten by each
	//However fort and factory, for now do the same thing
	P->push_away_from(center, 25);
}

void Structure::create_body()		{
	Point3f Top = Seen_Object::get_top_center();
	Point3f Bot = Seen_Object::get_bottom_center();
	body = Zeni::Collision::Capsule(Top, Bot, size.z/2);
}

void Structure::change_height(const float &delta)	{
	center.z += delta;
}

Animator *Structure::get_animator() const {
	return 0;
}

void Structure::switch_state(StructureEvent_e sevent)
{
	StructureAnimator *next = animation_state->get_next(sevent);
	if (next)
	{
		delete animation_state;
		animation_state = next;
	}
}

void Structure::restore_default_size_and_position()
{
	center = default_position;
	size = default_size;
	center.z += default_radius/2;
}