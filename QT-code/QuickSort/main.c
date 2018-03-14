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
         *�õݹ�ķ�ʽ�ٶ���ߵ����������
         *����֮��
         * ���õݹ�ķ�ʽ���ұߵ����������
         * ע��ݹ����ֹ����:
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
