#include "Sort.h"
Sort::Sort(int size_in, int min, int max)
{
	size = size_in;
	v = new int[size];
	for (int i = 0; i < size; i++)
	{
		int c = rand() % (max - min) + min;
		v[i] = c;
	}
}


/*
==============TE PUP LEON IUBIREA MEA UNICA SI ADEVARATA==========
               =                    =
              = =                  = =
             =   =                =   =
			=     =              =     = 
		   =       =            =       =
		  =         =          =         =
		 =           =       =            =
		=             =     =              =
	   =               =====                =
	   =                ===                 =
 	   =                                    =
	    =                                  =
		 =                                =
		  =                              =
		   =                            =
		    =                          =
			 =                        =
			  =                      =
			   =                    =
			    =                  =
				 =                =
				  =              =
				   =            =
				    =          =   
					 =        =
					  =      =
					   ======
						 ==
*/
/*Sort::Sort(int* v_in, int size_in)
{
	size = size_in;
	v = v_in;
}*/
Sort::Sort(int count, ...)
{
	size = count;
	v = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		v[i] = va_arg(args, int);
	}
	va_end(args);
}
void Sort::Print()
{
	for (int i = 0; i < size; i++)
		printf("%d ", v[i]);
}
int  Sort::GetElementsCount()
{
	return size;
}
int Sort::GetElementFromIndex(int index)
{
	return v[index];
}
Sort::Sort(const char* s_in)
{
	int size_new = 1, i = 0;
	char curent = s_in[i];

	int nrx = 0;
	while (curent != ',' && curent != '\0')
	{
		nrx = nrx * 10 + curent - '0';
		curent = s_in[++i];
	}
	v = new int[1];
	v[0] = nrx;
	curent = s_in[++i];
	while (curent != '\0')
	{
		int nr = 0;
		while (curent != ',' && curent!='\0')
		{
			nr = nr * 10 + curent- '0';
			curent = s_in[++i];
		}
		size_new++;
		int* c = v;
		v = new int[size_new];
		for (int j = 0; j < size_new-1 ; j++)
			v[j] = c[j];
		v[size_new - 1] = nr;
		delete c;
		if(curent!='\0')
		curent = s_in[++i];
	}
	size = size_new;
}

void Sort::BubbleSort(bool ascendent)
{
	int i, ok = 0, t, x = 0;
	if (ascendent)
	{
		while (ok == 0)
		{
			ok = 1;
			for(i=0;i<size-1;i++)
				if (v[i] > v[i + 1])
				{
					t = v[i];
					v[i] = v[i + 1];
					v[i + 1] = t;
					ok = 0;
				}
		}
	}
	else
	{
		while (ok == 0)
		{
			ok = 1;
			for(i=0;i<size-1;i++)
				if (v[i] < v[i + 1])
				{
					t = v[i];
					v[i] = v[i + 1];
					v[i + 1] = t;
					ok = 0;
				}
		}
	}
}
void Sort::InsertSort(bool ascendent)
{
	int i, j, t;
	if (ascendent)
	{
		for(i=0;i<size-1;i++)
			for(j=i+1;j<size;j++)
				if(v[i]>v[j])
				{
					t = v[i];
					v[i] = v[j];
					v[j] = t;
				}
	}
	else
	{
		for (i = 0; i < size - 1; i++)
			for (j = i + 1; j < size; j++)
				if (v[i] < v[j])
				{
					t = v[i];
					v[i] = v[j];
					v[j] = t;
				}
	}

}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partitionA(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low; j < high; j++)
		if (array[j] <= pivot)
		{
			i++; swap(&array[i], &array[j]);
		}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSortA(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partitionA(array, low, high);
		quickSortA(array, low, pi - 1);
		quickSortA(array, pi+1, high);
	}
}
int partitionD(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low; j < high; j++)
		if (array[j] >= pivot)
		{
			i++; swap(&array[i], &array[j]);
		}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSortD(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partitionD(array, low, high);
		quickSortD(array, low, pi - 1);
		quickSortD(array, pi + 1, high);
	}
}
void Sort::QuickSort(bool ascendent)
{
	if (ascendent)
		quickSortA(v, 0, size - 1);
	else
		quickSortD(v, 0, size - 1);
}