#include "context.h"

void hack::get_context( c_context& context )
{
	// func addresses
	// CG_PredictPlayerState - 83 EC 2C 53 8B 1D ? ? ? ? D9 83
	//
	//

	context.m_ent_list  = *memory::pattern_search< c_entity** >( "03 04 8D ? ? ? ? 8B F0 F6 86", 3 );
	context.m_cg        = *memory::pattern_search< c_cg** >( "8B 35 ? ? ? ? 89 44 24 08 F3 0F 10 86", 2 );
	context.m_cgs       = *memory::pattern_search< c_cg_static** >( "8B 0D ? ? ? ? D9 40 0C", 2 );
}