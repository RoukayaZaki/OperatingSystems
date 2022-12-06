#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 500
#define MAX_RESOURCES 500
#define MAX_LINE 256


int main()
{
	FILE *input = fopen("input_dl.txt", "r");
	if(input == NULL)
	{
		printf("Cannot open input file!\n");
		return 2;
	}
	char buffer[MAX_LINE];
	
	int processes[MAX_PROCESSES], existing_resources[MAX_RESOURCES], available_resources[MAX_RESOURCES], current_allocation[MAX_PROCESSES][MAX_RESOURCES], request[MAX_PROCESSES][MAX_RESOURCES];
	
	fgets(buffer, MAX_LINE, input);

	char *p = buffer;

	int index = 0;
	while(*p != '\n')
	{
		int temp = strtol(p, &p, 10);
		existing_resources[index++] = temp;
	}

	if(getc(input) != '\n')
	{
		printf("Malformed input file!\n");
		return 1;
	}
    
	fgets(buffer, MAX_LINE, input);
	p = buffer;
	int index_2 = 0;
	while(*p != '\n')
	{
		int temp = strtol(p, &p, 10);
		available_resources[index_2++] = temp;
	}
	int temp;
	if(index != index_2 || getc(input) != '\n')
	{
		printf("Malformed input file!\n");
		return 1;
	}
	
	int n_processes = 0;
	while(strcmp(fgets(buffer, MAX_LINE, input), "\n") != 0)
	{
		p = buffer;
		for(int i = 0; i < index; i++)
		{
			temp = strtol(p, &p, 10);
			current_allocation[n_processes][i] = temp;
		}
		n_processes++;
	}
	     
	for(int i = 0; i < n_processes; i++)
	{
		fgets(buffer, MAX_LINE, input);
		p = buffer;
		for(int j = 0; j < index; j++)
		{
			temp = strtol(p, &p, 10);
			request[i][j] = temp;
		}
	}
	
	bool process_ok[MAX_PROCESSES];
    for(int i = 0; i < MAX_PROCESSES; i++)
    {
        process_ok[i] = false;
    }
	bool satisfied = true;
	while(satisfied)
	{
		satisfied = false;
		for(int i = 0; i < n_processes; i++)
		{
			if(process_ok[i])
				continue;
			bool can_provide = true;
			for(int j = 0; j < index_2; j++)
			{
				if(request[i][j] > available_resources[j])
				{
                    can_provide = false;
					break;
				}	
			}
			if(!can_provide)	
				continue;

			for(int j = 0; j < index_2; j++)
			{
				available_resources[j] += current_allocation[i][j];
			}
			satisfied = process_ok[i] = true;
		}
	}
	
	FILE *output = fopen("output_dl.txt", "w");
	
	bool deadlock = false;
	for(int i = 0; i < n_processes; i++) deadlock |= !(process_ok[i]);
	
	if(deadlock)
	{
		fprintf(output, "These processes are deadlocked: ");
		for(int i = 0; i < n_processes; i++)
		{
			if(!process_ok[i])
			{
				fprintf(output, "%d, ", i);
			}
		}
		fprintf(output, "\n");
	}
	
    else {
		fprintf(output, "No deadlock found!\n");
	}
	return 0;
}