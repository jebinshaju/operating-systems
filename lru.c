#include <stdio.h>

int main()
{
        int numFrames, numPages, frameArray[50], pageArray[50], referenceCount[50], position, hitFlag, missFlag, pageFaults = 0, i, j, k;

        // Input: Number of frames and pages
        printf("Enter the number of frames: ");
        scanf("%d", &numFrames);
        printf("Enter the number of pages: ");
        scanf("%d", &numPages);

        // Input: Page references
        printf("Enter the page references: ");
        for (i = 0; i < numPages; i++)
        {
                scanf("%d", &pageArray[i]);
        }

        // Initialize frameArray and referenceCount arrays
        for (j = 0; j < numFrames; j++)
        {
                frameArray[j] = -1;    // Initialize frames to -1 (empty)
                referenceCount[j] = 0; // Initialize reference counts to 0
        }

        printf("\nPage Reference \tFrames\n");
        for (i = 0; i < numPages; i++)
        {
                hitFlag = missFlag = 0;

                // Check if the page is already in the frames
                for (j = 0; j < numFrames; j++)
                {
                        if (pageArray[i] == frameArray[j])
                        {
                                printf("hit-\t");
                                referenceCount[j] = i + 1; // Update the reference counter
                                hitFlag = missFlag = 1;    // Set hit and miss flags
                                break;
                        }
                }

                // If not found in frames and empty slot available, insert
                if (hitFlag == 0)
                {
                        for (j = 0; j < numFrames; j++)
                        {
                                if (frameArray[j] == -1)
                                {
                                        printf("miss-\t");
                                        frameArray[j] = pageArray[i];
                                        referenceCount[j] = i + 1; // Update the reference counter
                                        pageFaults++;
                                        missFlag = 1;
                                        break;
                                }
                        }
                }

                // If not found and no empty slot, perform LRU replacement
                if (missFlag == 0)
                { 
                        printf("miss-\t");
                        position = 0;
                        for (j = 1; j < numFrames; j++)
                        {
                                if (referenceCount[j] < referenceCount[position])
                                {
                                        position = j; // Find the least recently used frame
                                }
                        }
                        frameArray[position] = pageArray[i];
                        referenceCount[position] = i + 1; // Update the reference counter
                        pageFaults++;
                }

                // Display the frame status after each page reference
                for (j = 0; j < numFrames; j++)
                {
                        if (frameArray[j] == -1)
                        {
                                printf("-\t"); // Display empty frame
                        }
                        else
                        {
                                printf("%d\t", frameArray[j]); // Display page in the frame
                        }
                }
                printf("\n");
        }

        // Display total page faults
        printf("Total Page Faults: %d\n", pageFaults);

        return 0;
}
