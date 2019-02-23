//
// Created by User on 15.02.2019.
//
#include "Vector3.h"

using namespace std;

Vector3 operator + (const Vector3& one, const Vector3& two) {
    Vector3 res(one.x + two.x, one.y + two.y, one.z + two.z);
    return res;
}

Vector3 operator - (const Vector3& one, const Vector3& two) {
    Vector3 res(one.x - two.x, one.y - two.y, one.z - two.z);
    return res;
}

Vector3 operator * (const float& num, const Vector3& vect) {    //число * вектор
    Vector3 res(num * vect.x, num * vect.y, num * vect.z);
    return res;
}

//Vector3 operators

Vector3::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(double x1, double y1, double z1) {
    x = x1;
    y = y1;
    z = z1;
}

Vector3::Vector3(const Vector3& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

//Длина вектора

double Vector3::Length() const {
    return (sqrt(x*x + y*y + z*z));
}

double Vector3::SquareLength() const {
    return (x*x + y*y + z*z);
}

//Сложение

Vector3 Vector3::operator + (const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3& Vector3::operator + (const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
}

//Вычитание

Vector3 Vector3::operator - (const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3& Vector3::operator - (const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

//Деление

Vector3 Vector3::operator / (const float& num) const {
    return Vector3(x/num, y/num, z / num);
}

Vector3& Vector3::operator / (const float& num) {
    x = x/num;
    y = y/num;
    z = z/num;
}

// ++ and --

Vector3& Vector3::operator --() {
    x --;
    y --;
    z --;
}

Vector3& Vector3::operator ++() {
    x ++;
    y ++;
    z ++;
}

//Вращение

Vector3& Vector3::Rotate(const char& ort, double deg) {
    deg = deg * M_PI/180.0;
    if (ort == 'x') {
        //cout << "around x" << endl;
        double new_y = y * cos(deg) - z * sin(deg);
        double new_z = y * sin(deg) + z * cos(deg);
        y = new_y;
        z = new_z;
    } else if (ort == 'y') {
        double new_x = x * cos(deg) + z * sin(deg);
        double new_z = - x * sin(deg) + z * cos(deg);
        x = new_x;
        z = new_z;
    } else if (ort == 'z') {
        double new_x = x * cos(deg) - y * sin(deg);
        double new_y = x * sin(deg) + y * cos(deg);
        x = new_x;
        y = new_y;
    } else {
        cout << "Rotataing around unknown ort " << ort << endl;
    }
}

Vector3 Vector3::GetRotated(const char& ort, double deg) {
    Vector3 res(x, y, z);
    res.Rotate(ort, deg);
    return res;
}

double Vector3::operator *(const Vector3& other) const {   //скалярное
    return (x*other.x + y*other.y + z*other.z);
}

Vector3 Vector3::operator *(const float& num) {     //вектор * число
    Vector3 res(num*x, num*y, num*z);
    return res;
}

Vector3 Vector3::operator ^(const Vector3& vect) {      //векторное произведение
    Vector3 res;
    res.x = (y * vect.z) - (z * vect.y);
    res.y = - (x * vect.z) + (z * vect.x);
    res.z = (x * vect.y) - (y * vect.x);
    return res;
}

bool Vector3::LinearRelation(const Vector3& other) const {
    double rel = x/other.x;
    if (y/other.y == rel && z/other.z == rel) {
        return true;
    }
    return false;
}

Vector3::~Vector3() {    //деструктор
    //1. ничего не принимает
    //2. ничего не возвращает
    //3. может быть только один, в отличие от конструктора
    cout << "Deleted {" << x << ", " << y << ", " << z << "}" << endl;
}

istream& operator >> (istream& is, Vector3& v) {
    cin >> v.x >> v.y >> v.z;
    return is;
}

ostream& operator << (ostream& os, const Vector3& v) {
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
