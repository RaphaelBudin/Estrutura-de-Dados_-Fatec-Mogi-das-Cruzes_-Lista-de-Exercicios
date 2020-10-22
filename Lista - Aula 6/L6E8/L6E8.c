#include <stdio.h>
#include <pilha.h>

/*
As regras das argolas de Hanoi são:
- As argolas que estão em cima sempre precisam ser menores que as que estão abaixo
- É possível mover apenas uma argola por vez
- É necessário mover todas, na ordem correta, para a base destino

Para resolver o problema de Hanoi, podemos discernir 3 processos:
1 - Tirar todas as argolas acima da argola mais larga e transferir elas para a base auxiliar
2 - Mover a argola que restou para a base de destino
3 - Tirar todas as argolas da base auxiliar e transferir para a base destino

Essa tarefa é intuitiva de se fazer com as mãos, porém entender e expressar a lógica recursiva é difícil.
É fundamental que as três etapas acimas sejam muito bem entendidas para compreender como solucionar o problema.

A primeira dificuldade é: representação.
Na apostila o professor pede que resolvamos o problema das torres de hanoi...
Mas seria utilizando um vetor, que deve ser ordenado em forma crescente? Ou de alguma outra forma?
A solução que achei na internet e escolhi foi a de imprimir as instruções no console apenas

*/


void hanoi(int numeroDisco,char origem,char destino,char auxiliar){
	/*
	A função será chamada recursivamente até o momento em que apenas um disco for encontrado (caso base)
	Nessa situação, sabe-se que ele é o disco mais largo (o último que queremos mover), e que ele pode ir para a base de destino com segurança
	*/
	if(numeroDisco==1){ 
		printf("Mova o disco 1 da base %c para a base %c\n",origem ,destino);	//Todas as demais argolas foram retiradas de cima, logo basta movê-la para o destino
		return;		//Return em uma função void interrompe a execução dessa instância da função
	}


	//Mover o n-1 disco de A para B, usando C de auxiliar
	hanoi(numeroDisco-1,origem,auxiliar,destino);
	/* Mover os discos restantes de A para C*/
	printf("Mova o disco %d da base %c para a base %c\n",numeroDisco,origem,destino);
	/*Mover os n-1 discos de B para C usando A como auxiliar*/
	hanoi(numeroDisco-1,auxiliar,destino,origem);
}

int main(void){
	int nDiscos;
	printf("Numero de discos: ");
	scanf("%d", &nDiscos);
	hanoi(nDiscos, 'A', 'B', 'C');
	puts("");
	return 0;	
}
