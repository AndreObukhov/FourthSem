//
// Created by User on 15.02.2019.
//

#ifndef VECTOR3R_VECTOR3_H
#define VECTOR3R_VECTOR3_H

#pragma once

struct Vector3 {
    Vector3();                                //конструктор по умолчанию (нулями)
    Vector3(float x1, float y1, float z1);    //конструктор "тремя числами"
    Vector3(const Vector3& other);            //конструктор через другой вектор
    float Length() const;                     //длина вектора
    float operator * (const Vector3& other) const;    //скалярное произведение векторов
    Vector3 operator *(const float&);                 //умножение вектора на число (справа)
    Vector3 operator ^(const Vector3& vect);          //векторное произведение векторов
    bool LinearRelation(const Vector3& other) const;  //проверка на линейную зависимость
    ~Vector3();                               //деструктор (печатает удаляемый вектор)

    float x, y, z;
};

Vector3 operator +(const Vector3& one, const Vector3& two);     //сложение
Vector3 operator -(const Vector3& one, const Vector3& two);     //вычитание
Vector3 operator *(const float& num, const Vector3& vect);      //умножение вектора на число (слева)

#endif //VECTOR3R_VECTOR3_H
