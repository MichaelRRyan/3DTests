  /// <summary>
/// Vector 3 class
/// @Michael Rainsford Ryan
/// @Date 13/12/2018
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}


/// <summary>
/// create a vector 3 from three doubles
/// </summary>
/// <param name="t_x">X value</param>
/// <param name="t_y">Y value</param>
/// <param name="t_z">Z value</param>
MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	y = t_y;
	z = t_z;
}


/// <summary>
/// create a vector 3 from an sf::vector3f
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<double>( t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}


/// <summary>
/// create a vector 3 from an sf::vector3i
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}


/// <summary>
/// create a vector 3 from an sf::vector2i
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0.0;
}


/// <summary>
/// create a vector 3 from an sf::vector2u
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0.0;
}


/// <summary>
/// create a vector 3 from an sf::vector2f
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x);
	y = static_cast<double>(t_sfVector.y);
	z = 0.0;
}


/// <summary>
/// Defines the + operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be added with</param>
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z); // Add all coresponding components together
}


/// <summary>
/// Defines the - operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be subtracted</param>
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z); // Subtract each cooresponding component
}


/// <summary>
/// Defines the * operator for all myVector3's
/// </summary>
/// <param name="t_scalar">Scalar to be multiplied with</param>
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar); // multiply all coresponding components together
}


/// <summary>
/// Defines the / operator for all myVector3's
/// </summary>
/// <param name="t_divisor">Scalar to be divided with</param>
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor); // Divide each coresponding component
}


/// <summary>
/// Defines the += operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be added</param>
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	// Modify each value by t_right
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	return MyVector3(x, y, z);
}

/// <summary>
/// Defines the -= operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be subtracted</param>
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	// Modify each value by t_right
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;

	return MyVector3(x, y, z);
}


/// <summary>
/// Defines the equality check (==) operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be checked against</param>
bool MyVector3::operator==(const MyVector3 t_right) const
{
	return (x == t_right.x && y == t_right.y && z == t_right.z); // Checks if all components match
}


/// <summary>
/// Defines the not equal check (!=) operator for all myVector3's
/// </summary>
/// <param name="t_right">Vector to be checked against</param>
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	return !(this->operator==(t_right)); // Returns the negative of the equality operator
}


/// <summary>
/// Defines the negative (-) operator for all myVector3's
/// </summary>
MyVector3 MyVector3::operator-()
{
	return MyVector3(-x, -y, -z); // Returns the negative of each value
}


/// <summary>
/// Defines the reverseX function for all myVector3's
/// </summary>
void MyVector3::reverseX()
{
	x = -x; // Assign the x value the reverse of itself
}


/// <summary>
/// Defines the reverseY function for all myVector3's
/// </summary>
void MyVector3::reverseY()
{
	y = -y; // Assign the y value the reverse of itself
}


/// <summary>
/// Takes the square root of the squares of the vector to get a total magnitude or length of the vector and returns it
/// </summary>
double MyVector3::length() const
{
	const double lengthSquared = (x * x) + (y * y) + (z * z); // Squares and adds all components to get the lengh squared
	const double magnitude = sqrt(lengthSquared); // squares the value to get the magnitude, or length
	return magnitude;
}


/// <summary>
/// Adds the squares of the x, y and z of a vector to get the magnitude or length squared of the vector and returns it
/// </summary>
double MyVector3::lengthSquared() const
{
	const double lengthSquared = (x * x) + (y * y) + (z * z); // Squares and adds all components to get the lengh squared
	return lengthSquared;
}


/// <summary>
/// Multiplies each component of a vector against the equivalent component of the other and adds all results to return the dot product
/// </summary>
/// <param name="t_other">Vector to be scalar multiplied with</param>
double MyVector3::dot(const MyVector3 t_other) const
{
	const double dotProduct = (x * t_other.x) + (y * t_other.y) + (z * t_other.z); // Multiplies each coresponding value together and adds everthing to get the dot product
	return dotProduct;
}


/// <summary>
/// Multiplies and subtracts elements of the two vectors to produce a new vector perpendicular to the original two vectors
/// </summary>
/// <param name="t_other">Vector to be multiplied with</param>
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	const double newX = (y * t_other.z) - (z * t_other.y); // Finds the new x value
	const double newY = (z * t_other.x) - (x * t_other.z); // Finds the new y value
	const double newZ = (x * t_other.y) - (y * t_other.x); // Finds the new z value
	return MyVector3(newX, newY, newZ); // Returns the new values
}


