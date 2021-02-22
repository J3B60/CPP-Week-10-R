 #include <stdio.h>
 #include <string.h>
 
 int main(void){
	struct message{
		char userid[11];
		char message[141];
		int upvotes;
	}Caws;
	char Answer;
	printf("---CawCaw SMM---");
	Caws.upvotes = 0;
	printf("User ID: ");
	scanf("%s", &Caws.userid);
	printf("Message: ");
	scanf("%s[^\n]", &Caws.message);
	printf("Upvote? (y/n): ");
	scanf(" %c", Answer);
	if (Answer == 'y'||Answer == 'y'){
		Caws.upvotes++;
	}
	printf("%s\n%s\n%i", Caws.userid, Caws.message, Caws.upvotes);
 }