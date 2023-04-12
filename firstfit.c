#include <stdio.h>
#include <stdlib.h>

struct block {
    int size;
    int allocated;
    struct block *next;
};

struct block *head = NULL;

void allocate_memory(int size) {
    struct block *new_block = (struct block *)malloc(sizeof(struct block));
    new_block->size = size;
    new_block->allocated = 0;
    new_block->next = NULL;

    if (head == NULL) {
        head = new_block;
        return;
    }

    struct block *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_block;
}

void *first_fit(int size) {
    struct block *current = head;
    while (current != NULL) {
        if (current->size >= size && current->allocated == 0) {
            // if block is bigger than requested size, split it
            if (current->size > size) {
                struct block *new_block = (struct block *)((char *)current + sizeof(struct block) + size);
                new_block->size = current->size - size - sizeof(struct block);
                new_block->allocated = 0;
                new_block->next = current->next;
                current->next = new_block;
            }
            current->allocated = 1;
            return (void *)current + sizeof(struct block);
        }
        current = current->next;
    }
    return NULL;
}

void deallocate(void *memory) {
    struct block *block_to_free = (struct block *)((char *)memory - sizeof(struct block));
    block_to_free->allocated = 0;

    // merge adjacent free blocks
    struct block *current = head;
    while (current != NULL) {
        if (current->allocated == 0 && current->next != NULL && current->next->allocated == 0) {
            current->size += sizeof(struct block) + current->next->size;
            current->next = current->next->next;
        }
        current = current->next;
    }
}

void print_block(void *memory) {
    struct block *block = (struct block *)((char *)memory - sizeof(struct block));
    printf("Block of size %d allocated at address %p\n", block->size, memory);
}

int main() {
    int num_blocks;
    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);

    for (int i = 0; i < num_blocks; i++) {
        int block_size;
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &block_size);
        allocate_memory(block_size);
    }

    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        int process_size;
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &process_size);
        void *allocated_memory = first_fit(process_size);
        if (allocated_memory != NULL) {
            print_block(allocated_memory);
        } else {
            printf("Unable to allocate memory for process %d\n", i + 1);
        }
    }

    return 0;
}
