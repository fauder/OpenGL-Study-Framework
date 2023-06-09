#pragma once

// Project Includes.
#include "Angle.hpp"
#include "Vector.hpp"

namespace Framework
{
	// TODO: When these are necessary (for example, camera manipulation may utilize polar coordinates);
	// TODO: (cont'd) revise (if necessary) all classes according to XYZ coordinates & handedness utilized in-framework.

	/* In classical mathematical notation (r, theta). X is right & Y is forward & Z is up (right-handed space.) */
	class Polar2
	{
	public:
	/* Constructors. */
		Polar2()
			:
			r(),
			theta()
		{}

		Polar2( const float r, Radians theta )
			:
			r( r ),
			theta( theta )
		{}

	/* Getters & Setters. */
		constexpr float R() const { return r; }
		float& R() { return r; }
		constexpr Radians Theta() const { return theta; }
		Radians& Theta() { return theta; }

	private:
		float r;
		Radians theta;
	};

	/* In classical mathematical notation (r, theta, z).  X is right & Y is forward & Z is up (right-handed space.) */
	class Polar3_Cylindrical
	{
	public:
	/* Constructors. */
		Polar3_Cylindrical()
			:
			r(),
			theta(),
			z()
		{}

		Polar3_Cylindrical( const float r, const Radians theta, const float z )
			:
			r( r ),
			theta( theta ),
			z( z )
		{}

	/* Getters & Setters. */
		constexpr float R() const { return r; }
		float& R() { return r; }
		constexpr Radians Theta() const { return theta; }
		Radians& Theta() { return theta; }
		constexpr float Z() const { return z; }
		float& Z() { return z; }

	private:
		float r;
		Radians theta;
		float z;
	};

	/* In classical mathematical notation (r, theta, phi).  X is right & Y is forward & Z is up (right-handed space.).
	 * Phi starts as completely vertical (up) and rotates "downward" as its value increases (i.e phi = 0 equals vertical (up) direction & phi = 90 equals horizontal direction.
	 */
	class Polar3_Spherical
	{
	public:
	/* Constructors. */
		Polar3_Spherical()
			:
			r(),
			theta(),
			phi()
		{}

		Polar3_Spherical( const float r, const Radians theta, const Radians phi )
			:
			r( r ),
			theta( theta ),
			phi( phi )
		{}

	/* Getters & Setters. */
		constexpr float R() const { return r; }
		float& R() { return r; }
		/* Also called Azimuth or Longitude. */ constexpr Radians Theta() const { return theta; }
		/* Also called Azimuth or Longitude. */ Radians& Theta() { return theta; }
		/* Also called Zenith. Latitude is (90 - Zenith/Phi). */ constexpr Radians Phi() const { return phi; }
		/* Also called Zenith. Latitude is (90 - Zenith/Phi). */ Radians& Phi() { return phi; }

	private:
		float r;
		Radians theta;
		Radians phi;
	};

	/* Deviates from classical mathematical notation (r, theta, phi), more in-line with video game conventions/needs. In this convention, Y is up, X is right & Z is forward (left-handed).
	 * Uses (r, h, p), h = heading, p = pitch.
	 * Heading = 0 -> facing forward (assuming Pitch is also zero). Its value increases -> clockwise rotation.
	 * Pitch = 0 -> horizontal (on XZ plane). It's values increases -> clockwise rotation around X (i.e, facing "more downward", therefore also called the Angle of Declination).
	*/
	class Polar3_Spherical_Game
	{
	public:
	/* Constructors. */
		Polar3_Spherical_Game()
			:
			r(),
			heading(),
			pitch()
		{}

		Polar3_Spherical_Game( const float r, const Radians heading, const Radians pitch )
			:
			r( r ),
			heading( heading ),
			pitch( pitch )
		{}

	/* Getters & Setters. */
		constexpr float R() const { return r; }
		float& R() { return r; }
		/* Heading = 0 means forward (assuming Pitch is also zero).
		 * Increasing Heading means clockwise rotation around the Y axis.
		 */
		constexpr Radians Heading() const { return heading; }
		/* Heading = 0 means forward (assuming Pitch is also zero).
		 * Increasing Heading means clockwise rotation around the Y axis.
		 */
		Radians& Heading() { return heading; }
		/* Pitch = 0 means horizontal.
		 * Also called the Angle of Declination, as Z decreases with increasing Pitch.
		 */
		constexpr Radians Pitch() const { return pitch; }
		/* Pitch = 0 means horizontal.
		 * Also called the Angle of Declination, as Z decreases with increasing Pitch.
		 */
		Radians& Pitch() { return pitch; }

	private:
		float r;
		Radians heading;
		Radians pitch;
	};
}
