#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct music
{
    char song[80];
    struct music *next;
};
struct music *head = NULL;
void inmusic(struct music **head, char *s)
{
    struct music *temp = (struct music *)malloc(sizeof(struct music));
    strcpy(temp->song, s);
    temp->next = *head;
    *head = temp;
}
void delmusic(struct music **head, char *s)
{
    struct music *temp = *head, *temp1 = NULL;
    if (temp != NULL && strcasecmp(temp->song, s) == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcasecmp(temp->song, s) != 0)
    {
        temp1 = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("The song is not available\n");
        return;
    }
    temp1->next = temp->next;
    free(temp);
}
void display(struct music *temp)
{
    if (temp == NULL)
    {
        printf("No song in Playlist\n");
    }
    while (temp != NULL)
    {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
}
void delplaylist(struct music *head)
{
    struct music *temp;
    while (temp != NULL)
    {
        temp=head;
        head = head->next;
        free(temp);
        return;
    }
}
int main()
{
    int c = 0;
    char s[50];
    while (1)
    {
        printf("0 - Add song\n1 - Remove song\n2 - Display the playlist\n3 - End\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        getchar();
        switch (c)
        {
        case 0:
            printf("Enter song name: ");
            fgets(s, 80, stdin);
            s[strcspn(s, "\n")] = '\0';
            inmusic(&head, s);
            break;
        case 1:
            printf("Enter song name: ");
            fgets(s, 80, stdin);
            s[strcspn(s, "\n")] = '\0';
            delmusic(&head, s);
            break;
        case 2:
            printf("Current Playlist: \n");
            display(head);
            printf("\n");
            break;
        case 3:
            delplaylist(head);
            return 0;
        default:
            printf("Enter Valid choice\n");
            break;
        }
    }
    return 0;
}
