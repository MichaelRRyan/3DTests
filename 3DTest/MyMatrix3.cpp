// @Author Michael Rainsford Ryan
#include "MyMatrix3.h"


/// <summary>
/// Default constructer for the matrices
/// Creates a null matrix with all zero, double datatype values
/// </summary>
MyMatrix3::MyMatrix3()
{
	m11 = 0.0;
	m12 = 0.0;
	m13 = 0.0;
	m21 = 0.0;
	m22 = 0.0;
	m23 = 0.0;
	m31 = 0.0;
	m32 = 0.0;
	m33 = 0.0;
}

/// <summary>
/// Override constructer for for all matrices
/// Creates a matrix from the inputted values
/// m11 = t_a11 and so on
/// </summary>
/// <param name="t_a11">m11</param>
/// <param name="t_a12">m12</param>
/// <param name="t_a13">m13</param>
/// <param name="t_a21">m21</param>
/// <param name="t_a22">m22</param>
/// <param name="t_a23">m23</param>
/// <param name="t_a31">m31</param>
/// <param name="t_a32">m32</param>
/// <param name="t_a33">m33</param>
MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33)
{
	m11 = t_a11;
	m12 = t_a12;
	m13 = t_a13;
	m21 = t_a21;
	m22 = t_a22;
	m23 = t_a23;
	m31 = t_a31;
	m32 = t_a32;
	m33 = t_a33;
}

/// <summary>
/// Creates a new matrix from 3 MyVector3's
/// </summary>
/// <param name="t_row1">Row 1</param>
/// <param name="t_row2">Row 2</param>
/// <param name="t_row3">Row 3</param>
MyMatrix3::MyMatrix3(const MyVector3 t_row1, const MyVector3 t_row2, const MyVector3 t_row3)
{
	m11 = t_row1.x;
	m12 = t_row1.y;
	m13 = t_row1.z;
	m21 = t_row2.x;
	m22 = t_row2.y;
	m23 = t_row2.z;
	m31 = t_row3.x;
	m32 = t_row3.y;
	m33 = t_row3.z;
}

/// <summary>
/// Default deconstructer for for all matrices
/// </summary>
MyMatrix3::~MyMatrix3()
{
}

/// <summary>
/// Creates and returns a string from a matrix
/// </summary>
/// <returns>Matrix in string form</returns>
std::string MyMatrix3::toString() const
{
	std::string matrixString =	"[ " + std::to_string(m11) + " " + std::to_string(m12) + " " + std::to_string(m13) + " ]\n" +
								"[ " + std::to_string(m21) + " " + std::to_string(m22) + " " + std::to_string(m23) + " ]\n" +
								"[ " + std::to_string(m31) + " " + std::to_string(m32) + " " + std::to_string(m33) + " ]";
	return matrixString;
}

/// <summary>
/// Compares two matrices and returns true if they both contain the same values for all components
/// </summary>
/// <param name="other">Matrix to compare with</param>
/// <returns>Equality</returns>
bool MyMatrix3::operator==(const MyMatrix3 other) const
{
	if (m11 == other.m11 && m12 == other.m12 && m13 == other.m13
		&& m21 == other.m21 && m22 == other.m22 && m23 == other.m23
		&& m31 == other.m31 && m32 == other.m32 && m33 == other.m33)
	{
		return true;
	}
	return false;
}

/// <summary>
/// Compares two matrices and returns false if they both contain the same values for all components
/// </summary>
/// <param name="other">Matrix to compare with</param>
/// <returns>Reverse Equality</returns>
bool MyMatrix3::operator!=(const MyMatrix3 other) const
{
	return !(this->operator==(other));
}

/// <summary>
/// Returns a new matrix with each component added with each component of the other matrix.
/// </summary>
/// <param name="t_other">Vector to be added with</param>
/// <returns>A new vector with all components added</returns>
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	return MyMatrix3(m11 + t_other.m11, m12 + t_other.m12, m13 + t_other.m13,
					 m21 + t_other.m21, m22 + t_other.m22, m23 + t_other.m23,
					 m31 + t_other.m31, m32 + t_other.m32, m33 + t_other.m33);
}

