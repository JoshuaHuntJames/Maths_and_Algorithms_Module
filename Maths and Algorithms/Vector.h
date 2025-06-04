#pragma once

class Vector
{
public:
    float x, y, z;

    Vector(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    float Magnitude();
    void Normalise();
    void Scale(float Scaler);
    float Dot(Vector& B);
    Vector Cross(Vector& B);
};