#pragma once

namespace hooked
{
	extern  void  __cdecl    create_new_commands( int a1 );
	extern  long  __stdcall  present( IDirect3DDevice9*, RECT*, const RECT*, HWND, const RGNDATA* );

	extern decltype( &create_new_commands )     o_create_new_commands;
	extern decltype( &present )                 o_present;
}

namespace memory
{
	class c_hooking
	{
	public:
		template< typename t >
		inline t get_function( uintptr_t* address, void* new_function )
		{

		}
	};

	template <typename t = uintptr_t>
	static t pattern_search(

		// pattern of bytes to search for
		const  char*       pattern,

		// offset in bytes from address obtained by pattern searching
		const  size_t&     offset = 0,

		// module to search within, pretty much never use anything else
		const  module_t    module = GetModuleHandle( 0 ),

		// search region
		const  uintptr_t&  region_start = std::numeric_limits< uintptr_t >::max( ),
		const  uintptr_t&  region_end = 0
	)
	{
		auto get_pattern = []( const char* raw_pattern ) -> std::vector< uintptr_t >
		{
			std::vector< uintptr_t > pattern;
			char*                    start = ( char* ) raw_pattern;
			char*                    end = ( char* ) ( raw_pattern ) +strlen( raw_pattern );

			for ( char* byte = start; byte < end; ++byte )
			{
				// handle ida sttyle signatures, like a1 ? ? ? ? or a1 ?? ??
				if ( *byte == '?' )
				{
					// jump past ? in string, see if we land on another ?
					if ( *( ++byte ) == '?' )
						byte++;

					pattern.push_back( std::numeric_limits< uintptr_t >::max( ) );
				}
				else
				{
					// we have a valid byte to push back to our new pattern
					pattern.push_back( strtoul( byte, &byte, 16 ) );
				}
			}

			return pattern;
		};

		const   auto       bin = reinterpret_cast< uint8_t* >( module );
		const   auto       bytes = get_pattern( pattern );

		PIMAGE_DOS_HEADER dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( module );
		PIMAGE_NT_HEADERS nt_headers{ };

		if ( !dos_header || dos_header->e_magic != IMAGE_DOS_SIGNATURE )
			return 0;

		nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( ( uintptr_t ) dos_header + dos_header->e_lfanew );

		if ( !nt_headers || nt_headers->Signature != IMAGE_NT_SIGNATURE )
			return 0;

		const  uintptr_t  start = region_start != std::numeric_limits< uintptr_t >::max( ) ? region_start : 0;
		const  uintptr_t  end = region_end > 0 ? region_end : nt_headers->OptionalHeader.SizeOfImage;

		for ( uintptr_t address = start; address < end - bytes.size( ); ++address )
		{
			bool found_pattern = true;

			for ( uintptr_t token = 0; token < bytes.size( ); ++token )
			{
				if ( bytes.data( )[token] != std::numeric_limits< uintptr_t >::max( ) && bin[address + token] != bytes.data( )[token] )
				{
					// either invalid portion of signature or the current bytes don't match
					// break and invalidate return value for now
					found_pattern = false;
					break;
				}
			}

			if ( found_pattern )
			{
				// success, return address
				return ( t ) ( &bin[address] + offset );
			}
		}

		// didn't find pattern
		return ( t ) 0;
	}
}