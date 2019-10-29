#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }

    int find(int p) {
        while (p != _id[p]) {
            _id[p] = _id[_id[p]];  // 将p的父节点_id[p] 更新为 _id[p] 的父节点 _d[_id[p]], 实现路径压缩
            p = _id[p];
        }
        return p;
    }

    void union_(int p, int q) {
        int i = find(p);  // 查找p所在集合的根节点
        int j = find(q);  // 查找q所在集合的根节点
        if (i == j) {
            return;
        }
        if (_size[i] < _size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }

    void print_set() {
        printf("元素：");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d ", i);
        }
        printf("\n");
        printf("集合：");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d ", _id[i]);
        }
        printf("\n");
    }
private:
    std::vector<int> _id;
    std::vector<int> _size;
    int _count;
};

int main()
{
    DisjointSet disjoint_set(8);
    disjoint_set.print_set();
    printf("Union(0, 5)\n");
    disjoint_set.union_(0, 5);
    disjoint_set.print_set();
    printf("Find(0) = %d, Find(5) = %d\n", disjoint_set.find(0), disjoint_set.find(5));
    printf("Find(2) = %d, Find(5) = %d\n", disjoint_set.find(2), disjoint_set.find(5));
    disjoint_set.union_(2, 4);
    disjoint_set.print_set();
    disjoint_set.union_(0, 4);
    disjoint_set.print_set();
    printf("Find(2) = %d, Find(5) = %d\n", disjoint_set.find(2), disjoint_set.find(5));

    return 0;
}
