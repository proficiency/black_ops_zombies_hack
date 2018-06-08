#pragma once

class c_aimbot
{
public:	
	// highest level func to call
	void init( );

	// target entity
	c_entity* m_ent;
private:
	void aimbot( );
	void nospread( );
	int find_ideal_target( );
}; extern c_aimbot g_aimbot;