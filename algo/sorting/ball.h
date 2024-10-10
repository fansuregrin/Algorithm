#ifndef ALGO_BALL_H
#define ALGO_BALL_H
#include <iostream>
#include <utility>

namespace algo {

enum Color {RED, BLUE, GREEN };

class Ball {
public:
    friend std::ostream &operator<<(std::ostream &os, const Ball &ball);
    friend void swap(Ball &x, Ball &y);

    Ball() = default;

    Ball(int id, Color color) : m_id(id), m_color(color) {}

    bool operator<(const Ball &rhs) {
        return m_id < rhs.m_id;
    }

    bool operator==(const Ball &rhs) {
        return m_id == rhs.m_id;
    }

    bool operator<=(const Ball &rhs) {
        return *this < rhs || *this == rhs;
    }

    bool operator>(const Ball &rhs) {
        return !(*this <= rhs);
    }
private:
    int m_id;
    Color m_color;
};

std::ostream &operator<<(std::ostream &os, const Color &color) {
    switch (color) {
        case Color::RED: os << "RED"; break;
        case Color::BLUE: os << "BLUE"; break;
        case Color::GREEN: os << "GREEN"; break;
        default: break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Ball &ball) {
    return os << "(" << ball.m_id << "," << ball.m_color << ")";
}

void swap(Ball &x, Ball &y) {
    std::swap(x.m_id, y.m_id);
    std::swap(x.m_color, y.m_color);
}

}

#endif