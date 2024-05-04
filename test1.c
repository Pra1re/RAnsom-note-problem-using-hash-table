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
    int f=hashfunc(x);
    
    if(p[f]==NULL){

p[f]=malloc(sizeof(map));

        strcpy(p[f]->word,x);
        
        p[f]->ptr=NULL;
    }
    else{

map *temp=p[f];
while(temp->ptr!=NULL){
    temp=temp->ptr;
}
map *neow=malloc(sizeof(map));
strcpy(neow->word,x);

neow->ptr=NULL;
temp->ptr=neow;
    }





}



}

int lookup(char *b){

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

    int f=hashfunc(x);
    
    map *temp=p[f];
   
    if(p[f]==NULL){
        result=0;
        break;
    }

        

    else{
    while(temp!=NULL){
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
return result;



}






int main(){
int m, n;
    scanf("%d%d", &m,&n);
    while (getchar() != '\n');
    char a[30005];

    fgets(a, 30005, stdin);
    int f = strlen(a);
        a[f - 1] = '\0';
    seperate(a);
    char b[30005];

    fgets(b, 30005, stdin);
    int g = strlen(b);
        b[g - 1] = '\0';
    int i=lookup(b);

if(i==1){
    printf("Yes");
}
else{
    printf("No");
}



return 0;}
