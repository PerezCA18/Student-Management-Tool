#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

void clear(char key);
void screen(int holder);

int main(void) {
  FILE *dolist;
  FILE *GPA;
  FILE *PLANNER;
  float *gpaPointer;
  char key,grade,notesName[5][30];
  int menuOption,holder,unit,i,j=0,gpaOption,option,closing,todo,dooption,noteoption;
  float gradePoint=0.0,score,sumUnit=0.0,gpa,saveGPA;
  char sch,word[max],word2[max]="end";
  char monday[24][20]={{'\0'}},tuesday[24][20]={{'\0'}},wednesday[24][20]={{'\0'}},thursday[24][20]={{'\0'}},friday[24][20]={{'\0'}},saturday[24][20]={{'\0'}},sunday[24][20]={{'\0'}};
  char day,course[10];
  int startTime,endTIME,k=0,l,n,m,t,dysClss,z=1;

  //BEGINNING SCREEN
  printf("\t\t\t-------------------------------------\n");
  printf("\t\t\t|                                   |\n");
  printf("\t\t\t|              Welcome!             |\n");
  printf("\t\t\t|                                   |\n");
  printf("\t\t\t-------------------------------------\n");
  printf("\n\nPress Enter to continue.");
scanf("%c",&key);
clear(key);

  //GUI**************************************************************
  do
  { 
    clear(key);
    screen(holder);
    printf("\n\nPlease select an option:\n");
scanf("%d",&menuOption);
  switch(menuOption)
    {
      case 1://GPA............................................
        clear(key);
        printf("\t\t --------------- \t -----------------\n");
        printf("\t\t|   Check GPA   |\t|  Calculate GPA  |\n");
        printf("\t\t|       (1)     |\t|       (2)       |\n");
        printf("\t\t --------------- \t ----------------\n");
        printf("\n\t\t           ----------------");
        printf("\n\t\t          |  Estimate GPA  |");
        printf("\n\t\t          |       (3)      |");
        printf("\n\t\t           ----------------");
        printf("\n\n");
        
        printf("Please select an option: ");
        scanf("%d",&gpaOption);
        clear(key);
          if(gpaOption==1)
          {
             GPA=fopen("GPA.txt","r");
            fscanf(GPA,"%f",&saveGPA);
            fclose(GPA);
                printf("---------------------------------------------\n\n");
              printf("GPA is: %.2f \n\n",saveGPA);
                printf("---------------------------------------------\n\n\n");
        getchar();
      printf("Press any key to return to the main screen.\n");
      scanf("%c",&key);
clear(key);
break;
          }
        else if(gpaOption==2)
        {
          printf("\n\nEnter -1 when asked for credit finish entering courses.\n");
         for(i=0;i>=0;i++)
    {
      printf("\n---------------------------------------------\n");
      printf("Enter the credit units: ");
      scanf("%d",&unit);
      if(unit==-1)
      {
      break;
      }
      else if(unit>0&&unit<5)
      {
        printf("Enter the grade point obtained(A,B,C,D,F): ");
        scanf(" %c",&grade);
         printf("---------------------------------------------\n");
        if(grade=='A'||grade=='B'||grade=='C'||grade=='D'||grade=='F')
        {
            switch(grade)
         {
          case 'A':
          gradePoint=gradePoint+(4.00*unit);
            sumUnit+=unit;
          continue;
          
          case 'B':
           gradePoint+=(3.00*unit);
            sumUnit+=unit;
           continue;
          
          case 'C':
           gradePoint+=(2.00*unit);
            sumUnit+=unit;
            continue;
          
          case 'D':
           gradePoint+=(1.00*unit);
            sumUnit+=unit;
            continue;

           case 'F':
           gradePoint+=(0*unit);
           sumUnit+=unit;
           continue;

           case -1:
           break;
           
          default:
            continue;
         }       
        }
        else
        {
          printf("Please try again.\n");
          continue;
        }
      }
      else
      {
        printf("Please try again.\n");
        continue;
      }
    }
  gpa=gradePoint/sumUnit;
  printf("GPA is: %.2f\n",gpa);
  FILE *GPA=fopen("GPA.txt","w");
     fprintf(GPA,"%f %f",gpa,sumUnit); 
      fclose(GPA);
        getchar();
      printf("Press any key to return to the main screen.\n");
      scanf("%c",&key);
clear(key);
break;
          
        }
          else if(gpaOption==3)
          {
            clear(key);
            FILE *GPA=fopen("GPA.txt","r");
            fscanf(GPA,"%f %f",&gpa,&sumUnit);
            fclose(GPA);
            gpa=gpa*sumUnit;
             printf("\n\nEnter -1 when asked for credit finish entering courses.\n");
            for(i=0;i>=0;i++)
    {
      printf("\n---------------------------------------------\n");
      printf("Enter the credit units: ");
      scanf("%d",&unit);
      if(unit==-1)
      {
      break;
      }
      else if(unit>0&&unit<5)
      {
        printf("Enter the grade point obtained(A,B,C,D,F): ");
        scanf(" %c",&grade);
         printf("---------------------------------------------\n");
        if(grade=='A'||grade=='B'||grade=='C'||grade=='D'||grade=='F')
        {
            switch(grade)
         {
          case 'A':
          gradePoint=gradePoint+(4.00*unit);
            sumUnit+=unit;
          continue;
          
          case 'B':
           gradePoint+=(3.00*unit);
            sumUnit+=unit;
           continue;
          
          case 'C':
           gradePoint+=(2.00*unit);
            sumUnit+=unit;
            continue;
          
          case 'D':
           gradePoint+=(1.00*unit);
            sumUnit+=unit;
            continue;

           case 'F':
           gradePoint+=(0*unit);
           sumUnit+=unit;
           continue;

           case -1:
           break;
           
          default:
            continue;
         }       
        }
        else
        {
          printf("Please try again.\n");
          continue;
        }
      }
      else
      {
        printf("Please try again.\n");
        continue;
      }
      
    }
gpa=gpa+gradePoint;
    gpa=(gpa/sumUnit);
        clear(key);
        getchar();
        printf("\n--------------------------------------------------\n\n");
      printf("Estimated GPA based on current and GPA is: %.2f",gpa);
      printf("\n\n--------------------------------------------------\n");
      printf("\nPress Enter to return to Main Menu");
      getchar();
            
          }
        else//
        {
          printf("Invalid input. Please select ONE of the options\n");
          getchar();
          continue;
        }
     break; //Planner...............................................................
      case 2:
          clear(key);
                printf("\n\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\t\t|   Create   |\t\t\t|    Open   |\n");
printf("\t\t|  Schedule  |\t\t\t|  Schedule |\n");
printf("\t\t|    (1)     |\t\t\t|    (2)    |\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\n\n");
        printf("Please select an option: ");
        scanf("%d",&option);
if(option==1)
{
  do
    {
      clear(key);
      printf("Enter -1 to finish entering courses.\n");
        printf("\n\n---------------------------------\n");
      printf("Name of the course code: ");
  scanf("%s",course);
       if(strcmp(course,"-1")==0)
      {
        break;
      }
      else if(strlen(course)>=6)
      {
      printf("Course code too long. Please try again.");
        continue;
      }
       else
      {
        printf("\nHow many times does the class meet in a week: ");
          scanf("%d",&dysClss);
        
        for(m=0;m<dysClss;m++)
          {
            printf("\nWhat days is the class on: \n");
            printf("( M | T | W | R | F | S | U )\n");
  scanf(" %c",&day);
  printf("In 24-hour clock\n");
  printf("What time it starts: ");
  scanf("%d",&startTime);
  printf("\nWhat time it ends: ");
  scanf("%d",&endTIME);
  startTime-=1;
  endTIME-=1;
     if(startTime>endTIME)
     {
       getchar();
       printf("ERROR\n Course end time occurs before start time. Please enter the information again\n");
       continue;
     }
      else{
        switch(day)
    {
      case 'M':
      strcpy(monday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(monday[l],"| | |");
        }
      
      break;

        case 'T':
           strcpy(tuesday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(tuesday[l],"| | |");
        }
      break;

        case 'W':
           strcpy(wednesday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(wednesday[l],"| | |");
        }
      break;

        case 'R':
           strcpy(thursday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(thursday[l],"| | |");
        }
      break;

        case 'F':
           strcpy(friday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(friday[l],"| | |");
        }
      break;

        case 'S':
           strcpy(saturday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(saturday[l],"| | |");
        }
      break;

        case 'U':
           strcpy(sunday[startTime],course);
        for(l=(1+startTime);l<=endTIME;l++)
        {
          strcpy(sunday[l],"| | |");
        }
      break;
      
      default:
      break;
    }
          }
          }
    }
    }
    while(1);
  PLANNER=fopen("PLANNER.txt","w");
        clear(key);
printf("\t |  Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n");
fprintf(PLANNER,"\t | Sun  | Mon | Tue | Wed | Thu | Fri | Sat |\n");
  for(k=0;k<24;k++)
    {
      n=k+1.0;
printf("%2d:00|%6s|%5s|%5s|%5s|%5s|%5s|%5s|\n",n,sunday[k],monday[k],tuesday[k],wednesday[k],thursday[k],friday[k],saturday[k]);
      fprintf(PLANNER,"%2d:00|%6s|%5s|%5s|%5s|%5s|%5s|%5s|\n",n,sunday[k],monday[k],tuesday[k],wednesday[k],thursday[k],friday[k],saturday[k]);
    }
printf("\n\nPress Enter to return\n");
scanf("%c",&key);
    getchar();
    clear(key);    
        
fclose(PLANNER);
}
  else if(option==2)
  {    
    PLANNER=fopen("PLANNER.txt","r");
        clear(key);
    do
      {
      sch=fgetc(PLANNER);
      printf("%c",sch);
      }
      while(sch!=EOF);
printf("\n\nPress Enter to return\n");
scanf("%c",&key);
    getchar();
    clear(key);    
        
fclose(PLANNER);
  }
           break;
  //TODO LIST................................................
      case 3:
          clear(key);
        printf("\n\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\t\t|    New     |\t\t\t|    Open   |\n");
printf("\t\t|    List    |\t\t\t|    List   |\n");
printf("\t\t|    (1)     |\t\t\t|    (2)    |\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\n\n");
        printf("Please select an option: ");
        scanf("%d",&noteoption);
        if(noteoption==1)
        {
         clear(key);
          dolist=fopen("todolist.txt","w");
          
          fprintf(dolist,"\n");
          fclose(dolist);
        }
        else if(noteoption==2)
        {
              clear(key);
        printf("\n\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\t\t|    Read    |\t\t\t|  Write on |\n");
printf("\t\t|    List    |\t\t\t|    List   |\n");
printf("\t\t|    (1)     |\t\t\t|    (2)    |\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\n\n");
             printf("Please select an option: ");
        scanf("%d",&dooption);
          if(dooption==1)
          {
dolist=fopen("todolist.txt","r");
            clear(key);
  do
  {
    sch=fgetc(dolist);
    printf("%c",sch);
    
  }
          while(!(feof(dolist)));
            fclose(dolist);
            getchar();
            scanf("%c",&key);
          }
          else if(dooption==2)
          {
            clear(key);
            printf("Press Enter after every word to input the word\nInput 'spc' to create a new line\nInput 'end' to finish writing\n");
              printf("Add to the To-Do list:\n"); dolist=fopen("todolist.txt","a+");
            fprintf(dolist,"\n");
  do
    {
      scanf("%s",word);
      if((!(strcmp(word,word2)==0))&&(!(strcmp(word,"spc")==0)))
      {
        fprintf(dolist," %s",word);
      }
      else if(strcmp(word,"spc")==0)
      {
        fprintf(dolist,"\n");
      }
      else if(strcmp(word,word2)==0)
        {
          break;
        }
    }
    while(1);
  
  fclose(dolist);
          }
        }
        
        break;

//Exit------------------------------------
      case 4:
         clear(key);
        printf("\n-----------------------------------------------------");
        printf("\n\n\tAre you sure you want to close the program?\n");
        printf(" \t\t\t\tYes(1)\t\tNo(0)");
        printf("\n-----------------------------------------------------\n\n");
        scanf("%d",&closing);
        if(closing==1)
        {  z=0;
         break;
        }
        else if(closing==0)
        {
          break;
        }
      
      default:
        clear(key);
        printf("\nInvalid input. Please try again");
      continue;
    }
    continue;
  }
    while(z==1);
clear(key);
  printf("\n\n\t\tAll Done! Have a nice day\n");
  return 0;
}

//CHANGE SCREEN
void clear(char key)
{
  if(key)
  {
    system("clear");
  }
}

//GUI BODY
void screen(int holder)
{
printf("\n\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\t\t|    GPA     |\t\t\t|           |\n");
printf("\t\t| Calculator |\t\t\t|  Planner  |\n");
printf("\t\t|    (1)     |\t\t\t|    (2)    |\n");
printf("\t\t-------------\t\t\t-------------\n");
printf("\n\n");
printf("\t\t--------------\t\t\t-------------\n");
printf("\t\t|    To-Do   |\t\t\t|    Exit   |\n");
printf("\t\t|    List    |\t\t\t|  Program  |\n");
printf("\t\t|     (3)    |\t\t\t|    (4)    |\n");
printf("\t\t--------------\t\t\t-------------\n");
}
