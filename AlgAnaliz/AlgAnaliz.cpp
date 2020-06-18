// AlgAnaliz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<time.h>

using namespace std;

clock_t time1, time2;
double difference;

double startTime()
{
	time1 = clock();
	return (double)time1;
};

double endTime()
{
	time2 = clock();
	return (double)time2;
};

double timePassed()
{
	difference = time2 - time1;
	return difference;
};
void combSort(int array[], int length);
int shellSort(int arr[], int n);
void insertionSort(int arr[], int n);
void CocktailSort(int a[], int n);
void bubbleSort(int arr[], int n);

int main()
{
	int array[500];
	for (int i = 0; i < 500; i++)
	{
		array[i] = rand() % 500;
	}

	cout << "Masiv predi sortirane:" << endl;
	for (int i = 0; i < 500; i++)
	{
		cout << array[i] << ", ";
	}

	startTime();//Начало на измерването
	combSort(array, 500);
	endTime();//Край на измерването

	cout << endl;
	cout << "Masiva sled sortirane: " << ", ";
	for (int i = 0; i < 500; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
	cout << "Vremetraene na sortiraneto: " << timePassed() / 1000 << endl;
	cout << endl;

	system("pause");
	return 0;

}