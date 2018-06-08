#include "context.h"

decltype( hooked::o_present ) hooked::o_present;

long __stdcall hooked::present( IDirect3DDevice9* device, RECT* src, const RECT* dst, HWND dst_window_override, const RGNDATA* dirty_region )
{	
	anti_rin( ctx.m_renderer = std::make_unique< c_renderer >( device ); )

	ctx.m_renderer->start( );
	{
		// esp
		ctx.m_renderer->string( color_t( 255, 255, 255 ), 10.0f, 10.0f, false, "hello" );
	}
	ctx.m_renderer->finish( );

	return hooked::o_present( device, src, dst, dst_window_override, dirty_region );
}
