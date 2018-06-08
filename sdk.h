#pragma once

class vec2
{
public:
	vec2( )
	{
		x = y = 0.0f;
	}

	vec2( float X, float Y )
	{
		x = X; y = Y;
	}

	vec2( float* v )
	{
		x = v[0]; y = v[1];
	}

	vec2( const float* v )
	{
		x = v[0]; y = v[1];
	}

	vec2( const vec2& v )
	{
		x = v.x; y = v.y;
	}

	vec2& operator=( const vec2& v )
	{
		x = v.x; y = v.y; return *this;
	}

	float& operator[]( int i )
	{
		return ( ( float* ) this )[i];
	}

	float operator[]( int i ) const
	{
		return ( ( float* ) this )[i];
	}

	vec2& operator+=( const vec2& v )
	{
		x += v.x; y += v.y; return *this;
	}

	vec2& operator-=( const vec2& v )
	{
		x -= v.x; y -= v.y; return *this;
	}

	vec2& operator*=( const vec2& v )
	{
		x *= v.x; y *= v.y; return *this;
	}

	vec2& operator/=( const vec2& v )
	{
		x /= v.x; y /= v.y; return *this;
	}

	vec2& operator+=( float v )
	{
		x += v; y += v; return *this;
	}

	vec2& operator-=( float v )
	{
		x -= v; y -= v; return *this;
	}

	vec2& operator*=( float v )
	{
		x *= v; y *= v; return *this;
	}

	vec2& operator/=( float v )
	{
		x /= v; y /= v; return *this;
	}

	vec2 operator+( const vec2& v ) const
	{
		return vec2( x + v.x, y + v.y );
	}

	vec2 operator-( const vec2& v ) const
	{
		return vec2( x - v.x, y - v.y );
	}

	vec2 operator*( const vec2& v ) const
	{
		return vec2( x * v.x, y * v.y );
	}

	vec2 operator/( const vec2& v ) const
	{
		return vec2( x / v.x, y / v.y );
	}

	vec2 operator+( float v ) const
	{
		return vec2( x + v, y + v );
	}

	vec2 operator-( float v ) const
	{
		return vec2( x - v, y - v );
	}

	vec2 operator*( float v ) const
	{
		return vec2( x * v, y * v );
	}

	vec2 operator/( float v ) const
	{
		return vec2( x / v, y / v );
	}

	void set( float X = 0.0f, float Y = 0.0f )
	{
		x = X; y = Y;
	}

	float length( void ) const
	{
		return sqrtf( x * x + y * y );
	}

	float lengthsqr( void ) const
	{
		return ( x * x + y * y );
	}

	float dist_to( const vec2& v ) const
	{
		return ( *this - v ).length( );
	}

	float dist_to_sqr( const vec2& v ) const
	{
		return ( *this - v ).lengthsqr( );
	}

	float dot( const vec2& v ) const
	{
		return ( x * v.x + y * v.y );
	}

	bool is_zero( void ) const
	{
		return ( x > -FLT_EPSILON && x < FLT_EPSILON &&
				 y > -FLT_EPSILON && y < FLT_EPSILON );
	}

	operator bool( ) const noexcept
	{
		return !is_zero( );
	}

public:
	float x, y;
};

class vec3
{
public:
	vec3( )
	{
		x = y = z = 0.0f;
	}

	vec3( float X, float Y, float Z )
	{
		x = X;
		y = Y;
		z = Z;
	}

	vec3( float* v )
	{
		x = v[0];
		y = v[1];
		z = v[2];
	}

	vec3( const float* v )
	{
		x = v[0];
		y = v[1];
		z = v[2];
	}

