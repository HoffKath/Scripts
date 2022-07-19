#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define stack_size 128

int registrador1 = 0;
int registrador2 = 0;
int reverseBits(int num);

struct new_stack
{
    int size[stack_size];
    int top;
} stack;

int current_address = 0;


int stack_full()
{
    if (stack.top >= stack_size - 1)
        return 1;
    else
        return 0;
}

void push(int to_stack)
{
    if(!stack_full()){
        stack.size[++stack.top] = to_stack;
    }
    else {
        printf(" Can't push to empty stack!\n");
    }
}

void push_reg(){
    push(registrador1);
}

int stack_empty()
{
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

int pop()
{
    if(!stack_empty()){
        return stack.size[stack.top--];
    }
    else{
        printf(" Can't pop from empty stack!\n");
    }
}

int peek()
{
    return stack.size[stack.top];
}

void keep()
{
    registrador2 = peek();
    printf("%d\n", registrador2);
}
void pushK(){
    push(registrador2);
}

void regis()
{
    registrador1 = peek();
}

void out()
{
    int i;
    if (stack_empty())
        printf("\n Stack underflow!");
    else
    {
        for (i = stack.top; i >= 0; i--)
            printf(" %d\n", stack.size[i]);
    }
}

void add()
{
    int sum = pop() + pop();
    push(sum);
    regis(sum);
}

void sub()
{
    int sum = pop() - pop();
    push(sum);
    regis(sum);
}

void mult()
{
    int product = pop() * pop();
    push(product);
    regis(product);
}

void division()
{
    int product = pop() / pop();
    push(product);
    regis(product);
}

void square()
{
    int product = pop();
    int raiz = sqrt(product);
    push(raiz);
}

void not()
{
    int x = ~(pop());
    push(x);
    regis(x);
}

void or ()
{
    int x = pop() | pop();
    push(x);
    regis(x);
}

void and ()
{
    int x = pop() & pop();
    push(x);
    regis(x);
}

void mirror()
{
    int x = reverseBits(pop());
    push(x);
    regis(x);
}

int reverseBits(int num)
{
    int  NO_OF_BITS = sizeof(num) * 2;
    int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }

    return reverse_num;
}

void clear(){
    stack.top = -1;
}

void execute(char cmd[])
{
    char **spl = NULL;
    char *starray = strtok(cmd, " ");
    int n_spaces = 0, i;

    while (starray)
    {
        spl = realloc(spl, sizeof(char *) * ++n_spaces);

        if (spl == NULL)
            exit(-1);

        spl[n_spaces - 1] = starray;
        starray = strtok(NULL, " ");
    }

    spl = realloc(spl, sizeof(char *) * (n_spaces + 1));
    spl[n_spaces] = 0;

    if(strcmp(spl[0], "PUSHR\n") == 0)
        push_reg();
    else if (strcmp(spl[0], "PUSH") == 0)
    {
        int num = atoi(spl[1]);
        push(num);
    }
    else if (strcmp(spl[0], "POP\n") == 0)
        pop();
    else if (strcmp(spl[0], "PEEK\n") == 0)
        peek();
    else if (strcmp(spl[0], "ADD\n") == 0)
        add();
    else if (strcmp(spl[0], "MULT\n") == 0)
        mult();
    else if (strcmp(spl[0], "OUT\n") == 0)
        out();
    else if (strcmp(spl[0], "SQRT\n") == 0)
        square();
    else if (strcmp(spl[0], "KEEP\n") == 0)
        keep();
    else if (strcmp(spl[0], "SUB\n") == 0)
        sub();
    else if (strcmp(spl[0], "DIV\n") == 0)
        division();
    else if (strcmp(spl[0], "NOT\n") == 0)
        not();
    else if (strcmp(spl[0], "OR\n") == 0)
        or();
    else if (strcmp(spl[0], "AND\n") == 0)
        and();
    else if (strcmp(spl[0], "MIRROR\n") == 0)
        mirror();
    else if (strcmp(spl[0], "CLEAR\n") == 0)
        clear();
    else if (strcmp(spl[0], "PUSHK\n") == 0)
        pushK();
    else if (strcmp(spl[0], ";") == 0)
        return;
    else
        printf("Command not recognised: %s \n", spl[0]);

    free(spl);
}

int main()
{
    stack.top = -1;

    char str[140];
    FILE *srcfile;

    srcfile = fopen("erroEscrita.txt", "r");
    /*
    srcfile = fopen("baskara.txt", "r");
    srcfile = fopen("operacoesAritmeticas.txt", "r");
    srcfile = fopen("operacoesLogicas.txt", "r");
    srcfile = fopen("operacoesLogicas.txt", "r");
    srcfile = fopen("erroPUSH.txt", "r");
    srcfile = fopen("erroPOP.txt", "r");
    srcfile = fopen("erroEscrita.txt", "r");
    */

    if (srcfile == NULL)
    {
        printf("File failed to open.\n");
        exit(-1);
    }

    else
    {
        while (1)
        {
            if (fgets(str, 140, srcfile) == NULL)
                break;
            printf(" %04d: %s", current_address, str);
            execute(str);

            current_address++;
        }
        fclose(srcfile);
        printf("\nEOF. Quitting");
    }
    return 0;
}
