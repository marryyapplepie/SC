#include "shared.h"

int save(char *filename, struct modules *p);
int load(char *filename);
void read(struct modules *door);
int select(char *filename);
int update(char *filename);

void read(struct modules *door) {
    scanf("%d %15s %d %d %d", &door->id, door->name, &door->mem_num, &door->num, &door->delete_flag);
}

/* INSERT STARTS */

int insert(char *filename, struct modules *p) {
    FILE *fp;

    fp = fopen(filename, "ab");
    if (!fp) {
        printf("Error occurred while opening file \n");
        return 1;
    }

    fwrite(p, sizeof(struct modules), 1, fp);

    fclose(fp);
    return 0;
}

/* INSERT ENDS */

/* SELECT STARTS*/

int select(char *filename) {
    printf("Insert the number of records or leave empty to output all of them: \n");
    int door_id;
    scanf("%d", &door_id);
    FILE *fp;
    char *c;
    int i;
    int size = sizeof(struct modules);

    struct modules *ptr = malloc(size);

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error occured while opening file \n");
        free(ptr);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    int struct_amount = ftell(fp) / size;
    if (door_id == 0) {
        for (int k = 0; k < struct_amount; k++) {
            fseek(fp, k * size, SEEK_SET);
            c = (char *)ptr;
            while ((i = getc(fp)) != EOF) {
                *c = i;

                c++;
            }

            printf("%d %s %d %d %d \n", ptr->id, ptr->name, ptr->mem_num, ptr->num, ptr->delete_flag);
        }
    } else if (door_id <= struct_amount) {
        for (int k = 0; k < door_id; k++) {
            fseek(fp, k * size, SEEK_SET);
            c = (char *)ptr;
            while ((i = getc(fp)) != EOF) {
                *c = i;

                c++;
            }
            printf("%d %s %d %d %d \n", ptr->id, ptr->name, ptr->mem_num, ptr->num, ptr->delete_flag);
        }

    } else
        printf("n/a\n");

    free(ptr);
    fclose(fp);
    return 0;
}

/* SELECT ENDS */

/* UPDATE STARTS */

int update(char *filename) {
    int door_id;
    scanf("%d", &door_id);  //считываем номер структуры
    FILE *fp = fopen(filename, "rb+");
    int offset = door_id * sizeof(struct modules);
    fseek(fp, offset, SEEK_SET);
    struct modules door;
    fread(&door, 1, sizeof(struct modules), fp);
    read(&door);
    fseek(fp, offset, SEEK_SET);
    fwrite(&door, 1, sizeof(struct modules), fp);
    fclose(fp);
    return 0;
}

/* UPDATE ENDS */

/* DELETE STARTS

void delete (char *filename) {
    int door_id;
    scanf("%d", &door_id);
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    fseek(file, 0, SEEK_SET);
    long structureSize = sizeof();
    long removeOffset = structureSize * door_id;
    // сдвиг файла
    long shiftBytes = fileSize - removeOffset - structureSize;
    if (shiftBytes > 0) {
        char *shiftData = (char *)malloc(shiftBytes);
        fread(shiftData, 1, shiftBytes, file);

        fseek(file, removeOffset + structureSize, SEEK_SET);
        fwrite(shiftData, 1, shiftBytes, file);

        free(shiftData);
    }
    fseek(file, fileSize - structureSize, SEEK_SET);
    int truncated = ftruncate(fileno(file), fileSize - structureSize);
    if (truncated != 0) {
        printf("Ошибка удаления структуры из файла.\n");
    }

    fclose(file);
}

 DELETE ENDS */

/*
int load(char *filename)
{
    FILE *fp;
    char *c;
    int i;

    struct modules *ptr = malloc(sizeof(struct modules));
    if (!ptr)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Error occurred while opening file \n");
        free(ptr);
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        fseek(fp, sizeof(struct modules)*i, SEEK_SET);
        c = (char *)ptr;


        while ((i = getc(fp))!=EOF)
        {
            *c = i;
            c++;
    }
    printf("%d %s %d %d %d\n",  ptr->id, ptr->name, ptr->mem_num, ptr->num,
ptr->delete_flag);
    }



    fclose(fp);



    free(ptr);
    return 0;
}
*/