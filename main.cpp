//Charlie Castle
//Sorting project that shows times and counts of each sorting algorithm
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int arr100[100];
int arr1000[1000];
int arr5000[5000];
int arr10000[10000];
int size100 = sizeof(arr100) / sizeof(arr100[0]);
int size1000 = sizeof(arr1000) / sizeof(arr1000[0]);
int size5000 = sizeof(arr5000) / sizeof(arr5000[0]);
int size10000 = sizeof(arr10000) / sizeof(arr10000[0]);
int counter;
//Instertion Sort function
void insertionSortRand(int arr[], int n)
{

    int j;
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {

            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        //end while loop
        arr[j + 1] = key;

    }
    //end for loop

}
//end insertionSortRand

//Merge Sort function
void merge(int arr[], int l, int m, int r)
{

   int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    //end for
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
    }
    //end for

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            counter++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            counter++;
            arr[k] = R[j];
            j++;
        }
        //end if else
        k++;
        
    }
    //end while

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // end while


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    // end while

}
//end merge

// swap function
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//end swap

// partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            counter++;
        }
    }
    // end for
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}
//end partition
// quick sort function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    //end if
}
// end quickSort
//merge sort funciton
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
       merge(arr, l, m, r);

    }
    //end if
}
// end mergeSort



// Print an array function
void printArrays(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    // end for
    cout << endl;
}
//end printArrays

//fills array with random int
void arrayFillRand(int arr[], int size)
{
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    //end for
}
// end arrayFillRand

// fills array with random int given seed
void arrayFillSeed(int arr[], int size, int seed)
{
    
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%seed;
    }
    //end for
}
// end arrayFillSeed
// main function
int main()
{
    clock_t start, end;
    double time_taken;
    bool keepGoing = true;
    while(keepGoing == true)
    {
        cout << " Which type of Sorting algorithm do you want to look at?  (1) insertion sort (2) merge sort (3) quicksort (0) to quit program" << endl;
        int answer1;
        cin >> answer1;
        switch(answer1)
        {
            case 1:
                cout << " Do you want it completely random or enter the seed (1) enter seed (2) random seed " << endl;
                int answer2;
                cin >> answer2;
                switch(answer2)
                {
                    case 1:
                        cout << " What is the seed you want to enter? " << endl;
                        int seed;
                        cin >> seed;
                        arrayFillSeed(arr100, size100, seed);
                        arrayFillSeed(arr1000, size1000, seed);
                        arrayFillSeed(arr5000, size5000, seed);
                        arrayFillSeed(arr10000, size10000, seed);

                        cout << " Printing 100 int array " << endl;
                        start = clock();
                        insertionSortRand(arr100, size100);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);


                        cout << " Printing 1000 int array " << endl;
                        start = clock();
                        insertionSortRand(arr1000, size1000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        insertionSortRand(arr5000, size5000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        start = clock();
                        insertionSortRand(arr10000, size10000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        break;
                    case 2:
                        arrayFillRand(arr100, size100);
                        arrayFillRand(arr1000, size1000);
                        arrayFillRand(arr5000, size5000);
                        arrayFillRand(arr10000, size10000);
                        cout << " Printing 100 int array " << endl;


                        start = clock();
                        insertionSortRand(arr100, size100);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);

                        
                        cout << " Printing 1000 int array " << endl;
                        start = clock();
                        insertionSortRand(arr1000, size1000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        insertionSortRand(arr5000, size5000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        start = clock();
                        insertionSortRand(arr10000, size10000);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        break;  
                    default:
                        cout << " enter 1 or 2" << endl;
                        break;
                }
                break;
                //end switch 1
            case 2:
                cout << " Do you want it completely random or enter the seed (1) enter seed (2) random seed " << endl;
                cin >> answer2;
                switch(answer2)
                {
                    case 1:
                        cout << " What is the seed you want to enter" << endl;
                        int seed;
                        cin >> seed;
                        arrayFillSeed(arr100, size100, seed);
                        arrayFillSeed(arr1000, size1000, seed);
                        arrayFillSeed(arr5000, size5000, seed);
                        arrayFillSeed(arr10000, size10000, seed);


                        cout << " Printing 100 int array" << endl;
                        start = clock();
                        mergeSort(arr100, 0, size100 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);


                        cout << " Printing 1000 int array" << endl;
                        start = clock();
                        mergeSort(arr1000, 0, size1000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        mergeSort(arr5000, 0, size5000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        start = clock();
                        mergeSort(arr10000, 0, size10000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        break;
                    case 2:
                        arrayFillRand(arr100, size100);
                        arrayFillRand(arr1000, size1000);
                        arrayFillRand(arr5000, size5000);
                        arrayFillRand(arr10000, size10000);


                        cout << " Printing 100 int array " << endl;
                        start = clock();
                        mergeSort(arr100, 0, size100 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);


                        cout << " Printing 1000 int array " << endl;
                        start = clock();
                        mergeSort(arr1000, 0, size1000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        mergeSort(arr5000, 0, size5000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;

                        
                        start = clock();
                        mergeSort(arr10000, 0, size10000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        break;
                    default:
                        cout << " enter 1 or 2" << endl;
                        break;
                }
                // end switch 2
                break;
            case 3:
                cout << " Do you want it completely random or enter the seed (1) enter seed (2) random seed " << endl;
                cin >> answer2;
                switch(answer2)
                {
                    case 1:
                        cout << " What is the seed you want to enter" << endl;
                        int seed;
                        cin >> seed;
                        arrayFillSeed(arr100, size100, seed);
                        arrayFillSeed(arr1000, size1000, seed);
                        arrayFillSeed(arr5000, size5000, seed);
                        arrayFillSeed(arr10000, size10000, seed);


                        cout << " Printing 100 int array" << endl;
                        start = clock();
                        quickSort(arr100, 0, size100 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);


                        cout << " Printing 1000 int array" << endl;
                        start = clock();
                        quickSort(arr1000, 0, size1000 -1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        quickSort(arr5000, 0, size5000 -1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        start = clock();
                        quickSort(arr10000, 0, size10000 -1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        break;
                    case 2:
                        arrayFillRand(arr100, size100);
                        arrayFillRand(arr1000, size1000);
                        arrayFillRand(arr5000, size5000);
                        arrayFillRand(arr10000, size10000);


                        cout << " Printing 100 int array: " << endl;
                        start = clock();
                        quickSort(arr100, 0, size100 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter for 100 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr100, size100);


                        cout << " Printing 1000 int array " << endl;
                        start = clock();
                        quickSort(arr1000, 0, size1000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter 1000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;
                        printArrays(arr1000, size1000);


                        start = clock();
                        quickSort(arr5000, 0, size5000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter 5000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        start = clock();
                        quickSort(arr10000, 0, size10000 - 1);
                        end = clock();
                        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
                        cout << "Total Counter 10000 array: " << counter << endl;
                        cout << "Time taken by program is : " << fixed << time_taken << " seconds " << endl;
                        counter = 0;


                        break;
                    default:
                        cout << " enter 1 or 2" << endl;
                        break;
                }
                break;
            case 0:
                keepGoing = false;
            default:
                break;
        }
        //end switch
    }   
    //end while
return 0;
}
//end main


