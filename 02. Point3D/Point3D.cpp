#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

void maxHeapify(vector<Point>&, int, int);
void buildMaxHeap(vector<Point>&);
void heapSort(vector<Point>&);

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto& a : points)
        cin >> a.x >> a.y >> a.z;
    heapSort(points);
    for (const auto& a : points)
        cout << a.x << " " << a.y << " " << a.z << "\n";
    return 0;
}

void maxHeapify(vector<Point>& arr, int i, int heapSize)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && (arr[l].x > arr[largest].x || (arr[l].x == arr[largest].x && arr[l].y < arr[largest].y) || (arr[l].x == arr[largest].x && arr[l].y == arr[largest].y && arr[l].z > arr[largest].z)))
        largest = l;
    if (r < heapSize && (arr[r].x > arr[largest].x || (arr[r].x == arr[largest].x && arr[r].y < arr[largest].y) || (arr[r].x == arr[largest].x && arr[r].y == arr[largest].y && arr[r].z > arr[largest].z)))
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}
void buildMaxHeap(vector<Point>& arr)
{
    int heapSize = arr.size();
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        maxHeapify(arr, i, heapSize);
}

void heapSort(vector<Point>& arr)
{
    buildMaxHeap(arr);
    int heapSize = arr.size();
    for (int i = heapSize - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, 0, heapSize);
    }
}