/// <summary>
/// Returns a new matrix with each component subtracted with each component of the other matrix.
/// </summary>
/// <param name="t_other">Vector be subtracted</param>
/// <returns>A new vector with all components subtracted</returns>
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	return MyMatrix3(m11 - t_other.m11, m12 - t_other.m12, m13 - t_other.m13,
					 m21 - t_other.m21, m22 - t_other.m22, m23 - t_other.m23,
					 m31 - t_other.m31, m32 - t_other.m32, m33 - t_other.m33);
}

/// <summary>
/// Returns a new matrix multiplied with another
/// </summary>
/// <param name="t_other">matrix to be multiplied with</param>
/// <returns>Multiplied matrix</returns>
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	MyMatrix3 MultipliedMatrix;

	// Calculate row 1
	MultipliedMatrix.m11 = (m11 * t_other.m11) + (m12 * t_other.m21) + (m13 * t_other.m31); // Calculate column 1
	MultipliedMatrix.m12 = (m11 * t_other.m12) + (m12 * t_other.m22) + (m13 * t_other.m32); // Calculate column 2
	MultipliedMatrix.m13 = (m11 * t_other.m13) + (m12 * t_other.m23) + (m13 * t_other.m33); // Calculate column 3

	// Calculate row 2
	MultipliedMatrix.m21 = (m21 * t_other.m11) + (m22 * t_other.m21) + (m23 * t_other.m31); // Calculate column 1
	MultipliedMatrix.m22 = (m21 * t_other.m12) + (m22 * t_other.m22) + (m23 * t_other.m32); // Calculate column 2
	MultipliedMatrix.m23 = (m21 * t_other.m13) + (m22 * t_other.m23) + (m23 * t_other.m33); // Calculate column 3

	// Calculate row 3
	MultipliedMatrix.m31 = (m31 * t_other.m11) + (m32 * t_other.m21) + (m33 * t_other.m31); // Calculate column 1
	MultipliedMatrix.m32 = (m31 * t_other.m12) + (m32 * t_other.m22) + (m33 * t_other.m32); // Calculate column 2
	MultipliedMatrix.m33 = (m31 * t_other.m13) + (m32 * t_other.m23) + (m33 * t_other.m33); // Calculate column 3

	return MultipliedMatrix;
}

/// <summary>
/// Returns a new MyVector3 of a matrix multiplied with a MyVector3
/// </summary>
/// <param name="t_vector">Vector to be multiplied with</param>
/// <returns>Multiplied vector</returns>
MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	MyVector3 MultipliedVector;

	// Calculate the new vector
	MultipliedVector.x = m11 * t_vector.x + m12 * t_vector.y + m13 * t_vector.z; // Calculate the x component
	MultipliedVector.y = m21 * t_vector.x + m22 * t_vector.y + m23 * t_vector.z; // Calculate the y component
	MultipliedVector.z = m31 * t_vector.x + m32 * t_vector.y + m33 * t_vector.z; // Calculate the z component

	return MultipliedVector;
}

/// <summary>
/// Returns a new vector with each component multiplied against a scalar value
/// </summary>
/// <param name="t_scale">Scalar to be multiplied with</param>
/// <returns>Multiplied matrix</returns>
MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	return MyMatrix3(m11 * t_scale, m12 * t_scale, m13 * t_scale,
					 m21 * t_scale, m22 * t_scale, m23 * t_scale,
					 m31 * t_scale, m32 * t_scale, m33 * t_scale);
}

/// <summary>
/// Returns a new transposed matrix of the matrix calling it
/// </summary>
/// <returns>Matrix transpose</returns>
MyMatrix3 MyMatrix3::transpose() const
{
	return MyMatrix3(m11,m21,m31,m12,m22,m32,m13,m23,m33);
}

/// <summary>
/// Returns the scalar value of the matrix determinant
/// </summary>
/// <returns>Matrix determinant</returns>
double MyMatrix3::determinant() const
{
	const double termFirst = m11 * (m22 * m33 - m32 * m23); // Calculate the first part of the equation
	const double termSecond = m21 * (m33 * m12 - m32 * m13); // Calculate the second part of the equation
	const double termThird = m31 * (m23 * m12 - m22 * m13); // Calculate the third part of the equation
	return termFirst - termSecond + termThird; // Perform the final operations and return the scalar
}

