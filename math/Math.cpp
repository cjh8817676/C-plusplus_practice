#include <iostream>
#include <math.h>
#include <stdlib.h>


void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
float partition (float arr[], int low, int high)
{
    float pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(float *arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(float arr[], int size = 100)
{
    int i;
    for (i=0; i < size; i++)
        std::cout <<  arr[i] << " ";
    std::cout << std::endl;
}
 
float find_median(float list[],int size = 100)
{
    quickSort(list,0,size-1);
    if (size % 2 != 0)
        return (double)list[size / 2];
 
    return (double)(list[(size - 1) / 2] + list[size / 2]) / 2.0;
}

int median_index(float* list, int l, int r)
{
    int n = r - l + 1;
    n = (n + 1) / 2 - 1;
    return n + l;
}

float Percentile(float sequence[] , float excelPercentile,int size)
{
    quickSort(sequence,0,size-1);
    int N = size;
    double n = (N - 1) * excelPercentile + 1;
    // Another method: double n = (N + 1) * excelPercentile;
    if (n == 1) return sequence[0];
    else if (n == N) return sequence[N - 1];
    else
    {
         int k = (int)n;
         double d = n - k;
         return sequence[k - 1] + d * (sequence[k] - sequence[k - 1]);
    }
}


/////////////////////特徵值/////////////

float find_std(float list[], int size = 100) //'x_std' 'y_std' 'z_std'
{
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < size; ++i) {
        sum += list[i];
    }
    mean = sum / size;
   
    for (i = 0; i < size; ++i) {
        SD += pow(list[i] - mean, 2);
    }
    return sqrt(double(SD / size));
}

float find_min(float list[], int size = 100) //'x_min' 'y_min' 'z_min'
{
    float min;
    min = list[0];
    for (int i = 0;i<size;i++)
    {
        if (list[i] < min)
            min = list[i];
    }
    return min;
}

float find_max(float list[],int size = 100) //'x_max' 'y_max' 'z_max'
{
    float max;
    max = list[0];
    for (int i = 0;i<size;i++)
    {
        if (list[i] > max)
            max = list[i];
    }
    return max;
}

float find_aad(float list[], int size = 100) //avg absolute diff
{
    float mean,sum;
    float aad;
    for (int i = 0; i < size; ++i) {
        sum += list[i];
    }
    mean = sum / size;
    sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += abs(list[i] - mean);
    }

    aad = sum / size;

    return aad;
}

float find_maxmin_diff(float list[], int size = 100)
{
    float max,min;
    max = find_max(list);
    min = find_min(list);

    return max - min;
}

float find_mad(float list[],int size = 100) // median abs dev
{
    float sum = 0,median;
    float temp[100];
    median = find_median(list,100);

    sum = 0;
    for (int i = 0; i < size; i++)
      temp[i] = abs(list[i] - median);

   return find_median(temp,100);
}

float find_IQR(float list[],int size = 100) //interquartile range // 百分等級!!!
{
    float Q1 = Percentile(list,0.25,size);
    float Q3 = Percentile(list,0.75,size);

    //std::cout << Q1 << " " << Q3 << std::endl;

    return (Q3 - Q1);
}

float find_neg_count(float list[],int size = 100)
{
    float neg_count;

    for (int i = 0 ; i < size ; i++)
    {
        if (list[i] < 0)
            neg_count++;
    }
    return  neg_count;
}

float find_pos_count(float list[],int size = 100)
{
    float pos_count;

    for (int i = 0 ; i < size ; i++)
    {
        if (list[i] > 0)
            pos_count++;
    }
    return  pos_count;
}

float find_energy(float list[],int size = 100)
{
    float energy;

    for (int i=0; i < size; i++)
    {
        energy += list[i] * list[i];
    }
    return energy / size;
}

float find_avg_result_accl(float **list,int size = 100)
{
    float avg_result_accl;
    for (int i = 0 ; i < size; i++)
    {
        avg_result_accl += pow( (pow(list[0][i],2) + pow(list[1][i],2) + pow(list[2][i],2)) , 0.5);
    }
    return avg_result_accl / size;
}

float find_sma(float **list, int size = 100) //signal magnitude area
{
    float sma;
    float sma_x,sma_y,sma_z;
    for (int i = 0 ; i < size; i++)
    {
        sma_x += abs(list[0][i])/100 ;
        sma_y += abs(list[1][i])/100 ;
        sma_z += abs(list[2][i])/100 ;
    }
    return sma_x + sma_y + sma_z;
}

float find_argmax(float list[], int size = 100)
{
    float index;
    float max = find_max(list);
    for (int i = 0 ;i < size ; i++)
    {
        if(list[i] == max)
        {
            index =  i;
            break;
        }
    }
    return index;
}


