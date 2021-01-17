#ifndef _SORT_H
#define _SORT_
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int *&a, int &n);
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int *&a, int &n);
// Hàm phát sinh mảng dữ liệu có thứ tự ngược
void GenerateReverseData(int *&a, int &n);
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int *&a, int &n);
void copymang(int *a, int *&b, int &n);
void xuat(int *&a, int &n);
void Bubblesort(int *a, int &n);
void SelectionSort(int *&a, int n);
void Insertionsort(int *a, int n);
void Heapify(int *a, int vt, int heapsize);
void CreatHeap(int *a, int length);
void HeapSort(int *a, int length);
void Quicksort(int *a, int  l, int r);
void Merge(int *a, int left, int mid, int right);
void MergeSort(int *a, int left, int right);
int binarySearch(int arr[], int item, int low, int high);
void BinaryInsertionSort(int arr[], int n);
void Random();
void Sorted();
void Reverse();
void NearlySorted();
#endif

