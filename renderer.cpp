#include "context.h"

// very bad renderer
c_renderer::c_renderer( IDirect3DDevice9* device )
{
	m_device = device;
	create( );
}

void c_renderer::create( )
{
	m_device->CreateStateBlock( D3DSBT_ALL, &m_state_block );

	D3DXCreateSprite( m_device, &m_sprite );
	D3DXCreateFontA( m_device, 12, 0, FW_BOLD, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, "Verdana", &m_font );
}

void c_renderer::release( )
{
	if ( m_state_block )
		m_state_block->Release( );

	if ( m_sprite )
		m_sprite->Release( );

	if ( m_font )
		m_font->Release( );
}

void c_renderer::start( )
{
	if ( !m_state_block || !m_device || !m_sprite )
		return;

	m_state_block->Capture( );

	m_sprite->Begin( D3DXSPRITE_ALPHABLEND );

	m_device->GetFVF( &m_old_fvf );
	m_device->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );

	m_device->SetPixelShader( nullptr );
	m_device->SetTexture( 0, nullptr );

	m_device->SetRenderState( D3DRS_ZENABLE, false );
	m_device->SetRenderState( D3DRS_COLORWRITEENABLE, 0xFFFFFFFF );
	m_device->SetRenderState( D3DRS_MULTISAMPLEANTIALIAS, false );
}

void c_renderer::finish( )
{
	if ( !m_state_block || !m_device || !m_sprite )
		return;

	m_device->SetFVF( m_old_fvf );
	m_state_block->Apply( );
	m_sprite->End( );
	m_device->SetRenderState( D3DRS_MULTISAMPLEANTIALIAS, true );
}

void c_renderer::rect( color_t color, float x, float y, float w, float h )
{
	c_vertex vertices[5] = {
		c_vertex( x, y, 1.0f, color ),
		c_vertex( x + w, y, 1.0f, color ),
		c_vertex( x + w, y + h, 1.0f, color ),
		c_vertex( x, y + h, 1.0f, color ),
		c_vertex( x, y, 1.0f, color )
	};

	m_device->DrawPrimitiveUP( D3DPT_LINESTRIP, 4, vertices, sizeof( c_vertex ) );
}

void c_renderer::string( color_t color, float x, float y, bool centered, const char* fmt, ... )
{
	char buffer[256];
	va_list args;
	va_start( args, fmt );
	vsprintf( buffer, fmt, args );
	va_end( args );

	if ( centered )
	{
		RECT rec = { 0, 0, 0, 0 };

		m_font->DrawTextA( 0, buffer, -1, &rec, DT_CALCRECT | DT_NOCLIP, D3DCOLOR_RGBA( color.r( ), color.g( ), color.b( ), color.a( ) ) );
		rec = { static_cast<int>( x ) - rec.right / 2, static_cast<int>( y ), 0, 0 };
		m_font->DrawTextA( 0, buffer, -1, &rec, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_RGBA( color.r( ), color.g( ), color.b( ), color.a( ) ) );
	}
	else
	{
		RECT rec = { static_cast<int>( x ), static_cast<int>( y ), 1000, 100 };
		m_font->DrawTextA( NULL, buffer, -1, &rec, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_RGBA( color.r( ), color.g( ), color.b( ), color.a( ) ) );
	}
}