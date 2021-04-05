#include <iostream>
#include <memory>
#include <chrono>
#include "TreeSet.h"

using namespace std;
using namespace chrono;

int main()
{
    for (int i = 0;i<10;i++)
    {
        unique_ptr<BST<int>> tree = make_unique<Tree<int>>();
        auto start = high_resolution_clock::now();
        for (int i = 0; i < 1e6; i++)
            tree->insert(rand() % 1'000'000);
        auto end = high_resolution_clock::now();
        cout << "Insertion 1m elements " << duration_cast<microseconds>(end - start).count() / 1e3 << "ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < 1e6; i++)
            tree->contains(1'000'000 + 1);
        end = high_resolution_clock::now();
        cout << "Search of 1m non-existing elements " << duration_cast<microseconds>(end - start).count() / 1e3 << "ms\n";

        start = high_resolution_clock::now();
        tree->sum();
        end = high_resolution_clock::now();
        cout << "Sum of 1m elements " << duration_cast<microseconds>(end - start).count() / 1e3 << "ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < 1e6; i++)
            tree->erase(rand() % 1'000'000);
        end = high_resolution_clock::now();
        cout << "Erase 1m elements " << duration_cast<microseconds>(end - start).count() / 1e3 << "ms\n\n";
    }


    return 0;
}