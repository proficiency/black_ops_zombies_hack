#include "context.h"

decltype( hooked::o_create_new_commands ) hooked::o_create_new_commands;

void __cdecl hooked::create_new_commands( int a1 )
{
	hooked::o_create_new_commands( a1 );

	c_user_cmd* cmd = ctx.m_input->get_cmd( );

	if ( !cmd )
		return hooked::o_create_new_commands( a1 );

	ctx.m_cmd   = ctx.m_input->get_cmd( 1 );
	*ctx.m_cmd  = *cmd;
	// dec servertime


}