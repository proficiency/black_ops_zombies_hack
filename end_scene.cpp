#include "context.h"
#include "esp.h"

decltype( hooked::o_end_scene ) hooked::o_end_scene;

long __stdcall hooked::end_scene( IDirect3DDevice9* device )
{
	anti_rin( ctx.m_renderer = std::make_unique< c_renderer >( device ); )

	ctx.m_renderer->start( );
	{
		if ( engine::in_game( ) )
			g_esp.init( );
		else
			ctx.m_cg->get_ref_def( );

		ctx.m_renderer->string( color_t( 255, 255, 255 ), 10.0f, 10.0f, false, "client: %i\nmax clients: %i\nin game: %i\n",
								ctx.m_cg->m_client_number, ctx.m_cgs->m_max_clients, engine::in_game( ) );
	}
	ctx.m_renderer->finish( );

	return hooked::o_end_scene( device );
}