/// <summary>
/// Uses the magnitudes of both vectors along with the dot product to get the angle between the two vectors
/// </summary>
/// <param name="t_other">Vector to get the angle between</param>
double MyVector3::angleBetween(const MyVector3 t_other) const
{
	const MyVector3 vectorOne{ x, y, z }; // Creates a vector from the components of the vector calling this function
	double angleDeg = 0; // Initiates the angle to 0

	const double vectorMagnitudes = vectorOne.length() * t_other.length(); // Gets the magnitudes of both vector multiplied together

	if (vectorMagnitudes != 0) // Checks for zero to avoid zero division
	{
		const double cosOfAngle = vectorOne.dot(t_other) / vectorMagnitudes; // Divides the dot product by the magnitudes
		const double angleRads = acos(cosOfAngle); // Gets the angle in radians
		angleDeg = angleRads * 180.0 / PI; // Converts the angle to degrees
	}

	return angleDeg;
}


/// <summary>
/// Divides the vector by its magnitude to get the unit vector
/// </summary>
MyVector3 MyVector3::unit() const
{
	const MyVector3 vectorOne{ x, y, z }; // Creates a vector from the components of the vector calling this function
	MyVector3 unitVector{}; // Initialises the unit vector to a blank vector

	if (vectorOne.length() != 0) // Check for zero to avoid zero division
	{
		unitVector = vectorOne / vectorOne.length(); // Divide the vector by its length
	}

	return unitVector;
}


/// <summary>
/// Divides all components of a vector by the magnitude of the vector to get a normalised vector
/// </summary>
void MyVector3::normalise()
{
	const double magnitudeOfVector = MyVector3{ x, y, z }.length(); // Takes the length of a new vector created from the components of the vector calling the function

	if (magnitudeOfVector != 0) // Check for zero to avoid zero division
	{
		// Assigns each value to the unit vector value
		x = x / magnitudeOfVector;
		y = y / magnitudeOfVector;
		z = z / magnitudeOfVector;
	}
	else
	{
		// In case of zero division set everything to zero
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
}


/// <summary>
/// Uses the magnitude of the vector being projected onto along with the dot product to get the projection of one vector onto another
/// </summary>
/// <param name="t_onto">Vector to be projected onto</param>
MyVector3 MyVector3::projection(const MyVector3 t_onto) const
{
	const MyVector3 vectorOne{ x, y, z }; // Creates a vector from the components of the vector calling this function
	MyVector3 vectorProjection{}; // Initialise the vector projection to a blank vector

	if (t_onto.length() != 0) // Checks for zero to avoid zero division
	{
		const double dotOverMagnitude = t_onto.dot(vectorOne) / t_onto.length(); // Divides the dot product by the length of the vector being projected on
		const MyVector3 vectorOverMagnitude = t_onto / t_onto.length(); // Divides the vector by its magnitude

		vectorProjection = vectorOverMagnitude * dotOverMagnitude; // Multiplies the two new variables together to get the projection
	}

	return vectorProjection;
}


/// <summary>
/// Uses the projection of the vector to find the vector rejection and returns it
/// </summary>
/// <param name="t_onto">Vector to be projected onto</param>
MyVector3 MyVector3::rejection(const MyVector3 t_onto) const
{
	const MyVector3 vectorOne{ x, y, z }; // Creates a vector from the components of the vector calling this function

	const MyVector3 vectorRejection = vectorOne - vectorOne.projection(t_onto); // Divides the vector original vector by the projection to get the rejection

	return vectorRejection;
}


/// <summary>
/// Defines the operator to create an sf::Vector2u from a vector3
/// </summary>
MyVector3::operator sf::Vector2u()
{
	double newX = x; // initialise the new x
	double newY = y; // initialise the new y

	// Make the x positive if it's a negative
	if (x < 0)
	{
		newX *= -1;
	}

	// Make the y positive is it's a negative
	if (y < 0)
	{
		newY *= -1;
	}

	// Change the datatype and return the new x and y
	return sf::Vector2u{ static_cast<unsigned>(round(newX)),static_cast<unsigned>(round(newY)) };
}
