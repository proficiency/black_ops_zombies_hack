#include "context.h"

c_context ctx;

void hack( )
{
	ctx.m_ent_list  = *memory::pattern_search< c_entity** >( "8B 04 9D ? ? ? ? 03 C1", 3 );
	ctx.m_cg        = **memory::pattern_search< c_cg*** >( "8B 35 ? ? ? ? 89 44 24 08 F3 0F 10 86", 2 );
	ctx.m_cgs       = **memory::pattern_search< c_cg_static*** >( "8B 0D ? ? ? ? D9 40 0C", 2 );
	ctx.m_input     = *memory::pattern_search< c_input** >( "68 ? ? ? ? E8 ? ? ? ? 53 E8", 1  );
	ctx.m_matrix    = *memory::pattern_search< c_matrix** >( "B8 ? ? ? ? 8D 49 00 F3 0F 10 48", 1 );

	uintptr_t* device{};

	memcpy( &device, memory::pattern_search< void* >( "C7 06 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? 89 86", 2, GetModuleHandle( "d3d9.dll" ) ), sizeof( void* ) );

	ctx.m_hooking.start( );
	{
		hooked::o_create_new_cmds = ctx.m_hooking.get_function< decltype( &hooked::create_new_cmds ) >( ( void* ) memory::pattern_search( "83 EC 68 83 3D ? ? ? ? ? 7C 4A" ), &hooked::create_new_cmds );
		hooked::o_end_scene = ctx.m_hooking.get_function< decltype( &hooked::end_scene ) >( ( void* ) device[42], &hooked::end_scene );
	}
	ctx.m_hooking.finish( );
}

bool __stdcall DllMain( HINSTANCE instance, ulong_t reason, void* reserved )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls( instance );

		if ( AllocConsole( ) )
		{
			HWND  con_hwndw{ GetConsoleWindow( ) };
			RECT  con_bound{ 904 + 219, 420 };
			RECT  wndw_rect{ };

			SetConsoleTitle( "bo1z" );

			GetWindowRect( con_hwndw, &wndw_rect );
			MoveWindow( con_hwndw, wndw_rect.left, wndw_rect.top, con_bound.left, con_bound.top, true );

			SetWindowLong( con_hwndw, GWL_STYLE, GetWindowLong( con_hwndw, GWL_STYLE ) | WS_BORDER );
			SetWindowLong( con_hwndw, GWL_EXSTYLE, GetWindowLong( con_hwndw, GWL_EXSTYLE ) | WS_EX_LAYERED );

			SetLayeredWindowAttributes( con_hwndw, 0, 230, 2 );
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

			freopen( "CONOUT$", "w", stdout );
		}

		CreateThread( 0, 0, LPTHREAD_START_ROUTINE( hack ), 0, 0, 0 );

		return true;
	}

	return false;
}