struct scaled{
    float max_value = 1;
    float min_value = 0;
}rescale;
int main()
{
    using namespace std;
    float x_list[100] = { 0.069,  0.685,  0.093, -0.211, -0.459,  1.241,  1.727,  0.142,
       -0.268, -0.138,  0.157,  0.402,  0.494,  0.475,  0.334,  0.26 ,
        0.731,  0.843,  1.053,  0.666,  0.249, -0.112,  0.   ,  0.716,
       -0.08 , -0.513, -0.317,  1.957,  0.708,  0.015, -0.199,  0.065,
        0.349,  0.418,  0.298,  0.207,  0.429,  0.674,  1.092,  0.951,
        0.452,  0.291,  0.249,  0.234,  0.099, -0.218, -0.666,  1.061,
        1.743,  0.108, -0.317, -0.203,  0.264,  0.56 ,  0.725,  0.444,
        0.315,  0.283,  0.598,  1.16 ,  1.207,  0.579,  0.195, -0.112,
        0.395,  0.215, -0.222, -0.735,  1.291,  1.575, -0.211, -0.334,
       -0.188,  0.338,  0.602,  0.479,  0.245,  0.114,  0.541,  0.789,
        1.211,  1.08 ,  0.402,  0.118,  0.   ,  0.154, -0.019, -0.463,
       -0.475,  1.957,  0.706, -0.072, -0.268,  0.093,  0.391,  0.505,
        0.548,  0.353,  0.353,  0.816};
    float y_list[100] = { 1.08 , 0.744, 0.563, 0.501, 0.429, 1.118, 1.16 , 0.843, 1.589,
        0.992, 1.046, 0.981, 0.759, 0.721, 0.731, 0.919, 1.207, 1.076,
        1.203, 1.192, 1.786, 1.64 , 0.82 , 0.357, 0.429, 0.414, 0.774,
        1.644, 0.509, 1.613, 0.889, 1.18 , 1.057, 0.805, 0.59 , 0.812,
        1.004, 1.088, 1.111, 1.222, 1.425, 1.564, 1.509, 0.869, 0.395,
        0.249, 0.452, 1.057, 1.456, 1.241, 1.114, 1.135, 1.057, 0.908,
        0.59 , 0.64 , 0.816, 0.889, 1.141, 1.26 , 1.135, 1.498, 1.923,
        1.321, 0.456, 0.306, 0.296, 0.524, 1.399, 1.061, 1.241, 1.272,
        1.019, 1.18 , 0.774, 0.644, 0.708, 0.911, 1.053, 1.188, 1.073,
        1.118, 1.651, 1.862, 1.069, 0.659, 0.237, 0.317, 0.682, 1.705,
        0.563, 1.666, 0.943, 1.218, 0.953, 0.706, 0.621, 0.651, 0.873,
        1.26 };

    float z_list[100] = { -0.203, -0.05 , -0.05 , -0.069, -0.195,  0.782,  0.594, -0.528,
        -0.038, -0.199, -0.091, -0.161, -0.165, -0.118, -0.042, -0.108,
         0.123,  0.114,  0.368,  0.114, -0.283, -0.56 , -0.076, -0.072,
        -0.127, -0.195,  0.471,  0.421, -0.076, -0.283, -0.398, -0.112,
        -0.133, -0.133, -0.222, -0.23 ,  0.306, -0.057,  0.291,  0.276,
        -0.15 , -0.421, -0.533,  0.027, -0.15 , -0.133, -0.326,  1.088,
         0.651, -0.326, -0.379, -0.268, -0.15 , -0.184, -0.038,  0.138,
        -0.072, -0.123, -0.084,  0.666,  0.341, -0.065, -0.501, -0.682,
         0.241, -0.099, -0.192, -0.296,  0.977,  0.624, -0.245, -0.704,
        -0.114, -0.279, -0.046, -0.03 , -0.253, -0.18 ,  0.249,  0.011,
         0.203,  0.218, -0.253, -0.571, -0.138, -0.153, -0.176, -0.157,
         0.326,  0.133, -0.053, -0.142, -0.444, -0.153, -0.214, -0.046,
         0.008, -0.095, -0.118,  0.161};
    float all_acc[3][100];
    float * ptr[3];
    for (int i = 0 ; i < 100 ;i++)
    {
        all_acc[0][i] = x_list[i];
        all_acc[1][i] = y_list[i];
        all_acc[2][i] = z_list[i];
    }
    ptr[0] = all_acc[0];
    ptr[1] = all_acc[1];
    ptr[2] = all_acc[2];

        
    //'x_std', 'y_std', 'z_std', 'x_aad', 'y_aad', 'z_aad', 'x_min',
    //    'y_min', 'z_min', 'x_max', 'y_max', 'x_maxmin_diff',
    //    'y_maxmin_diff', 'z_maxmin_diff', 'x_mad', 'y_mad', 'z_mad',
    //    'x_IQR', 'y_IQR', 'z_IQR', 'y_neg_count', 'z_neg_count',
    //    'y_pos_count', 'z_pos_count', 'x_energy', 'y_energy', 'z_energy',
    //    'avg_result_accl', 'sma', 'y_argmax'       按照順序
    float x_std,y_std,z_std;
    float x_aad,y_aad,z_aad;
    float x_min,y_min,z_min;
    float x_max,y_max;
    float x_maxmin_diff,y_maxmin_diff,z_maxmin_diff;
    float x_mad,y_mad,z_mad;
    float x_IQR,y_IQR,z_IQR;
    float y_neg_count,z_neg_count;
    float y_pos_count,z_pos_count;
    float x_energy,y_energy,z_energy;
    float avg_result_accl;
    float sma;
    float y_argmax;
    float feature[15];

    for (int i = 0 ; i< 15 ; i++){
        feature[i] = 0;
    }

    cout << find_argmax(y_list) << endl;

    return 0;
}