/// <summary>
/// Returns an inverse matrix of the matrix calling it
/// </summary>
/// <returns>Inverse matrix</returns>
MyMatrix3 MyMatrix3::inverse() const
{
	MyMatrix3 inverseMatrix;

	if (this->determinant() != 0.0)
	{
		// Calculate the first row
		inverseMatrix.m11 = m33 * m22 - m32 * m23; // Calculate the first column
		inverseMatrix.m12 = m32 * m13 - m33 * m12; // Calculate the second column
		inverseMatrix.m13 = m23 * m12 - m22 * m13; // Calculate the third column

		// Calculate the second row
		inverseMatrix.m21 = m31 * m23 - m33 * m21; // Calculate the first column
		inverseMatrix.m22 = m33 * m11 - m31 * m13; // Calculate the second column
		inverseMatrix.m23 = m21 * m13 - m23 * m11; // Calculate the third column

		// Calculate the third row
		inverseMatrix.m31 = m32 * m21 - m31 * m22; // Calculate the first column
		inverseMatrix.m32 = m31 * m12 - m32 * m11; // Calculate the second column
		inverseMatrix.m33 = m22 * m11 - m21 * m12; // Calculate the third column

		return inverseMatrix * (1 / this->determinant()); // Multiply by the 1 divided by the determinant to get the inverse
	}
	
	return MyMatrix3{};
}

/// <summary>
/// Returns the a row as inputted as a MyVector3
/// </summary>
/// <param name="t_row">Row number</param>
/// <returns>Row vector</returns>
MyVector3 MyMatrix3::row(const int t_row) const
{
	if (t_row == 0) // Return the first row
	{
		return MyVector3{ m11, m12, m13 };
	}
	else if (t_row == 1) // Return the second row
	{
		return MyVector3{ m21, m22, m23 };
	}
	else if (t_row == 2) // Return the third row
	{
		return MyVector3{ m31, m32, m33 };
	}

	return MyVector3(); // Return a blank vector if not a valid row number
}

/// <summary>
/// Returns the a column as inputted as a MyVector3
/// </summary>
/// <param name="t_column">Column number</param>
/// <returns>Column vector</returns>
MyVector3 MyMatrix3::column(const int t_column) const
{
	if (t_column == 0) // Return the first column
	{
		return MyVector3{ m11, m21, m31 };
	}
	else if (t_column == 1) // Return the second column
	{
		return MyVector3{ m12, m22, m32 };
	}
	else if (t_column == 2) // Return the third column
	{
		return MyVector3{ m13, m23, m33 };
	}

	return MyVector3();
}

/// <summary>
/// Returns a rotation matrix along the Z axis by the inputted angle
/// </summary>
/// <param name="t_angleRadians">Rotation Angle</param>
/// <returns>Rotation matrix</returns>
MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	return MyMatrix3{ cos(t_angleRadians), -sin(t_angleRadians), 0.0, sin(t_angleRadians), cos(t_angleRadians), 0.0, 0.0, 0.0, 1.0 };
}

/// <summary>
/// Returns a rotation matrix along the Y axis by the inputted angle
/// </summary>
/// <param name="t_angleRadians">Rotation Angle</param>
/// <returns>Rotation matrix</returns>
MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	return MyMatrix3{ cos(t_angleRadians), 0.0, sin(t_angleRadians), 0.0, 1.0, 0.0, -sin(t_angleRadians), 0.0, cos(t_angleRadians) };
}

/// <summary>
/// Returns a rotation matrix along the X axis by the inputted angle
/// </summary>
/// <param name="t_angleRadians">Rotation Angle</param>
/// <returns>Rotation matrix</returns>
MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	return MyMatrix3{ 1.0, 0.0, 0.0, 0.0, cos(t_angleRadians), -sin(t_angleRadians), 0.0, sin(t_angleRadians), cos(t_angleRadians) };
}

/// <summary>
/// Returns the translation matrix with the given displacement
/// </summary>
/// <param name="t_displacement">Displacement</param>
/// <returns>Translation matrix</returns>
MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{

	return MyMatrix3{ 1.0, 0.0, t_displacement.x, 0.0, 1.0, t_displacement.y, 0.0, 0.0, 1.0 };
}

/// <summary>
/// Returns the scaling matrix with the given scale factor
/// </summary>
/// <param name="t_scalingfactor">Scale</param>
/// <returns>Scaling matrix</returns>
MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	return MyMatrix3{ t_scalingfactor, 0.0, 0.0, 0.0, t_scalingfactor, 0.0, 0.0, 0.0, t_scalingfactor };
}