	vec3( const vec3& v )
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	vec3( const vec2& v )
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
	}

	vec3& operator=( const vec3& v )
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	vec3& operator=( const vec2& v )
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
		return *this;
	}

	float& operator[]( int i )
	{
		return ( ( float* ) this )[i];
	}

	float operator[]( int i ) const
	{
		return ( ( float* ) this )[i];
	}

	vec3& operator+=( const vec3& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	vec3& operator-=( const vec3& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	vec3& operator*=( const vec3& v )
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	vec3& operator/=( const vec3& v )
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	vec3& operator+=( float v )
	{
		x += v;
		y += v;
		z += v;
		return *this;
	}

	vec3& operator-=( float v )
	{
		x -= v;
		y -= v;
		z -= v;
		return *this;
	}

	vec3& operator*=( float v )
	{
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}

	vec3& operator/=( float v )
	{
		x /= v;
		y /= v;
		z /= v;
		return *this;
	}

	vec3 operator+( const vec3& v ) const
	{
		return vec3( x + v.x, y + v.y, z + v.z );
	}

	vec3 operator-( const vec3& v ) const
	{
		return vec3( x - v.x, y - v.y, z - v.z );
	}

	vec3 operator*( const vec3& v ) const
	{
		return vec3( x * v.x, y * v.y, z * v.z );
	}

	vec3 operator/( const vec3& v ) const
	{
		return vec3( x / v.x, y / v.y, z / v.z );
	}

	vec3 operator+( float v ) const
	{
		return vec3( x + v, y + v, z + v );
	}

	vec3 operator-( float v ) const
	{
		return vec3( x - v, y - v, z - v );
	}

	vec3 operator*( float v ) const
	{
		return vec3( x * v, y * v, z * v );
	}

	vec3 operator/( float v ) const
	{
		return vec3( x / v, y / v, z / v );
	}

	bool operator== ( const vec3& other ) const
	{
		return x == other.x && y == other.y && other.z == other.z;
	}

	bool operator!= ( const vec3& other ) const
	{
		return !( *this == other );
	}

	bool operator!( ) const
	{
		return this->is_zero( );
	}

	vec3 center( ) const
	{
		return *this * 0.5f;
	}

	float length( ) const
	{
		return std::sqrt( x * x + y * y + z * z );
	}

	float length_sqr( ) const
	{
		return ( x * x + y * y + z * z );
	}

	float length2d( ) const
	{
		return std::sqrt( x * x + y * y );
	}

	float length2d_sqr( ) const
	{
		return ( x * x + y * y );
	}

	float dist( const vec3& v ) const
	{
		return ( *this - v ).length( );
	}

	float dist_sqr( const vec3& v ) const
	{
		return ( *this - v ).length_sqr( );
	}

	float dot( const vec3& v ) const
	{
		return ( x * v.x + y * v.y + z * v.z );
	}

	float dot_2d( const vec3& v ) const
	{
		return ( x * v.x + y * v.y );
	}

	vec3 cross_product( const vec3& v ) const
	{
		return vec3( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x );
	}

	bool is_zero( ) const
	{
		return ( x > -0.01f && x < 0.01f &&
				 y > -0.01f && y < 0.01f &&
				 z > -0.01f && z < 0.01f );
	}

	void zero( )
	{
		x = y = z = 0.0f;
	}

	bool is_nan( ) const
	{
		return isnan( x ) || isnan( y ) || isnan( z );
	}

	void normalize( )
	{
		auto& vec = *this;

		// Proper large epenis normalization, none of that gay while loop shit
		for ( auto i = 0; i <= 2; i++ )
			if ( vec[i] > 180.f || vec[i] < -180.f )
				vec[i] = ( vec[i] < 0.f ) ? vec[i] + 360.f * round( abs( vec[i] / 360.f ) ) : vec[i] - 360.f * round( abs( vec[i] / 360.f ) );
	}

	vec3 normalized( ) const
	{
		auto vec = *this;
		vec.normalize( );
		return vec;
	}

	bool is_zero( )
	{
		return x == 0.0f && y == 0.0f && z == 0.0f;
	}

public:
	float x, y, z;
};

class color_t
{
	uint8_t R, G, B, A;
public:
	constexpr color_t( ) : R( 0 ), G( 0 ), B( 0 ), A( 0 ) { }
	constexpr color_t( int r, int g, int b, int a ) : R( r ), G( g ), B( b ), A( a ) { }
	constexpr color_t( int r, int g, int b ) : R( r ), G( g ), B( b ), A( 255 ) { }

	// for esp
	static __forceinline color_t team_based( const bool& friendly )
	{
		return friendly ? color_t( 0, 100, 255 ) : color_t( 255, 50, 0 );
	}

	int r( ) const { return R; }
	int g( ) const { return G; }
	int b( ) const { return B; }
	int a( ) const { return A; }

	color_t& operator =( const color_t& c )
	{
		R = c.r( );
		G = c.g( );
		B = c.b( );
		A = c.a( );
		return *this;
	}
};

class c_entity
{
public:
	uint8_t pad[48];
	vec3 m_origin;
	uint8_t pad1[84];
	int m_client_number;
	uint8_t pad2[154];
	uint8_t m_ent_type;
	uint8_t pad3[125];
	int m_lifestate;

	__forceinline bool alive( )
	{
		return m_lifestate & 2;
	}
};

class c_weap_def
{
	// BG_GetWeaponDef - 0x425770
};

class c_user_cmd
{
public:
	int m_server_time;
	uint32_t m_buttons;
	uint8_t pad[4];
	int m_viewangles[3];
	uint8_t m_weapon;
	uint8_t pad1[27];
};

class c_input
{
public:
	c_user_cmd m_cmds[128];
	int m_cmd_number;

	__forceinline c_user_cmd* get_cmd( const size_t& offset = 0 )
	{
		return &m_cmds[( m_cmd_number - offset ) & 0x7f];
	}
};

class c_ref_def
{
public:
	uint8_t pad[32];

	// using this is very bad dont do it pls
	// use viewmatrix->viewposition
	vec3 m_view_origin;
};

class c_matrix
{
public:
	vec3 m_recoil;
	vec3 m_origin;
	vec3 m_vieworigin;
	vec3 m_weapon_angles;
	uint8_t pad[72];
	vec3 m_viewangles;
};

class c_cg
{
public:
	// if u ever want/ need it
	//uint8_t pad[141522];
	//float   m_time;
	uint8_t pad[211280];
	int m_client_number;
	// i really hope i counted right
	uint8_t pad1[362412];
	c_ref_def* m_ref_def;
};

class c_cg_static
{
public:
	uint8_t pad[320];
	int m_max_clients;
};

static const char* tag_list[] =
{
	"j_head",
	"j_neck",
	"j_spineupper",
	"j_spinelower",
	"j_elbow_ri",
	"j_elbow_le",
	"j_wrist_ri",
	"j_wrist_le",
	"j_knee_ri",
	"j_knee_le",
	"j_ankle_ri",
	"j_ankle_le"
};

enum button_t
{
	state_none = 0x0,
	state_fire = 0x1,
	state_use = 0x8,
	state_prone = 0x100,
	state_crouch = 0x200,
	state_lethal = 0x4000,
	state_tactical = 0x8000,
	state_ads = 0x80800,
	state_pause = 0x800000,
	state_melee = 0x4000004,
};