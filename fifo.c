#include <stdio.h>

int main()
{
        int i, j, k, flag = 0;
        int frames[20], pages[20], numFrames, numPages, pageFaults = 0, currentIndex = 0;

        // Input number of frames and pages
        printf("Enter the number of frames: ");
        scanf("%d", &numFrames);

        printf("Enter the number of pages: ");
        scanf("%d", &numPages);

        // Input page references
        printf("Enter the page references: ");
        for (i = 0; i < numPages; i++)
        {
                scanf("%d", &pages[i]);
        }

        // Initialize frames with -1 (empty)
        for (i = 0; i < numFrames; i++)
        {
                frames[i] = -1;
        }

        // Process page references and handle page replacement
        for (i = 0; i < numPages; i++)
        {
                flag = 0;

                // Check if page is already in a frame
                for (k = 0; k < numFrames; k++)
                {
                        if (pages[i] == frames[k])
                        {
                                flag = 1; // Page found in frame
                                break;
                        }
                }

                if (flag == 0)
                {
                        frames[currentIndex] = pages[i];               // Replace frame content
                        currentIndex = (currentIndex + 1) % numFrames; // Move to the next frame
                        pageFaults++;                                  // Increase page fault count
                }

                // Print current page reference and frame contents
                printf("%d\t", pages[i]);
                for (j = 0; j < numFrames; j++)
                {
                        printf("%d", frames[j]);
                }

                // Print HIT or MISS based on page presence in frame
                if (pages[i] == frames[k])
                {
                        printf("\tHIT");
                }
                else
                {
                        printf("\tMISS");
                }
                printf("\n");
        }

        // Print total number of page faults
        printf("Page faults: %d\n", pageFaults);

        return 0;
}
