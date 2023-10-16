#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int points[] = {8, 7, 6, 3, 2};

int main(){
    int total = 0; 
    int td_two_pts = 8;
    int td_field_pts = 7;
    int td_pts = 6;
    int fg_pts = 3;
    int safety_pts = 2;
  
    while(1){
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the number of points scored: ");
        scanf("%d", &total);
        for(int a=0; a<=total/td_two_pts; a++){
            for(int b=0; b<=total/td_field_pts; b++){
                for(int c=0; c<=total/td_pts; c++){
                    for(int d=0; d<=total/fg_pts; d++){
                        for(int e=0; e<=total/safety_pts; e++){
                            if((td_two_pts*a + td_field_pts*b + td_pts*c + fg_pts*d + safety_pts*e) == total){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                            }
                        }
                    }
                }
            }
        }
        if(total == 0 || total == 1){
            break;
        }
    }
    return 0;
}