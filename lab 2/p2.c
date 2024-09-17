#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char passward[10];
  int hasUpperCase = 0;
  int hasLowerCase = 0;
  int hasdigit = 0;
  int hasSpecialChar = 0;
  
  printf(" please enter your passward : ");
  scanf("%s", passward);

  int length = strlen(passward);
  for (int i = 0; passward[i] != '\0'; i++)
  {

    if (isupper(passward[i]))
    {
      hasUpperCase = 1;
    }
    if (islower(passward[i]))
    {
      hasLowerCase = 1;
    }
    if (isdigit(passward[i]))
    {
      hasdigit = 1;
    }

    if (!isalnum((passward[i])))
    {
      hasSpecialChar += 1;
    }
  }

  if (length >= 8 && hasUpperCase && hasLowerCase && hasdigit && hasSpecialChar)
  {
    printf("Strong Password!");
  }
  else if (length >= 6 && hasUpperCase + hasLowerCase + hasdigit+ hasSpecialChar >= 3)
  {
    printf("Avarage Passward!");
  }
  else
  {
    printf("Weak Password! ");
  }

  return 0;
}
