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

	void set( float X = 0.0f, float Y = 0.0f, float Z = 0.0f )
	{
		x = X;
		y = Y;
		z = Z;
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

	void clamp( )
	{
		x = std::clamp<float>( x, -89.f, 89.f );
		y = std::clamp<float>( y, -180.0f, 180.0f );
		z = 0.0f;
	}

	vec3 clamped( )
	{
		return vec3(
			std::clamp<float>( x, -89.f, 89.f ),
			std::clamp<float>( y, -180.0f, 180.0f ),
			0.0f
		);
	}
	void normalize_in_place( )
	{
		vec3& v = *this;

		float iradius = 1.f / ( this->length( ) + FLT_EPSILON );

		v.x *= iradius;
		v.y *= iradius;
		v.z *= iradius;
	}

	bool is_zero( )
	{
		return x == 0.0f && y == 0.0f && z == 0.0f;
	}

public:
	float x, y, z;
};

class c_entity
{
public:
	uint8_t pad[796];
};

class c_weap_def
{
	// BG_GetWeaponDef - 0x425770
};

class c_user_cmd
{
	uint8_t pad[52];
};

class c_input
{
public:
	c_user_cmd m_cmds[128];

	__forceinline c_user_cmd* get_cmd( const size_t& offset = 0 )
	{
		static auto g_cmd_num = memory::pattern_search< int** >( "A1 ? ? ? ? 56 8B 74 24 0C 3B F0", 2 );

		return &m_cmds[( ( **g_cmd_num ) - offset ) & 0x7f];
	}
};

class c_ref_def
{
	uint8_t pad[32];
	vec3 m_view_origin;
};

class c_cg
{
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
	uint8_t pad[409600];
};