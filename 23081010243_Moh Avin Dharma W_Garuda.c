#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0'; // Jika stack kosong
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']') ||
           (left == '<' && right == '>');
}

int checkBalancedBrackets(const char *code) {
    Stack stack;
    initStack(&stack);
    int i; // Deklarasi variabel i di luar loop

    for (i = 0; i < strlen(code); i++) {
        char current = code[i];
        if (current == '(' || current == '{' || current == '[' || current == '<') {
            push(&stack, current);
        } else if (current == ')' || current == '}' || current == ']' || current == '>') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), current)) {
                return 0; // Tidak seimbang
            }
        }
    }

    return isEmpty(&stack); // True jika stack kosong (seimbang)
}

int main() {
    const char code[] = "Object obj (in inputParams, out outParams)\n"
                        "{\n"
                        "\t<Blob> myInf = new Blob(function(){\n"
                        "\t\tdata : [\n"
                        "\t\t\t{\n"
                        "\t\t\t\ttype: image,\n"
                        "\t\t\t\tsize: 100,\n"
                        "\t\t\t\tbg: transparent\n"
                        "\t\t\t}\n"
                        "\t\t]\n"
                        "\t\t})\n"
                        "\trun process_img(){\n"
                        "\t\tthis.myInf.blobToImage({\n"
                        "\t\t\ttype: jpg\n"
                        "\t\t})\n"
                        "\t}\n"
                        "}";

    if (checkBalancedBrackets(code)) {
        printf("Kode valid: Semua tanda kurung seimbang.\n");
    } else {
        printf("Kode tidak valid: Terdapat ketidakseimbangan tanda kurung.\n");
    }

    return 0;
}

