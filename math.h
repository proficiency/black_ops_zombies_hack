#pragma once

namespace math
{
	enum
	{
		PITCH,
		YAW,
		ROLL
	};

	static constexpr float pi = 3.14159265358979323846f;
	static constexpr float radpi = 180.0f / pi;
	static constexpr float pirad = pi / 180.0f;

	inline int to_short( const float& angle )
	{
		return ( ( int ) ( ( angle ) * 65536 / 360 ) & 65535 );
	}

	inline float to_angle( const int& _short )
	{
		return  ( ( _short )*( 360.0f / 65536 ) );
	}

	inline void q_vector_angles( const vec3& value1, vec3& angles )
	{
		float   forward;
		float   yaw, pitch;

		if ( value1[1] == 0 && value1[0] == 0 )
		{
			yaw = 0;
			if ( value1[2] > 0 )
			{
				pitch = 90;
			}
			else
			{
				pitch = 270;
			}
		}
		else
		{
			if ( value1[0] )
			{
				yaw = ( atan2( value1[1], value1[0] ) * 180 / pi );
			}
			else if ( value1[1] > 0 )
			{
				yaw = 90;
			}
			else
			{
				yaw = 270;
			}
			if ( yaw < 0 )
			{
				yaw += 360;
			}

			forward = sqrt( value1[0] * value1[0] + value1[1] * value1[1] );
			pitch = ( atan2( value1[2], forward ) * 180 / pi );
			if ( pitch < 0 )
			{
				pitch += 360;
			}
		}

		angles[0] = -pitch;
		angles[1] = yaw;
		angles[2] = 0;
	}

	inline void q_angle_vectors( const vec3& angles, vec3& forward, vec3& right, vec3& up )
	{
		float		angle;
		float		sr, sp, sy, cr, cp, cy;

		angle = angles[YAW] * ( pi * 2 / 360 );
		sy = sin( angle );
		cy = cos( angle );
		angle = angles[PITCH] * ( pi * 2 / 360 );
		sp = sin( angle );
		cp = cos( angle );
		angle = angles[ROLL] * ( pi * 2 / 360 );
		sr = sin( angle );
		cr = cos( angle );

		forward[0] = cp * cy;
		forward[1] = cp * sy;
		forward[2] = -sp;

		right[0] = ( -1 * sr*sp*cy + -1 * cr*-sy );
		right[1] = ( -1 * sr*sp*sy + -1 * cr*cy );
		right[2] = -1 * sr*cp;

		up[0] = ( cr*sp*cy + -sr * -sy );
		up[1] = ( cr*sp*sy + -sr * cy );
		up[2] = cr * cp;
	}

	inline void q_angle_vectors( const vec3& angles, vec3& forward )
	{
		float   angle{ };
		float   sp{ }, sy{ }, cp{ }, cy{ };

		angle = angles[YAW] * ( pi * 2 / 360 );
		sy = sin( angle );
		cy = cos( angle );
		angle = angles[PITCH] * ( pi * 2 / 360 );
		sp = sin( angle );
		cp = cos( angle );

		forward[0] = cp * cy;
		forward[1] = cp * sy;
		forward[2] = -sp;
	}
}