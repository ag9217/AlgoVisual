//function prototypes
void swap(int &a, int &b);
void BubbleSort(std::vector<int>& array);
void SelectionSort(std::vector<int>& array);

//-------------ALGORITHMS-----------------
//Bubble Sort
void BubbleSort(std::vector<int>& array) {
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.size() - j; ++i) {
      if (array[i] > array[i + 1]) {
        swap(array[i+1], array[i]);
        swapped = true;
      }
    }
  }
}

//Selection Sort
void SelectionSort(std::vector<int>& array) {
   int imin;

   for(int i = 0; i<array.size()-1; i++) {

      imin = i;   //find index of smallest value in vector

      for(int j = i+1; j<array.size(); j++)

         if(array[j] < array[imin])

            imin = j;

         //placing in correct position by swapping
         swap(array[i], array[imin]);
   }
}

void swap(int &a, int &b) //used to swap two values in a vector/array
{
   int temp = a;
   a = b;
   b = temp;
}