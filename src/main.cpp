#include <iostream>
#include "../include/data_structures/doubly_linked_list.hpp"
#include "../include/data_structures/queue_list.hpp"
#include "../include/data_structures/queue_tab.hpp"
#include "../include/data_structures/stack_tab.hpp"
#include "../include/data_structures/stack_list.hpp"
#include <stdio.h>
#include <time.h>
#include <bits/stdc++.h>
//123
using namespace std;

int main(int argc, char *argv[]) {

    int tab[5]={10,100,1000,10000,100000};

StackList<int> stackList;
StackTab<int> stackTab;

QueueList<int> queueList;
QueueTab<int> queueTab;
    double elapsed;
    clock_t start;
    clock_t stop;
    for(const auto& item : tab)
    {
        start=clock();
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < item; j++)
                queueList.enqueue(j);
        }
            stop = clock();
            elapsed = (double)(stop - start) / (double)CLOCKS_PER_SEC / item;
            std::cout << "List implementation, N = " << item << ". average push time: " << fixed << elapsed
                      << setprecision(12) << endl;

        start = ::clock();
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < item; j++)
            {
                queueList.dequeue();
            }
        }
            stop = clock();
            elapsed = (double)(stop - start) / (double)CLOCKS_PER_SEC / item;
            std::cout << "List implementation, N = " << item << ". average pop time: " << fixed << elapsed
                      << setprecision(12) << endl;

    }
    for(const auto& item : tab)
    {
        start=clock();
        for(int i = 0; i < 100; i++)
            {
                for(int j = 0; j < item; j++)
                queueTab.enqueue(j);
            }
            stop = clock();
            elapsed = (double)(stop - start) / (double)CLOCKS_PER_SEC / item;
            std::cout << "Tab implementation, N = " << item << ". average push time: " << fixed << elapsed
                      << setprecision(12) << endl;

        start = ::clock();
        for(int i = 0; i < 100; i++)
            {
            for(int j = 0; j < item; j++)
            {
                queueTab.dequeue();
            }
            }
            stop = clock();
            elapsed = (double)(stop - start) / (double)CLOCKS_PER_SEC / item;
            std::cout << "Tab implementation, N = " << item << ". average pop time: " << fixed << elapsed
                      << setprecision(12) << endl;

    }

}