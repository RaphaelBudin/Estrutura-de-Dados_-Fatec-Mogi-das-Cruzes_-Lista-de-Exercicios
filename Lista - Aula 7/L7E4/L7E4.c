#include <stdio.h>
#define DIM 10

void exibe(int v[], int n ){
	for (int i = 0; i < n; i++) printf("%i ", v[i]);
}

//Ordena o vetor divido usando a intercala��o
void intercala(int vetor[], int vcp, int vcm, int vcu){
	
	int vetorTemporario[vcu-vcp+1];		//vcu-vcp+1 � o tamanho do vetor 
	int posicaoLivre=0;					//Posi��o livre para atribui��o do NOVO vetor (vetorTempor�rio)
	int p1=vcp;							//Primeiro elemento do PRIMEIRO vetor
	int p2=vcm+1; 						//Primeiro elemento do SEGUNDO vetor
	
	
	while (p1<=vcm && p2<=vcu){								// -------- IN�CIO DO WHILE ----------
															// 
															//Garante que o primeiro �ndice n�o passe da metade do vetor completo (o que faria com que ele invadisse o segundo vetor)...
															//E garante que o segundo �ndice n�o ultrapasse o �ltimo �ndice do vetor completo

															
		if (vetor[p1] < vetor[p2]){									//se p1 for menor...
			vetorTemporario[posicaoLivre] = vetor[p1]; 			
			posicaoLivre++;									
			p1++;											//Atualiza o elemento a ser avaliado para o pr�ximo elemento do v1
		}
		else{												//se p2 for menor...
			vetorTemporario[posicaoLivre] = vetor[p2]; 			
			posicaoLivre++;									
			p2++;											//Atualiza o elemento a ser avaliado para o pr�ximo elemento do v2
		}													
	}															
															// -------- FIM DO WHILE ----------
															// Isso pode significar duas coisas:
															// 1 - Um dos dois vetores pode ter acabado/estourado
															// 2 - Os dois vetores tinham tamahos iguais e ambos acabaram
															

															// -------- UM DOS VETORES ACABOU E O OUTRO N�O --------

	while (p1<= vcm){										//Caso o vetor 2 tenha acabado antes... o vetor1 cont�m o restante dos dados j� ordenados, logo basta atribuir
		vetorTemporario[posicaoLivre] = vetor[p1];				
		posicaoLivre++;										
		p1++;
	}
		
	while (p2<= vcu){										//Caso o vetor 1 tenha acabado antes... o vetor2 cont�m o restante dos dados j� ordenados, logo basta atribuir
		vetorTemporario[posicaoLivre] = vetor[p2];
		posicaoLivre++;
		p2++;
	}
															// -------------------------------------------------------

	for (int i=0; i<=vcu-vcp; i++) 						//Atribui��o dos valores organizados no vetorTemporario para o vetorOriginal
		vetor[vcp+i] = vetorTemporario[i];
}

//primeira = primeira posi��o do Vetor a ser ordenada
//�ltima = �ltima posi��o do Vetor a ser ordenada
//meio = posi��o m�dia do Vetor para separar
void ms (int vetor[], int primeira, int ultima){
	if (primeira == ultima) return;
	int meio  = (primeira + ultima)/2;	// Este algotimo ir� chamar recursivamente a fun��o, dividindo o vetor1 em 2 at� o momento em que haja apenas 1 valor
	ms(vetor, primeira, meio);			
	ms(vetor,meio+1,ultima);					// Quando isso acontecer,far� o mesmo processo com o vetor2
	intercala(vetor, primeira, meio, ultima);	//Quando a execu��o chegar nesta linha, o m�todo de intercalar ser� executado, partindo das menores vers�es dos vetores at� o vetor completo
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
