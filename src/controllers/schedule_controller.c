# include<stdio.h>
# include<string.h>
# include<stdlib.h>
void schedule_write()
{
	char entry[1000];
	char stored_entry[1000];
	int choice;
	while (1)
	{
		printf("please choose the service\n");
		printf("1 Add new to  the schedule\n");
		printf("2 look through the schedule\n");
		printf("3 exit\n");
		scanf("%d", choice);
		getchar();
		switch x:
		{
		case 1:
			printf("please entry your contents");
			fgets(entry, 1000, stdin);
			entry[strcspn(entry, "\n")] = 0;
			strcpy(stored_entry, entry);
			printf("The schedule is updated successfully\n");
			break;
		case 2:
			if (strlen(stored_entry) == 0) {
				printf("No schedule exists\n");
			}
			else {
				printf("%s\n", stored_entry);
			}
			break;
		case 3:
			printf("exit successfully\n");
			break;
		default:
			printf("Your choice is invalid.\n");
		}



	}
}