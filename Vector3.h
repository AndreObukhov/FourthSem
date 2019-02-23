//
// Created by User on 15.02.2019.
//

#ifndef VECTOR3R_VECTOR3_H
#define VECTOR3R_VECTOR3_H

#pragma once

#include <iostream>
#include <cmath>

using namespace std;

struct Vector3 {
    Vector3();                                //конструктор по умолчанию (нулями)
    Vector3(double x1, double y1, double z1);    //конструктор "тремя числами"
    Vector3(const Vector3& other);            //конструктор через другой вектор

    double Length() const;                     //длина вектора
    double SquareLength() const;               //квадрат длины

    Vector3 operator + (const Vector3& other) const;    //2 оператора сложения
    Vector3& operator + (const Vector3& other);

    Vector3 operator - (const Vector3& other) const;    //2 оператора вычитания
    Vector3& operator - (const Vector3& other);

    Vector3 operator / (const float& num) const;        //деление на скаляр (и запись в новый вектор
    Vector3& operator / (const float& num);             //деление на скаляр (того же вектора)

    Vector3& operator --();                             //уменьшаем (увеличиваем) все
    Vector3& operator ++();                             //координаты на 1

    Vector3& Rotate(const char& ort, double deg);        //поворот вокруг оси ort
    Vector3 GetRotated(const char& ort, double deg);     //на градус deg

    double operator * (const Vector3& other) const;    //скалярное произведение векторов
    Vector3 operator *(const float&);                 //умножение вектора на число (справа)
    Vector3 operator ^(const Vector3& vect);          //векторное произведение векторов
    bool LinearRelation(const Vector3& other) const;  //проверка на линейную зависимость
    ~Vector3();                               //деструктор (печатает удаляемый вектор)

    double x, y, z;
};

istream& operator >> (istream& is, Vector3& v);
ostream& operator << (ostream& os, const Vector3& v);

Vector3 operator +(const Vector3& one, const Vector3& two);     //сложение
Vector3 operator -(const Vector3& one, const Vector3& two);     //вычитание
Vector3 operator *(const float& num, const Vector3& vect);      //умножение вектора на число (слева)

#endif //VECTOR3R_VECTOR3_H
