#pragma once
#include <iostream>
using namespace std;

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/

//VECTOR CLASS
class Vector {
private:
	double data[4];
public:
	Vector(double x = 0, double y = 0, double z = 0) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = 1;
	}
	void setX(double x) {
		data[0] = x;
	}
	void setY(double y) {
		data[1] = y;
	}
	void setZ(double z) {
		data[2] = z;
	}
	void setW(double w) {
		data[3] = w;
	}
	void setData(int index, double x) {
		data[index] = x;
	}
	void setData(double x, double y, double z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}
	double getX() {
		return data[0];
	}
	double getY() {
		return data[1];
	}
	double getZ() {
		return data[2];
	}
	double getW() {
		return data[3];
	}
	double getData(int index) {
		return data[index];
	}
	void operator=(Vector vector) {
		data[0] = vector.getX();
		data[1] = vector.getY();
		data[2] = vector.getZ();
		data[3] = vector.getW();
	}
	Vector operator+(Vector vector) {
		Vector result;
		result.setData(data[0] + vector.getX(), data[1] + vector.getY(), data[2] + vector.getZ());
		//kurang w
		return result;
	}
	Vector operator-(Vector vector) {
		Vector result;
		result.setData(data[0] - vector.getX(), data[1] - vector.getY(), data[2] - vector.getZ());
		//kurang w
		return result;
	}
	Vector operator*(double scalar) {
		Vector result;
		result.setData(data[0] * scalar, data[1] * scalar, data[2] * scalar);
		//kurang w
		return result;
	}
	Vector operator/(double scalar) {
		Vector result;
		result.setData(data[0] / scalar, data[1] / scalar, data[2] / scalar);
		//kurang w
		return result;
	}
	Vector cross(Vector vector) {
		Vector result;
		result.setX(data[1] * vector.getZ() - data[2] * vector.getY());
		result.setY(data[2] * vector.getX() - data[0] * vector.getZ());
		result.setZ(data[0] * vector.getY() - data[1] * vector.getX());
		//kurang w
		return result;
	}
	double dot(Vector vector) {
		double result;
		result = data[0] * vector.getX() + data[1] * vector.getY() + data[2] * vector.getZ();
		return result;
	}
	void print() {
		for (int a = 0; a < 4; a++) {
			printf("%6.3lf ", data[a]);
		}
		cout << endl;
	}
};

//MATRIX CLASS
class Matrix {
private:
	double data[4][4];
public:
	Matrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j)
					data[i][j] = 1;
				else
					data[i][j] = 0;
			}
		}
	}
	void setData(int row, int col, double x) {
		data[row][col] = x;
	}
	double getData(int row, int col) {
		return data[row][col];
	}
	void operator=(Matrix tmp) {
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				data[a][b] = tmp.getData(a, b);
			}
		}
	}
	Matrix operator+(Matrix tmp) {
		Matrix result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.setData(i, j, (data[i][j] + tmp.getData(i, j)));
			}
		}
		return result;
	}
	Matrix operator-(Matrix tmp) {
		Matrix result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.setData(i, j, (data[i][j] - tmp.getData(i, j)));
			}
		}
		return result;
	}
	Matrix operator*(Matrix tmp) {
		Matrix result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				double res = 0;
				for (int k = 0; k < 4; k++) {
					res = res + (data[i][k] * tmp.getData(k, j));
				}
				result.setData(i, j, res);
			}
		}
		return result;
	}
	Vector operator*(Vector x) {
		Vector result;
		for (int a = 0; a < 4; a++) {
			double res = 0;
			for (int b = 0; b < 4; b++) {
				res = res + (data[a][b] * x.getData(b));
			}
			result.setData(a, res);
		}
		return result;
	}
	Matrix transpose() {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++)
				result.setData(b, a, data[a][b]);
		}
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++)
				data[a][b] = result.getData(a, b);
		}
		return (*this);
	}
	void Viewprint() {
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++)
				printf("%8.3lf ", data[a][b]);
			cout << endl;
		}
	}
};

//TRANSFORMATION CLASS
class Transformation {
public:
	Matrix identity() {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (a == b)
					result.setData(a, b, 1);
				else
					result.setData(a, b, 0);
			}
		}
		return result;
	}
	Matrix translation(double x, double y, double z) {
		Matrix result;
		result.setData(0, 3, x);
		result.setData(1, 3, y);
		result.setData(2, 3, z);
		return result;
	}
	Matrix scalling(double x, double y, double z) {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (a == b) {
					switch (a) {
					case 0: result.setData(a, b, x); break;
					case 1: result.setData(a, b, y); break;
					case 2: result.setData(a, b, z); break;
					case 3: result.setData(a, b, 1); break;
					}
				}
				else
					result.setData(a, b, 0);
			}
		}
		return result;
	}
	Matrix rotationX(double degree) {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			if (a == 0)
				result.setData(0, 0, 1);
			else {
				result.setData(0, a, 0);
				result.setData(a, 0, 0);
			}
		}
		double radian = degree * 3.14 / 180.0;
		result.setData(1, 1, cos(radian));
		result.setData(2, 2, cos(radian));
		result.setData(1, 2, -1 * sin(radian));
		result.setData(2, 1, sin(radian));
		return result;
	}
	Matrix rotationY(double degree) {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			if (a == 1)
				result.setData(1, 1, 1);
			else {
				result.setData(1, a, 0);
				result.setData(a, 1, 0);
			}
		}
		double radian = degree * 3.14 / 180.0;
		result.setData(0, 0, cos(radian));
		result.setData(2, 2, cos(radian));
		result.setData(2, 0, -1 * sin(radian));
		result.setData(0, 2, sin(radian));
		return result;
	}
	Matrix rotationZ(double degree) {
		Matrix result;
		for (int a = 0; a < 4; a++) {
			if (a == 1)
				result.setData(1, 1, 1);
			else {
				result.setData(1, a, 0);
				result.setData(a, 1, 0);
			}
		}
		double radian = degree * 3.14 / 180.0;
		result.setData(0, 0, cos(radian));
		result.setData(1, 1, cos(radian));
		result.setData(1, 0, sin(radian));
		result.setData(0, 1, -1 * sin(radian));
		return result;
	}
};

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/
