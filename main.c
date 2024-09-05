#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048


int adma(){

    char admid[40],admpwd[40];
    int a;
    FILE *f;
    a:
    printf("press 1 if u want to change any admin details\n");
    printf("press 2 to enter a new admin\n");
    scanf("%d",&a);
    if(a==2){
    printf("enter the admin id");
    scanf("%s",&admid);
    printf("enter the admin password\n");
    scanf("%s",&admpwd);
    f=fopen(admid,"w");
    fprintf(f,"%s\n",admid);
    fprintf(f,"%s\n",admpwd);
    fclose(f);
    }else if(a==1){
    printf("enter the admin id");
    scanf("%s",&admid);
    printf("enter the admin password\n");
    scanf("%s",&admpwd);
    strcat(admid,".txt");
    remove(admid);
    f=fopen(admid,"w");
    fprintf(f,"%s\n",admid);
    fprintf(f,"%s\n",admpwd);
    fclose(f);
    }else{
    goto a;
    }
    return 0;
}
int adml(){
    char a[31],data[101],pwd[31],mail[31],r[40]="r",c[50];
    char dataa[100],data3[100],data1[100],data5[101];
    int b,s=0,s1=0,d,e,i,y,g,bb,ee;
    int linecount,linestatus,h,aaa,ii;
    int hh;
    float spi;
    bool status,access;
    FILE *p;
    FILE *aa;
    u:
    printf("are you a main admin?  press 1\n");
    printf("if not press 2\n");
    scanf("%d",&bb);
    if(bb==1||bb==2){
    printf("enter admin id\n");
    scanf("%s",&a);
    printf("enter your password\n");
    scanf("%s",&pwd);
    if(bb==1){
    y=strcmp(a,"admin@iiti.ac.in");
    aaa=strcmp(pwd,"admin_123");
    if(y==0&&aaa==0){
        printf("main admin found\n");
        printf("press 1 if you want to give access to a new admin\n");
        printf("press 2 if you want to access the datails of students\n");
        scanf("%d",&ii);
        if(ii==1){
            adma();
            printf("admin successfully added\n");
            goto u;
        }else if(ii==2){
            goto aaaa;
        }
        access=true;
    }else{
        goto u;
    }
    }else{
        char data4[50];
        int cc,dd;
        p=fopen(a,"r");
        if(p==NULL){
            printf("OOPS! you don't have access to the files contact admin\n");
            goto a;
        }else{
            status=true;
            fgets(data4,40,p);
            do{
               int linecount2=1;
               if(linecount2==1){
                cc=strcmp(data4,a);
               }if(linecount2==2){
                dd=strcmp(data4,pwd);
                status=false;
               }
               linecount2++;
            }while(status);
            if(cc==0&&dd==0){
                goto aaaa;
            }else{
                goto u;
            }
        }
    }
    }else{
        goto u;
    }
    aaaa:
    p=fopen("studentslist.txt","r");
    do{
        fgets(data,100,p);
        if(feof(p)){
            status=false;
            printf("all the data has been accessed successfully\n");
        }else{
            printf("%s\n",data);
        }
    }while(status);
    fclose(p);
    printf("enter the mail of the student to enter his/her result\n");
    scanf("%s",&mail);
   // strcat(mail,".txt");
    strcat(r,mail);
    ad:
    printf("to re-enter the details of student press 1\n");
    printf("for a fresh entry press 2\n");
    printf("to view the details of a student press 3\n");
    scanf("%d",&hh);
    if(hh==1){
        goto jj;
    }else if(hh==2){
        goto kk;
    }else if(hh==3){
            goto d;
        }else{
        goto ad;
    }
    kk:
    p=fopen(r,"w");
    printf("enter the number of subjects:\n");
    scanf("%d",&b);
    i=0;
    do{
    printf("enter the name of the subject:\n");
    scanf("%s",&c);
    printf("enter the grade in that subject:\n");
    scanf("%d",&d);
    printf("enter the no.of credits in that subject:\n");
    scanf("%d",&e);
    fprintf(p,"s.no:%d\tsubject:%s\tcredits:%d\tgrade:%d\n",i+1,c,e,d);
    s=(s+(d*e));
    s1=s1+e;
    i++;
    }while(i<b);
    spi=(s/s1);
    fprintf(p,"spi:%f",spi);
    fprintf(p,"\n");
    fclose(p);
    printf("successfully entered the details\n");
    d:
    printf("want to view the entered details? press 1\n");
    printf("to exit the program press 2\n");
    scanf("%d",&g);
    status=true;
    if(g==1){
            p=fopen(r,"r");
        do{
            fgets(data1,100,p);
            if(feof(p)){
                status=false;
            }else{
                printf("%s\n",data1);
            }
        }while(status);
        c:
        printf("any changes to be made press 1\n");
        printf("to terminate press 2\n");
        scanf("%d",&h);
        if(h==1){
            goto b;
        }else if(h==2){
            goto a;
        }else{
            goto c;
        }
    }else if(g==2){
        goto a;
    }else{
        goto d;
    }
    b:
        fclose(p);
        jj:
        //strcat(r,".txt");
        remove(r);
        goto aaaa;

    a:
    return 0;

}
void stdfp(){
    char mail[30],data1[20],data3[20],data2[20],file[30];
    char s1[20],s2[20],s3[20],data[31];
    char pwdn[20],pwdnc[20];
    int r,f,c;
    char tempfile[20],replacetext[31];
    int j,k,l,i,d,linecount=1;
    int replaceline;
    bool status=true;
    FILE *a,*temp;
    abc:
    printf("enter ur institute mail id\n");
    scanf("%s",mail);
    strcpy(file,mail);
    a=fopen(file,"r");
    if(a==NULL){
        printf("file couldn't be opened\n");
        goto abc;
    }else{
     printf("enter 1 or 2 for the questions asked");
        printf("\n1 for yes");
        printf("\n2 for no\n");
        printf("do you like yoga\n");
        scanf("%d",&r);
        printf("do you play any sports\n");
        scanf("%d",&f);
        printf("enter ur lucky number\n");
        scanf("%d",&c);
    }
    do{
        fgets(data1,19,a);
        if(feof(a)){
            status=false;
        }else if(linecount==4){
            printf("final:%s",data1);
            int num1=atoi(data1);
            if(num1==r){
                    j=0;
                printf("security 1 matched\n");
            }else{
                goto abc;
            }
        }else if(linecount==5){
            int num1=atoi(data1);
            if(num1==f){
                k=0;
                printf("security 2 matched\n");
            }else{
                goto abc;
            }
        }else if(linecount==6){
            printf("final:%s",data1);
            int num1=atoi(data1);
            if(num1==c){
                    l=0;
                printf("security 3 matched\n");
            }else{
                goto abc;
            }

        }
        linecount++;
    }while(status);
    status=true;
    linecount=0;
    if(j==0&&k==0&&l==0){
             printf("enter the new password\n");
            scanf("%s",pwdn);
            system("CLS");
            printf("re-enter the password\n");
            scanf("%s",pwdnc);
            i=strcmp(pwdn,pwdnc);
            if(i==0){
            strcpy(tempfile,"temp____");
            strcat(tempfile,file);
            fflush(stdin);
            fgets(replacetext,30,stdin);
            a=fopen(file,"r");
            temp=fopen(tempfile,"w");
            if(a==NULL||temp==NULL){
                printf("error in opening the files\n");
            }
            bool status=true;
            linecount=1;
            do{
                fgets(data,30,a);
                if(feof(a)){
                    status=false;
                }else if(linecount==2){
                    fputs(pwdn,temp);
                    fprintf(temp,"\n");
                }else{
                    fputs(data,temp);
                }
                linecount++;
            }while(status);
            fprintf(temp,"\n");
            strcat(file,".txt");

            fclose(a);
            fclose(temp);

            remove(file);
            rename(tempfile,file);
            printf("success");
            }
    }
}
int stdl(){
    char mail[30],data[40],data2[20],data3[101],p[30]="r",mail1[30],mailv[30];
    char pwd[20],pwdc[20];
    char file[FILENAME_SIZE];
    long int rollno;
    bool status=true;
    int b,m,d=0,k,linecount=1,readline=1;
    FILE *a;
    aa:
    printf("enter ur institute mail id\n");
    scanf("%s",mail);
    strcpy(file,mail);
    strcpy(mail1,mail);
    abc:
    printf("press 1 to go to the main menu\n");
    printf("press 2 if you can login\n");
    scanf("%d",&m);
    if(m==1){
        goto c;
    }if(m==2){
    printf("enter ur password\n");
    scanf("%s",pwd);
    }
    a=fopen(file,"r");
    if(a==NULL){
        printf("file couldn't be opened\n");
        goto aa;
    }
    bbb:
    fgets(data,29,a);
    if(d==0){
        printf("email id found\n");
    }else{
        goto aa;
    }
    do{
        fgets(data2,20,a);
        if(feof(a)){
            status=false;
        }else if(linecount==1){
            status==false;
            strcpy(pwdc,data2);
            k=strcmp(pwdc,data2);
            if(k==0){
                printf("password matched\n");
            }else{
                goto abc;
            }
        }
        linecount++;
    }while(status);
     printf("Wow! login successful\n");
    fclose(a);
    strcat(p,mail1);
    status=true;
    if(k==0&&d==0){
        a=fopen(p,"r");
        if(a==NULL){
            printf("seems there is no record please contact the admin\n");
        }else{
        int linecount=0;
        do{
           fgets(data3,100,a);
           if(feof(a)){
            printf("viewing successful\n");
            status=false;
           }else{
           printf("%s\n",data3);
           }
        }while(status);
    }
    }
    c:
        return 0;


    }




