# __0x1B. C - Sorting algorithms & Big O__

## __0-bubble_sort.c__

a function that sorts an array of integers in ascending order using the `Bubble sort` algorithm

- Prototype: `void bubble_sort(int *array, size_t size);`
- Prints the `array` after each time two elements are swapped.

## __1-insertion_sort_list.c__

a function that sorts a doubly linked list of integers in ascending order using the `Insertion sort` algorithm

- Prototype: `void insertion_sort_list(listint_t **list);`
- Does not modify the integer `n` of a node. Swaps the nodes themselves.
- Prints the `list` after each time two elements are swapped.

## __2-selection_sort.c__

a function that sorts an array of integers in ascending order using the `Selection sort` algorithm

- Prototype: `void selection_sort(int *array, size_t size);`
- Prints the `array` after each time two elements are swapped.

## __3-quick_sort.c__

a function that sorts an array of integers in ascending order using the `Quick sort` algorithm

- Prototype: `void quick_sort(int *array, size_t size);`
- Implements the Lomuto partition scheme.
- The pivot will always be the last element of the partition being sorted.
- Prints the `array` after each time two elements are swapped.

## __100-shell_sort.c__

a function that sorts an array of integers in ascending order using the `Shell sort` algorithm, using the `Knuth sequence`

- Prototype: `void shell_sort(int *array, size_t size);`
- Uses the following sequence of intervals (a.k.a the Knuth sequence):
  - `n+1 = n * 3 + 1`
  - `1, 4, 13, 40, 121, ...`
- Prints the array each time the interval is decreased.

## __101-cocktail_sort_list.c__

a function that sorts a doubly linked list of integers in ascending order using the `Cocktail shaker sort` algorithm

- Prototype: `void cocktail_sort_list(listint_t **list);`
- Does not modify the integer `n` of a node. Swaps the nodes themselves.
- Prints the `list` after each time two elements are swapped.

## __102-counting_sort.c__

a function that sorts an array of integers in ascending order using the `Counting sort` algorithm

- Prototype: `void counting_sort(int *array, size_t size);`
- Its assumed that the `array` will contain only numbers `>= 0`
- Uses `malloc` and `free`
- Prints the counting array once it is set up
  - This array is of size `k + 1` where `k` is the largest number in `array`

## __103-merge_sort.c__

a function that sorts an array of integers in ascending order using the `Merge sort` algorithm

- Prototype: `void merge_sort(int *array, size_t size);`
- Implements the `top-down` merge sort algorithm
  - When an array is divided into two sub-arrays, the size of the left array will always be `<=` the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
  - Sorts the left array before the right array
- Uses `printf`
- Uses `malloc` and `free` only once (only one call)

## __104-heap_sort.c__

a function that sorts an array of integers in ascending order using the `Heap sort` algorithm

- Prototype: `void heap_sort(int *array, size_t size);`
- Implements the `sift-down` heap sort algorithm
- Prints the `array` after each time two elements are swapped.

## __105-radix_sort.c__

a function that sorts an array of integers in ascending order using the `Radix sort` algorithm

- Prototype: `void radix_sort(int *array, size_t size);`
- Implements the `LSD` radix sort algorithm
- Its assumed that `array` will contain only numbers `>= 0`
- Uses `malloc` and `free`
- Prints the `array` each time the `significant digit` is increased.

## __106-bitonic_sort.c__

a function that sorts an array of integers in ascending order using the `Bitonic sort` algorithm

- Prototype: `void bitonic_sort(int *array, size_t size);`
- Its assumed that `size` will be equal to `2^k`, where `k >= 0` (when `array` is not `NULL` ...)
- Uses `printf`
- Prints the `array` after each time two elements are swapped.

## __107-quick_sort_hoare.c__

a function that sorts an array of integers in ascending order using the `Quick sort` algorithm

- Prototype: `void quick_sort_hoare(int *array, size_t size);`
- Implements the `Hoare` partition scheme.
- The pivot will always be the last element of the partition being sorted.
- Prints the `array` after each time two elements are swapped.

## __1000-sort_deck.c__

a function that sorts a deck of cards.

- Prototype: `void sort_deck(deck_node_t **deck);`
  - where `deck` is a pointer to a doubly linked list with cards as nodes
- Uses the `C` standard library function `qsort`.
- Each node of the doubly linked list contains a card that will not be modified. The nodes will be swapped.
- Its assumed that there is exactly `52` elements in the doubly linked list.
- The deck will be ordered:
  - From `Ace` to `King`
  - From `Spades` to `Diamonds`

## __Contributors__

- [__Toby Salau__](https://github.com/Toby2507)
- __Girma Eshete__
