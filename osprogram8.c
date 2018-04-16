
#include<stdio.h> 
 #include<stdlib.h>
typedef struct 
{ 
      int p, a, b, imp;
      int q, start; 
      int wt;
    int ttime;
}P; 
 
int Q(int m1) 
{ 
      if(m1 == 0 || m1 == 1 || m1 == 2 || m1 == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
} 
 void table(P p[], int n)
{
system("cls");
    int i;
   puts("\n\n\t\t\t\t| PID | Burst Time | Waiting Time | Turnaround Time |");
    for(i=0; i<n; i++) {
        printf("\n\n\t\t\t| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].p, p[i].b, p[i].wt, p[i].ttime );
      
    }

}
void G(P p[], int n)
{
    int i, j;
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b - 1; j++) printf(" ");
        printf("P%d", p[i].p);
        for(j=0; j<p[i].b - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("  ");
        if(p[i].ttime > 9) printf("\b"); 
        printf("%d", p[i].ttime);

    }
    printf("\n");

} 

int main() 
{ 
      int r,n, c, temp_process, time, j, y; 
      P temp; 
	        printf("Enter Total Number of function:\t"); 
      scanf("%d", &n);  
      r=n;
     P function[n]; 
      for(c = 0; c < n; c++) 
      { 
            printf("\nprocess ID:\t"); 
            scanf("%d", &function[c].p); 
            printf("Arrival Time:\t"); 
            scanf("%d", &function[c].a); 
            printf("Burst Time:\t"); 
            scanf("%d", &function[c].b); 
            printf("process Priority:\t"); 
            scanf("%d", &function[c].p); 
            temp_process = function[c].imp; 
            function[c].q = Q(temp_process);
            function[c].start = 0;
			function[c].wt = function[c].ttime = 0; 
      }
      function[0].ttime = function[0].b;
      time = function[0].b; 
      for(y = 0; y < n; y++) 
      
      {
	  for(c=1; c<n; c++) 
	  {
        function[c].wt = function[c-1].wt + function[c-1].b;
        function[c].ttime = function[c].wt + function[c].b;
      } 
      
            for(c = y; c < n; c++) 
            { 
                  if(function[c].a < time) 
                  {
                        function[c].start = 1; 
                  } 
            } 
            while(c< n - 1) 
            {c=y;
                  for(j = c + 1; j < n; j++) 
                  { 
                        if(function[c].start == 1 && function[j].start == 1) 
                        { 
                              if(function[c].q == 2 && function[j].q == 1) 
                              { 
                                    temp = function[c]; 
                                    function[c] = function[j]; 
                                    function[j] = temp; 
                              } 
                        } 
                  } 
          c++;  } 
            while(c < n - 1) 
            { c=y;
                  for(j = c + 1; j < n; j++) 
                  {
                        if(function[c].start == 1 && function[j].start == 1) 
                        { 
                              if(function[c].q == 1 && function[j].q == 1) 
                              { 
                                    if(function[c].b > function[j].b) 
                                    { 
                                          temp = function[c]; 
                                          function[c] = function[j]; 
                                          function[j] = temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            c++;}
			 

            for(c = y; c < n; c++) 
            {
                  if(function[c].start == 1) 
                  { 
                        function[c].start = 0; 
                  } 
            }
      }
       table(function, n);
       G(function, n);
      return 0;
}

