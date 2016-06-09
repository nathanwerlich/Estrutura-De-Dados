/* Copyright 2016 - Nathan Sargon Werlich */
template <typename T> /*!< template generico do tipo T*/
#define VAL 100 /*!< valor constante para inicializar o array dados */
//!  Classe para a implementação de uma pilha
/*!
 *   \author Nathan Sargon Werlich.
 *   \since 04/04/16
 *   \version 1.0
 */
class Pilha {
 private:
    T* dados; /*< Criando um ponteiro */
    int top; /*< Criando a variavel top que define o top da fila */
    int tamanhoPilha; /* Variavel que recebera o valor da constante 'VAL' */

 public:
    //! Construtor da pilha.
    /*!
     *A variavel 'tamanhoPilha' recebe o valor da constante 'VAL'
     *Instancia o vetor dados em pilha e inicia ele com o valor de 'tamanhoPilha'
     *Set a variavel 'top' como -1
    */
    Pilha() {
    tamanhoPilha = VAL;
    dados = new T[tamanhoPilha];
    top = -1;
    }
    /*! 
     * Costrutor com parâmetro int 't', com os atributos dados, 'top' e 'tamanhoPilha'
     * Atributo dados é um array do tipo 'T' de tamanho 't'
     * Atributo 'top' é inicializado com -1
     * Atributo 'tamanhoFila', recebe a variável t
     */
    Pilha<T>(int t) {
        dados = new T[t];
        top = -1;
        tamanhoPilha = t;
    }
    /*
	 * @brief Metoodo que avisa se a pilha está cheia
	 * @details Retorna verdadeiro caso a variavel 'top' for igual a variavel 'tamanhoPilha' - 1
	 */
	void empilha(T dado) {
        if (PilhaCheia()) {
            throw("Pilha Cheia");
	    } else {
	        top += 1;
	        dados[top] = dado;
	    }
	}
	/*
	 * @brief Metodo para desempilhar os dados
	 * @details Caso a pilha não esteja vazia, decrementa 1 na variavel 'top' e retorna o dado do array 'dados' na posição 'top+1'
	 */
	T desempilha() {
	    if (PilhaVazia()) {
        throw("Pilha Vazia");
	    } else {
	        top -= 1;
	        return (dados[top+1]);
	    }
	}
	/*
	 * @brief Metodo para pegar o dado em determinada posição do array
	 * @details retorna o dado na posição da variavel 'top'
	 */
	T topo() {
	    if (PilhaVazia()) {
	        throw("Pilha Vazia");
	    } else {
	        return (dados[top]);
	    }
	}
	/*
	 * @brief Metodo para indicar a posição atual do topo
	 * @details Retorna a variavel 'top'
	 */
	int getPosTopo() {
	    if (PilhaVazia()) {
	        throw("PilhaVazia");
        } else {
	    return (top);
	    }
    }
    /*
	 * @brief Metodo limpar a pilha
	 * @details Caso a pilha não esteja vazia, set a variavel 'top' para -1 tornando a pilha vazia
	 */
	void limparPilha() {
	    if (PilhaVazia()) {
	        throw("Pilha Vazia");
	    } else {
	        top = -1;
	    }
	}
	/*
	 * @brief Metodo que avisa se a pilha está vazia
	 * @details Retorna verdadeiro caso a variavel 'top' for igual - 1
	 */
	bool PilhaVazia() {
	    return (top == -1);
	}
	/*
	 * @brief Metodo que avisa se a pilha está cheia
	 * @details Retorna verdadeiro caso a variavel 'top' for igual a variavel 'tamanhoPilha' - 1
	 */
	bool PilhaCheia(){
	    return (top == tamanhoPilha-1);
	}
};
