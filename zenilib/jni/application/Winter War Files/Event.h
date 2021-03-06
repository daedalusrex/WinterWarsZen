
#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <zenilib.h>

#include "BitStream.h"

class Player;
class Structure;
class Snowball;

class WWEvent
{
public :
	WWEvent();
	virtual RakNet::BitStream *package() = 0;
	virtual void unpackage(RakNet::BitStream *) = 0;

	virtual void put_in_game() = 0;

	void send_me();

};

WWEvent *create_event(unsigned char event_type);

class Build_Event : public WWEvent
{
public:	
	Build_Event(Structure *);
	Build_Event(){}

	virtual RakNet::BitStream *package();
	virtual void unpackage(RakNet::BitStream *);

	virtual void put_in_game();
	virtual void put_in_game(int row, int col, int team_, int type_);

private:
	int type;
	Zeni::Point3f tile;
	int team_color;
};

class Player_Movement_Event : public WWEvent
{
public:
	Player_Movement_Event(Player *);
	Player_Movement_Event()	{};

	virtual RakNet::BitStream *package();
	virtual void unpackage(RakNet::BitStream *);

	virtual void put_in_game();

private:
	int player_num; //We are going to have to redo which player is on what team
	Zeni::Point3f position;
	Zeni::Vector3f velocity;
	int team_color;
};

class Throw_Snowball_Event : public WWEvent
{
public:
	Throw_Snowball_Event(Player* , 
		const Zeni::Point3f &position,
		const Zeni::Vector3f &velo,
		float radius);

	Throw_Snowball_Event()	{};

	virtual RakNet::BitStream *package();
	virtual void unpackage(RakNet::BitStream *);

	virtual void put_in_game();

private:
	int player_num; 
	Zeni::Point3f pos;
	Zeni::Vector3f velo;
	float radius;
};

#endif