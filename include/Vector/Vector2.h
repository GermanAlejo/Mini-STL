//
// Created by german on 14/10/25.
//
#pragma once
#ifndef PLAYGROUND_VECTOR_H
#define PLAYGROUND_VECTOR_H

namespace mystl {
    class Vector2 {
    private:
        float x;
        float y;

    public:
        //Constructor
        Vector2(float x = 0.0f, float y = 0.0f);
        float getX();
        float getY();
        void setX(float x);
        void setY(float y);
        void PrintVector();
        Vector2 operator+(const Vector2& vector) const;
        Vector2 operator-(const Vector2& vector) const;

    };
}

#endif //PLAYGROUND_VECTOR_H