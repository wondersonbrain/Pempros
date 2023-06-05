#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    int looping = 0;
    char command[100];
    struct student_t *murid = malloc(100 * sizeof(struct student_t));
    struct dorm_t *asrama = malloc(100 *sizeof(struct dorm_t));
    int banyak_murid = 0;
    int banyak_asrama = 0;
    
    while (looping != 1 )
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';    
        }

        char *input = strtok(command, "#");

        if (strcmp(input, "student-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].id, input);
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].name, input);
            input = strtok(NULL, "#");
            strcpy(murid[banyak_murid].year, input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                murid[banyak_murid].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                murid[banyak_murid].gender = 1;
            }
            murid[banyak_murid].dorm = NULL;
            banyak_murid++;
        }
        if (strcmp(input, "student-print-all") == 0)
        {
            for (int i = 0; i < banyak_murid; i++)
            {
                if (murid[i].gender != 1)
            {
                printf("%s|%s|%s|male\n", murid[i].id, murid[i].name, murid[i].year);
                
            }
            else 
            {
                printf("%s|%s|%s|female\n", murid[i].id, murid[i].name, murid[i].year);
            }
            } 
        }
        if (strcmp(input, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < banyak_murid; i++)
            {
                if (murid[i].dorm == NULL)
                {
                    if (murid[i].gender != 1)
                    {
                        printf("%s|%s|%s|male|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                    }   else 
                        {
                            printf("%s|%s|%s|female|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
                        }
                }   else 
                    {
                    if (murid[i].gender != 1)
                    {
                    printf("%s|%s|%s|male|%s\n", murid[i].id, murid[i].name, murid[i].year, murid[i].dorm->name);
                    }   else 
                        {
                            printf("%s|%s|%s|female|%s\n", murid[i].id, murid[i].name, murid[i].year, murid[i].dorm->name);
                        }
                    }
                   
            }
        }

        if (strcmp(input, "dorm-add") == 0)
        {
            input = strtok(NULL, "#");
            strcpy(asrama[banyak_asrama].name, input);
            input = strtok(NULL, "#");
            asrama[banyak_asrama].capacity = atoi(input);
            input = strtok(NULL, "#");
            if (strcmp(input, "male") == 0)
            {
                asrama[banyak_asrama].gender = 0;
            }
            else if (strcmp(input, "female") == 0)
            {
                asrama[banyak_asrama].gender = 1;
            }
            asrama[banyak_asrama].residents_num = 0;
            banyak_asrama++;
        }
        if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < banyak_asrama; i++)
            {
                if (asrama[i].gender != 1)
            {
                printf("%s|%d|male|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
                
            }
            else 
            {
                printf("%s|%d|female|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
            }
            } 
        }
        if (strcmp(input, "dorm-print-all") == 0)
        {
            for (int i = 0; i < banyak_asrama; i++)
            {
                if (asrama[i].gender != 1)
                {
                    printf("%s|%d|male\n", asrama[i].name, asrama[i].capacity);
                }
                else 
                {
                    printf("%s|%d|female\n", asrama[i].name, asrama[i].capacity);
                }   
            }
        }

        if (strcmp(input, "assign-student") == 0)
        {
            int indexMurid = 0;
            int indexAsrama = 0;
            char *nim = strtok(NULL, "#");
            char *namaAsrama = strtok(NULL, "#");
            for (int i = 0; i < banyak_murid; i++)
            {
                if(strcmp(nim, murid[i].id) == 0 )
                {
                    indexMurid = i;
                } 
                
            }
            for (int i = 0; i < banyak_asrama; i++)
            {
                if (strcmp(namaAsrama, asrama[i].name) == 0)
                {
                    indexAsrama = i;
                }
                
            }
            
            if (asrama[indexAsrama].capacity > asrama[indexAsrama].residents_num)
            {
                if (murid[indexMurid].gender == asrama[indexAsrama].gender)
                {
                    murid[indexMurid].dorm = &asrama[indexAsrama];
                    asrama[indexAsrama].residents_num++;
                }
            }
        }
        
        if (strcmp(input, "move-student") == 0)
        {
            int indexMurid = 0;
            int indexAsrama = 0;
            int temp_asrama = 0;
            char *nim = strtok(NULL, "#");
            char *namaAsrama = strtok(NULL, "#");
            for (int i = 0; i < banyak_murid; i++)
            {
                if(strcmp(nim, murid[i].id) == 0 )
                {
                    indexMurid = i;
                } 
            }

            for (int i = 0; i < banyak_murid; i++)
            {
                if (murid[indexMurid].dorm == &asrama[i])
                {
                    temp_asrama = i;
                }
            }
            
            for (int i = 0; i < banyak_asrama; i++)
            {
                if (strcmp(namaAsrama, asrama[i].name) == 0)
                {
                    indexAsrama = i;
                }
            }

            if (asrama[indexAsrama].capacity > asrama[indexAsrama].residents_num && murid[indexMurid].gender == asrama[indexAsrama].gender)
            {
                if (murid[indexMurid].dorm != NULL)
                {
                    asrama[temp_asrama].residents_num--;
                }

                murid[indexMurid].dorm = &asrama[indexAsrama];
                asrama[indexAsrama].residents_num++;
            }           
        }

        if (strcmp(input, "---") == 0)
        {
            looping = 1;
        }
    }
    
}