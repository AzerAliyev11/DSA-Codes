#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


//bubble sort
void BubbleSort(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//selection sort
void SelectionSort(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        int minIndex = i;

        for(int j = i; j < len; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(&arr[minIndex], &arr[i]);
    }
}

//insertion sort
void InsertionSort(int* arr, int len)
{
    for(int i = 1; i < len; i++)
    {
        int insertValue = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > arr[j+1])
                arr[j+1] = arr[j];
            else
                break;
        }

        arr[j+1] = insertValue;
    }
}

#pragma region MergeSort
void merge(int* arr, int left, int middle, int right)
{
    int nLeft = middle - left + 1;
    int nRight = right - middle;

    int* leftArray = new int[nLeft];
    int* rightArray = new int[nRight];

    for(int i = 0; i < nLeft; i++)
    {
        leftArray[i]=arr[left+i];
    }

    for(int i = 0; i < nRight; i++)
    {
        rightArray[i] = arr[middle + 1 + i];
    }

    int mergedIndex = left, leftIndex = 0, rightIndex = 0;
    while(leftIndex < nLeft && rightIndex < nRight)
    {
        if(leftArray[leftIndex] < rightArray[rightIndex])
            arr[mergedIndex++] = leftArray[leftIndex++];
        else
            arr[mergedIndex++] = rightArray[rightIndex++];
    }

    while(leftIndex < nLeft)
    {
        arr[mergedIndex++] = leftArray[leftIndex++];
    }

    while(rightIndex < nRight)
    {
        arr[mergedIndex++] = rightArray[rightIndex++];
    }
}

void mergeSort(int* arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

#pragma endregion

#pragma region QuickSort
int partition(int* arr, int low, int high)
{
    int pivotValue = arr[low];
    int pivotIndex = low;

    for(int i = low + 1; i <= high; i++)
    {
        if(arr[i] < pivotValue)
        {
            pivotIndex++;
            swap(&arr[i], &arr[pivotIndex]);
        }
    }

    swap(&arr[low], &arr[pivotIndex]);
    return pivotIndex;
}

void quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

#pragma endregion

void PrintElements(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    int arr[5] = {1,13,6,8,6};
    mergeSort(arr, 0, 4);
    PrintElements(arr, 5);
}