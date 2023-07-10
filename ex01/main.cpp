#include "iter.hpp"

int main(void)
{
    int i[5] = { 1, 2, 3, 4, 5 };

    // iter<int>(i, sizeof(i) / sizeof (*i), print<int>);
    // iter(i, sizeof(i) / sizeof(*i), print<int>);
    iter(i, sizeof(i) / sizeof(*i), print);

    return (0);
}