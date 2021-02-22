 #include <stdio.h>
 #include <string.h>
 
 int main(void){
	struct message{
		char userid[10];
		char message[141];
		int upvotes;
	}Caws[100];
	char Answer, yn, CurrentFile[100];
	int MessageSelect, p, NumUpvotes;
	FILE *Fptr;
	printf("---CawCaw SMM---\n");
	while(1){
		printf("-Main Menu-\n   M - Create Message\n   U - Upvote a message\n   P - Print last messages\n   L - Load Messages(Import)\n   S - Save Messages(Export)");
		scanf(" %c", Answer);
		switch (Answer) {
			case: 'M'
			case: 'm'
				p = 0;
				for (int i = 0; i < 100; i++){
					Caws[i].upvotes = 0;
					printf("User ID: ");
					scanf("%s", &Caws[i].userid);
					printf("Message: ");
					scanf("%s[^\n]", &Caws[i].message);
					p = i;
				}
				break;
			case: 'U'
			case: 'u'
				printf("Select which message you would like to upvote by message number: ");
				scanf("%i", &MessageSelect);
				if (Caws[MessageSelect].upvotes != {NULL}){
					Caws[MessageSelect].upvote++;
				}
				break;
			case: 'P'	/*Print Code*/
			case: 'p'
				printf("Add Upvote Filter?\n(y/n): ");
				scanf(" %c", &yn);
				if (yn == 'y'|| yn == 'Y'){
					printf("Number of upvotes: ");
					scanf(" %c", &NumUpvotes);
					for (int c = 0; c < p; c++){
						if (NumUpvotes == Caws[c].upvotes){
								printf("\n-----------------------------------\nMessage %i.\n %s\n   %s\n   %i", c, Caws[c].userid, Caws[c].message, Caws[c].upvotes);
						}
					}
				}
				else{
					for (int c = 0; c < p; c++){
						printf("\n-----------------------------------\nMessage %i.\n %s\n   %s\n   %i", c, Caws[c].userid, Caws[c].message, Caws[c].upvotes);
					}
				}
				break;
			case: 'L'	/*Load Code*/
			case: 'l'
				printf("# Warning, any previous messages will be overwriten\nContinue? (y/n): ");
				scanf(" %c", &yn);
				if (yn == 'y'||yn == 'Y'){
					printf("Please input file location: ");
					scanf("%s", &CurrentFile);
					Fptr = fopen( CurrentFile, "r");
					p = 0;
					for(int q = 0; !feof(Fptr); q++){
							fscanf(Fptr, "%s[^\|]", &Caws[q].userid);
							fscanf(Fptr, "%s[^\|]", &Caws[q].message);
							fscanf(Fptr, "%s[^\n]", &Caws[q].upvotes);
							p++;
					}
					fclose(Fptr);
				}
			case: 'S'
			case: 's'
				printf("# Warning, file will be overwriten\nContinue? (y/n): ");
				scanf(" %c", &yn);
				if (yn == 'y'||yn == 'Y'){
					printf("Please input file location: ");
					scanf("%s", &CurrentFile);
					Fptr = fopen( CurrentFile, "w");
					for(int q = 0; !feof(Fptr); q++){
							fprintf(Fptr, "%s|", Caws[q].userid);
							fprintf(Fptr, "%s|", Caws[q].message);
							fprintf(Fptr, "%s\n", Caws[q].upvotes);
					}
					fclose(Fptr);
				}
				break;
				default:
		}
	}
}

