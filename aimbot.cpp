#include "context.h"

c_aimbot g_aimbot;

void c_aimbot::init( )
{
	if ( !ctx.m_local || !ctx.m_local->alive( ) || !ctx.m_cmd )
		return;

	aimbot( );
}

void c_aimbot::aimbot( )
{
	const int target_index = find_ideal_target( );

	if ( target_index == 2049 )
		return;

	m_ent = engine::get_entity( target_index );
	
	// lol
	if ( !m_ent )
		return;

	vec3 world_pos{};
	vec3 aim_angle{};
	engine::get_head_pos( m_ent, world_pos );
	math::q_vector_angles( world_pos - ctx.m_cg->get_ref_def( ).m_view_origin, aim_angle );
	
	// angle, not short!!!
	ctx.m_matrix->m_viewangles += aim_angle;

	if ( ctx.m_cmd->m_server_time % 2 == 0 )
		ctx.m_cmd->m_buttons |= button_t::state_fire;
	else
		ctx.m_cmd->m_buttons &= ~button_t::state_fire;

	ctx.m_matrix->m_recoil.zero( );

	m_ent = nullptr;
	// if storing aimpoint, set to zero here
}

int c_aimbot::find_ideal_target( )
{
	int    ideal_target  = 2049;
	float  closest       = std::numeric_limits< float >::max( );

	// todo: check if maxclients actually returns the right number
	// might return max players, invalidating our zombies aimbot
	for ( size_t i = 0; i < ctx.m_cgs->m_max_clients; ++i )
	{
		auto ent = engine::get_entity( i );

		if ( !ent || !ent->alive( ) )
			continue;

		vec3 world_position{};
		engine::get_head_pos( ent, world_position );

		if ( world_position.is_zero( ) )
			continue;

		// if !visible continue

		float distance = ctx.m_local->m_origin.dist( world_position );

		if ( distance < closest )
		{
			closest = distance;
			ideal_target = i;
		}
	}

	return ideal_target;
}