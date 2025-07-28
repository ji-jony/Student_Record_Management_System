#include<stdio.h>
#include<stdlib.h>

// Function Name //
void create();
void display();
void add();
void deleterec();
void totalrecord();
void search();

// Structure //
struct student{
    char name[20];
    int id;
    char dep[20];
}student;


// Main Section //
int main() {
    int ch;
    do{
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Add");
        printf("\n4. Delete");
        printf("\n5. Total Record");
        printf("\n6. Search");
        printf("\n0. Exit");

        printf("\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1 :
                create();
                break;
            case 2 :
                display();
                break;
            case 3 :
                add();
                break;
            case 4 :
                deleterec();
                break;
            case 5 :
                totalrecord();
                break;
            case 6 :
                search();
                break;


        }
    }while(ch!=0);


    return 0;
}


// Create Function //

void create(){
    struct student *s;
    FILE *fp;
    int n,i;
    printf("Enter how many students record you want to store : ");
    scanf("%d",&n);
    s = (struct student*)calloc(n,sizeof(struct student));

    fp = fopen("students.txt","w");

    for(i=0;i<n;i++){
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",&s[i].name);
        fflush(stdin);
        printf("Enter ID : ");
        scanf("%d",&s[i].id);
        fflush(stdin);
        printf("Enter Department : ");
        scanf("%[^\n]s",&s[i].dep);

        fwrite(&s[i],sizeof(student),1,fp);

    }
    fclose(fp);

};


// Display Function //
void display(){
    struct student s1;
    FILE *fp;
    fp = fopen("students.txt","r");
    printf("\n");
    printf("Student Record \n");
    while(fread(&s1,sizeof(student),1,fp)){
        printf("\n%-20s%-5d%-20s",s1.name,s1.id,s1.dep);

    }
    printf("\n");
    fclose(fp);
};


// Add Function //

void add(){
    struct student *s;
    FILE *fp;
    int n,i;
    printf("Enter how many students record you want to store : ");
    scanf("%d",&n);
    s = (struct student*)calloc(n,sizeof(struct student));

    fp = fopen("students.txt","a");

    for(i=0;i<n;i++){
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s",&s[i].name);
        fflush(stdin);
        printf("Enter ID : ");
        scanf("%d",&s[i].id);
        fflush(stdin);
        printf("Enter Department : ");
        scanf("%[^\n]s",&s[i].dep);

        fwrite(&s[i],sizeof(student),1,fp);

    }
    fclose(fp);

};


// No Of Record //

void totalrecord(){
    struct student s1;
    FILE *fp;
    fp = fopen("students.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    printf("\n\nTotal Record : %d",n);
    printf("\n");

    fclose(fp);
};

// Search Function //

void search(){
    struct student s1;
    FILE *fp;
    int sitem;
    int found = 0;
    fp = fopen("students.txt","r");
    printf("Enter ID to search : ");
    scanf("%d",&sitem);
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.id== sitem){
            printf("\n%-20s%-5d%-20s",s1.name,s1.id,s1.dep);
            found = 1;
        }


    }
    if(found==0){
        printf("\n");
        printf("Record not found\n");
    }
    printf("\n");
    fclose(fp);

};

// Delete Function //

void deleterec(){
    struct student s1;
    FILE *fp, *fp1;
    int sitem;
    int found = 0;
    fp = fopen("students.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("Enter ID to Delete : ");
    scanf("%d",&sitem);
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.id== sitem){
            found = 1;
        }
        else {
            fwrite(&s1,sizeof(student),1,fp1);
        }

    }
    fclose(fp);
    fclose(fp1);
    if(found==1){
        fp1 = fopen("temp.txt","r");
        fp = fopen("students.txt","w");

        while(fread(&s1,sizeof(student),1,fp1)){
            fwrite(&s1,sizeof(student),1,fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else {
        printf("\nRecord not found\n");
    }
    printf("\n");
    fclose(fp);

};

