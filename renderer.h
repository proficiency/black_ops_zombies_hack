#pragma once

class c_renderer
{
public:
	c_renderer( IDirect3DDevice9* );

	void create( );
	void release( );

	void start( );
	void finish( );

	void rect( color_t color, float x, float y, float w, float h );
	void string( color_t color, float x, float y, bool centered, const char* fmt, ... );

private:
	IDirect3DDevice9*       m_device;
	IDirect3DStateBlock9*   m_state_block;
	ID3DXSprite*            m_sprite;
	DWORD                   m_old_fvf;
	ID3DXFont*              m_font;

	class c_vertex
	{
	public:
		c_vertex( float x, float y, float z, color_t color )
			: m_x( x ), m_y( y ), m_z( z ), m_color( D3DCOLOR_RGBA( color.r( ), color.g( ), color.b( ), color.a( ) ) )
		{
		}

		float m_x;
		float m_y;
		float m_z;
		float m_rhw = 0;
		D3DCOLOR m_color;
	};
};