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
	static inline void get_head_pos( c_entity* ent, vec3& out )
	{
		static const auto 
			aimtarget_gettagpos = memory::pattern_search< int( __cdecl* )( int client_num, c_entity* ent, uint32_t tag_name, float* out ) >( "66 83 BE ? ? ? ? ? 53 8B 5C 24 0C" );

		static const uint16_t* 
			j_head = *memory::pattern_search< uint16_t** >( "0F B7 05 ? ? ? ? 57 50", 3 );

		int x = aimtarget_gettagpos( ctx.m_cg->m_client_number, ent, ( int ) *j_head, &out.x );

		printf( "%i %f %f %f\n", x, out.x, out.y, out.z );
	}
}