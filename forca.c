#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vq = 1; //indice usado no array da linha 9
char palavra[100]; //palavra introduzida por um dos utilizadores
char palavra_incompleta[100]; //palavra em formato de traços até ser resolvida
int vida = 0; //vidas que o utilizador tem
char alfabeto[25] = "123456789123456789123456"; //array onde guarda letras que já foram usadas
int jogadas = 0; //número de jogadas
int ganhar = 0;

void desenho(int qual); //faz o desenho da forca

//Mete a palavra em linhas, ex. Olá -> _ _ _
int linhas_palavra() {
    int numero = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] == '-'){
            palavra_incompleta[i] = '-';
        }
        else{palavra_incompleta[i] = '_';}
    }
    printf("\n");
}

//Vai dando print há palavra conforme é resolvida
void print_palavra(){
    for(int i = 0; i < strlen(palavra); i++){
                printf("%c", palavra_incompleta[i]);
        }
}

//Insere letra/palavra para ver se acerta ou não
void inserir(int opcao){
    char letra;
    char palavra_adivinhar[100];
    int certo = 0;
    int owo = 0;

    if(opcao == 1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Insira a letra:\n->");
        scanf(" %c", &letra);
        letra = toupper(letra);
        if(strchr(alfabeto, letra) == NULL){
            alfabeto[vq] = letra;
            vq++;
        }
        for(int i = 0; i < strlen(palavra); i++){
            if(palavra[i] == letra){
                certo++;
                palavra_incompleta[i] = letra;
            }
        }
    }
    if(opcao == 2){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Insira a palavra:\n->");
        scanf(" %s", palavra_adivinhar);
        for(int i = 0; i < strlen(palavra_adivinhar); i++){
        palavra_adivinhar[i] = toupper(palavra_adivinhar[i]);
    }
        int a = strcmp(palavra, palavra_adivinhar);
        if(a == 0){ganhar = 1;}
        else{vida = 5;}
    }

    jogadas++;
    if(certo == 0){vida++;}
    else{
        for (int i = 0; i < strlen(palavra); i++){
            if(palavra[i] == palavra_incompleta[i]){owo++;}
        }
        
    }
    if (owo == strlen(palavra))
    {
        ganhar = 1;
    }
    
}

//Dá print ás letras usadas
void letras_usadas(){
    printf("letras usadas: ");
    for (int i = 1; i <= jogadas; i++)
    {
        if(jogadas != 0 && !isdigit(alfabeto[i]))
            {printf("%c ", alfabeto[i]);}
    }
    printf("\n"); 
}

//Mete tudo em letra grande
void letra_grande(){
    for(int i = 0; i < strlen(palavra); i++){
        palavra[i] = toupper(palavra[i]);
    }
}

int main() {
    int opcao = 99;
    while (opcao != 0) {
        vq = 1; //indice usado no array da linha 9
        palavra[100]; //palavra introduzida por um dos utilizadores
        palavra_incompleta[100]; //palavra em formato de traços até ser resolvida
        vida = 0; //vidas que o utilizador tem
        jogadas = 0; //número de jogadas
        int opcao1 = 99, correta = 0, proseguir;
        char letra;
        vida = 0;
        ganhar = 0;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        desenho(6);
        printf("Bem-vindo ao jogo da forca :)!\n");
        printf("Escolha a sua opção:\n");
        printf("1 - Jogo da forca\n");
        printf("2 - Regras do jogo\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                desenho(0);
                printf("Obrigado por jogar :)!\n");
                break;
            case 1:
                while(correta != 1){
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    printf("Insira a palavra que quer que o outro adivinhe (caso tenha espaços, use \"-\"):\n");
                    scanf(" %s", palavra);

                    letra_grande();

                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    printf("É esta a palavra que quer que o outro adivinhe?\n-> %s\n(se sim, 1, se não, 0)\n", palavra);
                    scanf("%d", &correta);
                    }
                    linhas_palavra();
                    while(vida != 6 && ganhar != 1){
                        if(vida != 6){
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            desenho(vida);
                            print_palavra();
                            printf(" (%ld letras a contar com os \"-\" se tiver)\n", strlen(palavra));
                            letras_usadas();
                            printf("1 -> Inserir letra (-1 vida se falhas)\n");
                            printf("2 -> Inserir palavra (-6 vidas se falhas)\n");
                            scanf("%d", &opcao1);
                            inserir(opcao1);
                        }
                        if(vida == 6){
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            desenho(vida);
                            printf("Game over, usaste as vidas todas :(\n");
                            printf("Insira um número para voltar ao menu\n");
                            scanf("%d", &proseguir);
                        }
                        if(ganhar == 1){
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                            printf("Ganhaste :)\n");
                            printf("Insira um número para voltar ao menu\n");
                            scanf("%d", &proseguir);
                        }
                    }
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("Este jogo é simples de jogar, alguém escreve uma palavra, e outra tenta adivinhar\n");
                printf("dizendo letras para ter uma ideia de qual palavra possa ser ou tentando adivinhar\n");
                printf("logo a palavra em si\n");

                printf("Insira qualquer número para voltar ao ménu:\n");
                scanf("%d", &proseguir);
                break;
            default:
                printf("\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("houve algum erro, por favor volte a executar\n");
                opcao = 0;
                break;
        }
    }    
}

void desenho(int qual){
    if(qual == 6){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |             *********\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                * *\n");
        printf(" |               *   *\n");
        printf(" |              *     *\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 5){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |             *********\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                *\n");
        printf(" |               *\n");
        printf(" |              *\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 4){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |             *********\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 3){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |             *****\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 2){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |                 *\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 1){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |                ***\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }

    if(qual == 0){
        printf(" ____________________\n");
        printf(" |                 |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("***\n");
    }
}