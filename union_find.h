//
// Created by ZaberKo on 2019-02-11.
//

#ifndef DATASTRUCTURE_UNION_FIND_H
#define DATASTRUCTURE_UNION_FIND_H
using namespace std;

#include <cassert>

namespace UF {
    class UnionFind {
    private:
        int *parent;
        int *height;
        int count;
    public:
        UnionFind(int count) : count(count) {
            parent = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                height[i] = 0;
            }
        }

        virtual ~UnionFind() {
            delete[] parent;
            delete[] height;

        }

        int find(int p) {
            assert(p >= 0 && p < count);


            //while (p!=parent[p])
            //    p=parent[p];

            // optimize: path-compression

//            while (p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;

            if(p!=parent[p])
                parent[p]=find(parent[p]);
            return p;
        }


        //non-recursion
        int find2(int p){
            int r,j,k;

            r=p;
            while (r!=parent[r])
                r=parent[r];

            k=p;
            while (k!=r)
            {
                j=parent[k];
                parent[k]=r;
                k=j;
            }

            return r;

        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;

            if (height[pRoot] < height[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (height[qRoot] < height[pRoot]) {
                parent[qRoot] = pRoot;
            } else {
                parent[pRoot] = qRoot;
                height[qRoot]++;
            }
        }
    };
}
#endif //DATASTRUCTURE_UNION_FIND_H
