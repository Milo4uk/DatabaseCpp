//
//  lookatthis.c
//  cppTraining
//
//  Created by Mila ✨ on 03.01.2023.
//

//
//  BinaryTree.c
//  2semestr
//
//  Created by Mila ✨ on 14.06.2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct stand{
    int number;
    char name[MAX];
    char power[MAX];
    char range[MAX];
    struct stand *link;
}* head;
//struct stand *head = NULL;

 struct node
{
    struct node *prev;
    struct stand info;
    struct node *next;
}node;


void registration(int number, char *name, char *power, char *range){
    struct stand* stand = (struct stand*)malloc(sizeof(struct stand));
    stand->number = number;
    strcpy(stand->name, name);
    strcpy(stand->power, power);
    strcpy(stand->range, range);
    stand->link = NULL;
    
    if (head == NULL){
        head = stand;
    }
    else{
        stand->link = head;
        head = stand;
        
    }
    
}
    void lookUp(int number){
        struct stand *temp = head;
        while (temp!=NULL) {
            if (temp->number == number){
                printf("Number: %d\n", temp->number);
                printf("Name: %s\n", temp->name);
                printf("Power: %s\n", temp->power);
                printf("Range: %s\n", temp->range);
                return;
            }
            temp = temp->link;
        }
        printf("Stand with such number does not exist\n");
    }
    
    void renew(int number){
        struct stand *temp = head;
        while (temp!=NULL) {
            if (temp->number == number) {
                printf("Edit the name:\n");
                scanf("%s", temp->name);
                printf("Edit the power of stand:\n");
                scanf("%s", temp->power);
                printf("Edit the range of stand:\n");
                scanf("%s", temp->range);
                printf("Updated succesfully./n");
            }
            else temp = temp->link;
        }
         printf("Updation failed.\n");
    }
    
    void delete(int number){
        struct stand * temp1 = head;
        struct stand * temp2 = head;
        while(temp1!=NULL){
            
            if(temp1->number == number){
                printf("The stand %d is located\n", number);
            if(temp1==temp2){
                head = head->link;
                free(temp1);
            }
            else{
            temp2->link = temp1->link;
            free(temp1);
            }
            printf("Stand was demilished\n");
            return;
            }
            temp2 = temp1;
            temp1 = temp1->link;
        }
        printf("The stand %d is not found\n", number);
        
    }
    void show()
    {
        struct stand * temp = head;
        while(temp!=NULL){
            printf("\t\tStand's number: %d\n", temp->number);
            printf("\t\tName: %s\n", temp->name);
            printf("\t\tPower: %s\n", temp->power);
            printf("\t\tRange: %s\n", temp->range);
            temp = temp->link;
        }
    }
       

    int main(){
    head = NULL;
        int number;
        char power[MAX];
        char range[MAX];
        char name[MAX];
        int choice;
        printf("1 for Registrating a Stand\n"
               "2 for Showing Specific Stand\n"
               "3 for Deleting a stand\n"
               "4 for Correcting Info\n"
               "5 for Showing a List of Existing Stands In Database");
        do
        {
            printf("\nChoose an option: \n");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    printf("Enter Stand's Number:  ");
                    scanf("%d", &number);
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter Its Power: ");
                    scanf("%s", power);
                    printf("Enter Its Range: ");
                    scanf("%s", range);
                    registration(number, name, power, range);
                    break;
                case 2:
                    printf("Enter Stand's Number for serching: \n");
                    scanf("%d", &number);
                    lookUp(number);
                    break;
                case 3:
                    printf("Enter Stand's Number to delete: \n");
                    scanf("%d", &number);
                    delete(number);
                    break;
                case 4:
                    printf("Enter Stand's Number to upgrade: \n");
                    scanf("%d", &number);
                    renew(number);
                    break;
                case 5:
                    show();
                    break;
//                case 6:
//                    save();
//                    break;
//                case 7:
//                    upload();
//                    break;;
            }
            
        } while (choice != 0);
}
