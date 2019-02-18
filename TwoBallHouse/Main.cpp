#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
#include <iostream>


int find(int size, std::function<bool(int)> ballFall)
{
    int interval = sqrt(size);
    for (int i = interval, z = 0; i <= size; )
    {
        if (!ballFall(i + z))
        {
            std::cout << "ball crash: " << i + z << std::endl;
            while (z < interval)
            {
                int height = i - interval + z;
                if (!ballFall(height))
                {
                    std::cout << "ball crash and find: " << height << std::endl;
                    return height;
                }
                z++;
            }
        }

        i + interval > size ? i = size : i += interval;
    }

    return -1;
}

int main()
{

    auto res = find(100, [](int i) { return i < 45; });
    assert(res == 45);

    res = find(1000, [](int i) {return i < 999; });
    assert(res == 999);

    res = find(1000, [](int i) {return i < 500; });
    assert(res != 800);

    system("pause");

}