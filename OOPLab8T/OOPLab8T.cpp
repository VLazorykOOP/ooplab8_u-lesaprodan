
#include <iostream>

template <typename T>
T calculateAverage(T* array, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* intArray = new int[size];
    std::cout << "Enter " << size << " integer values:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> intArray[i];
    }

    double* doubleArray = new double[size];
    std::cout << "Enter " << size << " double values:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> doubleArray[i];
    }

    int intAverage = calculateAverage(intArray, size);
    double doubleAverage = calculateAverage(doubleArray, size);

    std::cout << "Average of intArray: " << intAverage << std::endl;
    std::cout << "Average of doubleArray: " << doubleAverage << std::endl;

    delete[] intArray;
    delete[] doubleArray;

    return 0;
}
