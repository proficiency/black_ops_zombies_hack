#pragma once

class c_esp
{
public:
	void init( );
	
private:
	inline void draw_player_box( const color_t& box_color, const vec3& top_screen, const vec3& bot_screen, const float& width )
	{
		float box_x = top_screen.x - width * 0.5f;

		ctx.m_renderer->rect( box_color * 0.15f, box_x - 1, top_screen.y - 1, box_x + 1 + width, bot_screen.y + 1.0f );
		ctx.m_renderer->rect( box_color * 0.15f, box_x + 1, top_screen.y + 1, box_x - 1 + width, bot_screen.y - 1.0f );
		ctx.m_renderer->rect( box_color, box_x, top_screen.y, box_x + width, bot_screen.y );
	}

	inline void draw_ent_box( const color_t& box_color, c_entity* player, const std::string& title = "" )
	{
		vec3  top, top_screen;
		vec3  bot, bot_screen;

		const vec3 head_pos = vec3( player->m_origin.x, player->m_origin.y, player->m_origin.z + 5.0f );

		top = head_pos + vec3( 0.f, 0.f, 10.f );
		bot = head_pos;
		bot.z = player->m_origin.z - 5.f;

		if ( !engine::w2s( top, top_screen ) || !engine::w2s( bot, bot_screen ) )
			return;

		const float width = ( bot_screen.y - top_screen.y ) * 0.979f;
		const float box_x = top_screen.x - ( width  * 0.5f );

		ctx.m_renderer->rect( box_color * 0.15f, box_x - 1, top_screen.y - 1, box_x + 1 + width, bot_screen.y + 1.0f );
		ctx.m_renderer->rect( box_color * 0.15f, box_x + 1, top_screen.y + 1, box_x - 1 + width, bot_screen.y - 1.0f );
		ctx.m_renderer->rect( box_color, box_x, top_screen.y, box_x + width, bot_screen.y );

		if ( title.length( ) )
			ctx.m_renderer->string( box_color, top_screen.x, top_screen.y - 13.0f, true, title.c_str( ) );
	}
}; extern c_esp g_esp;