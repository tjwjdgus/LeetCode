int Partition(int* a, int start, int end) {
	int j = start, i;
	int pivot = a[end];

	for (i = start; i < end; i++) {
		if (a[i] < pivot) {
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			j++;
		}
	}

	int tmp = a[j];
	a[j] = a[end];
	a[end] = tmp;

	return j;
}

void QuickSort(int* a, int start, int end) {
	if (start < end) {
		int pivot = Partition(a, start, end);
		QuickSort(a, start, pivot - 1);
		QuickSort(a, pivot + 1, end);
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;

	QuickSort(nums, 0, numsSize - 1);

	return nums;
}