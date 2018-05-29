#pragma once
#include <stdint.h>
#include <Windows.h>
#include <vector>
#include <intrin.h>
#include <limits.h>
#include <algorithm>
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

namespace hack
{
	class c_context
	{
	public:
		c_entity*     m_local;
		c_entity*     m_ent_list;
		c_cg*         m_cg;
		c_cg_static*  m_cgs;
		c_input*      m_input;
		c_user_cmd*   m_cmd;

		memory::c_hooking m_hooking;
	};

	extern void get_context( c_context& );
}

static hack::c_context ctx;