#include "Player.h"

#include <zenilib.h>

using namespace Zeni;

const int Player::player_ID_c = 1;

Player::Player(const Zeni::Point3f &center_) 
	: Moveable(center_), m_camera(center_)
{
}


Player::~Player(void)
{
}

void Player::adjust_pitch(float phi) {
    const Quaternion backup = m_camera.orientation;
    const Vector3f backup_up = m_camera.get_up();

    m_camera.adjust_pitch(phi);

    if(m_camera.get_up().k < 0.0f && backup_up.k >= 0.0f)
      m_camera.orientation = backup;
}

void Player::turn_left(float theta) {
	m_camera.turn_left_xy(theta);
}




