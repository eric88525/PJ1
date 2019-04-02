#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);



	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int currentLoadVectorID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		std::vector<double> tempVectorData;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempSring;
		
		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (fin >> tempSring)
		{
			//�q�ɮ�Ū���r��
			
			//�ѪR��V�q�аO"V"
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//�w�q�Ȧs�V�q��Ƶ��c
					Vector tempVector;
					//�s�J�V�q���
					tempVector.Data = tempVectorData;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.Name = vectorVariableTemp;
					//�s�J�V�q
					Vectors.push_back(tempVector);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					VectorVariableIndex++;
					//�M���V�q��ƼȦs
					tempVectorData.clear();
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadVectorID++;
				
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempSring;
			}
			else
			{
				//Ū���V�q��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//�N�V�q��Ʀs�J�Ȧs
				tempVectorData.push_back(value);
			}
			
		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//Ū�����\�^��false
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}
void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}
//----------------------------------------------------------------------vector

Vector::Vector(std::vector<double> data)
{
	this->Data = data;
}

Vector::Vector(std::string name,std::vector<double> data) {
	this->Name = name;
	this->Data = data;
}


const Vector operator+(const Vector &x, const Vector &y) {
	int rankdiff;
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] + y.Data[i]);
		}
	}
	return Vector(data);
}

const Vector operator-(const Vector &x, const Vector &y) {
	int rankdiff;	
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}
	else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] - y.Data[i]);
		}
	}
	return Vector(data);
}


const Vector operator*(const Vector &x, const Vector &y) {
	
	int rankdiff;
	std::vector<double> data;
	if (x.Data.size()==1) {
		for (int i = 0; i < y.Data.size(); i++) {
			data.push_back(y.Data[i]*x.Data[0]);
		}
	}else if (y.Data.size()==1){
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] * y.Data[0]);
		}
	}else if (x.Data.size() != y.Data.size()) {
		throw rankdiff;
	}else {
		double sum=0;
		for (int i = 0; i < x.Data.size(); i++) {
			sum+=y.Data[i] * x.Data[i];
		}
		data.push_back(sum);
	}
	return Vector(data);
}

const double norm(const Vector &x) {
	double sum = 0.0;
	std::vector<double> data;
	for (int i = 0; i < x.Data.size(); i++) {
		sum += std::abs(pow(x.Data[i], 2));
	}
	return sqrt(sum);
}
const Vector normalization(const Vector &x) {
	double sum = 0;
	std::vector<double>data;
	for (auto i: x.Data) {
		sum += i * i;
	}
	sum = sqrt(sum);
	data =x.Data;
	for (auto &i: data) {
		i /= sum;
	}
	return Vector(data);
}


const Vector crossProduct(const Vector & x, const Vector & y)
{
	double i = x.Data[1] * y.Data[2] - y.Data[1] * x.Data[2],
		j = x.Data[0] * y.Data[2] - y.Data[0] * x.Data[2],
		k = x.Data[0] * y.Data[1] - y.Data[0] * x.Data[1];
	std::vector<double>data = {i,j,k};
	return Vector(data);
}

const Vector component(  const Vector & x, const Vector & y)
{
	Vector vec;
	vec = x * y;
	double n;
	n = norm(y);
	vec.Data[0] /= n;
	return  Vector(vec.Data);
}

const Vector projection(const Vector & x, const  Vector & y)
{
	Vector vec;
	vec = component(x, y);
	vec = vec * normalization(y);
	return Vector(vec.Data);
}

const double area(const Vector & x, const Vector & y)
{

	double c = norm(x);
	double a = component(x,y).Data[0];
	double b = sqrt(c*c - a * a);
	double area = norm(y)*b / 2;
	return area;
	
}



const Vector pN(const Vector & x, const Vector & y)
{
	return Vector();
}


const bool isParallel(const Vector & x, const Vector & y)
{
	if (x.Data.size() != y.Data.size())return false;
	double rate=-999;
	for (int i = 0; i < x.Data.size(); i++) {
		if (!(x.Data[i]==0 || y.Data[i]==0)) {
			if (rate==-999) {
				rate = y.Data[i] / x.Data[i];
			}else if(x.Data[i]*rate!=y.Data[i]){
				return false;
			}
		}
	}
	if(rate!=-999)return true;
	else return false;
}

const bool isOrthogonal(const Vector & x, const Vector & y)
{
	double sum;
	for (int i = 0; i < x.Data.size();i++) {
		sum += x.Data[i] * y.Data[i];
	}
	if (!sum)return true;
	return false;
}

const double angle(const Vector & x, const Vector & y)
{
	Vector vec;
	double result;
	vec = x * y;
	for (auto &i:vec.Data) {
		i = i / (norm(x)*norm(y));
	}
	result = acos(vec.Data[0]) * 180.0 / PI;
	return result;
}

const bool isLI(const Vector & x, const Vector & y)
{
	if (!isParallel(x,y)) {
		return true;
	}
	return false;
}

//----------------------------------------------------------------------matrix


Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<std::vector<double>> data):Data(data)
{
	Name = "";
}

const Matrix operator+(const Matrix & x, const Matrix & y)
{
	std::vector<std::vector<double>>;
	for (auto row:x.Data) {
		
	}


	return Matrix();
}
