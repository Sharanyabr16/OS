#include <stdio.h>
#include <stdlib.h>

void SCAN(int disk[], int n, int head, int direction) {
    int left = 0, right = 0;
    int seek_count = 0;

    // Find the left and right side requests
    int left_array[n], right_array[n];
    int left_index = 0, right_index = 0;

    for (int i = 0; i < n; i++) {
        if (disk[i] < head) {
            left_array[left_index++] = disk[i];
        } else {
            right_array[right_index++] = disk[i];
        }
    }

    // Sort the left and right requests
    for (int i = 0; i < left_index - 1; i++) {
        for (int j = i + 1; j < left_index; j++) {
            if (left_array[i] < left_array[j]) {
                int temp = left_array[i];
                left_array[i] = left_array[j];
                left_array[j] = temp;
            }
        }
    }
    for (int i = 0; i < right_index - 1; i++) {
        for (int j = i + 1; j < right_index; j++) {
            if (right_array[i] > right_array[j]) {
                int temp = right_array[i];
                right_array[i] = right_array[j];
                right_array[j] = temp;
            }
        }
    }

    // Service the requests in the direction of the head
    // Moving towards the left
    if (direction == 0) {
        for (int i = left_index - 1; i >= 0; i--) {
            int diff = abs(head - left_array[i]);
            seek_count += diff;
            head = left_array[i];
        }

        // Move to the end of the disk (0)
        seek_count += head;
        head = 0;

        // Moving towards the right
        for (int i = 0; i < right_index; i++) {
            int diff = abs(head - right_array[i]);
            seek_count += diff;
            head = right_array[i];
        }
    }
    // Moving towards the right
    else {
        for (int i = 0; i < right_index; i++) {
            int diff = abs(head - right_array[i]);
            seek_count += diff;
            head = right_array[i];
        }

        // Move to the end of the disk (maximum value)
        seek_count += (100 - head);
        head = 100;

        // Moving towards the left
        for (int i = left_index - 1; i >= 0; i--) {
            int diff = abs(head - left_array[i]);
            seek_count += diff;
            head = left_array[i];
        }
    }

    printf("Total seek count is %d\n", seek_count);
}

int main() {
    int n, head, direction;

    // Input number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int disk[n];

    // Input the disk requests
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &disk[i]);
    }

    // Input the initial head position
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Input the direction (0 for left, 1 for right)
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Call SCAN algorithm
    SCAN(disk, n, head, direction);

    return 0;
}
