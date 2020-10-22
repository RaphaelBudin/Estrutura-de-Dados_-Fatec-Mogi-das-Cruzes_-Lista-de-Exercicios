#include <stdio.h>
#define DIM 10

void exibe(int v[], int n ){
	for (int i = 0; i < n; i++) printf("%i ", v[i]);
}

//Ordena o vetor divido usando a intercalação
void intercala(int vetor[], int vcp, int vcm, int vcu){
	
	int vetorTemporario[vcu-vcp+1];		//vcu-vcp+1 é o tamanho do vetor 
	int posicaoLivre=0;					//Posição livre para atribuição do NOVO vetor (vetorTemporário)
	int p1=vcp;							//Primeiro elemento do PRIMEIRO vetor
	int p2=vcm+1; 						//Primeiro elemento do SEGUNDO vetor
	
	
	while (p1<=vcm && p2<=vcu){								// -------- INÍCIO DO WHILE ----------
															// 
															//Garante que o primeiro índice não passe da metade do vetor completo (o que faria com que ele invadisse o segundo vetor)...
															//E garante que o segundo índice não ultrapasse o último índice do vetor completo

															
		if (vetor[p1] < vetor[p2]){									//se p1 for menor...
			vetorTemporario[posicaoLivre] = vetor[p1]; 			
			posicaoLivre++;									
			p1++;											//Atualiza o elemento a ser avaliado para o próximo elemento do v1
		}
		else{												//se p2 for menor...
			vetorTemporario[posicaoLivre] = vetor[p2]; 			
			posicaoLivre++;									
			p2++;											//Atualiza o elemento a ser avaliado para o próximo elemento do v2
		}													
	}															
															// -------- FIM DO WHILE ----------
															// Isso pode significar duas coisas:
															// 1 - Um dos dois vetores pode ter acabado/estourado
															// 2 - Os dois vetores tinham tamahos iguais e ambos acabaram
															

															// -------- UM DOS VETORES ACABOU E O OUTRO NÃO --------

	while (p1<= vcm){										//Caso o vetor 2 tenha acabado antes... o vetor1 contém o restante dos dados já ordenados, logo basta atribuir
		vetorTemporario[posicaoLivre] = vetor[p1];				
		posicaoLivre++;										
		p1++;
	}
		
	while (p2<= vcu){										//Caso o vetor 1 tenha acabado antes... o vetor2 contém o restante dos dados já ordenados, logo basta atribuir
		vetorTemporario[posicaoLivre] = vetor[p2];
		posicaoLivre++;
		p2++;
	}
															// -------------------------------------------------------

	for (int i=0; i<=vcu-vcp; i++) 						//Atribuição dos valores organizados no vetorTemporario para o vetorOriginal
		vetor[vcp+i] = vetorTemporario[i];
}

//primeira = primeira posição do Vetor a ser ordenada
//última = última posição do Vetor a ser ordenada
//meio = posição média do Vetor para separar
void ms (int vetor[], int primeira, int ultima){
	if (primeira == ultima) return;
	int meio  = (primeira + ultima)/2;	// Este algotimo irá chamar recursivamente a função, dividindo o vetor1 em 2 até o momento em que haja apenas 1 valor
	ms(vetor, primeira, meio);			
	ms(vetor,meio+1,ultima);					// Quando isso acontecer,fará o mesmo processo com o vetor2
	intercala(vetor, primeira, meio, ultima);	//Quando a execução chegar nesta linha, o método de intercalar será executado, partindo das menores versões dos vetores até o vetor completo
}

void msort(int vetor[], int tamanho){
	ms(vetor,0,tamanho-1);
}

int main(void){
	int v[DIM] = {83,31,91,46,27,20,96,25,96,80};
	msort(v,DIM);
	exibe(v,DIM);
	puts("");
	return 0;
}
