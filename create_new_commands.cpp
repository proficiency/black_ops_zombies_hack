#include "context.h"

decltype( hooked::o_create_new_commands ) hooked::o_create_new_commands;

void __cdecl hooked::create_new_commands( int a1 )
{
	__asm
	{
		mov ecx, a1
		call [hooked::o_create_new_commands]
	}

	ctx.m_cmd    = ctx.m_input->get_cmd( );
	ctx.m_local  = &ctx.m_ent_list[ctx.m_cg->m_client_number];

	if ( !ctx.m_cmd || !ctx.m_local )
		return hooked::o_create_new_commands( a1 );

	g_aimbot.init( );
}