#pragma once

#include <zenilib.h>

enum Input_Action	{
	PRESS_A, RELEASE_A, R_TRIG, L_TRIG, PRESS_B, RSTICK_X, RSTICK_Y, LSTICK_X, LSTICK_Y
};


class Controls
{
public:
	Controls(bool inverted_ = false);
	~Controls(void);
	

	bool take_input(const SDL_Event &event);
	bool take_input(const Zeni::Zeni_Input_ID &Zid, const float &confidence, const int &action);

//private:
	
	struct Inputs	{
		Inputs()	: jump(false), pack(false), mini_map(false), shoot(false), 
			build_view(false), right_y(0.0f), right_x(0.0f), left_y(0.0f), left_x(0.0f)		{}

		bool jump;	//A button
		bool pack;	//B button
		bool mini_map;	//left shoulder
		bool shoot;			//Right trigger
		bool build_view;	//left trigger

		float right_y;	//Right Stick
		float right_x;
		float left_y;		//Left Stick
		float left_x;
	} input;

};

