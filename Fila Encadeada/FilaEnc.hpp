/* Copyright 2016 - Nathan Sargon Werlich */
#include "ListaEnc.hpp" /*!< inclui o arquivo ListaEnc.hpp */
#include "Elemento.hpp" /*!< inclui o arquivo Elemento.hpp */
template <typename T> /*!< template generico do tipo T*/
/* Classe para a implementação de uma Fila Encadeada ultilizando herença da classe 
 * ListaEnc onde a mesma é classe 'pai' e FilaEnc é classe 'filho'
 *
 *   \author Nathan Sargon Werlich.
 *   \since 25/04/16
 *   \version 1.0
 */
class FilaEnc:ListaEnc<T> {
 public:
    //! Construtor da Classe FilaEnc
    /*!
     * Inicializado como vazio
     */
	FilaEnc<T>() {
	}
    //! Destrutor
    /*!
     * Destrutor da classe FilaEnc. 
     * É chamado o metodo 'LimparFila()' para eliminar a Fila por completo
     */
	~FilaEnc() {
	    limparFila();
	}
    /*
     * @brief Metodo 'incluir'
     * @details Metodo para adicionar um elemento na Fila.
     * É chamado o metodo 'adiciona()' da classe Pai 'ListaEnc' no metodo 'inclui'
     * @param O parametro 'dado' é o elemento a ser adicionado na Fila
     */
	void inclui(const T& dado) {
	    this->adiciona(dado);
	}
	/*
     * @brief Metodo 'retira'
     * @details Metodo para retirar um elemento da Fila.
     * É chamado o metodo 'retiraDoInicio()' da classe Pai 'ListaEnc' no metodo 'inclui'
     * @return É retornado o metodo 'retiraDoInicio' que é herdado da classe pai 'ListaEnc'
     */
	T retira() {
        if (filaVazia()) {
            throw "ERROFILAVAZIA";
        } else {
            return this->retiraDoInicio();
        }
	}
    /*
     * @brief Metodo 'primeiro'
     * @details Metodo saber o primeiro elemento da Fila
     * É chamado o objeto 'cabeca' e feito um 'getInfo' utilizando metodos da classe pai 'ListaEnc'
     * @return É retornado a informação obtida atraves do 'getInfo' de 'cabeca'
     */
	T primeiro() {
	    if (filaVazia()) {
	        throw "ERROFILAVAZIA";
	    } else {
	        return this->cabeca->getInfo();
	    }
	}
	/*
     * @brief Metodo 'ultimo'
     * @details Metodo para saber o ultimo elemento da Fila
     * É feito um laço de repetição para passar por todos os elementos da Fila e pegar a informação do ultimo elemento da Fila
     * @return É retornado a informação obtida atraves do 'getInfo' da variavel 'auxiliar'.
     */
	T ultimo() {
	    if (filaVazia()) {
	        throw "ERROFILAVAZIA";
	    } else {
	        Elemento <T> *auxiliar;
	        auxiliar = this->cabeca;
            for (int i = 0; i < this->tamanho-1; i++) {
                auxiliar = auxiliar->getProximo();
            }
            return auxiliar->getInfo();
        }
    }
    /*
     * @brief Metodo 'filaVazia'
     * @details Metodo para verificar se a 'FilaEnc' está vazia
     * É chamado o metodo 'listaVazia()' da classe Pai 'ListaEnc' no metodo 'filaVazia'
     * @return É retornado o metodo 'listaVazia' que é herdado da classe pai 'ListaEnc'
     */
	bool filaVazia() {
	    return this->listaVazia();
	}
	/*
     * @brief Metodo 'limparFila'
     * @details Metodo para limpar a Fila evitando 'lixo' na memoria
     * É chamado o metodo 'destroiLista()' da classe Pai 'ListaEnc' no metodo 'limpaFila'
     * @return É retornado o metodo 'destroiLista()' que é herdado da classe pai 'ListaEnc'
     */
	void limparFila() {
	    this->destroiLista();
	}
};
