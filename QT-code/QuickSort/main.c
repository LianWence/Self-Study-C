#include <stdio.h>

void quickSort(int *p, int low, int high)
{
    if(low < high)
    {
        int indexLow = low;
        int indexHigh = high;
        int pivot = p[low];

        while(indexLow < indexHigh)
        {
            while(p[indexHigh] >= pivot && indexLow < indexHigh)
            {
                indexHigh--;
            }
            p[indexLow] = p[indexHigh];
//            indexLow++;

            while(p[indexLow] <= pivot && indexLow < indexHigh)
            {
                indexLow++;
            }
            p[indexHigh] = p[indexLow];
//            indexHigh--;
        }

        p[indexHigh] = pivot;
        /*
         *用递归的方式再对左边的组进行排序
         *完事之后
         * 再用递归的方式对右边的组进行排序
         * 注意递归的终止条件:
         *         indexLow < indexhigh
         */
        quickSort(p, low, indexLow - 1);
        quickSort(p, indexHigh + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};

    quickSort(arr, 0, 9);

    for(int i = 0; i < sizeof(arr)/ sizeof(*arr); i++)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}
