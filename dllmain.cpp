#include "context.h"

void hack( )
{
	hack::get_context( ctx );

	uintptr_t* device{};

	memcpy( &device, memory::pattern_search< void* >( "C7 06 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? 89 86", 2, GetModuleHandle( "d3d9.dll" ) ), sizeof( void* ) );

	hooked::o_create_new_commands     = ctx.m_hooking.get_function< decltype( &hooked::create_new_commands ) >( memory::pattern_search< uintptr_t* >( "83 EC 68 83 3D ? ? ? ? ? 7C 4A" ), &hooked::create_new_commands );
	hooked::o_present                 = ctx.m_hooking.get_function< decltype( &hooked::present ) >( ( uintptr_t* ) device[17], &hooked::present );
	hooked::o_draw_indexed_primitive  = ctx.m_hooking.get_function< decltype( &hooked::draw_indexed_primitive ) >( ( uintptr_t* ) device[82], &hooked::draw_indexed_primitive );
}