int stdr(){
    char mail[30],c[20];
    char pwdi[20],pwdf[20],filename[20];
    int a,d,z,e;
    FILE *b;
    b:
    printf("enter ur institute mail id\n");
    scanf("%s",mail);
    strcpy(filename,mail);
        b=fopen(filename,"r");
        if(b!=NULL){
            printf("you have already registered\n");
            goto aaa;
        }else {
             printf("enter ur password\n");
             printf("make sure that there is no space involved in ur password\n");
    scanf("%s",pwdi);
    system("CLS");
    printf("confirm ur password\n");
    scanf("%s",pwdf);
    e=strcmp(pwdi,pwdf);
    if(e==0){
            fclose(b);
            b=fopen(filename,"w");
            fprintf(b,"%s\n",mail);
        fprintf(b,"%s\n",pwdi);
        goto a;
        } else{
        printf("passwords entered are different");
        goto b;
    }
        }


    a:
        printf("enter 1 or 2 for the questions asked");
        printf("\n1 for yes");
        printf("\n2 for no\n");
        printf("do you like yoga\n");
        scanf("%d",&a);
        printf("do you play any sports\n");
        scanf("%d",&d);
        printf("\n enter ur lucky number\n");
        scanf("%d",&z);
        fprintf(b,"%d\n%d\n%d",a,d,z);
        fprintf(b,"\n\t");
        fclose(b);
        b=fopen("studentslist.txt","a");
        printf("enter your name\n");
        printf("If your name has any spaces please use underscore '_' there instead of space\n");
        char name[50];
        scanf("%s",&name);
        fprintf(b,"%s\t",name);
        fprintf(b,"%s\n",mail);
        fclose(b);
        aaa:
            printf("if would you like to login now press 1\n");
            printf("if you want to terminate the program press 2\n");
            int rrr;
            scanf("%d",&rrr);
            if(rrr==1){
            stdl();
            }else if(rrr==2){
                goto aaaaa;
           } else{
            goto aaa;
           }
            aaaaa:
                return 0;
}


int main()
{
    int n,p;
    h:
    printf("enter your choice\n");
    printf("enter 1 for student login\n");
    printf("enter 2 for student register\n");
    printf("enter 3 to reset password\n");
    printf("enter 4 for admin login\n");
    scanf("%d",&n);
    if(n==1){
        stdl();
        k:
        printf("login failure or forgot password??press 1\n");
        printf("to terminate the program press 2\n");
        scanf("%d",&p);
        if(p==1){
            goto h;
        }else if(p==2){
            goto g;
        }else{
            goto k;
        }
    }
    else if(n==2){
        stdr();
        printf("Welcome to the portal\n");
        printf("Congratulations on your registration\n");
        i:
        printf("press 1 to proceed to login\n");
        printf("press 2 to exit the portal\n");
        printf("3 to go to main menu\n");
        scanf("%d",&p);
        if(p==1){
            stdl();
        }else if(p==2){
            goto g;
        }else if (p==3){
            goto h;
            }else{
        goto i;
        }
    }else if(n==3){
        stdfp();
    }else if(n==4){
        adml();
        }else{
    goto h;
    }

    g:
    return 0;
}
