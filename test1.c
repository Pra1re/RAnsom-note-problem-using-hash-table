#include<stdio.h>

#define table 100

int hashfunc(char *a){
int sum=0;
for(int i=0;a[i]!='\0';i++){
    sum+=a[i];
}

return sum%table;

}

typedef struct m{

char word[100];

struct m *ptr;


}map;
map *p[table]={NULL};




void seperate(char *a){
    //printf("%s\n",a);
int i=0;


while(a[i]!='\0'){
char x[100]="";
    int j=0;

    while(a[i]!=' '&&a[i]!='\0'){


        x[j]=a[i];
        j++;
        i++;

    }
if(a[i]==' '){
    i++;}
    //printf("%s\n",x);
    int f=hashfunc(x);
    //printf("%d\n",f);
    if(p[f]==NULL){

p[f]=malloc(sizeof(map));

        strcpy(p[f]->word,x);
        //printf("%s ",p[f]->word);
        p[f]->ptr=NULL;
    }
    else{

map *temp=p[f];
while(temp->ptr!=NULL){
    temp=temp->ptr;
}
map *neow=malloc(sizeof(map));
strcpy(neow->word,x);
//printf("%s ",neow->word);
neow->ptr=NULL;
temp->ptr=neow;
    }





}



}

int lookup(char *b){
//printf("%s\n",b);
int i=0,result=0,totalwords=0;
while(b[i]!='\0'){
char x[100]="";
    int j=0;

    while(b[i]!=' '&& b[i]!='\0'){

        x[j]=b[i];
        i++;
        j++;


    }
    totalwords++;
    if(b[i]==' '){
    i++;}
//printf("%s ",x);
    int f=hashfunc(x);
    //printf("f = %d ",f);
    map *temp=p[f];
    //printf("x = %s temp word = %s\n",x,p[f]->word);
    if(p[f]==NULL){
        result=0;
        break;
    }
    /*else if(strcmp(temp->word,x)==0){
            result=1;
                strcpy(temp->word,"youdonemessedupa-aron");
                }*/
    //temp=p[f];
    else{
    while(temp!=NULL){
    //printf("comparison between x and temp word %d\n",p);
        if(strcmp(temp->word,x)==0){
                result=1;
                strcpy(temp->word,"youdonemessedupa-aron");

            break;
        }
        else{
            result=0;
        }
temp=temp->ptr;

    }


}
if(result==0){
    break;
}


}
//printf("result %d\n",result);
//printf("total words %d\n",totalwords);

return result;



}






int main(){
int m, n;
    //printf("Enter the lengths of the strings: ");
    scanf("%d", &m);
scanf("%d",&n);
    while (getchar() != '\n');

    char a[30005];

    //printf("Enter the first string: ");
    fgets(a, 30005, stdin);
    int f = strlen(a);
        a[f - 1] = '\0';
    seperate(a);
    //while (getchar() != '\n');
    char b[30005];

    //printf("Enter the second string: ");
    fgets(b, 30005, stdin);
    int g = strlen(b);
        b[g - 1] = '\0';
    int i=lookup(b);
//printf("%d",i);




if(i==1){
    printf("Yes");
}
else{
    printf("No");
}



return 0;}
