//
// Created by ZaberKo on 2019-02-03.
//

#ifndef DATASTRUCTURE_TEST_H
#define DATASTRUCTURE_TEST_H

#include <iostream>

using namespace std;

class Test {


public :
    double hehe = 12;

    void print() {
        cout << "Hi:" << hehe << endl;
    }

    void lambda() {
        auto fun = [this]() mutable {
            cout << "lambda:" << this->hehe << endl;

        };
        fun();
    }
};


#endif //DATASTRUCTURE_TEST_H
