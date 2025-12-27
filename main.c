#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int dados;
	struct node *prox;
}Node;

typedef struct{
	Node *inicio;
	Node *fim;
}FilaCircular;

void fim(){
	getchar();
	printf("\n\nprecione qualquer tecla para continuar");
	getchar();
	system("cls");
}
void adicionar(FilaCircular *f, int num){
	Node *novo = (Node*) malloc(sizeof(Node));
	novo->dados = num;
	if(f->inicio == NULL){
		f->fim = novo;
		f->inicio = novo;
	}
	else{
		f->fim->prox = novo;
		f->fim = novo;	
	}
	novo->prox = f->inicio;
	fim();
}
void ver(FilaCircular *f){
	Node *temp = f->inicio;
	 do {
        printf("%d ", temp->dados);
        temp = temp->prox;
    } while (temp != f->inicio);
    fim();
}

void retirar(FilaCircular *f){
	if(f->inicio == f->fim){
		free(f->inicio);
		f->inicio = NULL;
		f->fim = NULL;
		free(f->inicio);
		fim();
		return;
	}
	Node *in = f->inicio->prox;
	free(f->inicio);
	f->fim->prox = in;
	f->inicio = in;
	fim();
}

void consultar(FilaCircular *f, int p){
	Node *temp = f->inicio;
	 do {
	 	if(temp->dados == p){
		 	printf("\n%d foi encontrado na fila", temp->dados);
		 	return;
		 }
        temp = temp->prox;
    } while (temp != f->inicio);
    printf("\n%d nao foi encontrado na fila",p);
    fim();
}

int main(int argc, char *argv[]) {
	FilaCircular l;
	int o = 0, num, op;
	l.inicio = NULL;
	l.fim = NULL;
	while(o == 0){
		printf("Escolha a opcao desejada:\n\n-[1] Adicionar\n-[2] Retirar\n-[3] Exibir fila\n-[4] Buscar\n\nPrecione outra tecla para sair");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("\nNumero que deseja adicionar: ");
				scanf("%d",&num);
				adicionar(&l,num);
				break;
			case 2:
				system("cls");
				if(l.inicio == NULL){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				retirar(&l);
				printf("\nPrimeiro elemente retirado com sucesso");
				break;
			case 3:
				system("cls");
				if(l.inicio == NULL){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				ver(&l);
				break;
			case 4:
				system("cls");
				if(l.inicio == NULL){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				printf("\nNumero que deseja verficar se esta na fila: ");
				scanf("%d",&num);
				consultar(&l,num);
				break;
			default:
				o = 1;
		}
		Node *atual = l.inicio;;	
		Node *prox;
		do {
        	prox = atual->prox;
        	free(atual);
        	atual = prox;
    	} while (atual != l.inicio);
	}
	return 0;
}
