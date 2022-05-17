#include <iostream>

template<typename T>
T add(T x, T y)
{
    return x + y;
}


int main()
{
    int x1 = 3, y1 = 5;
    auto result1 = add(x1, y1);
    std::cout << result1 << std::endl;
    float x2 = 0.0f, y2 = 1.0f;
    auto result2 = add(x2, y2);
    std::cout << result2 << std::endl;
    return 0;
}
