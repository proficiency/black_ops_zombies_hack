#pragma once
#include <stdint.h>
#include <Windows.h>
#include <vector>
#include <intrin.h>
#include <limits.h>
#include <algorithm>
#include <memory>
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

typedef unsigned long ulong_t;
typedef HMODULE       module_t;

#define anti_rin( items )\
 static bool jisekoldzgoilkszdegf = true; \
if ( jisekoldzgoilkszdegf ) \
{ \
	items; \
	jisekoldzgoilkszdegf = false;\
} \


#include "memory.h"
#include "sdk.h"
#include "math.h"
#include "aimbot.h"

#include "renderer.h"

class c_context
{
public:
	c_entity*     m_local;
	c_entity*     m_ent_list;
	c_cg*         m_cg;
	c_cg_static*  m_cgs;
	c_input*      m_input;
	c_user_cmd*   m_cmd;
	c_matrix*     m_matrix;

	memory::c_hooking m_hooking;
	std::unique_ptr< c_renderer > m_renderer;
}; extern c_context ctx;

namespace engine
{
	static inline c_entity* get_entity( const int& ent_num )
	{
		static const auto cg_get_ent = memory::pattern_search< c_entity*( __cdecl* )( int local_client_num, int ent_num ) >( "8B 44 24 08 3D ? ? ? ? 8B 4C 24 04 7C 19" );

		return cg_get_ent( ctx.m_cg->m_client_number, ent_num );
	}

	static inline void get_head_pos( c_entity* ent, vec3& out )
	{
		static const auto 
			aimtarget_gettagpos = memory::pattern_search< int( __cdecl* )( c_entity* ent, uint16_t tag_name, float* out ) >( "0F B6 46 04 8B 8E ? ? ? ? 53" );

		static const uint16_t* 
			j_head = *memory::pattern_search< uint16_t** >( "0F B7 05 ? ? ? ? 57 50", 3 );

		aimtarget_gettagpos( ent, *j_head, &out.x );
	}

	static inline int connection_state( )
	{
		static const auto local_connection_state = memory::pattern_search< int** >( "8B 35 ? ? ? ? 83 C4 04 8B D8", 2 );
		return **local_connection_state;
	}

	static inline bool is_connected( )
	{
		static const auto is_client_disconnected = memory::pattern_search< bool( __cdecl* )( ) >( "6A 00 E8 ? ? ? ? 83 C4 04 85 C0 75 21" );

		return !is_client_disconnected( );
	}

	static inline bool in_game( )
	{
		return connection_state( ) == 10 && is_connected( );
	}

	static inline bool w2s( const vec3& world, vec3& screen )
	{
		// dont even get me started
		static auto worldpos_to_screenpos = memory::pattern_search< bool( __cdecl* )( int local_client_num, const float* world_pos, float* out_pos ) >( "8B 4C 24 04 A1 ? ? ? ? F3 0F 10 98 ? ? ? ? F3 0F 10 80 ? ? ? ? F3 0F 10 88 ? ? ? ? 05 ? ? ? ? 8B D1 C1 E2 04 2B D1 8D 0C D5 ? ? ? ? 8B 54 24 08 F3 0F 10 62 ? F3 0F 5C 60" );

		return worldpos_to_screenpos( ctx.m_cg->m_client_number, &world.x, &screen.x );
	}
}