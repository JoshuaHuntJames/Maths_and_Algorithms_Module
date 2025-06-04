#pragma once

#include "../MATHS AND ALGORITHMS/Vector.h"
#include <iostream>
#include <iomanip>
#include <numbers>

using namespace std;

class Matrix
{
public:
    // this is a 3 x 3
#define M_PI 3.14159265358979323846
    float Data[3][3];

    // constructor to zero-initialise the data
    Matrix() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                Data[i][j] = 0.0f;
    }

    void SetIdentity() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                Data[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    Matrix operator*(const Matrix& RHS) const
    {
        Matrix result;
        Matrix LHS = *this; // Make a safe copy of the left-hand side

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                for (int k = 0; k < 3; ++k) {
                    result.Data[row][col] += LHS.Data[row][k] * RHS.Data[k][col];
                }
            }
        }
        return result;
    }

    void SetMatrix(const float input[3][3]) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                Data[i][j] = input[i][j];
    }

    float Determinate() {
        float a = Data[0][0], b = Data[0][1], c = Data[0][2];
        float d = Data[1][0], e = Data[1][1], f = Data[1][2];
        float g = Data[2][0], h = Data[2][1], i = Data[2][2];

        return a * (e * i - f * h)
            - b * (d * i - f * g)
            + c * (d * h - e * g);
    }

    void Print() const {
        std::cout << "Matrix contents:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << std::setw(8) << std::fixed << std::setprecision(4) << Data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void SetRotateAroundX(float Angle) {
        std::cout << "SetRotateAroundX " << Angle;
        float rad = Angle * M_PI / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);

        std::cout << "1,1 " << cosA << std::endl;
        std::cout << "1,2 " << -sinA << std::endl;
        std::cout << "2,1 " << sinA << std::endl;
        std::cout << "2,2 " << cosA << std::endl;

        Data[0][0] = 1; Data[0][1] = 0; Data[0][2] = 0;
        Data[1][0] = 0; Data[1][1] = cosA; Data[1][2] = -sinA;
        Data[2][0] = 0; Data[2][1] = sinA; Data[2][2] = cosA;
    }

    void SetRotateAroundY(float Angle) {
        std::cout << "SetRotateAroundY " << Angle;
        float rad = Angle * M_PI / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);

        Data[0][0] = cosA; Data[0][1] = 0; Data[0][2] = sinA;
        Data[1][0] = 0; Data[1][1] = 1; Data[1][2] = 0;
        Data[2][0] = -sinA; Data[2][1] = 0; Data[2][2] = cosA;
    }

    void SetRotateAroundZ(float Angle) {
        std::cout << "SetRotateAroundZ " << Angle;
        float rad = Angle * M_PI / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);

        Data[0][0] = cosA; Data[0][1] = -sinA; Data[0][2] = 0;
        Data[1][0] = sinA; Data[1][1] = cosA; Data[1][2] = 0;
        Data[2][0] = 0; Data[2][1] = 0; Data[2][2] = 1;
    }

    void Translate(const Vector& delta) {
        Matrix transformation;
        transformation.Data[0][0] = 1.0f; transformation.Data[0][1] = 0.0f; transformation.Data[0][2] = delta.x;
        transformation.Data[1][0] = 0.0f; transformation.Data[1][1] = 1.0f; transformation.Data[1][2] = delta.y;
        transformation.Data[2][0] = 0.0f; transformation.Data[2][1] = 0.0f; transformation.Data[2][2] = 1.0f;

        transformation.Print();
        Print();
        *this = (*this) * transformation;
    }
};