#include <stdio.h>
void File(const char* inputFileName, const char* outputFileName, int offset)
{
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Error opening files!\n");
        return;
    }
    int ch;
    while ((ch = fgetc(inputFile)) != EOF)
    {
        ch += offset;
        fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("'%s' success\n", inputFileName);
}
int main()
{
    char inputFileName[30];
    char outputFileName[30];
    int choose;
    printf("Enter the file to open: ");
    scanf("%s", inputFileName);
    printf("Enter the file to create: ");
    scanf("%s", outputFileName);
    printf("\nChoose an option:\n");
    printf("1. Encryption.\n");
    printf("2. Decryption.\n");
    printf(": ");
    scanf("%d", &choose);
    switch (choose)
    {
        case 1:
            File(inputFileName, outputFileName, 100);
            break;
        case 2:
            File(inputFileName, outputFileName, -100);
            break;
        default:
            printf("Errors!!!\n");
            break;
    }
    return 0;

}
