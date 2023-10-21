#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // String to store user-entered text
    
    do {
        printf("Input text: ");
        fgets(input, sizeof(input), stdin); // Reading of the input text

        // Removes a newline character that can be read by the fgets function
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strlen(input) == 0) {
            printf("Error: empty string. Please enter some text\n");
        }
    } while (strlen(input) == 0);

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            // If the symbol is lowercase - convert it to a uppercase
            input[i] = input[i] - 'a' + 'A';
        }
        i++;
    }

    printf("Result: %s\n", input);
    return 0;
}
