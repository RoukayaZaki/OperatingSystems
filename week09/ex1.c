#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define member_size(type, member) sizeof(((type *)0)->member)

typedef struct page
{
	int id;
	unsigned int counter;
} page_t;

int main(int argc, char *argv[])
{
	
	if(argc != 2)
	{
		printf("Error: can't find the number of page frames\n");
		return 1;
	}
	
	int frames = atoi(argv[1]);
	
	page_t *pages = calloc(frames, sizeof(page_t));

	if(pages == NULL)
	{
		printf("Error allocating memory for page table\n");
		return 1;
	}
	
	FILE *file = fopen("Lab 09 input.txt", "r");
	if(file == NULL)
	{
		printf("Cannot read input file\n");
		return 3;
	}
	
	int page_id, hit = 0, miss = 0;

	while(fscanf(file, "%d", &page_id) == 1)
	{
		page_t *page = NULL;

        for(int i = 0; i < frames; i++)
        {
            if(pages[i].id == page_id)
                page = pages + i;
        }

		if(page != NULL) hit++;
		else{

			miss++;
            unsigned int minimum = 1 << 31;
            int min_id = 0;
            bool found = false;
            for(int i = 0; i < frames; i++)
            {
                if(pages[i].id == 0) {
                    page = pages + i;
                    found = true;
                    break;
                }
                
                if(pages[i].counter < minimum)
                {
                    minimum = pages[i].counter;
                    min_id = i;
                }
            }
            if(!found) {
                page = pages + min_id;
            }
			page->id = page_id;
			page->counter = 0;
		}

		for(int i = 0; i < frames; i++)
			pages[i].counter >>= 1;
		
		page->counter |= 1 << (member_size(page_t, counter)*8 - 1);
	}
	
	printf("Hits: %d, Misses: %d\n", hit, miss);
	printf("Hits/Misses = %f\n", (double)hit / miss);
	
	free(pages);
	fclose(file);
	
	return 0;
}