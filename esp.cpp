#include "context.h"
#include "esp.h"

c_esp g_esp;

void c_esp::init( )
{
	if ( !ctx.m_local || !ctx.m_local->alive( ) )
		return;

	size_t zombie_count{};

	for ( size_t i = 0; i < 1024; ++i )
	{
		auto ent = engine::get_entity( i );

		if ( !ent || !ent->alive( ) || ent == ctx.m_local || ( ent->m_ent_type != ent_actor && ent->m_ent_type != ent_player ) )
			continue;

		if ( ent->m_ent_type == ent_actor )
			zombie_count++;

		/*vec3  top, top_screen;
		vec3  bot, bot_screen;
		vec3  head_pos = ent->m_origin;

		// need to reverse proper way of doing this
		//engine::get_head_pos( ent, head_pos );

		top = head_pos - vec3( 0.f, 0.f, 10.f );
		bot = ent->m_origin + vec3( 0.0f, 0.0f, 5.0f );

		if ( !engine::w2s( top, top_screen ) || !engine::w2s( bot, bot_screen ) )
			continue;

		const float width = ( bot_screen.y - top_screen.y ) * 0.979f;

		draw_player_box( color_t::team_based( ent_type == ent_player ), top_screen, bot_screen, width );
		ctx.m_renderer->string( color_t( 255, 255, 255 ), top_screen.x + width * 0.5f, top_screen.y - 13.0f, true, ent->ent_type_name( ) );
		ctx.m_renderer->string( color_t( 255, 255, 255 ), top_screen.x + width * 0.5f + 4.0f, top_screen.y - 2.0f, false, "%.1fm", ctx.m_local->m_origin.dist( ent->m_origin ) * 0.01905f );*/

		vec3 origin_screen;
		if ( !engine::w2s( ent->m_origin, origin_screen ) )
			continue;

		// color_t::team_based( ent->m_ent_type == ent_player )
		ctx.m_renderer->string(
			color_t( 255, 255, 255 ), 
			origin_screen.x, 
			origin_screen.y, 
			true, 
			"%s %.1fm",
			ent->ent_type_name( ),
			ctx.m_local->m_origin.dist( ent->m_origin ) * 0.01905f
		);
	}

	ctx.m_renderer->string( color_t( 255, 255, 255 ), 10.0f, 46.0f, false, "zombie count: %u", zombie_count );
	zombie_count = 0;
}