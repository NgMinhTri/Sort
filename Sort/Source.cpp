#include"Header.h"
void swap(int &p, int &q)
{
	int temp = p;
	p = q;
	q = temp;
}
//random
void GenerateRandomData(int *&a, int &n)
{
	srand(time(NULL));
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (1000000 + 1);
		//cout << a[i];
	}
}
//tăng dần
void GenerateSortedData(int *&a, int &n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		//cout << a[i];
	}
}
//thứ tự ngược
void GenerateReverseData(int *&a, int &n)
{
	a = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = i;
		//cout << a[i];
	}
}
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int *&a, int &n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}
void copymang(int *a, int *&b, int &n)
{
	b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}
void xuat(int *&a, int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
}

void Bubblesort(int *a, int &n)
{
	long double Gan = 0, SS = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				Gan = Gan + 3;
			}
		}
	}
}
void SelectionSort(int *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[iMin] > a[j])
				iMin = j;
		}
		if (i != iMin)
			swap(a[i], a[iMin]);
	}
}
void Insertionsort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void Heapify(int *a, int vt, int heapsize)
{
	int left, right, largest;
	left = 2 * vt;
	right = 2 * vt + 1;
	if (left <= heapsize && a[left] > a[vt])
	{
		largest = left;
	}
	else
	{
		largest = vt;
	}
	if (right <= heapsize && a[right] > a[largest])
	{
		largest = right;
	}
	if (largest != vt)
	{
		swap(a[vt], a[largest]);
		Heapify(a, largest, heapsize);
	}
}
void CreatHeap(int *a, int length)
{
	int  heapsize;
	heapsize = length - 1;
	for (int vt = (length / 2); vt >= 0; vt--)
	{
		Heapify(a, vt, heapsize);
	}
}
void HeapSort(int *a, int length)
{
	CreatHeap(a, length);
	int heapsize, vt;
	heapsize = length - 1;
	for (vt = heapsize; vt >= 0; vt--)
	{
		swap(a[0], a[heapsize]);
		heapsize--;
		Heapify(a, 0, heapsize);
	}
}
void Quicksort(int *a, int  l, int r)
{
	if (l <= r)
	{
		int key = a[(l + r) / 2];
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (a[i] < key)
			{
				i++;
			}
			while (a[j] > key)
			{
				j--;
			}

			if (i <= j)
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		if (l < j)
		{
			Quicksort(a, l, j);
		}
		if (r > i)
		{
			Quicksort(a, i, r);
		}
	}
}
void Merge(int *a, int left, int mid, int right)
{
	int *temp; // Khoi tao mang tam de sap xep
	int i = left;
	int j = mid + 1;
	temp = new int[right - left + 1];

	for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}
		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
	{
		a[left + k] = temp[k];
	}
	delete temp;
}
void MergeSort(int *a, int left, int right)
{
	if (right > left)
	{
		int mid;
		mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

int binarySearch(int arr[], int item, int low, int high)
{
	if (high <= low)
		return (item > arr[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == arr[mid])
		return mid + 1;
	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);
	return binarySearch(arr, item, low, mid - 1);
}
void BinaryInsertionSort(int arr[], int n)
{
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = arr[i];
		loc = binarySearch(arr, selected, 0, j);
		while (j >= loc) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}
void Random()
{
	int n[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "Waiting....\n";
	for (int i = 0; i < 5; i++)
	{
		int *a, *b, *c, *d, *e, *f, *g;
		GenerateRandomData(a, n[i]);
		copymang(a, b, n[i]);
		copymang(a, c, n[i]);
		copymang(a, d, n[i]);
		copymang(a, e, n[i]);
		copymang(a, f, n[i]);
		copymang(a, g, n[i]);

		clock_t begin1 = clock();
		Bubblesort(a, n[i]);
		clock_t finish1 = clock();
		double tg1 = ((double)(finish1 - begin1)) / CLOCKS_PER_SEC;

		clock_t begin2 = clock();
		SelectionSort(b, n[i]);
		clock_t finish2 = clock();
		double tg2 = ((double)(finish2 - begin2)) / CLOCKS_PER_SEC;

		clock_t begin3 = clock();
		Insertionsort(c, n[i]);
		clock_t finish3 = clock();
		double tg3 = ((double)(finish3 - begin3)) / CLOCKS_PER_SEC;

		clock_t begin4 = clock();
		HeapSort(d, n[i]);
		clock_t finish4 = clock();
		double tg4 = ((double)(finish4 - begin4)) / CLOCKS_PER_SEC;

		clock_t begin5 = clock();
		Quicksort(e, 0, n[i] - 1);
		clock_t finish5 = clock();
		double tg5 = ((double)(finish5 - begin5)) / CLOCKS_PER_SEC;

		clock_t begin6 = clock();
		MergeSort(f, 0, n[i] - 1);
		clock_t finish6 = clock();
		double tg6 = ((double)(finish6 - begin6)) / CLOCKS_PER_SEC;

		clock_t begin7 = clock();
		BinaryInsertionSort(g, n[i]);
		clock_t finish7 = clock();
		double tg7 = ((double)(finish7 - begin7)) / CLOCKS_PER_SEC;

		ofstream F;
		F.open("Results.csv", ios::app);
		if (F)
		{
			F.seekp(SEEK_END);
			F << "random" << "," << n[i] << "," << tg1 << "," << tg2 << "," << tg3 << "," << tg4 << "," << tg5 << "," << tg6 << "," << tg7 << "\n";
			F.close();
		}
		else
		{
			cout << "mo file khong thanh cong\n";
		}
		delete[]a;
		delete[]b;
		delete[]c;
		delete[]d;
		delete[]e;
		delete[]f;
		delete[]g;
	}
}
void Sorted()
{
	int n[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "Waiting....\n";
	for (int i = 0; i < 5; i++)
	{
		int *a, *b, *c, *d, *e, *f, *g;
		GenerateSortedData(a, n[i]);
		copymang(a, b, n[i]);
		copymang(a, c, n[i]);
		copymang(a, d, n[i]);
		copymang(a, e, n[i]);
		copymang(a, f, n[i]);
		copymang(a, g, n[i]);

		clock_t begin1 = clock();
		Bubblesort(a, n[i]);
		clock_t finish1 = clock();
		double tg1 = ((double)(finish1 - begin1)) / CLOCKS_PER_SEC;

		clock_t begin2 = clock();
		SelectionSort(b, n[i]);
		clock_t finish2 = clock();
		double tg2 = ((double)(finish2 - begin2)) / CLOCKS_PER_SEC;

		clock_t begin3 = clock();
		Insertionsort(c, n[i]);
		clock_t finish3 = clock();
		double tg3 = ((double)(finish3 - begin3)) / CLOCKS_PER_SEC;

		clock_t begin4 = clock();
		HeapSort(d, n[i]);
		clock_t finish4 = clock();
		double tg4 = ((double)(finish4 - begin4))/ CLOCKS_PER_SEC;

		clock_t begin5 = clock();
		Quicksort(e, 0, n[i] - 1);
		clock_t finish5 = clock();
		double tg5 = ((double)(finish5 - begin5)) / CLOCKS_PER_SEC;

		clock_t begin6 = clock();
		MergeSort(f, 0, n[i] - 1);
		clock_t finish6 = clock();
		double tg6 = ((double)(finish6 - begin6))/ CLOCKS_PER_SEC;

		clock_t begin7 = clock();
		BinaryInsertionSort(g, n[i]);
		clock_t finish7 = clock();
		double tg7 = ((double)(finish7 - begin7)) / CLOCKS_PER_SEC;

		ofstream F;
		F.open("Results.csv", ios::app);
		if (F)
		{
			F.seekp(SEEK_END);
			F << "sorted" << "," << n[i] << "," << tg1 << "," << tg2 << "," << tg3 << "," << tg4 << "," << tg5 << "," << tg6 << "," << tg7 << "\n";
			F.close();
		}
		else
		{
			cout << "mo file khong thanh cong\n";
		}
		delete[]a;
		delete[]b;
		delete[]c;
		delete[]d;
		delete[]e;
		delete[]f;
		delete[]g;
	}
}
void Reverse()
{
	int n[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "Waiting....\n";
	for (int i = 0; i < 5; i++)
	{
		int *a, *b, *c, *d, *e, *f, *g;
		GenerateReverseData(a, n[i]);
		copymang(a, b, n[i]);
		copymang(a, c, n[i]);
		copymang(a, d, n[i]);
		copymang(a, e, n[i]);
		copymang(a, f, n[i]);
		copymang(a, g, n[i]);
		clock_t begin1 = clock();
		Bubblesort(a, n[i]);
		clock_t finish1 = clock();
		double tg1 = ((double)(finish1 - begin1)) / CLOCKS_PER_SEC;

		clock_t begin2 = clock();
		SelectionSort(b, n[i]);
		clock_t finish2 = clock();
		double tg2 = ((double)(finish2 - begin2)) / CLOCKS_PER_SEC;

		clock_t begin3 = clock();
		Insertionsort(c, n[i]);
		clock_t finish3 = clock();
		double tg3 = ((double)(finish3 - begin3)) / CLOCKS_PER_SEC;

		clock_t begin4 = clock();
		HeapSort(d, n[i]);
		clock_t finish4 = clock();
		double tg4 = ((double)(finish4 - begin4)) / CLOCKS_PER_SEC;

		clock_t begin5 = clock();
		Quicksort(e, 0, n[i] - 1);
		clock_t finish5 = clock();
		double tg5 = ((double)(finish5 - begin5)) / CLOCKS_PER_SEC;

		clock_t begin6 = clock();
		MergeSort(f, 0, n[i] - 1);
		clock_t finish6 = clock();
		double tg6 = ((double)(finish6 - begin6)) / CLOCKS_PER_SEC;

		clock_t begin7 = clock();
		BinaryInsertionSort(g, n[i]);
		clock_t finish7 = clock();
		double tg7 = ((double)(finish7 - begin7)) / CLOCKS_PER_SEC;

		ofstream F;
		F.open("Results.csv", ios::app);
		if (F)
		{
			F.seekp(SEEK_END);
			F << "reversed" << "," << n[i] << "," << tg1 << "," << tg2 << "," << tg3 << "," << tg4 << "," << tg5 << "," << tg6 << "," << tg7 << "\n";
			F.close();
		}
		else
		{
			cout << "mo file khong thanh cong\n";
		}
		delete[]a;
		delete[]b;
		delete[]c;
		delete[]d;
		delete[]e;
		delete[]f;
		delete[]g;
	}


}
void NearlySorted()
{
	int n[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "Waiting....\n";
	for (int i = 0; i < 5; i++)
	{
		int *a, *b, *c, *d, *e, *f, *g;
		GenerateNearlySortedData(a, n[i]);
		copymang(a, b, n[i]);
		copymang(a, c, n[i]);
		copymang(a, d, n[i]);
		copymang(a, e, n[i]);
		copymang(a, f, n[i]);
		copymang(a, g, n[i]);
		clock_t begin1 = clock();
		Bubblesort(a, n[i]);
		clock_t finish1 = clock();
		double tg1 = ((double)(finish1 - begin1)) / CLOCKS_PER_SEC;

		clock_t begin2 = clock();
		SelectionSort(b, n[i]);
		clock_t finish2 = clock();
		double tg2 = ((double)(finish2 - begin2)) / CLOCKS_PER_SEC;

		clock_t begin3 = clock();
		Insertionsort(c, n[i]);
		clock_t finish3 = clock();
		double tg3 = ((double)(finish3 - begin3)) / CLOCKS_PER_SEC;

		clock_t begin4 = clock();
		HeapSort(d, n[i]);
		clock_t finish4 = clock();
		double tg4 = ((double)(finish4 - begin4)) / CLOCKS_PER_SEC;

		clock_t begin5 = clock();
		Quicksort(e, 0, n[i] - 1);
		clock_t finish5 = clock();
		double tg5 = ((double)(finish5 - begin5)) / CLOCKS_PER_SEC;

		clock_t begin6 = clock();
		MergeSort(f, 0, n[i] - 1);
		clock_t finish6 = clock();
		double tg6 = ((double)(finish6 - begin6)) / CLOCKS_PER_SEC;

		clock_t begin7 = clock();
		BinaryInsertionSort(g, n[i]);
		clock_t finish7 = clock();
		double tg7 = ((double)(finish7 - begin7)) / CLOCKS_PER_SEC;

		ofstream F;
		F.open("Results.csv", ios::app);
		if (F)
		{
			F.seekp(SEEK_END);
			F << "NearlySorted" << "," << n[i] << "," << tg1 << "," << tg2 << "," << tg3 << "," << tg4 << "," << tg5 << "," << tg6 << "," << tg7 << "\n";
			F.close();
		}
		else
		{
			cout << "mo file khong thanh cong\n";
		}
		delete[]a;
		delete[]b;
		delete[]c;
		delete[]d;
		delete[]e;
		delete[]f;
		delete[]g;
	}


}