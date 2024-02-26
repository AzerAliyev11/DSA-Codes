#include<iostream>
using namespace std;

void print_elements(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int len)
{
    for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void insertion_sort(int* arr, int len)
{
    for(int i = 1; i < len; i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && key < arr[j])
        {
            swap(&arr[j], &arr[j+1]);
            j--;
        }
    }
}

void selection_sort(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        int min = i;

        for(int j = i+1; j < len; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(&arr[i], &arr[min]);
    }
}

//quick sort functions
int partition(int* arr, int left, int right)
{
    int pivot = arr[left];
    int pivotPosition = left;

    for(int i = left+1; i <= right; i++)
    {
        if(arr[i] < pivot)
        {
            pivotPosition++;
            swap(&arr[i], &arr[pivotPosition]);
        }
    }

    swap(&arr[left], &arr[pivotPosition]);

    return pivotPosition;
}

void quick_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int pivotPosition = partition(arr, left, right);
        quick_sort(arr, left, pivotPosition-1);
        quick_sort(arr, pivotPosition+1, right); 
    }
}

//merge sort functions
void merge(int* arr, int left, int middle, int right)
{
    int nLeft = middle-left+1;
    int nRight = right-middle;

    int* leftArray = new int[nLeft];
    int* rightArray = new int[nRight];

    for(int i = 0; i < nLeft; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for(int i = 0; i < nRight; i++)
    {
        rightArray[i] = arr[middle + 1 + i];
    }

    int leftIndex = 0, rightIndex = 0, mergedIndex = left;

    while(leftIndex < nLeft && rightIndex < nRight)
    {
        if(leftArray[leftIndex] < rightArray[rightIndex])
        {
            arr[mergedIndex++] = leftArray[leftIndex++];
        }
        else
        {
            arr[mergedIndex++] = rightArray[rightIndex++];
        }
    }

    while(leftIndex < nLeft)
    {
        arr[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while(rightIndex < nRight)
    {
        arr[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}

void merge_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right-left)/2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    int arr[5] = {4, 3, 2, 6, 1};
    //uncomment the necessary sort function to use

    //bubble_sort(arr, 5);
    insertion_sort(arr, 5);
    //selection_sort(arr, 5);
    //quick_sort(arr, 0, 4);
    //merge_sort(arr, 0, 4);

    print_elements(arr, 5);
}