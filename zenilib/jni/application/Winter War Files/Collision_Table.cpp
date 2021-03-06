#include "Collision_Table.h"

#include "Game_Model.h"
#include "World.h"

#include "Collidable.h"
#include "Player.h"
#include "Structure.h"
#include "Snowball.h"
#include "Team.h"
#include "Effect.h"


#include <cmath>
#include <vector>
#include <zenilib.h>

#define PI 3.1415926

using namespace std;
using namespace Zeni;

const int num_Obs_c = 4;

Collision_Table::Collision_Table()
	: table(num_Obs_c, vector<fxn_ptr_t>(num_Obs_c, (fxn_ptr_t)0))
{
	collided = false;
	table.at(Snowball::snowball_ID_c).at(Collidable::collidable_ID_c) = 0;

	table.at(Snowball::snowball_ID_c).at(Snowball::snowball_ID_c) =
		(fxn_ptr_t)&Collision_Table::collideSnowballSnowball;

	table.at(Snowball::snowball_ID_c).at(Player::player_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collideSnowballPlayer;

	table.at(Snowball::snowball_ID_c).at(Structure::structure_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collideSnowballStructure;



	
	table.at(Player::player_ID_c).at(Collidable::collidable_ID_c) = 0;

	table.at(Player::player_ID_c).at(Snowball::snowball_ID_c) =
		(fxn_ptr_t)&Collision_Table::collidePlayerSnowball;

	table.at(Player::player_ID_c).at(Player::player_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collidePlayerPlayer;

	table.at(Player::player_ID_c).at(Structure::structure_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collidePlayerStructure;



	
	table.at(Structure::structure_ID_c).at(Collidable::collidable_ID_c) = 0;

	table.at(Structure::structure_ID_c).at(Player::player_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collideStructureSnowball;

	table.at(Structure::structure_ID_c).at(Snowball::snowball_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collideStructurePlayer;

	table.at(Structure::structure_ID_c).at(Structure::structure_ID_c) = 
		(fxn_ptr_t)&Collision_Table::collideStructureStructure;		

}


void Collision_Table::collideSnowballSnowball(Snowball* b1, Snowball* b2)
{


	if(b1 == b2)
		return;

	if(!b1->body.intersects(b2->body))
		return;

	if(b1->damage_dealt || b2->damage_dealt)
		return;


	if(b1->size.x > max_snowball_size/2 && b2->size.x < max_snowball_size/2)
	{ //represents big snowball for b1
		b2->deal_damage();
		b1->size *= 0.8;
	}

	if(b1->size.x < max_snowball_size/2 && b2->size.x > max_snowball_size/2)
	{ //represents big snowball for b2
		b1->deal_damage();
		b2->size *= 0.8;
	}

	if(b1->size.x > max_snowball_size/2 && b2->size.x > max_snowball_size/2)
	{ //represents big snowballs both colliding
		b2->deal_damage();
		b1->deal_damage();
		b1->mark_for_deletion();
		b2->mark_for_deletion();		

		Vector3f origin(b1->center);
		float s = max_snowball_size/4;

		//Wish this could be random :(
		//them in several directions...., instead just do many based on unit circle
		for(int i = -2; i < 3; i++)	{
			for(int j = 0; j < 12; j++)	{
				Vector3f direction(cos(j*PI/6), sin(j*PI/6), sin(i*PI/6));
				Snowball *sb;
				if(j%2 == 1)	
					sb = new Snowball(b1->team, Point3f(origin + 20*direction), Vector3f(s,s,s));
				else	
					sb = new Snowball(b2->team, Point3f(origin + 20*direction), Vector3f(s,s,s));
				sb->get_thrown(direction);
				Game_Model::get().add_moveable(sb);
			}
		}
	}

}

void Collision_Table::collidePlayerSnowball(Player* p1, Snowball* b1)
{	
   	//if no collision, return
	if (!p1->body.intersects(b1->body) || b1->owner == p1)
		return;

	if (b1->damage_dealt)
		return;


	//*// Friendly Fire
	if (p1->get_team() == b1->team)
	{
		if (b1->owner) // not a snowman
			b1->owner->stats.friendly_hit++;	

		if (!b1->owner) // <-comment out for all friendly fire to go through
			return;  // just pass through if thrown by snowman
	}
	//*/


	// if the player's dead, don't continue
	if (p1->is_player_KO())
		return;
	
	//If we want to stop the snowball, move this above friendly fire
	float damage_dealt = b1->deal_damage();  
	
	p1->get_damaged(damage_dealt);

	Game_Model::get().add_effect(new Effect("explode", b1->center, Vector3f(10,10,10)*b1->size.z/4));
	
	// Drain Resources on death
//	if (p1->is_player_KO() )
	{
//		b1->team->modify_resources(p1->get_team()->take_resources(500));
	}

	// if snowman shot it, don't add player stats
	if (!b1->owner)
		return;

	// tell the player that threw the ball that he made a hit
	b1->owner->stats.hit++;
	b1->owner->stats.damage_dealt += damage_dealt;

	// he killed the player
	if (p1->is_player_KO() )
	{
		//Keep track of friendly fire kills separately
		if (p1->get_team() == b1->team)
		{
			b1->owner->stats.friendly_kills++;
		}
		else
			b1->owner->stats.kills++;
	}
}

void Collision_Table::collideSnowballPlayer(Snowball* b1, Player* p1)
{
	collidePlayerSnowball(p1,b1);
}

void Collision_Table::collidePlayerPlayer(Player* p1, Player* p2)
{
	//if no collision, return
	if (!p1->body.intersects(p2->body) || p1 == p2)
		return;

	p1->push_away_from(p2->center, 200);
	p2->push_away_from(p1->center, 200);
}

void Collision_Table::collideStructureSnowball(Structure* w1, Snowball* ob2)
{	
	collideSnowballStructure(ob2, w1);
}

void Collision_Table::collidePlayerStructure(Player *ob2, Structure *w1)
{	
	//Structure player collision resolution
	if (!ob2->is_player_KO())
		w1->handle_player_in_range(ob2->myTeam, ob2->body);

	if(!ob2->body.intersects(w1->body))
		return;
	w1->handle_player_collision(ob2);
}

void Collision_Table::collideStructurePlayer(Structure* w1, Player* ob2)
{
	collidePlayerStructure(ob2, w1);
}

void Collision_Table::collideSnowballStructure(Snowball *b2, Structure *w1)
{
	if(w1->get_type() == TREE || w1->get_type() == BASE)
		return;

	if (!b2->body.intersects(w1->body))
		return;
	
	if (b2->damage_dealt)
		return;
	
	if (w1->Status == DESTROYED || b2->team == w1->owner)
		return;

	int damage = b2->deal_damage();

	w1->receive_hit(damage);

	Game_Model::get().get_player_here(0)->play_sound();
	Game_Model::get().add_effect(new Effect("explode", b2->center, Vector3f(10,10,10)*b2->size.z/4));

	if (!b2->owner)  //snowmen should damage other structures
		return;		// but no stats
	
	b2->owner->stats.hit++;
	b2->owner->stats.damage_dealt += damage;
	
	if (w1->Status == DESTROYED)
		b2->owner->stats.destroyed++;
}

void Collision_Table::collideStructureStructure(Structure*, Structure*)
{
	//WAT. This cannot happen
	// Explode Everything!
}

