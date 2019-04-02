#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <numeric>
#include <math.h> 
#define PI 3.14159265
//�w�q�V�q��Ƶ��c

struct Vector
{
	std::string Name="";
	std::vector<double> Data;
	Vector() {};
	Vector(std::vector<double> data);
	Vector(std::string name,std::vector<double> data);
	friend const Vector operator+(const Vector &x, const Vector &y);
	friend const Vector operator-(const Vector &x, const Vector &y);
	friend const Vector operator*(const Vector &x, const Vector &y);
	friend const double norm(const Vector &x);
	friend const Vector normalization(const Vector &x);
	friend const Vector crossProduct(const Vector &x, const Vector &y);
	friend const Vector component(const Vector &x, const Vector &y);
	friend const Vector projection(const Vector &x, const Vector &y);
	friend const double area(const Vector &x, const Vector &y);
	friend const bool isParallel(const Vector &x, const Vector &y);
	friend const bool isOrthogonal(const Vector &x, const Vector &y);
	friend const double angle(const Vector &x, const Vector &y);
	friend const Vector pN(const Vector &x, const Vector &y);
	friend const bool isLI(const Vector &x, const Vector &y);
};
struct Matrix {
	std::string Name = "";
	std::vector<std::vector<double>> Data;
	Matrix();
	Matrix(std::vector<std::vector<double>> data);
	friend const Matrix operator+(const Matrix &x, const Matrix &y);
	friend const Matrix operator-(const Matrix &x, const Matrix &y);
	friend const Matrix operator*(const Matrix &x, const Matrix &y);
	friend const int rank(const Matrix &x);
	friend const Matrix transpose(const Matrix &x);
	friend const Matrix operator/(const Matrix &x, const Matrix &y);	//linear system
	friend const double determinants(const Matrix &x);
	friend const Matrix inverse(const Matrix &x);
	friend const Matrix Adj(const Matrix &x);
	friend const Matrix pm(const Matrix &x);



};

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�s�x�}
	


	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};
