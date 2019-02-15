//
// Created by User on 15.02.2019.
//
#include "Vector3.h"

#include <cmath>
#include <iostream>

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

Vector3::Vector3(float x1, float y1, float z1) {
    x = x1;
    y = y1;
    z = z1;
}

Vector3::Vector3(const Vector3& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

float Vector3::Length() const {
    return (sqrt(x*x + y*y + z*z));
}

float Vector3::operator *(const Vector3& other) const {   //скалярное
    return (x*other.x + y*other.y + z*other.z);
}

Vector3 Vector3::operator *(const float& num) {     //вектор * число
    Vector3 res(num*x, num*y, num*z);
    return res;
}

Vector3 Vector3::operator ^(const Vector3& vect) {
    Vector3 res;
    res.x = (y * vect.z) - (z * vect.y);
    res.y = - (x * vect.z) + (z * vect.x);
    res.z = (x * vect.y) - (y * vect.x);
    return res;
}

bool Vector3::LinearRelation(const Vector3& other) const {
    float rel = x/other.x;
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