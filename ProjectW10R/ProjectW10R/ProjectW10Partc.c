 #include <stdio.h>
 #include <string.h>
 
 int main(void){
	struct message{
		char userid[10];
		char message[141];
		int upvotes;
	}Caws[100];
	char Answer, yn, CurrentFile[100];
	int MessageSelect;
	FILE *Fptr;
	for (int i = 0; i < 100; i++){
		printf("---CawCaw SMM---");
		Caws[i].upvotes = 0;
		printf("User ID: ");
		scanf("%s", &Caws[i].userid);
		printf("Message: ");
		scanf("%s[^\n]", &Caws[i].message);
		printf("Upvote? (y/n): ");
		scanf(" %c", Answer);
		if (Answer == 'y'||Answer == 'y'){
			Caws[i].upvotes++;
		}
		printf("Print last messages? (y/n): ");
		scanf(" %c", Answer);
		if (Answer == 'y'|| Answer == 'Y'){
			for (int c = 0; c < i; c++){
				printf("\n-----------------------------------\n%i %s\n   %s\n   %i", c, Caws[c].userid, Caws[c].message, Caws[c].upvotes);
			}
		}
	}
}


printf("-Main Menu-\n   M - Create Message\n   U - Upvote a message\n   P - Print last messages\n   L - Load Messages(Import)");
scanf(" %c", Answer);
switch (Answer) {
	case: 'M'
	case: 'm'
		/*whole message code here (Need to set each upvote to zero)*/
		break;
	case: 'U'
	case: 'u'
		printf("Select which message you would like to upvote by message number: ");
		scanf("%i", &MessageSelect);
		Caws[MessageSelect].upvote++;
		/*Add loops to check that the same message isn't upvoted*/
		break;
	case: 'P'
	case: 'p'
		/*Print Code*/
		break;
	case: 'L'	/*Load Code*/
	case: 'l'
		printf("# Warning, any previous messages will be overwriten\nContinue? (y/n): ");
		scanf(" %c", &yn);
		if (yn == 'y'||yn == 'Y'){
			printf("Please input file location: ");
			scanf("%s", &CurrentFile);
			Fptr = fopen( CurrentFile, "r");
			for(int q = 0; !feof(Fptr); q++){
					fscanf(Fptr, "%s[^\|]", Caws[q].userid);
					fscanf(Fptr, "%s[^\|]", Caws[q].message);
					fscanf(Fptr, "%s[^\n]", Caws[q].upvotes);
			}
		}
		
		break;
}