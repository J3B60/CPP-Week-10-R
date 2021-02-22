#include <stdio.h>
#include <string.h>

int main(void) {
	struct message {
		char userid[10];
		char message[141];
		int upvotes;
	}Caws[100];
	char Answer, yn, CurrentFile[100];
	int MessageSelect, p, NumUpvotes, b;
	FILE *Fptr;
	printf("---CawCaw SMM---\n");
	p = 0;
	while (1) {
		printf("\n-Main Menu-\n   M - Create Message\n   U - Upvote a message\n   P - Print last messages\n   L - Load Messages(Import)\n   S - Save Messages(Export)\n(M/U/P/L/S): "); /*Menu*/
		scanf(" %c", &Answer);	/*Select*/
		switch (Answer) {
		case 'M':
		case 'm':
			for (int i = 0; i < 100; i++) {
				Caws[p].upvotes = 0;
				printf("\nUser ID: ");	/*Input UserID*/
				scanf("%s", &Caws[p].userid);
				printf("Message: ");
				scanf("%s[^\n]", &Caws[p].message);	/*Input Message*/
				printf("Continue? (y/n): ");		/*Add more messages?*/
				scanf(" %c", &yn);
				p++;
				if (yn == 'n' || yn == 'N') {
					break;
				}
			}
			break;
		case 'U':
		case 'u':
			printf("Select which message you would like to upvote by message number: "); /*Upvote*/
			scanf("%i", &MessageSelect);
			if (Caws[MessageSelect].upvotes) {		/*If exist*/
				b = Caws[MessageSelect].upvotes;
				Caws[MessageSelect].upvotes = b + 1;		/*Add 1*/
			}
			else {
				printf("Error Message doesn't exist\n");
			}
			break;
		case 'P':	/*Print Code*/
		case 'p':
			printf("Add Upvote Filter?\n(y/n): ");
			scanf(" %c", &yn);
			if (yn == 'y' || yn == 'Y') {
				printf("Number of upvotes: ");			/*Upvotes Q*/
				scanf("%i", &NumUpvotes);				
				for (int c = 0; c < p; c++) {
					if (NumUpvotes == Caws[c].upvotes) {				/*If requested Number of Upvotes Comparison*/
						printf("\n-----------------------------------\nMessage %i.\n   %s\n   %s\n   %i\n", (c + 1), Caws[c].userid, Caws[c].message, Caws[c].upvotes);	/*Output*/
					}
				}
			}
			else {
				for (int c = 0; c < p; c++) {
					printf("\n-----------------------------------\nMessage %i.\n   %s\n   %s\n   %i\n", (c + 1), Caws[c].userid, Caws[c].message, Caws[c].upvotes);	/*Output for all messages*/
				}
			}
			break;
		case 'L':	/*Load Code*/
		case 'l':
			printf("# Warning, any previous messages will be overwriten\nContinue? (y/n): ");	/*Import Warning*/
			scanf(" %c", &yn);
			if (yn == 'y' || yn == 'Y') {
				printf("Please input file location: ");
				scanf("%s", &CurrentFile);				/*User input File*/
				Fptr = fopen(CurrentFile, "r");			/*Open for read*/
				//if (Fptr == NULL)
				//{
					//perror("ERROR");
				//}
				printf("\nImport Started");
				p = 0;
				int q = 0;
				while (!feof(Fptr)) {
					fscanf(Fptr, "%[^\|]|%[^\|]|%i\n", &Caws[q].userid, &Caws[q].message, &Caws[q].upvotes);	/*Read File*/
					p++;
					q++;
				}
				fclose(Fptr);/*Close*/
				printf("Import Done");
			}
			break;
		case 'S':
		case 's':
			printf("# Warning, file will be overwriten\nContinue? (y/n): ");	/*Output Warning*/
			scanf(" %c", &yn);
			if (yn == 'y' || yn == 'Y') {
				printf("Please input file location: ");
				scanf("%s", &CurrentFile);				/*User input file + Make new file*/
				Fptr = fopen(CurrentFile, "w");			/*Open For write*/
				int b = 0;
				while (b != p){
					fprintf(Fptr, "%s|%s|%i\n", Caws[b].userid, Caws[b].message, Caws[b].upvotes);
					b++;
				}
				fclose(Fptr);	/*Close*/
			}
			break;
		default:
			break;
		}
	}
}