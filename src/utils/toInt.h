#ifndef TOINT_H
#define TOINT_H

template<typename T>
constexpr int toInt(const T cast)
{
    return static_cast<int>(cast);
}

#endif // TOINT_H
