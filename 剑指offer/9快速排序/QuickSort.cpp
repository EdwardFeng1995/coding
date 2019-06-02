#include <iostream>
#include <algorithm> 

using namespace std;

int RandomInRange(int start,int end)
{
    srand ( time(NULL) );
    return rand() % (end-start+1) + start;

}

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start <0 || end >= length)
        return -1;

    int index = RandomInRange(start, end);
    std::swap(data[index], data[end]);

    int small = start - 1;
    for(index = start; index < end; ++index) {
        if (data[index] < data[end]){
            small++;
            if(small != index)
                swap(data[small], data[index]);
        }
    }

    ++small;
    swap(data[small], data[end]);

    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return ;
    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index - 1);
    if(index < end)
        QuickSort(data, length, index + 1, end);
}

int main()
{
    int data[] = {7,8,2,4,6,9,1,3,5};
    QuickSort(data, 9, 0, 8);
    for (int i = 0; i <= 8; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}

