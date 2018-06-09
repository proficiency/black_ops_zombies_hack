#include "context.h"

decltype( hooked::o_create_new_cmds ) hooked::o_create_new_cmds;

void __cdecl hooked::create_new_cmds( int a1 )
{
	// ok lemme explain
	/*
		void __cdecl CL_CreateNewCommands(int a1)
		{
			char v1; // [sp+0h] [bp-68h]@2

			// condition to run the func is handled within itself
			// so we do actually have to check connection state manually
			// as CL_CreateNewCommands would do normally
			if ( *(_DWORD *)g_LocalClientConnectionState >= 9 )
			{
				++g_CmdNumber;
				qmemcpy(&v1, (const void *)CL_CreateCmd(a1), 0x34u);
				qmemcpy((char *)&g_input + 52 * (g_CmdNumber & 0x7F), &v1, 0x34u);
				}
		}
	*/
	// however, the calling context for CL_CreateCmdsDuringConnection and CL_Input, do have condittional call
	// ideally, we want to only run stuff from the CL_Input call c:
	// since we get jmp'd to from CL_CreateCmdsDuringConnection, our return address becomes CL_CreateCmdsDuringConnection's
	/*
		sub_61C680+126  E8 D5 8B FC FF                    call    CL_CreateCmdsDuringConnection_0
		sub_61C680+12B  83 C3 FA                          add     ebx, 0FFFFFFFAh
	*/
	static const uintptr_t connection_ret_addr = memory::pattern_search( "83 C3 FA 83 C4 14" );

	// we don't want to run hack code while connecting
	// you could also just check connection state
	// but idk the enum sooo
	if ( ( uintptr_t ) _ReturnAddress( ) == connection_ret_addr )
	{
		// it really doesn't matter if we filter CL_Input or CL_CreateCmdsDuringConnection, both have one call
		anti_rin( printf( "filtering CL_CreateCmdsDuringConnection call from 0x%lx\n", ( uintptr_t ) _ReturnAddress( ) ) );
		return hooked::o_create_new_cmds( a1 );
	}

	// call original to not mess ourselves up with cmd handling
	hooked::o_create_new_cmds( a1 );

	// at this point, we're going to have connection state of 10 due to:
	/*
		CL_Input      83 3D 64 01 91 02+                cmp     g_LocalClientConnectionState, 10
		CL_Input+7    75 05                             jnz     short locret_49F32E
		CL_Input+9    E9 B2 30 3E 00                    jmp     CL_CreateNewCommands
	*/
	// however, we don't want to run hack code while disconnected
	// game doesn't have a seperate connection state for this
	// so we have to use a cdecl global func called Console_IsClientDisconnected
	if ( engine::is_connected( ) )
	{
		ctx.m_cmd    = ctx.m_input->get_cmd( );
		ctx.m_local  = engine::get_entity( ctx.m_cg->m_client_number );

		if ( !ctx.m_cmd || !ctx.m_local )
			return hooked::o_create_new_cmds( a1 );

		// not finished
		//g_aimbot.init( );
	}
}