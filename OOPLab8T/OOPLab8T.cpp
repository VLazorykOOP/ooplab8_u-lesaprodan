
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

#include <iostream>
#include <unordered_set>
#include <vector>

template <typename T>
std::vector<T> mergeArrays(const std::vector<T>& array1, const std::vector<T>& array2) {
    std::unordered_set<T> uniqueElements;
    std::vector<T> mergedArray;

    // Додаємо елементи першого масиву
    for (const T& element : array1) {
        if (uniqueElements.count(element) == 0) {
            uniqueElements.insert(element);
            mergedArray.push_back(element);
        }
    }

    // Додаємо елементи другого масиву
    for (const T& element : array2) {
        if (uniqueElements.count(element) == 0) {
            uniqueElements.insert(element);
            mergedArray.push_back(element);
        }
    }

    return mergedArray;
}

// Специфікація функції-шаблону для типу char*
template <>
std::vector<const char*> mergeArrays(const std::vector<const char*>& array1, const std::vector<const char*>& array2) {
    std::unordered_set<std::string> uniqueElements;
    std::vector<const char*> mergedArray;

    // Додаємо елементи першого масиву
    for (const char* element : array1) {
        if (uniqueElements.count(element) == 0) {
            uniqueElements.insert(element);
            mergedArray.push_back(element);
        }
    }

    // Додаємо елементи другого масиву
    for (const char* element : array2) {
        if (uniqueElements.count(element) == 0) {
            uniqueElements.insert(element);
            mergedArray.push_back(element);
        }
    }

    return mergedArray;
}

int main() {
    std::vector<int> intArray1, intArray2;
    int n;

    std::cout << "Enter the size of the first integer array: ";
    std::cin >> n;
    std::cout << "Enter " << n << " elements for the first integer array: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        intArray1.push_back(element);
    }

    std::cout << "Enter the size of the second integer array: ";
    std::cin >> n;
    std::cout << "Enter " << n << " elements for the second integer array: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        intArray2.push_back(element);
    }

    std::vector<int> mergedIntArray = mergeArrays(intArray1, intArray2);

    std::cout << "Merged integer array without duplicates: ";
    for (const int& element : mergedIntArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<const char*> charArray1, charArray2;
    std::string input;

    std::cout << "Enter the size of the first string array: ";
    std::cin >> n;
    std::cout << "Enter " << n << " elements for the first string array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        charArray1.push_back(input.c_str());
    }

    std::cout << "Enter the size of the second string array: ";
    std::cin >> n;
    std::cout << "Enter " << n << " elements for the second string array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        charArray2.push_back(input.c_str());
    }

    std::vector<const char*> mergedCharArray = mergeArrays(charArray1, charArray2);

    std::cout << "Merged string array without duplicates: ";
    for (const char* element : mergedCharArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
