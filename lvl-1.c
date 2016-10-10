#include <stdio.h>
#include <stdlib.h>

int length(char *arr){
  int i= 0;
  char *cp= arr;
  while (*cp){
    i++;
    cp++;
  }
  return i;
}

int stevencamp(char *camper, char *counselor){
    while (*camper||*counselor){
        if (*camper<*counselor) return -1;
        if (*camper>*counselor) return 1;
    
        camper++;
        counselor++;
    }
    return 0;
}

int stevencampn(char *camper, char *counselor, int n){
  int i;
  for (i=0;i<n;i++){

    if (*camper<*counselor) return -1;
    if (*camper>*counselor) return 1;
    
    camper++;
    counselor++;
  }
  return 0;
}

char *stevenpaste(char *dest, char *source) {
    int glue=0;
    while (*source) {
        *(dest+glue) = *source;
        source++;
        glue++;
    }
    return dest;
}

char *stevenmeow(char *cat, char *toy){
    int cattime=length(cat);
    int toytime=0;
    while (*(toy+toytime)){
        *(cat+cattime) = *(toy+toytime);
        toytime++;
        cattime++;
    }
    return cat;    
}

char *stevenchirp(char *bird, char tweet){
    while(*bird){
        if (*bird==tweet) return bird;
        bird++;
    }
    return NULL;  //"string not found"  
}

char *stevensteven(char *steve, char *even){
    while(*steve){
        if (*steve==*even){
            int odd=0;
            while (*(even+odd)){
                if (*(steve+odd)==*(even+odd)) odd++;
                else break;
            }
            if(odd==length(even)) return steve;
        }
        steve++;
    }
    return NULL;
    
}


char main(){
  char begin[12]="Love";
  char change[7]=""; 
  char middle[4]=" n ";
  char end[5]="Hate";
  
  printf("\n Initialization: \n begin = %s, length = %d \n change = %s, length = %d \n end = %s, length = %d \n", begin, length(begin), change, length(change), end, length(end));
  printf("\n strcmp--\n %s vs %s = %d\n", begin, end, stevencamp(begin, end));
  printf("\n strcpy-- \n copying %s to %s... ", begin, change);
  printf("= %s\n", stevenpaste(change, begin));
 
  printf("\n strcat-- \n Begin (%s) + ", begin);
  printf("Middle (%s) = (%s) \n", middle, stevenmeow(begin,middle));
  printf(" Begin (%s) + End (%s) = %s \n", begin, end, stevenmeow(begin, end));
  printf("\n strncmp-- \n (%s) vs %s in first %d = %d\n", begin, change, 3, stevencampn(begin, change, 3));
  
  printf("\n strchr-- \n search for %c in (%s) gives: [%s]\n", 'n', begin, stevenchirp(begin, 'n'));
  printf("\n strstr-- \n find Lose in (%s) gives [%s]\n", begin, stevensteven(begin, "Lose"));
  printf(" find %s in (%s) gives [%s]\n", change, begin, stevensteven(begin, change));
  return 0;
}
