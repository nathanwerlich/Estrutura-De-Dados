/* Copyright 2016 - Nathan Sargon Werlich */
template <typename T> /*!< template generico do tipo T*/
#define VAL 100 /*!< valor constante para inicializar o array dados */
    //!  Classe para a implementação de uma fila
    /*!
     *   \author Nathan Sargon Werlich.
     *   \since 05/04/16
     *   \version 1.0
     */
class Fila {
 private:
    T* dados; /*< Criando um ponteiro */
    int inicio; /*< Criando a variavel 'inicio' que define o inicio da fila */
    int fim; /*< Criando a variavel 'fim' que define o fim da fila */
    int tamanhoFila; /*< Criando a 'tamanhoFila' que define o tamanho da fila */

 public:
    //! Construtor da pilha.
    /*!
     *A variavel 'tamanhoFila' recebe o valor da constante 'VAL'
     *Instancia o vetor dados em Fila e inicia ele com o valor de 'tamanhoFila'
     *Set a variavel 'inicio' como -1
     */
	Fila() {
	tamanhoFila = VAL;
	dados = new T[tamanhoFila];
	inicio = -1;
	}
	/*! 
     * Costrutor com parâmetro int 'tam', com os atributos dados, 'fim' e 'tamanhoFila'
     * Atributo dados é um array do tipo 'T' de tamanho 'tam'
     * Atributo 'fim' é inicializado com -1
     * Atributo 'tamanhoFila', recebe a variável tam
     */
	Fila<T>(int tam) {
	    dados = new T[tam];
	    fim = -1;
	    tamanhoFila = tam;
	}
	/*
    * @brief Metodo para incluir dado no array
    * @details incrementa +1 na variavel 'fim' e grava o dado no array 'dados' na posição 'fim'
    */
	void inclui(T dado) {
        if (filaCheia()) {
            throw("Fila Cheia");
        } else {
            fim += 1;
            dados[fim] = dado;
	    }
    }
    /*
    * @brief Metodo para retirar o primeiro dado da fila
    * @details Guarda o dado da posição zero do array na variavel t, e atraves de um for joga todos os dados uma posição a frente no array
    */
	T retira() {
	    if (filaVazia()) {
	        throw("Fila Vazia");
	    } else {
	        T t = dados[0];
	        for (int i = 0; i < fim; i++) {
	            dados[i] = dados[(i+1)];
	        }
            fim -= 1;
            return (t);
	    }
    }
    /*
    * @brief Metodo para pegar o dado em determinada posição do array
    * @details retorna o dado na posição da variavel 'fim'
    */
	T ultimo() {
        if (filaVazia()) {
            throw("Fila Vazia");
    } else {
        return (dados[fim]);
	    }
	}
	/*
	 * @brief Metodo para indicar a ultima posição da fila
 	 * @details Retorna a variavel 'fim'
 	 */
	int getUltimo() {
	    if (filaVazia()) {
            throw("Fila Vazia");
        } else {
            return (fim);
        }
	}
	/*
	 * @brief Metodo que avisa se a pilha está cheia
 	 * @details Retorna verdadeiro caso a variavel 'fim' for igual a variavel 'tamanhoFila' - 1
 	 */
	bool filaCheia() {
	    return (fim == tamanhoFila-1);
	}
	/*
	 * @brief Metodo que avisa se a fila vazia
 	 * @details Retorna verdadeiro caso a variavel 'fim' for igual a variavel - 1
 	 */
	bool filaVazia() {
	    return (fim == -1);
	}
	/*
	 * @brief Metodo para inicializar a fila
 	 * @details set a variavel 'fim' como -1
 	 */
	void inicializaFila(){
	    fim = -1;
    }
};
