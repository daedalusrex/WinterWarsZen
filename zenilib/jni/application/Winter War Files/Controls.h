#pragma once

#include <zenilib.h>


class Player;



class Controls
{
public:
	Controls(bool inverted_ = false, int which_id_ = 0);
	~Controls(void);
	
	static int Mouse_Camera;
	static void check_keyboard_player_change(const SDL_KeyboardEvent &event);
	static void take_God_keyboard(const SDL_KeyboardEvent &event);

	std::string give_stick_status();

	bool take_keyboard_input(const SDL_KeyboardEvent &event);
	void take_mouse_button_input(const SDL_MouseButtonEvent &event);

	bool HandleJoy(const SDL_JoyAxisEvent &event);
	bool HandleJoy(const SDL_JoyHatEvent &event);
	bool HandleJoy(const SDL_JoyButtonEvent &event);

	/*		This function translates most control inputs into actions
		Doesn't handle joystics, might split up into buttons and triggers*/
	void interact_with_player(Player* Tron , const float &time);

	/* Adjust player view using right stick	*/
	void adjust_Cam(Player* Tron);

	int get_cam_to_adjust();

	void reset_controls();

	void reset_Cam()	{
		input.Cam.x = 0;
		input.Cam.y = 0;
	}


	/*	Sets inverted if the player changes options menu (options to be implemented */
	void set_inverted(bool invert);
	void set_input_sensitivity(int _sensitivity);

	Zeni::Vector2f give_movement();

private:

	struct Inputs	{
		Inputs()	: jump(false), pack(false), mini_map(false), shoot(false), 
		build_view(false), RSHOULDER(false), LSHOULDER(false),
		Build_Go(false), Tile_up(false), Tile_down(false), tip(false), jet_pack_mode(false), Cam(0.0f, 0.0f), Move(0.0f, 0.0f)		{}



		bool jump;				//A button
		bool pack;				//B button
		bool mini_map;		//left shoulder
		bool shoot;				//Right trigger
		bool build_view;	//left trigger

		bool RSHOULDER;		//&&&Right shoulder, only temporary
		bool LSHOULDER;
		bool Build_Go;
		bool Tile_up;
		bool Tile_down;
		bool tip;

		bool jet_pack_mode;

		Zeni::Vector2f		Cam;
		Zeni::Vector2f		Move;

		void reset_inputs();

	} input;

	bool inverted;
	float aim_input_sensitivity;
	bool left_last;
	bool right_last;


	
	

	int which_id;

	//Temp Pointer (or not????)
	Player * Chell;

};

